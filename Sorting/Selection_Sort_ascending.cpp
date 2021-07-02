#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;++i){
        int temp=arr[i];
        int min_index=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<temp){
                min_index=j;
                temp=arr[j];
            }
        }
        swap(&arr[i],&arr[min_index]);
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
    cout<<"Enter the size of the array."<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array."<<endl;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<"The entered array is:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionsort(arr,n);
    cout<<"The array after sorting in ascending order is:"<<endl;
    printarray(arr,n);
}