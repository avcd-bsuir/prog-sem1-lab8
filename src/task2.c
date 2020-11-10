// License: CC BY-NC-SA 4.0
/*
 * task2.c
 *
 * The function takes data blocks {size, pointer to the beginning of the array}.
 * Find the average of all elements.
 * Do not use va_start, va_end, va_arg.
 *
 * Written by AlexeyFilich
 * 06 nov 2020
 */

#include <stdbool.h>
#include <stdio.h>
#include "Random.h"

void average(int size_first, ...) {
    int ctr = 0; // Argument stack shift
    while (true) {
        int size = *(int *)(&size_first + 2 * ctr++); // Read size of array
        if (size == -1) // If -1 - it is stop value
            return;
        int * array = *(int **)(&size_first + 2 * ctr++); // Read pointer to array
        double average = 0; // Average = 0
        for (int i = 0; i < size; i++, array++) {
            average += *array; // Add array[ctr] to average
            printf("%d ", *array); // Print it
        }
        average /= size; // Find average
        printf("-> Average: %.3lf\n", average); // Print average
    }
}

int main(int argc, char* args[]) {
    int size1 = 5; // Set size to 5
    int * array1 = malloc(size1 * sizeof(int)); // Create array with 5 elements
    for (int i = 0; i < size1; i++) // Fill with random integers
        array1[i] = aRandInt(-5, 5);

    int size2 = 10; // Set size to 10
    int * array2 = malloc(size2 * sizeof(int)); // Create array with 10 elements
    for (int i = 0; i < size2; i++) // Fill with random integers
        array2[i] = aRandInt(-5, 5);

    int size3 = 3; // Set size to 3
    int * array3 = malloc(size3 * sizeof(int)); // Create array with 3 elements
    for (int i = 0; i < size3; i++) // Fill with random integers
        array3[i] = aRandInt(-5, 5);

    printf("With 2 blocks:\n");
    average(size1, array1, size2, array2, -1);
    printf("With 3 blocks:\n");
    average(size1, array1, size2, array2, size3, array3, -1);

    free(array1); // Free arrays
    free(array2);
    free(array3);
    return 0;
}
