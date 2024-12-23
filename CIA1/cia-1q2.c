#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int intValue;
    float floatValue;
    char charValue;
    char stringValue[100];
} DataPoint;

typedef DataPoint MultiPurposeArray;

void readDataPoint(DataPoint *dp) {
    char inputType;
    printf("Enter data type (i for int, f for float, c for char, s for string): ");
    scanf(" %c", &inputType);
    switch(inputType) {
        case 'i':
            printf("Enter integer: ");
            scanf("%d", &dp->intValue);
            break;
        case 'f':
            printf("Enter float: ");
            scanf("%f", &dp->floatValue);
            break;
        case 'c':
            printf("Enter character: ");
            scanf(" %c", &dp->charValue);
            break;
        case 's':
            printf("Enter string: ");
            scanf("%s", dp->stringValue);
            break;
        default:
            printf("Invalid type.\n");
    }
}

void sortDataPoints(MultiPurposeArray *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j].intValue > arr[j+1].intValue) {
                MultiPurposeArray temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    MultiPurposeArray *dataPoints = (MultiPurposeArray*)malloc(n * sizeof(MultiPurposeArray));

    for(int i = 0; i < n; i++) {
        readDataPoint(&dataPoints[i]);
    }

    sortDataPoints(dataPoints, n);

    for(int i = 0; i < n; i++) {
        printf("Data Point %d: %d\n", i+1, dataPoints[i].intValue);
    }

    free(dataPoints);
    return 0;
}
