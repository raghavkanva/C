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

    printf("Total numbers entered: %d\n", count);
    printf("Sum of numbers: %d\n", sum);

    free(numbers);
    return 0;
}
