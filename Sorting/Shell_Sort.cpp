#include<iostream>
using namespace std;
void shellSort(int arr[],int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int i=gap;i<n;++i){
            for(int j=i-gap;j>=0;j-=gap){
                if(arr[j+gap]>arr[j]){
                    break;
                }
                else{
                    swap(arr[j+gap],arr[j]);
                }
            }
        }
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
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<"The entered array elements are:"<<endl;
    display(arr,n);
    shellSort(arr,n);
    cout<<"The elements in the sorted order are:"<<endl;
    display(arr,n);
}