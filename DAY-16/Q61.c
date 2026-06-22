//Write a program to Find missing number in array.
//array must consist of natural number from 1....to..n
#include<stdio.h>
int main(){
        int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int s=((n+1)*(n+2))/2;
    int as=0;
    for(int i=0;i<n;i++){
          as+=arr[i];
    }
    printf("Missing element: %d",(s-as));
    return 0;
}