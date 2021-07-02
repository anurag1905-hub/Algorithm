#include<iostream>
using namespace std;
int CircularArraySearch(int arr[],int n,int x){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]<=arr[high]){
            if(x>arr[mid]&&x<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        else{
            if(arr[low]<=x&&x<arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int main(){
    int arr[]={12,14,18,21,3,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the element you want to search:"<<endl;
    cin>>x;
    int index=CircularArraySearch(arr,n,x);
    if(index==-1){
        cout<<x<<" is not present in the array."<<endl;
    }
    else{
        cout<<x<<" is present in the array at index "<<index<<endl;
    }
}