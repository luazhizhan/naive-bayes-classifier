
#include "training/season.c"
#include "training/age.c"
#include "training/childishDisease.c"
#include "training/trauma.c"
#include "training/surgery.c"
#include "training/highFever.c"
#include "training/alcoholConsumption.c"
#include "training/smokingHabit.c"
#include "training/sitting.c"

trainingResults training(float data[ROW][COLUMN], const int start, const int end)
{
    // Reset and calculate the number of normal and altered data
    float numOfNormalData = 0, numOfAlteredData = 0;
    for (int i = start; i < end; i++)
    {
        if (data[i][RESULT_COLUMN] == NORMAL)
            numOfNormalData++;
        else
            numOfAlteredData++;
    }
    // Caculate normal and altered prior probability
    int totalNumOfData = end - start;
    float normalPriorProb = numOfNormalData / totalNumOfData;
    float alteredPriorProb = numOfAlteredData / totalNumOfData;

    metadata meta = {numOfNormalData, numOfAlteredData,
                     normalPriorProb, alteredPriorProb};

    // Train with 9 different features
    age ageProbs = trainAge(data, meta, start, end);
    sitting sittingProbs = trainSitting(data, meta, start, end);

    trainingResults result = {meta, ageProbs, sittingProbs};

    return result;
}
