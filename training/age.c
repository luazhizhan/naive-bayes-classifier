extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float normalAgeMean, alteredAgeMean, normalAgeVariance, alteredAgeVariance;

void trainAge(const int trainingStartRow, const int trainingEndRow)
{
    // Calculate mean of normal and altered age
    float sumOfNormalAge = 0, sumOfAlteredAge = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][1];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalAge += val;
        else
            sumOfAlteredAge += val;
    }
    normalAgeMean = sumOfNormalAge / noOfNormalData;
    alteredAgeMean = sumOfAlteredAge / noOfAlteredData;

    // calculate variance of normal and altered age
    float sumOfNormalAgeVariance = 0, sumOfAlteredAgeVariance = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][1];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalAgeVariance += pow((val - normalAgeMean), 2);
        else
            sumOfAlteredAgeVariance += pow((val - alteredAgeMean), 2);
    }
    normalAgeVariance = sumOfNormalAgeVariance / (noOfNormalData - 1);
    alteredAgeVariance = sumOfAlteredAgeVariance / (noOfAlteredData - 1);
    // printf("2. Age : %f %f %f %f\n",
    //        normalAgeMean, alteredAgeMean,
    //        normalAgeVariance, alteredAgeVariance);
}
