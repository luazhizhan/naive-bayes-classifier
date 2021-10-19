extern float normalHrsMean, alteredHrsMean, normalHrsVariance, alteredHrsVariance;

float gaussianDistrbution(float value, float variance, float mean);

void testSitting(float sitHrs, float *normalResult, float *alteredResult)
{
    *normalResult *= gaussianDistrbution(sitHrs, normalHrsVariance, normalHrsMean);
    *alteredResult *= gaussianDistrbution(sitHrs, alteredHrsVariance, alteredHrsMean);
}
