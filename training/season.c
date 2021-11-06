
season trainSeason(float **data, metadata meta, const int start, const int end)
{
    // number of rows that are NORMAL(N) or altered(A) by season
    float noOfWinterNormal = ALPHA, noOfSpringNormal = ALPHA, noOfSummerNormal = ALPHA,
          noOfFallNormal = ALPHA, noOfWinterAltered = ALPHA, noOfSpringAltered = ALPHA,
          noOfSummerAltered = ALPHA, noOfFallAltered = ALPHA;

    for (int i = start; i < end; i++)
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
    float noOfNormalDataAlpha = meta.numOfNormalData + 4;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 4;

    float winterNormal = noOfWinterNormal / noOfNormalDataAlpha;
    float springNormal = noOfSpringNormal / noOfNormalDataAlpha;
    float summerNormal = noOfSummerNormal / noOfNormalDataAlpha;
    float fallNormal = noOfFallNormal / noOfNormalDataAlpha;
    float winterAltered = noOfWinterAltered / noOfAlteredDataAlpha;
    float springAltered = noOfSpringAltered / noOfAlteredDataAlpha;
    float summerAltered = noOfSummerAltered / noOfAlteredDataAlpha;
    float fallAltered = noOfFallAltered / noOfAlteredDataAlpha;

    // printf("1. Seasons : %f %f %f %f %f %f %f %f \n", winterNormal, springNormal, summerNormal,
    //        fallNormal, winterAltered, springAltered, summerAltered, fallAltered);

    season result = {winterNormal, springNormal, summerNormal, fallNormal,
                     winterAltered, springAltered, summerAltered, fallAltered};
    return result;
}
