extern float neverSmokeNormal, occasionSmokeNormal, dailySmokeNormal,
    neverSmokeAltered, occasionSmokeAltered, dailySmokeAltered;

void testSmokingHabit(float smoking, float *normalResult, float *alteredResult)
{
    if (smoking == NEVER_SMOKE)
    {
        *normalResult *= neverSmokeNormal;
        *alteredResult *= neverSmokeAltered;
    }
    else if (smoking == OCCASIONAL_SMOKE)
    {
        *normalResult *= occasionSmokeNormal;
        *alteredResult *= occasionSmokeAltered;
    }
    else if (smoking == DAILY_SMOKE)
    {
        *normalResult *= dailySmokeNormal;
        *alteredResult *= dailySmokeAltered;
    }
}
