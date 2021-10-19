extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float haveChildDiseaseNormal, noChildDiseaseNormal, haveChildDiseaseAltered,
    noChildDiseaseAltered;

void trainChildishDisease(const int trainingStartRow, const int trainingEndRow)
{
    float noOfHaveChildDiseaseNormal = ALPHA, noOfNoChildDiseaseNormal = ALPHA,
          noOfHaveChildDiseaseAltered = ALPHA, noOfNoChildDiseaseAltered = ALPHA;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][2];
        float result = data[i][RESULT_COLUMN];
        if (val == HAVE_CHILD_DISEASE)
        {
            if (result == NORMAL)
                noOfHaveChildDiseaseNormal++;
            else
                noOfHaveChildDiseaseAltered++;
        }
        else if (val == NO_CHILD_DISEASE)
        {
            if (result == NORMAL)
                noOfNoChildDiseaseNormal++;
            else
                noOfNoChildDiseaseAltered++;
        }
    }
    // Add 2 as there are 2 different answers (yes,no) for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = noOfNormalData + 2;
    float noOfAlteredDataAlpha = noOfAlteredData + 2;

    haveChildDiseaseNormal = noOfHaveChildDiseaseNormal / noOfNormalDataAlpha;
    noChildDiseaseNormal = noOfNoChildDiseaseNormal / noOfNormalDataAlpha;
    haveChildDiseaseAltered = noOfHaveChildDiseaseAltered / noOfAlteredDataAlpha;
    noChildDiseaseAltered = noOfNoChildDiseaseAltered / noOfAlteredDataAlpha;

    // printf("3. Childish Disease : %f %f %f %f\n", haveChildDiseaseNormal, noChildDiseaseNormal,
    //        haveChildDiseaseAltered, noChildDiseaseAltered);
}
