extern float haveTraumaNormal, noTraumaNormal, haveTraumaAltered, noTraumaAltered;

void testTrauma(float traumaValue, float *normalResult, float *alteredResult)
{
    if (traumaValue == HAVE_TRAUMA)
    {
        *normalResult *= haveTraumaNormal;
        *alteredResult *= haveTraumaAltered;
    }
    else if (traumaValue == NO_TRAUMA)
    {
        *normalResult *= noTraumaNormal;
        *alteredResult *= noTraumaAltered;
    }
}
