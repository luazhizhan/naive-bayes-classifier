extern float normalAgeMean, alteredAgeMean, normalAgeVariance, alteredAgeVariance;

void testAge(float ageValue, float *normalResult, float *alteredResult)
{
    *normalResult *= gaussianDistribution(ageValue, normalAgeVariance, normalAgeMean);
    *alteredResult *= gaussianDistribution(ageValue, alteredAgeVariance, alteredAgeMean);
}
