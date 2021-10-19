#include "testing/season.c"
#include "testing/age.c"
#include "testing/childishDisease.c"
#include "testing/trauma.c"
#include "testing/surgery.c"
#include "testing/highFever.c"
#include "testing/alcoholConsumption.c"
#include "testing/smokingHabit.c"
#include "testing/sitting.c"

void testing(const int testingStartRow, const int testingEndRow)
{
    float totalNumOfErrors = 0, totalNumOfTests = testingEndRow - testingStartRow,
          falseNegative = 0, falsePositive = 0,
          trueNegative = 0, truePositive = 0;

    for (int i = testingStartRow; i < testingEndRow; i++)
    {
        // Result for normal and altered probability based on test
        float normalResult = normalPriorProb, alteredResult = alteredPriorProb;

        float seasonValue = data[i][0], ageValue = data[i][1], childDisease = data[i][2],
              traumaValue = data[i][3], surgeryValue = data[i][4], feverValue = data[i][5],
              alcohol = data[i][6], smoking = data[i][7], sitHrs = data[i][8],
              result = data[i][RESULT_COLUMN];

        // Calculate probability of Y = Normal OR Y = Altered
        testSeason(seasonValue, &normalResult, &alteredResult);
        testAge(ageValue, &normalResult, &alteredResult);
        testChildishDisease(childDisease, &normalResult, &alteredResult);
        testTrauma(traumaValue, &normalResult, &alteredResult);
        testSurgery(surgeryValue, &normalResult, &alteredResult);
        testHighFever(feverValue, &normalResult, &alteredResult);
        testAlcoholConsumption(alcohol, &normalResult, &alteredResult);
        testSmokingHabit(smoking, &normalResult, &alteredResult);
        testSitting(sitHrs, &normalResult, &alteredResult);

        // Y = Normal
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
    float probOfError = totalNumOfErrors / totalNumOfTests;
    printf("Probability of error = %f\n", probOfError);
    printf("Confusion Matrix table values: \n");
    printf("True Positive = %.0f\nTrue Negative = %.0f\n", truePositive, trueNegative);
    printf("False Positive = %.0f\nFalse Negative = %.0f\n", falsePositive, falseNegative);
}
