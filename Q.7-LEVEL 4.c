/*Question: Get a Three digit number from the user and print the reverse of it.
Example: User Enters “738”*/

#include<stdio.h>
int main ()
{
int x, y;
printf ("Enter a THREE-digit Number: ");
scanf ("%d", &x);
y=(((x%10)*100)+(((x/10)%10)*10)+(x/100));
printf ("The reversed number is : %d\n",y);
}
