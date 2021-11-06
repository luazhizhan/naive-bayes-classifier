alcohol trainAlcoholConsumption(float **data, metadata meta,
                                const int trainingStartRow, const int trainingEndRow)
{
    float noOfDrinkServeralADayNormal = ALPHA, noDrinkADayNormal = ALPHA,
          noOfDrinkServeralAWeekNormal = ALPHA, noDrinkAWeekNormal = ALPHA,
          noOfDrinkHardlyNormal = ALPHA, noOfDrinkServeralADayAltered = ALPHA,
          noDrinkADayAltered = ALPHA, noOfDrinkServeralAWeekAltered = ALPHA,
          noDrinkAWeekAltered = ALPHA, noOfDrinkHardlyAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][6];
        float result = data[i][RESULT_COLUMN];
        if (val == DRINK_SERVERAL_A_DAY)
        {
            if (result == NORMAL)
                noOfDrinkServeralADayNormal++;
            else
                noOfDrinkServeralADayAltered++;
        }
        else if (val == DRINK_EVERY_DAY)
        {
            if (result == NORMAL)
                noDrinkADayNormal++;
            else
                noDrinkADayAltered++;
        }
        else if (val == DRINK_SERVERAL_A_WEEK)
        {
            if (result == NORMAL)
                noOfDrinkServeralAWeekNormal++;
            else
                noOfDrinkServeralAWeekAltered++;
        }
        else if (val == DRINK_EVERY_WEEK)
        {
            if (result == NORMAL)
                noDrinkAWeekNormal++;
            else
                noDrinkAWeekAltered++;
        }
        else if (val == HARDLY_DRINK)
        {
            if (result == NORMAL)
                noOfDrinkHardlyNormal++;
            else
                noOfDrinkHardlyAltered++;
        }
    }
    // Add 5 as there are 5 different value (0.2,0.4,0.6,0.8,1) for normal
    // and altered data due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 5;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 5;

    float drinkServeralADayNormal = noOfDrinkServeralADayNormal / noOfNormalDataAlpha;
    float drinkADayNormal = noDrinkADayNormal / noOfNormalDataAlpha;
    float drinkServeralAWeekNormal = noOfDrinkServeralAWeekNormal / noOfNormalDataAlpha;
    float drinkAWeekNormal = noDrinkAWeekNormal / noOfNormalDataAlpha;
    float drinkHardlyNormal = noOfDrinkHardlyNormal / noOfNormalDataAlpha;

    float drinkServeralADayAltered = noOfDrinkServeralADayAltered / noOfAlteredDataAlpha;
    float drinkADayAltered = noDrinkADayAltered / noOfAlteredDataAlpha;
    float drinkServeralAWeekAltered = noOfDrinkServeralAWeekAltered / noOfAlteredDataAlpha;
    float drinkAWeekAltered = noDrinkAWeekAltered / noOfAlteredDataAlpha;
    float drinkHardlyAltered = noOfDrinkHardlyAltered / noOfAlteredDataAlpha;

    alcohol result = {drinkServeralADayNormal,
                      drinkADayNormal,
                      drinkServeralAWeekNormal,
                      drinkAWeekNormal,
                      drinkHardlyNormal,
                      drinkServeralADayAltered,
                      drinkADayAltered,
                      drinkServeralAWeekAltered,
                      drinkAWeekAltered,
                      drinkHardlyAltered};
    return result;
}
