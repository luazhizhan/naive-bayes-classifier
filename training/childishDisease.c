disease trainChildishDisease(float **data, metadata meta,
                             const int trainingStartRow, const int trainingEndRow)
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
    float noOfNormalDataAlpha = meta.numOfNormalData + 2;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 2;

    float haveChildDiseaseNormal = noOfHaveChildDiseaseNormal / noOfNormalDataAlpha;
    float noChildDiseaseNormal = noOfNoChildDiseaseNormal / noOfNormalDataAlpha;
    float haveChildDiseaseAltered = noOfHaveChildDiseaseAltered / noOfAlteredDataAlpha;
    float noChildDiseaseAltered = noOfNoChildDiseaseAltered / noOfAlteredDataAlpha;

    disease result = {haveChildDiseaseNormal,
                      noChildDiseaseNormal,
                      haveChildDiseaseAltered,
                      noChildDiseaseAltered};
    return result;
}
