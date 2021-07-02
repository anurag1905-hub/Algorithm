#include<iostream>
using namespace std;
int binarysearch(int arr[],int x,int low,int high){
    if(high>=low){
    int mid=(low+high)/2;
    if(arr[mid]==x){
        return mid;
    }
    if(arr[mid]<x){
        return binarysearch(arr,x,mid+1,high);
    }
    if(arr[mid]>x){
        return binarysearch(arr,x,low,mid-1);
    }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array."<<endl;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the element you want to search:"<<endl;
    cin>>x;
    int result=binarysearch(arr,x,0,n-1);
    if(result==-1){
        cout<<"Element not found!"<<endl;
    }
    else{
        cout<<"Element is found!"<<endl;
    }
}