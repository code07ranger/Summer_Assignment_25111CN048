// Write a program to Input and display array.
#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    //input array
    printf("Enter element of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //display array
     for(int i=0;i<=n-1;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}