//Write a program to Selection sort.
#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int minidx=-1;
    for(int i=0;i<n;i++){
    int min=INT_MAX;
    if(arr[i]<min){
        min=arr[i];
        minidx=i;
    }
    for(int j=0;j<n;j++){
        if(arr[j]>arr[minidx]){
            int temp=arr[j];
            arr[j]=arr[minidx];
            arr[minidx]=temp;
        }
    }
   }
   for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
   }
    return 0;

}