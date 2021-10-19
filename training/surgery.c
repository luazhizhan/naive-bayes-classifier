extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float haveSurgeryNormal, noSurgeryNormal, haveSurgeryAltered, noSurgeryAltered;

void trainSurgery(const int trainingStartRow, const int trainingEndRow)
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
    float noOfNormalDataAlpha = noOfNormalData + 2;
    float noOfAlteredDataAlpha = noOfAlteredData + 2;

    haveSurgeryNormal = noOfHaveSurgeryNormal / noOfNormalDataAlpha;
    noSurgeryNormal = noOfNoSurgeryNormal / noOfNormalDataAlpha;
    haveSurgeryAltered = noOfHaveSurgeryAltered / noOfAlteredDataAlpha;
    noSurgeryAltered = noOfNoSurgeryAltered / noOfAlteredDataAlpha;
    // printf("5. Surgical Intervention : %f %f %f %f\n", haveSurgeryNormal, noSurgeryNormal,
    //        haveSurgeryAltered, noSurgeryAltered);
}
