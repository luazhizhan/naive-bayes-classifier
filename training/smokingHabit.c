smoking trainSmokingHabit(float **data, metadata meta,
                          const int trainingStartRow, const int trainingEndRow)
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
    float noOfNormalDataAlpha = meta.numOfNormalData + 3;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 3;

    float neverSmokeNormal = noOfNeverSmokeNormal / noOfNormalDataAlpha;
    float occasionSmokeNormal = noOfOccasionSmokeNormal / noOfNormalDataAlpha;
    float dailySmokeNormal = noOfDailySmokeNormal / noOfNormalDataAlpha;

    float neverSmokeAltered = noOfNeverSmokeAltered / noOfAlteredDataAlpha;
    float occasionSmokeAltered = noOfOccasionSmokeAltered / noOfAlteredDataAlpha;
    float dailySmokeAltered = noOfDailySmokeAltered / noOfAlteredDataAlpha;

    smoking result = {neverSmokeNormal,
                      occasionSmokeNormal,
                      dailySmokeNormal,
                      neverSmokeAltered,
                      occasionSmokeAltered,
                      dailySmokeAltered};
    return result;
}
