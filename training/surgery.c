surgery trainSurgery(float **data, metadata meta,
                     const int trainingStartRow, const int trainingEndRow)
{
    float noOfHaveSurgeryNormal = ALPHA, noOfNoSurgeryNormal = ALPHA,
          noOfHaveSurgeryAltered = ALPHA, noOfNoSurgeryAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][4];
        float result = data[i][RESULT_COLUMN];
        if (val == HAVE_SURGERY)
        {
            if (result == NORMAL)
                noOfHaveSurgeryNormal++;
            else
                noOfHaveSurgeryAltered++;
        }
        else if (val == NO_SURGERY)
        {
            if (result == NORMAL)
                noOfNoSurgeryNormal++;
            else
                noOfNoSurgeryAltered++;
        }
    }
    // Add 2 as there are 2 different answers (yes,no) for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 2;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 2;

    float haveSurgeryNormal = noOfHaveSurgeryNormal / noOfNormalDataAlpha;
    float noSurgeryNormal = noOfNoSurgeryNormal / noOfNormalDataAlpha;
    float haveSurgeryAltered = noOfHaveSurgeryAltered / noOfAlteredDataAlpha;
    float noSurgeryAltered = noOfNoSurgeryAltered / noOfAlteredDataAlpha;

    surgery result = {haveSurgeryNormal, noSurgeryNormal,
                      haveSurgeryAltered, noSurgeryAltered};
    return result;
}
