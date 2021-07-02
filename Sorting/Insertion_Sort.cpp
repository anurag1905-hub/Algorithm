#include<iostream>
using namespace std;
void insertionsort_ascending(int arr[],int n){
    for(int i=1;i<n;++i){
      int temp=arr[i];
      int j=i-1;
      while(j>=0&&arr[j]>temp){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=temp;
    }
}
void insertionsort_descending(int arr[],int n){
    for(int i=1;i<n;++i){
      int temp=arr[i];
      int j=i-1;
      while(j>=0&&arr[j]<temp){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=temp;
    }
}
void print(int arr[],int n){
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
    cout<<"The entered array is..."<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionsort_ascending(arr,n);
    cout<<"The enetered array in ascending order is:"<<endl;
    print(arr,n);
    insertionsort_descending(arr,n);
    cout<<"The enetered array in descending order is:"<<endl;
    print(arr,n);

}