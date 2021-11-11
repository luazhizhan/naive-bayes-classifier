highFever trainHighFever(float data[ROW][COLUMN], metadata meta,
                         const int trainingStartRow, const int trainingEndRow)
{
    float noOfHaveFeverLess3MthsNormal = ALPHA, noOfHaveFeverMore3MthsNormal = ALPHA,
          noOfNoFeverNormal = ALPHA, noOfHaveFeverLess3MthsAltered = ALPHA,
          noOfHaveFeverMore3MthsAltered = ALPHA, noOfNoFeverAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][5];
        float result = data[i][RESULT_COLUMN];
        if (val == FEVER_LESS_3_MTHS)
        {
            if (result == NORMAL)
                noOfHaveFeverLess3MthsNormal++;
            else
                noOfHaveFeverLess3MthsAltered++;
        }
        else if (val == FEVER_MORE_3_MTHS)
        {
            if (result == NORMAL)
                noOfHaveFeverMore3MthsNormal++;
            else
                noOfHaveFeverMore3MthsAltered++;
        }
        else if (val == NO_FEVER)
        {
            if (result == NORMAL)
                noOfNoFeverNormal++;
            else
                noOfNoFeverAltered++;
        }
    }

    // Add 3 as there are 3 different value (-1,0,1) for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 3;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 3;

    float haveFeverLess3MthsNormal = noOfHaveFeverLess3MthsNormal / noOfNormalDataAlpha;
    float haveFeverMore3MthsNormal = noOfHaveFeverMore3MthsNormal / noOfNormalDataAlpha;
    float noFeverNormal = noOfNoFeverNormal / noOfNormalDataAlpha;
    float haveFeverLess3MthsAltered = noOfHaveFeverLess3MthsAltered / noOfAlteredDataAlpha;
    float haveFeverMore3MthsAltered = noOfHaveFeverMore3MthsAltered / noOfAlteredDataAlpha;
    float noFeverAltered = noOfNoFeverAltered / noOfAlteredDataAlpha;

    highFever result = {haveFeverLess3MthsNormal, haveFeverMore3MthsNormal,
                        noFeverNormal, haveFeverLess3MthsAltered,
                        haveFeverMore3MthsAltered, noFeverAltered};
    return result;
}
