extern float drinkServeralADayNormal, drinkADayNormal, drinkServeralAWeekNormal,
    drinkAWeekNormal, drinkHardlyNormal, drinkServeralADayAltered, drinkADayAltered,
    drinkServeralAWeekAltered, drinkAWeekAltered, drinkHardlyAltered;

void testAlcoholConsumption(float alcohol, float *normalResult, float *alteredResult)
{
    if (alcohol == DRINK_SERVERAL_A_DAY)
    {
        *normalResult *= drinkServeralADayNormal;
        *alteredResult *= drinkServeralADayAltered;
    }
    else if (alcohol == DRINK_EVERY_DAY)
    {
        *normalResult *= drinkADayNormal;
        *alteredResult *= drinkADayAltered;
    }
    else if (alcohol == DRINK_SERVERAL_A_WEEK)
    {
        *normalResult *= drinkServeralAWeekNormal;
        *alteredResult *= drinkServeralAWeekAltered;
    }
    else if (alcohol == DRINK_EVERY_WEEK)
    {
        *normalResult *= drinkAWeekNormal;
        *alteredResult *= drinkAWeekAltered;
    }
    else if (alcohol == HARDLY_DRINK)
    {
        *normalResult *= drinkHardlyNormal;
        *alteredResult *= drinkHardlyAltered;
    }
}
