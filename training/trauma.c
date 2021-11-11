trauma trainTrauma(float data[ROW][COLUMN], metadata meta,
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
    float numOfNormalData = meta.numOfNormalData + 2;
    float numOfAlteredData = meta.numOfAlteredData + 2;

    float haveTraumaNormal = noOfHaveTraumaNormal / numOfNormalData;
    float noTraumaNormal = noOfNoTraumaNormal / numOfNormalData;
    float haveTraumaAltered = noOfHaveTraumaAltered / numOfAlteredData;
    float noTraumaAltered = noOfNoTraumaAltered / numOfAlteredData;

    trauma result = {haveTraumaNormal,
                     noTraumaNormal,
                     haveTraumaAltered,
                     noTraumaAltered};
    return result;
}
