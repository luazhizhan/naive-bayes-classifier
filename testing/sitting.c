extern float normalHrsMean, alteredHrsMean, normalHrsVariance, alteredHrsVariance;

float gaussianDistribution(float value, float variance, float mean);

void testSitting(float sitHrs, float *normalResult, float *alteredResult)
{
    *normalResult *= gaussianDistribution(sitHrs, normalHrsVariance, normalHrsMean);
    *alteredResult *= gaussianDistribution(sitHrs, alteredHrsVariance, alteredHrsMean);
}
