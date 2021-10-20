
// Gaussain distribution using variance formula
float gaussianDistribution(float value, float variance, float mean)
{
    float fx = 1 / sqrt(2 * M_PI) * exp(-0.5 * pow((value - mean), 2) / variance);
    return fx;
}
