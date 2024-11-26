#include<stdio.h>
int main()
{
    int number,temp_number,reverse_of_number,total;
    total = 0;
    for (number = 0; number < 100000; number++)
    {
        temp_number = number;
        reverse_of_number = 0;
        while(temp_number)
        {
            reverse_of_number = reverse_of_number * 10 + (temp_number%10);
            temp_number = temp_number/10;
        }
        if(number == reverse_of_number) total++;
    }
    printf("total number of all Palindrome numbers less than 100000 is %d",total);
}
