/*Question: Get a Two digit number from user and print the digit in “Tens”
position
Example: User Enters “78”
Answer - 7*/

#include<stdio.h>
int main ()
{
int x, y;
printf ("Enter a TWO-digit Number: ");
scanf ("%d", &x);
y=x/10;
printf ("The digit in Tens position is : %d\n",y);
}
