void testChildishDisease(float childDisease, disease probs, float *normalResult, float *alteredResult)
{
    if (childDisease == HAVE_CHILD_DISEASE)
    {
        *normalResult *= probs.haveChildDiseaseNormal;
        *alteredResult *= probs.haveChildDiseaseAltered;
    }
    else if (childDisease == NO_CHILD_DISEASE)
    {
        *normalResult *= probs.noChildDiseaseNormal;
        *alteredResult *= probs.noChildDiseaseAltered;
    }
}
