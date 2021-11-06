
void testSeason(float seasonValue, season probs,
                float *normalResult, float *alteredResult)
{
    if (seasonValue == WINTER)
    {
        *normalResult *= probs.winterNormal;
        *alteredResult *= probs.winterAltered;
    }
    else if (seasonValue == SPRING)
    {
        *normalResult *= probs.springNormal;
        *alteredResult *= probs.springAltered;
    }
    else if (seasonValue == SUMMER)
    {
        *normalResult *= probs.summerNormal;
        *alteredResult *= probs.summerAltered;
    }
    else if (seasonValue == FALL)
    {
        *normalResult *= probs.fallNormal;
        *alteredResult *= probs.fallAltered;
    }
}
