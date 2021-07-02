#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int arr[],int n){
    for(int i=0;i<=n-1;++i){
        bool swapped=false;
        for(int j=0;j<n-1;++j){
           if(arr[j]>arr[j+1]){
               swap(&arr[j],&arr[j+1]);
               swapped=true;
           }
        }
        if(swapped==false){
            break;
        }
    }
}
void print(int arr[],int n){
    cout<<"The sorted array in ascending order is:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
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
            bubblesort(arr,n);
            print(arr,n);
}