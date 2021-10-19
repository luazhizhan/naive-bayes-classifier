extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float neverSmokeNormal, occasionSmokeNormal, dailySmokeNormal,
    neverSmokeAltered, occasionSmokeAltered, dailySmokeAltered;

void trainSmokingHabit(const int trainingStartRow, const int trainingEndRow)
{
    float noOfNeverSmokeNormal = ALPHA, noOfOccasionSmokeNormal = ALPHA,
          noOfDailySmokeNormal = ALPHA, noOfNeverSmokeAltered = ALPHA,
          noOfOccasionSmokeAltered = ALPHA, noOfDailySmokeAltered = ALPHA;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][7];
        float result = data[i][RESULT_COLUMN];
        if (val == NEVER_SMOKE)
        {
            if (result == NORMAL)
                noOfNeverSmokeNormal++;
            else
                noOfNeverSmokeAltered++;
        }
        else if (val == OCCASIONAL_SMOKE)
        {
            if (result == NORMAL)
                noOfOccasionSmokeNormal++;
            else
                noOfOccasionSmokeAltered++;
        }
        else if (val == DAILY_SMOKE)
        {
            if (result == NORMAL)
                noOfDailySmokeNormal++;
            else
                noOfDailySmokeAltered++;
        }
    }
    // Add 3 as there are 3 different value (-1,0,1) for normal
    // and altered data due to ALPHA being set to 1
    float noOfNormalDataAlpha = noOfNormalData + 3;
    float noOfAlteredDataAlpha = noOfAlteredData + 3;

    neverSmokeNormal = noOfNeverSmokeNormal / noOfNormalDataAlpha;
    occasionSmokeNormal = noOfOccasionSmokeNormal / noOfNormalDataAlpha;
    dailySmokeNormal = noOfDailySmokeNormal / noOfNormalDataAlpha;

    neverSmokeAltered = noOfNeverSmokeAltered / noOfAlteredDataAlpha;
    occasionSmokeAltered = noOfOccasionSmokeAltered / noOfAlteredDataAlpha;
    dailySmokeAltered = noOfDailySmokeAltered / noOfAlteredDataAlpha;

    // printf("8. Smoking Habit : %f %f %f %f %f %f\n",
    //        neverSmokeNormal, occasionSmokeNormal, dailySmokeNormal,
    //        neverSmokeAltered, occasionSmokeAltered, dailySmokeAltered);
}
