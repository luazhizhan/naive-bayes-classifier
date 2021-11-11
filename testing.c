#include "testing/season.c"
#include "testing/age.c"
#include "testing/childishDisease.c"
#include "testing/trauma.c"
#include "testing/surgery.c"
#include "testing/highFever.c"
#include "testing/alcoholConsumption.c"
#include "testing/smokingHabit.c"
#include "testing/sitting.c"

float testing(float data[ROW][COLUMN], trainingResults trainResult,
              const int testingStartRow, const int testingEndRow)
{
    float totalNumOfErrors = 0, totalNumOfTests = testingEndRow - testingStartRow,
          falseNegative = 0, falsePositive = 0,
          trueNegative = 0, truePositive = 0;

    for (int i = testingStartRow; i < testingEndRow; i++)
    {
        // Result for normal and altered probability based on test
        float normalResult = trainResult.metadata.normalPriorProb,
              alteredResult = trainResult.metadata.alteredPriorProb;

        float seasonValue = data[i][0], ageValue = data[i][1], childDisease = data[i][2],
              traumaValue = data[i][3], surgeryValue = data[i][4], feverValue = data[i][5],
              alcohol = data[i][6], smoking = data[i][7], sitHrs = data[i][8],
              result = data[i][RESULT_COLUMN];

        // Calculate probability of Y = Normal OR Y = Altered
        // with 9 different features
        testAge(ageValue, trainResult.age, &normalResult, &alteredResult);
        testSitting(sitHrs, trainResult.sitting, &normalResult, &alteredResult);

        // Data for probability of error and confusion matrix
        if (normalResult > alteredResult)
        {
            if (result == NORMAL)
                truePositive++;
            else
            {
                falsePositive++;
                totalNumOfErrors++;
            }
        }
        // Y = Altered
        else
        {
            if (result == NORMAL)
            {
                falseNegative++;
                totalNumOfErrors++;
            }
            else
            {
                trueNegative++;
            }
        }
    }
    // Probability of error formula here
    float probOfError = 0;

    // Print confusion matrix data

    return probOfError;
}
