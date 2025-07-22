// File: 15.c | System: Dell | Time: 09:45 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0909:45 AM.45 
//


#include <stdio.h>
#include <stdlib.h>

#include "../sum.h"

int main(void) {
    int *numbers = NULL;
    int *numNew = NULL;
    int count = 0, input, Sum= 0;

    printf("Enter numbers (0 to stop):\n");

    while (1) {
        scanf("%d", &input);
        Sum = sum(input);
        if (input == 0) break;
        numbers = realloc(numbers, (count + 1) * sizeof(int));
        numNew = realloc(numNew, (count + 1) * sizeof(int));
        if (numbers == NULL || numNew == NULL) {
            printf("Memory error\n");
            return 1;
        }
        numbers[count] = input;
        numNew[count] = Sum;
        count++;
        input = 0;
    }
    for (int i = 0; i < count; i++) {
        printf("The original array is : %d\n",numbers[i]);
        printf("The sum of the digits array is : %d\n",numNew[i]);
    }
    return 0;
}
