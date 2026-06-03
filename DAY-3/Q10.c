//write a program to check if a number is prime or not within a range
#include<stdio.h>
#include<stdbool.h>
int main(){
    for(int j=1;j<=11;j++){
    bool flag=false;
    for ( int i=2;i<=j-1;i++)
    {
        if(j%i==0)
        {
            flag=true;
            break;
        }
    }
        if (j==1)
        {
           printf("1 is neither composite nor prime\n");
        }
        else if (flag==false)
        {
          printf("%d is prime\n",j);
        }
        else
        {
            printf("%d is composite\n",j);
        }
    }
    return 0;
}