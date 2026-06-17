//Write a program to Find sum and average of array.
#include<stdio.h>
int sum(int brr[],float a){
    float x=0;
    for(int i=0;i<a;i++){
        x+=brr[i];
    }
    return x;
}
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    float s=sum(arr,n);
    printf("The sum of array is %f\n",s);
    float c=n;
    float avg=(s/c);
    printf("The average of array is %f",avg);
    return 0;
}