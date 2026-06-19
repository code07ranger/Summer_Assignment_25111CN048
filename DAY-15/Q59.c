//Write a program to Rotate array right.
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
    int d;
    printf("enter no of rotation: ");
    scanf("%d",&d);
     for(int i=1;i<=d;i++){
            for(int j=n-1;j>0;j--){
             int temp=arr[j];
             arr[j]=arr[j-1];
             arr[j-1]=temp;
            }
        }
    printf("rotated array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}