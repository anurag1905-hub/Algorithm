#include<iostream>
using namespace std;
int get_Partition_Index(int arr[],int start,int end){
    int pivot=arr[end];
    int pindex=start;
    for(int i=start;i<end;++i){
      if(arr[i]<=pivot){
          swap(arr[i],arr[pindex]);
          pindex++;
      }
    }
    swap(arr[pindex],arr[end]);
    return pindex;
}
void mergesort(int arr[],int start,int end){
     if(start<end){
        int pindex=get_Partition_Index(arr,start,end);
        mergesort(arr,start,pindex-1);
        mergesort(arr,pindex+1,end);
     }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    mergesort(arr,0,n-1);
    cout<<"The array sorted in ascending order is:"<<endl;
    printarray(arr,n);
}