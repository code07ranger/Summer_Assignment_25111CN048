//Write a program to Find duplicate in array.
#include<stdio.h>
int main(){
       int arr[7]={6,1,2,5,4,2,3};
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){

     if(arr[i]==arr[j]){
            printf("%d is the duplicate element\n",arr[i]);
            break;
        }
    }
}
    return 0;
}