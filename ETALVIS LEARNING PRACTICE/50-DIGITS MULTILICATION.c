#include<stdio.h>
#include<string.h>
#include<math.h>
char addition(char n1[100],char n2[100],int k,int n,int i ,int j);
char printres(char res[100]);
int big(int l1,int l2);
int main()
{
    char num1[50], num2[50];
    char tempa[100],tempb[100];
    int n=0;
    for(int i = 0; i < 100; i++) {
    tempb[i] =48;
    tempa[i]=48;
    }
    int i=0,j=0;
    printf("Enter the first Number :(Upto 50 Digits)--->  ");
    scanf("%s",&num1);
    printf("Enter the second Number :(Upto 50 Digits)--->  ");
    scanf("%s",&num2);
    int len1=strlen(num1);
    int len2=strlen(num2);
    int carry=0;
    int k=99;
    int temp1=0;
    for (j=(len2-1);j>=0;j--)
    {
        //k=100;
        for(i=(len1-1);i>=0;i--)
        {
            //printf("For i=%d & j=%d :\n",i,j);

            if(i!=0)
            {
                temp1=((num1[i]-48)*(num2[j]-48))+carry;
                //printf("The carry is : %d\n",carry);
                //printf("Product is : %d\n",((num1[i]-48)*(num2[j]-48)));
                tempa[k-n]=((temp1%10)+48);
                //printf("Displaying number is and is store at pos %d:%c\n",k-n,tempa[k-n]);
                carry=temp1/10;
                k--;
            }
            else//if i=0
            {
                temp1=((num1[i]-48)*(num2[j]-48))+carry;
                //printf("Product is : %d\n",((num1[i]-48)*(num2[j]-48)));
                tempa[k-n]=((temp1%10)+48);
                //printf("Displaying number is stores at pos %d:%c\n",k-n,tempa[k-n]);
                int temp2;
                temp2=(temp1/10);
                if (temp2 != 0)
                {
                    tempa[k-n-1]=((temp2+48));
                    //printf("Displaying number is :%c\n",tempa[k-n-1]);
                }
                //printf("\n---over----------------------------------------------------------\n");
                addition(tempa , tempb,k,n,i,j);
                k--;



            }

        }
        n++;
        k=99;
        carry=0;


    }



}


char addition(char n1[100], char n2[100],int k, int n,int i ,int j)
{
    char finale[100];
    for(int v = 0; v < 100; v++) {
    finale[v]=48;
    }
    k=99;
    if(n!=0)
    {
        for(int i=(k-n+1);i<=k;k++)
    {
        n1[i]=48;
    }

    }

    int m=99;
    int carry=0;
    for(m=99;m>=0;m--)
    {
        //printf("Before Updation :\n");
        //printf("For m=%d  \n:",m);
        //printf("First String of Str tempa : %c\n",n1[m]);
        //printf("Second String of Str tempa : %c\n",n2[m]);
        int sum=(n2[m]-48)+(n1[m]-48)+carry;
        carry=(sum/10);
        n2[m]=((sum%10)+48);
        //printf("After Updation :\n Second String of Str tempa : %c\n",n2[m]);
        //printf("The carry is : %d\n",carry);


    }
    printf("---------------------------------------------------------------------------------------------\n");
    if ((i==0)&&(j==0))
    {
        printres(n2);

    }


    return 0;
}

char printres(char res[100])
{
    int flag=0;
    printf("The product is : ");
    for(int i=0;i<100;i++)
    {
        if(res[i]!='0')
        {
            flag=1;
        }
        if(flag==1)
        {
            printf("%c",res[i]);
        }
    }
}
