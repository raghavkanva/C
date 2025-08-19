/*Get a number from user and subtract 5 to that number and print the
result. Write your code inside the function. Do not Change the format.

Input :45 Output 40. Input:56789 Output:56784*/

#include <stdio.h>
int function(int no1);
int main()
{
int number1, number2;
scanf("%d",&number1);
number2 = function(number1);
printf("%d",number2);
return 0;
}
int function(no1)
{
int no2;
no2=(no1-5);
return no2;
}
