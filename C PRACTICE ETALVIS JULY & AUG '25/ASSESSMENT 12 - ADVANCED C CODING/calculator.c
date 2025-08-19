#include <stdint.h>
#include <stdio.h>
#include <string.h>

//Addition
void add(char *num1, char *num2);

//Subtraction
void subtract(char *num1, char *num2, char *result);

//Multiplication
void multiply(char *num1, char *num2);

//Division
void divide(char *divisor, char *dividend);

int check_if_bigger(char *num1, char *num2);
void print(char *result);
void remove_leading_zeros(char *num);

//Custom Functions
void *memmove_custom(void *dest, const void *src, size_t n);
size_t strlen_custom(const char *str);
char *strcpy_custom(char *dest, const char *src);

int main() {
    char input[103] = {0};
    while (1) {
        printf("Calc >"); // removed leading \n for prompt
        scanf("%s",input);
        if (strcmp(input, "Exit") == 0) {
            printf("Thank you for using this Calculator\n"); // removed leading \n for thank you
            break;
        }
        int len = strlen_custom(input);

        //Scan for the arithmetic operator symbols like +,-,*,/
        int index = 0;
        char num1[51] = {0};
        char num2[51] = {0};
        char op = '0';

        //To get two inputs num1 and num2 and the operator
        while (input[index] != '\0') {
            if (input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/') {
                op = input[index];

                int temp_index = 0;
                int j = 0;
                //Split before index
                while (temp_index < index && input[temp_index] != ' ') {
                    num1[temp_index] = input[temp_index];
                    temp_index++;
                }
                num1[temp_index] = '\0';

                temp_index = index + 1;

                //Split after index
                while (temp_index < len && input[temp_index] != ' ') {
                    num2[j++] = input[temp_index++];
                }
                num2[j] = '\0';

                //Remove the leading zeros
                remove_leading_zeros(num1);
                remove_leading_zeros(num2);
            }
            index++;
        }

        //Call the functions accoding to the operator
        if (op == '+') add(num1,num2);
        else if (op == '-') {
            char result[51] = {0};
            subtract(num1,num2,result);
        }
        else if (op == '*') multiply(num1,num2);
        else if (op == '/') divide(num1,num2);
        else printf("Error\n"); // changed to print error on new line
    }
}

//Addition
void add(char *num1, char *num2) {
    char res[52] = {0};
    int sum = 0;
    int carry = 0;
    int len1 = strlen_custom(num1);
    int len2 = strlen_custom(num2);
    int i = len1 - 1, j = len2 - 1, k = 51;
    res[k--] = '\0';
    // Add digits from the end of the strings
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    // Print the result
    print(res + k + 1);
}

//Subtraction
void subtract(char *num1, char *num2, char *result) {
    int negative = 0;
    // Check if num1 < num2, if yes: swap and set negative flag
    if (!check_if_bigger(num1, num2)) {
        negative = 1;
        char temp[51];
        strcpy_custom(temp, num1);
        strcpy_custom(num1, num2);
        strcpy_custom(num2, temp);
    }

    int i = strlen_custom(num1) - 1;
    int j = strlen_custom(num2) - 1;
    int k = i+1;
    int borrow = 0;
    result[k] = '\0';

    // Subtract digits from the end of the strings
    while (i >= 0) {
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        digit1 -= borrow;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        }
        else borrow = 0;

        result[--k] = (digit1 - digit2) + '0';

        i--;
        j--;
    }
    //Remove Leading Zeros Using memmove_custom
    int start = 0;
    while (result[start] == '0' && result[start +1] != '\0') start++;

    if (start > 0) {
        memmove_custom(result, result + start, strlen_custom(result + start) + 1);
    }
    // If negative, add '-' at the beginning
    if (negative) {
        char temp[52];
        temp[0] = '-';
        strcpy_custom(temp + 1, result);
        strcpy_custom(result, temp);
    }
    print(result);
}

//Multiplication
void multiply(char *num1, char *num2){
    char result[101] = {0};
    int len1 = strlen_custom(num1);
    int len2 = strlen_custom(num2);
    int temp[102] = {0};

    //Multiply Each Digit
    for (int i = len1 - 1; i >= 0; i--) {
        int n1 = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            temp[i + j + 1] += n1 * n2;
        }
    }

    //Handle the carry
    for (int i = len1 + len2 - 1; i > 0; i--) {
        if (temp[i] >= 10) {
            temp[i - 1] += temp[i]/10;
            temp[i] %= 10;
        }
    }

    //convert array to string
    for (int i = 0; i < len1 + len2; i++) {
        result[i] = temp[i] + '0';
    }
    result[len1 + len2] = '\0';
    //Remove leading zeros
    int start = 0;
    while (result[start] == '0' && result[start + 1] != '\0') start++;
    // Print the result
    print(result + start);
}

//Division
void divide(char *divisor, char *dividend) {

    //Initialise array of characters(strings) to store the quotient
    char quotient[51] = {0};

    //Initialise an array to store the current part that has been divided
    char temp_dividend[51] = {0};
    int len = strlen_custom(dividend); //Variable to store the length of the dividend

    //To store the result of each division process , initialise a variable to track the index
    int q = 0;

    //Traverse the array using for loop
    for (int i = 0; i < len; i++) {
        int len_temp_dividend = strlen_custom(temp_dividend);
        temp_dividend[len_temp_dividend] = dividend[i];
        temp_dividend[len_temp_dividend + 1] = '\0';// To Terminate the string

        //Terminate the leading zeros in the dividend
        uint8_t index = 0;
        while (temp_dividend[index] == '0' && temp_dividend[index + 1] != '\0') {
            memmove_custom(temp_dividend, temp_dividend + 1, strlen_custom(temp_dividend + 1) + 1);
        }

        //Division Process
        int count = 0; //To track the count of how many times a numbers gets divided
        char temp[51] = {0};
        while (check_if_bigger(temp_dividend, divisor)) {
            subtract(temp_dividend, divisor, temp);
            strcpy_custom(temp_dividend, temp);
            count++;
        }
        quotient[q++] = count + '0';
    }
    quotient[q] = '\0';
    //Remove leading zeros
    int start = 0;
    while (quotient[start] == '0' && quotient[start + 1] != '\0') start++;
    // Print the quotient
    print(quotient + start);
}

int check_if_bigger(char *num1, char *num2) {
    int l1 = strlen_custom(num1);
    int l2 = strlen_custom(num2);

    if (l1 > l2) return 1;
    if (l1 < l2) return 0;

    while (*num1 && *num2) {
        if (*num1 > *num2) return 1;
        if (*num1 < *num2) return 0;
        num1++;
        num2++;
    }
    return 1;
}

void print(char *result) {
    printf("The final answer is : %s\n", result); // removed leading \n, added \n at end
}

void remove_leading_zeros(char *num) {
    int start = 0;
    //Remove leading zeros from a number
    while (num[start] == '0' && num[start + 1] != '\0') {
        start++;
    }
    memmove_custom(num, num + start, strlen_custom(num + start) + 1);
}

// Custom implementation of strlen
size_t strlen_custom(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Custom implementation of memmove
void *memmove_custom(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    if (d == s || n == 0) return dest;
    if (d < s) {
        for (size_t i = 0; i < n; i++)
            d[i] = s[i];
    } else {
        for (size_t i = n; i != 0; i--)
            d[i-1] = s[i-1];
    }
    return dest;
}

// Custom implementation of strcpy
char *strcpy_custom(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}