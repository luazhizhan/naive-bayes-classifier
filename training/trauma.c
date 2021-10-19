extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float haveTraumaNormal, noTraumaNormal, haveTraumaAltered, noTraumaAltered;

void trainTrauma(const int trainingStartRow, const int trainingEndRow)
{
    float noOfHaveTraumaNormal = ALPHA, noOfNoTraumaNormal = ALPHA,
          noOfHaveTraumaAltered = ALPHA, noOfNoTraumaAltered = ALPHA;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][3];
        float result = data[i][RESULT_COLUMN];
        if (val == HAVE_TRAUMA)
        {
            if (result == NORMAL)
                noOfHaveTraumaNormal++;
            else
                noOfHaveTraumaAltered++;
        }
        else if (val == NO_TRAUMA)
        {
            if (result == NORMAL)
                noOfNoTraumaNormal++;
            else
                noOfNoTraumaAltered++;
        }
    }
    // Add 2 as there are 2 different answers (yes,no) for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = noOfNormalData + 2;
    float noOfAlteredDataAlpha = noOfAlteredData + 2;

    haveTraumaNormal = noOfHaveTraumaNormal / noOfNormalDataAlpha;
    noTraumaNormal = noOfNoTraumaNormal / noOfNormalDataAlpha;
    haveTraumaAltered = noOfHaveTraumaAltered / noOfAlteredDataAlpha;
    noTraumaAltered = noOfNoTraumaAltered / noOfAlteredDataAlpha;
    // printf("4. Accident or serious trauma : %f %f %f %f\n", haveTraumaNormal, noTraumaNormal,
    //        haveTraumaAltered, noTraumaAltered);
}
