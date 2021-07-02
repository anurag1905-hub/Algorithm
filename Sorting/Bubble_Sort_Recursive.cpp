#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void recursivebubblesort_ascending(int arr[],int n){
   if(n==1){
       return;
   }
   for(int i=0;i<n-1;++i){
       if(arr[i]>arr[i+1]){
           swap(&arr[i],&arr[i+1]);
       }
   }
   recursivebubblesort_ascending(arr,n-1);
}
void recursivebubblesort_descending(int arr[],int n){
   if(n==1){
       return;
   }
   for(int i=0;i<n-1;++i){
       if(arr[i]<arr[i+1]){
           swap(&arr[i],&arr[i+1]);
       }
   }
   recursivebubblesort_descending(arr,n-1);
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
            cout<<"The enetered array is:"<<endl;
            for(int i=0;i<n;++i){
                cout<<arr[i]<<" ";
            }
            cout<<endl<<"Sorting the array......"<<endl;
            recursivebubblesort_ascending(arr,n);
            cout<<"The sorted array in ascending order is:"<<endl;
            print(arr,n);
            recursivebubblesort_descending(arr,n);
            cout<<"The sorted array in descending order is:"<<endl;
            print(arr,n);
}