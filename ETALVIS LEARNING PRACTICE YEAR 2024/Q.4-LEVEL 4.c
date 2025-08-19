/*Question: Get a Three digit number from user and print the digit in “Tens”
position
Example: User Enters “738”
Answer - 3*/

#include<stdio.h>
int main ()
{
int x, y;
printf ("Enter a THREE-digit Number: ");
scanf ("%d", &x);
y=(x/10)%10;
printf ("The digit in Tens position is : %d\n",y);
}
