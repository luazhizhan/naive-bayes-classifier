extern float normalAgeMean, alteredAgeMean, normalAgeVariance, alteredAgeVariance;

void testAge(float ageValue, float *normalResult, float *alteredResult)
{
    *normalResult *= gaussianDistrbution(ageValue, normalAgeVariance, normalAgeMean);
    *alteredResult *= gaussianDistrbution(ageValue, alteredAgeVariance, alteredAgeMean);
}
