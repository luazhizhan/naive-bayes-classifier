extern float winterNormal, springNormal, summerNormal, fallNormal, winterAltered,
    springAltered, summerAltered, fallAltered;

void testSeason(float seasonValue, float *normalResult, float *alteredResult)
{
    if (seasonValue == WINTER)
    {
        *normalResult *= winterNormal;
        *alteredResult *= winterAltered;
    }
    else if (seasonValue == SPRING)
    {
        *normalResult *= springNormal;
        *alteredResult *= springAltered;
    }
    else if (seasonValue == SUMMER)
    {
        *normalResult *= summerNormal;
        *alteredResult *= summerAltered;
    }
    else if (seasonValue == FALL)
    {
        *normalResult *= fallNormal;
        *alteredResult *= fallAltered;
    }
}
