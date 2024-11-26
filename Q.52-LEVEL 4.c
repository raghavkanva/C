#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    char sstr[50];
    printf("Enter String : ");
    scanf("%s",str);
    printf("Enter the substring : ");
    scanf(" %s",sstr);
    int i=0,si=0,count=0;
    int lens=strlen(sstr);
    while(str[i]!='\0')
    {
        if(str[i]==sstr[0])
        {
            si=i;
            int j=0;
            int k=0;
            k=si;
            while(str[k]==sstr[j])
            {
                count++;
                k++;
                j++;
            }
            if(count==lens)
            {
                printf("The position is : %d",(si+1));
            }
        }
        else
        {
            si=0;
            count=0;
        }
        i++;
    }
}
