#include <stdio.h>
#include <stdlib.h>

int main() {
    int* samples = NULL; 
    
    int count = 0;       
    char choice;         
    double average = 0;  

    samples = (int*)malloc(sizeof(int));
    if (samples == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    do {
        printf("Enter a sample integer value: ");
        scanf("%d", &samples[count]);

        printf("Do you want to add more samples? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            count++;
            samples = (int*)realloc(samples, (count + 1) * sizeof(int));
            if (samples == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }
        } else {
            break;
        }
    } while (1);

    count++;

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += samples[i];
    }
    average = (double)sum / count;

    printf("\nYou entered the following samples: ");
    for (int i = 0; i < count; i++) {
        printf("%d", samples[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }

    printf("\nCalculated average (DC value): %.2f", average);

    printf("\nFinal adjusted samples after DC shift: ");
    for (int i = 0; i < count; i++) {
        samples[i] -= (int)average;
        printf("%d", samples[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("\n");

    free(samples);

    return 0;
}

