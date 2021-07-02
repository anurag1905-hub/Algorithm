#include<iostream>
using namespace std;
void countSort(int arr[],int n,int exp){
  int count[10]={0};
  int output[n];
  for(int i=0;i<n;++i){
      count[(arr[i]/exp)%10]++;
  }
  for(int i=1;i<10;++i){
      count[i]+=count[i-1];
  }
  for(int i=n-1;i>=0;--i){
      output[count[(arr[i]/exp)%10]-1]=arr[i];
      count[(arr[i]/exp)%10]--;
  }
  for(int i=0;i<n;++i){
      arr[i]=output[i];
  }
}
int getMax(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;++i){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void RadixSort(int arr[],int n){
    int max=getMax(arr,n);
    for(int exp=1;max/exp>0;exp*=10){
      countSort(arr,n,exp);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    cout<<"Enter them."<<endl;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<"The entered array is:"<<endl;
    display(arr,n);
    cout<<"The sorted array is:"<<endl;
    RadixSort(arr,n);
    display(arr,n);
}