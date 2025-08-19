// File: 14.c | System: Dell | Time: 09:36 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0909:36 AM.36 
//


#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = NULL;
    int count = 0, input, sum = 0;

    printf("Enter numbers (0 to stop):\n");

    while (1) {
        scanf("%d", &input);
        if (input == 0) break;
        numbers = realloc(numbers, (count + 1) * sizeof(int));
        if (numbers == NULL) {
            printf("Memory error\n");
            return 1;
        }

        numbers[count] = input;
        sum += input;
        count++;
    }

    if (count % 2 == 1 ) printf("The average is : %d",numbers[count/2]);
    else printf("The average is : %.2f", ((numbers[count/2]+numbers[(count/2)-1])/2.0));


    free(numbers);
    return 0;
}
