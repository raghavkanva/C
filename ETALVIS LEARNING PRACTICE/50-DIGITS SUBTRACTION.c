#include<stdio.h>
#include <string.h>
int main()
{
    char s1[50],s2[50];
    char big[50];
    for(int j=0;j<50;j++)
    {
        s1[j]='\0';
        s2[j]='\0';
        big[j]='\0';
    }
    printf("Enter the first number (Upto 50 Digits)---> :");
    scanf("%s",s1);
    printf("Enter the second number (Upto 50 Digits)---> :");
    scanf("%s",s2);
    int f1=0, f2=0;
    while (s1[f1] != '\0' && f1 < 50) {
        f1++;
    }
    if(f1<f2)
    {
        strcpy(big,s1);
    }
    else if(f1>f2)
    {
        strcpy(big,s2);
    }
    else
    {
        for(int m=0;m<f1;m++)
        {
            if(s1[m]>s2[m])
            {
                strcpy(big,s1);

            }
            else if(s1[m]<s2[m])
            {
                strcpy(big,s2);

            }
            else
            {
                continue;
            }
        }

    }

}

