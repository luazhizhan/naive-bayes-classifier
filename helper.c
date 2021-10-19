void printData(float data[100][10])
{
    for (int i = 0; i < 100; i++)
    {
        int k = 0;
        printf("%d. ", i + 1);
        while (k < 10)
            printf("%f ", data[i][k++]);
        printf("\n");
    }
}

float gaussianDistrbution(float value, float variance, float mean)
{
    float fx = 1 / sqrt(2 * M_PI) * exp(-0.5 * pow((value - mean), 2) / variance);
    return fx;
}
