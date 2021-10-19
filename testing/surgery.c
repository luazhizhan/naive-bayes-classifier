extern float haveSurgeryNormal, noSurgeryNormal, haveSurgeryAltered, noSurgeryAltered;

void testSurgery(float surgeryValue, float *normalResult, float *alteredResult)
{
    if (surgeryValue == HAVE_SURGERY)
    {
        *normalResult *= haveSurgeryNormal;
        *alteredResult *= haveSurgeryAltered;
    }
    else if (surgeryValue == NO_SURGERY)
    {
        *normalResult *= noSurgeryNormal;
        *alteredResult *= noSurgeryAltered;
    }
}
