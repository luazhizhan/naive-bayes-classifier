#include "training/season.c"
#include "training/age.c"
#include "training/childishDisease.c"
#include "training/trauma.c"
#include "training/surgery.c"
#include "training/highFever.c"
#include "training/alcoholConsumption.c"
#include "training/smokingHabit.c"
#include "training/sitting.c"

extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float normalPriorProb, alteredPriorProb;

void training(const int trainingStartRow, const int trainingEndRow)
{
    // Reset and calculate the number of normal and altered data
    noOfNormalData = 0, noOfAlteredData = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        if (data[i][RESULT_COLUMN] == NORMAL)
            noOfNormalData++;
        else
            noOfAlteredData++;
    }
    // Caculate normal and altered prior probability
    int totalNumOfData = trainingEndRow - trainingStartRow;
    normalPriorProb = noOfNormalData / totalNumOfData;
    alteredPriorProb = noOfAlteredData / totalNumOfData;

    // Train with 9 different features
    trainSeason(trainingStartRow, trainingEndRow);
    trainAge(trainingStartRow, trainingEndRow);
    trainChildishDisease(trainingStartRow, trainingEndRow);
    trainTrauma(trainingStartRow, trainingEndRow);
    trainSurgery(trainingStartRow, trainingEndRow);
    trainHighFever(trainingStartRow, trainingEndRow);
    trainAlcoholConsumption(trainingStartRow, trainingEndRow);
    trainSmokingHabit(trainingStartRow, trainingEndRow);
    trainSitting(trainingStartRow, trainingEndRow);
}
