trauma trainTrauma(float **data, metadata meta,
                   const int trainingStartRow, const int trainingEndRow)
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
    float noOfNormalDataAlpha = meta.numOfNormalData + 2;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 2;

    float haveTraumaNormal = noOfHaveTraumaNormal / noOfNormalDataAlpha;
    float noTraumaNormal = noOfNoTraumaNormal / noOfNormalDataAlpha;
    float haveTraumaAltered = noOfHaveTraumaAltered / noOfAlteredDataAlpha;
    float noTraumaAltered = noOfNoTraumaAltered / noOfAlteredDataAlpha;

    trauma result = {haveTraumaNormal,
                     noTraumaNormal,
                     haveTraumaAltered,
                     noTraumaAltered};
    return result;
}
