//Write a program to Move zeroes to end.
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
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int zeros=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) zeros++;
    }
    for (int i=0;i<zeros;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Moved zeroes array: ");
    for(int i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
    return 0;
}