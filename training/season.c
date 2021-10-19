extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float winterNormal, springNormal, summerNormal, fallNormal, winterAltered,
    springAltered, summerAltered, fallAltered;

void trainSeason(const int trainingStartRow, const int trainingEndRow)
{
    // number of rows that are NORMAL(N) or altered(A) by season
    float noOfWinterNormal = ALPHA, noOfSpringNormal = ALPHA, noOfSummerNormal = ALPHA,
          noOfFallNormal = ALPHA, noOfWinterAltered = ALPHA, noOfSpringAltered = ALPHA,
          noOfSummerAltered = ALPHA, noOfFallAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][0];
        float result = data[i][RESULT_COLUMN];
        if (val == WINTER)
        {
            if (result == NORMAL)
                noOfWinterNormal++;
            else
                noOfWinterAltered++;
        }
        else if (val == SPRING)
        {
            if (result == NORMAL)
                noOfSpringNormal++;
            else
                noOfSpringAltered++;
        }
        else if (val == SUMMER)
        {
            if (result == NORMAL)
                noOfSummerNormal++;
            else
                noOfSummerAltered++;
        }
        else if (val == FALL)
        {
            if (result == NORMAL)
                noOfFallNormal++;
            else
                noOfFallAltered++;
        }
    }

    // Add 4 as there are 4 different seasons for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = noOfNormalData + 4;
    float noOfAlteredDataAlpha = noOfAlteredData + 4;

    winterNormal = noOfWinterNormal / noOfNormalDataAlpha;
    springNormal = noOfSpringNormal / noOfNormalDataAlpha;
    summerNormal = noOfSummerNormal / noOfNormalDataAlpha;
    fallNormal = noOfFallNormal / noOfNormalDataAlpha;
    winterAltered = noOfWinterAltered / noOfAlteredDataAlpha;
    springAltered = noOfSpringAltered / noOfAlteredDataAlpha;
    summerAltered = noOfSummerAltered / noOfAlteredDataAlpha;
    fallAltered = noOfFallAltered / noOfAlteredDataAlpha;
    // printf("1. Seasons : %f %f %f %f %f %f %f %f \n", winterNormal, springNormal, summerNormal,
    //        fallNormal, winterAltered, springAltered, summerAltered, fallAltered);
}
