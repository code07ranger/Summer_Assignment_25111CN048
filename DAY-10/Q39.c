// Write a program to Print number pyramid.
//     1
//    121
//   12321
//  1234321
// 123454321
#include<stdio.h>
int main(){
    int nsp=4;
    int a=1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=nsp;j++){
            printf(" ");
        }
        for(int k=1;k<=a;k++){
            printf("%d",k);
        }
        if(i!=1){
            for(int h=a-1;h!=0;h--){
                printf("%d",h);
            }
        }
        printf("\n");
        nsp--;
        a++;
    }
    return 0;
}