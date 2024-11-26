/*Question: Get a Four digit number from the user and print the sum of all digits.
Example: User Enters “7638”
Answer - 24*/

#include<stdio.h>
int main ()
{
int x, y;
printf ("Enter a FOUR-digit Number: ");
scanf ("%d", &x);
y=((x/1000)+((x/100)%10)+((x%100)/10)+(x%10));
printf ("The sum of the digits is : %d\n",y);
}
