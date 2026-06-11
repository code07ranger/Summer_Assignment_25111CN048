// Write a program to Print character pyramid.
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
#include<stdio.h>
int main(){
    int nsp=4;
    int a=1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=nsp;j++){
            printf(" ");
        }
        for(int k=1;k<=a;k++){
            char ch1=(char)(k+64);
            printf("%c",ch1);
        }
        if(i!=1){
            for(int h=a-1;h!=0;h--){
                char ch2=(char)(h+64);
                printf("%c",ch2);
            }
        }
        printf("\n");
        nsp--;
        a++;
    }
    return 0;
}