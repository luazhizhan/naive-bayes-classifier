extern float data[100][10];
extern float noOfNormalData, noOfAlteredData;
extern float haveFeverLess3MthsNormal, haveFeverMore3MthsNormal, noFeverNormal,
    haveFeverLess3MthsAltered, haveFeverMore3MthsAltered, noFeverAltered;

void trainHighFever(const int trainingStartRow, const int trainingEndRow)
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
    float noOfNormalDataAlpha = noOfNormalData + 3;
    float noOfAlteredDataAlpha = noOfAlteredData + 3;

    haveFeverLess3MthsNormal = noOfHaveFeverLess3MthsNormal / noOfNormalDataAlpha;
    haveFeverMore3MthsNormal = noOfHaveFeverMore3MthsNormal / noOfNormalDataAlpha;
    noFeverNormal = noOfNoFeverNormal / noOfNormalDataAlpha;
    haveFeverLess3MthsAltered = noOfHaveFeverLess3MthsAltered / noOfAlteredDataAlpha;
    haveFeverMore3MthsAltered = noOfHaveFeverMore3MthsAltered / noOfAlteredDataAlpha;
    noFeverAltered = noOfNoFeverAltered / noOfAlteredDataAlpha;

    // printf("6. High fevers in last year : %f %f %f %f %f %f\n", haveFeverLess3MthsNormal,
    //        haveFeverMore3MthsNormal, noFeverNormal, haveFeverLess3MthsAltered,
    //        haveFeverMore3MthsAltered, noFeverAltered);
}
