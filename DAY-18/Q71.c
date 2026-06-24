//Write a program to Binary search.
#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter element of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter element to be searched: ");
    scanf("%d",&x);
    int beg=0;
    int end=n-1;
    bool flag=false;
    int pos=-1;
    while(beg<end){
        int mid=((beg+end)/2);
        if(arr[mid]==x){
           pos=mid;
           flag=true;
           break;
        }
        if(arr[mid]>x){
            end=mid-1;
        } 
        if(arr[mid]<x){
            beg=mid+1;
        }
    }
    if(flag==true){
        printf("%d element found at %d position",x,pos+1);
    }
    else{
        printf("Search unsucessfull");
    }
    return 0;
}