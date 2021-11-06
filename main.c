#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include "constant.h" // Defined constant
#include "type.h"
#include "helper.c"
#include "training.c" // Training codes
#include "testing.c"
#include "diagnostic.c"

float **readFile();
int main()
{
    // Time the program
    clock_t timer;
    timer = clock();

    // Read data file
    float **data = readFile();

    // 1) Training set (First 80),  Testing set (Last 20)
    printf("\n\n1) Training Set (First 80), Testing Set (Last 20)\n");
    const int trainingStartRow1 = 0, trainingEndRow1 = 80,
              testingStartRow1 = 80, testingEndRow1 = 100;
    trainingResults result1 = training(data, trainingStartRow1, trainingEndRow1);
    testing(data, result1, testingStartRow1, testingEndRow1);

    // 2) Training set (First 50),  Testing set (Last 50)
    printf("\n\n2) Training Set (First 50), Testing Set (Last 50)\n");
    const int trainingStartRow2 = 0, trainingEndRow2 = 50,
              testingStartRow2 = 50, testingEndRow2 = 100;
    trainingResults result2 = training(data, trainingStartRow2, trainingEndRow2);
    testing(data, result2, testingStartRow2, testingEndRow2);

    // 3) Training set (First 90),  Testing set (Last 10)
    printf("\n\n3) Training Set (First 90), Testing Set (Last 10)\n");
    const int trainingStartRow3 = 0, trainingEndRow3 = 90,
              testingStartRow3 = 90, testingEndRow3 = 100;
    trainingResults result3 = training(data, trainingStartRow3, trainingEndRow3);
    testing(data, result3, testingStartRow3, testingEndRow3);

    // Calculate time taken and print it
    timer = clock() - timer;
    double timerTimeTaken = ((double)timer) / CLOCKS_PER_SEC;
    printf("\nTime taken to complete entire program = %.1f milliseconds\n\n", timerTimeTaken * 1000);

    // Diagnostic program
    int diagnosticNum = 1;
    printf("Running diagnostic program...\n");
    while (diagnosticNum >= 1)
    {
        printf("Select diganostic training result set \n1) (80/20) \n2) (50/50) \n3) (90/10).\n");
        printf("Enter < 1 number to stop this program.\n");
        scanf("%d", &diagnosticNum);
        if (diagnosticNum < 1)
            break;
        if (diagnosticNum == 1)
            diagnostic(result1);
        else if (diagnosticNum == 2)
            diagnostic(result2);
        else
            diagnostic(result3);
    }
    return 0;
}

float **readFile()
{
    // Read data from file
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        printf("data.txt not found.\n");
        exit(1);
    }

    int row = 0;
    char line[50];
    float **data = malloc(ROW * sizeof(float *));

    while (fgets(line, sizeof(line), fptr))
    {
        // split line data using "," as delimiter
        char *token = strtok(line, ",");
        int col = 0;
        data[row] = malloc(COLUMN * sizeof(float));

        while (token != NULL)
        {
            // convert char pointer to float
            // store the value to 2d array
            // increment column number
            data[row][col++] = atof(token);

            // continue splitting the next line data using "," as delimiter
            token = strtok(NULL, ",");
        }
        row++;
    }
    // close the file
    fclose(fptr);
    return data;
}
