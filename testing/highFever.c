extern float haveFeverLess3MthsNormal, haveFeverMore3MthsNormal, noFeverNormal,
    haveFeverLess3MthsAltered, haveFeverMore3MthsAltered, noFeverAltered;

void testHighFever(float feverValue, float *normalResult, float *alteredResult)
{
    if (feverValue == FEVER_LESS_3_MTHS)
    {
        *normalResult *= haveFeverLess3MthsNormal;
        *alteredResult *= haveFeverLess3MthsAltered;
    }
    else if (feverValue == FEVER_MORE_3_MTHS)
    {
        *normalResult *= haveFeverMore3MthsNormal;
        *alteredResult *= haveFeverMore3MthsAltered;
    }
    else if (feverValue == NO_FEVER)
    {
        *normalResult *= noFeverNormal;
        *alteredResult *= noFeverAltered;
    }
}
