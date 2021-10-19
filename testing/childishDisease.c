extern float haveChildDiseaseNormal, noChildDiseaseNormal, haveChildDiseaseAltered,
    noChildDiseaseAltered;

void testChildishDisease(float childDisease, float *normalResult, float *alteredResult)
{
    if (childDisease == HAVE_CHILD_DISEASE)
    {
        *normalResult *= haveChildDiseaseNormal;
        *alteredResult *= haveChildDiseaseAltered;
    }
    else if (childDisease == NO_CHILD_DISEASE)
    {
        *normalResult *= noChildDiseaseNormal;
        *alteredResult *= noChildDiseaseAltered;
    }
}
