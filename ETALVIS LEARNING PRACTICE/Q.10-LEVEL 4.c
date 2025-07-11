/*Question: Get a Three digit number from the user and print the sum of all digits.
Example: User Enters “738”
Answer - 18*/

#include<stdio.h>
int main ()
{
int x, y;
printf ("Enter a THREE-digit Number: ");
scanf ("%d", &x);
y=((x/100)+((x/10)%10)+(x%10));
printf ("The sum of the digits is : %d\n",y);
}
