#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter them:"<<endl;
    int max=-1;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<endl<<"The entered elements are:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int hash[max+1];
    for(int i=0;i<=max;++i){
        hash[i]=0;
    }
    for(int i=0;i<n;++i){
        hash[arr[i]]++;
    }
    for(int i=1;i<=max;++i){
        hash[i]+=hash[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;--i){
        output[hash[arr[i]]-1]=arr[i];
        --hash[arr[i]];
    }
    for(int i=0;i<n;++i){
        arr[i]=output[i];
    }
    cout<<"The elements in sorted order are:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
