/*Question: Get a Four digit number from the user and print the reverse of it.
Example: User Enters “6738”*/

#include<stdio.h>
int main ()
{
int x, y;
printf ("Enter a FOUR-digit Number: ");
scanf ("%d", &x);
y=(((x%10)*1000)+(((x%100)/10)*100)+(((x/100)%10)*10)+(x/1000));
printf ("The reversed number is : %d\n",y);
}
