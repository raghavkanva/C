// File: 13.c | System: Dell | Time: 09:33 AM | Date: 22-07-2025 | Year: 2025 | ID: 222025.0909:33 AM.33 
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

    if ((count == 4)&&(numbers[0]==numbers[3])) printf("Success !");
    else printf("Not Success !");

    free(numbers);
    return 0;
}
