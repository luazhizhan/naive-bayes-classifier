#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

#include "constant.h"
#include "global.c"   // Shared global variables
#include "helper.c"   // Shared methods
#include "training.c" // Training codes
#include "testing.c"  // Testing codes

void readFile();

int main()
{
    // Time the program
    clock_t timer;
    timer = clock();

    // Read data file
    readFile();

    // 1) Training set (First 80),  Testing set (Last 20)
    printf("\n\n1) Training Set (First 80), Testing Set (Last 20)\n");
    const int trainingStartRow1 = 0, trainingEndRow1 = 80,
              testingStartRow1 = 80, testingEndRow1 = 100;
    training(trainingStartRow1, trainingEndRow1);
    testing(testingStartRow1, testingEndRow1);

    // 2) Training set (First 50),  Testing set (Last 50)
    printf("\n\n2) Training Set (First 50), Testing Set (Last 50)\n");
    const int trainingStartRow2 = 0, trainingEndRow2 = 50,
              testingStartRow2 = 50, testingEndRow2 = 100;
    training(trainingStartRow2, trainingEndRow2);
    testing(testingStartRow2, testingEndRow2);

    // 3) Training set (First 90),  Testing set (Last 10)
    printf("\n\n3) Training Set (First 90), Testing Set (Last 10)\n");
    const int trainingStartRow3 = 0, trainingEndRow3 = 90,
              testingStartRow3 = 90, testingEndRow3 = 100;
    training(trainingStartRow3, trainingEndRow3);
    testing(testingStartRow3, testingEndRow3);

    // Calculate time taken and print it
    timer = clock() - timer;
    double timerTimeTaken = ((double)timer) / CLOCKS_PER_SEC;
    printf("\nTime taken to complete entire program = %.1f milliseconds\n", timerTimeTaken * 1000);

    return 0;
}

void readFile()
{
    // Read data from file
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL)
        exit(1);

    int row = 0;
    char line[50];

    while (fgets(line, sizeof(line), fptr))
    {
        // split line data using "," as delimiter
        char *token = strtok(line, ",");
        int col = 0;

        while (token != NULL)
        {
            // convert char pointer to float
            // store the value to 2d array
            // increment column number
            data[row][col++] = atof(token);

            // continue splitting the same line data using "," as delimiter
            token = strtok(NULL, ",");
        }
        row++;
    }
    // close the file
    fclose(fptr);
}
