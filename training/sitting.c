extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float normalHrsMean, alteredHrsMean, normalHrsVariance, alteredHrsVariance;

void trainSitting(const int trainingStartRow, const int trainingEndRow)
{
    float sumOfNormalHrs = 0, sumOfAlteredHrs = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][8];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalHrs += val;
        else
            sumOfAlteredHrs += val;
    }
    normalHrsMean = sumOfNormalHrs / noOfNormalData;
    alteredHrsMean = sumOfAlteredHrs / noOfAlteredData;

    // calculate variance of normal and altered hours
    float sumOfNormalHrsVariance = 0, sumOfAlteredHrsVariance = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][1];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalHrsVariance += pow((val - normalHrsMean), 2);
        else
            sumOfAlteredHrsVariance += pow((val - alteredHrsMean), 2);
    }
    normalHrsVariance = sumOfNormalHrsVariance / (noOfNormalData - 1);
    alteredHrsVariance = sumOfAlteredHrsVariance / (noOfAlteredData - 1);
    // printf("9. Number of hours spent sitting per day : %f %f %f %f\n",
    //        normalHrsMean, alteredHrsMean, normalHrsVariance, alteredHrsVariance);
}
