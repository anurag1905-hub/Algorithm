#include<iostream>
using namespace std;
int findRotation(int arr[],int n){
    int low=0,high=n-1;
    while(low<=high){
         if(arr[low]<=arr[high]){         /*Calculating how many times a sorted array is rotated.*/
            return low;
        }
        int mid=(low+high)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(arr[mid]<=arr[next]&&arr[mid]<=arr[prev]){
            return mid;
        }
        else if(arr[mid]<=arr[high]){
            high=mid-1;
        }
        else if(arr[mid]>=arr[low]){
            low=mid+1;
        }
    }
    return -1;
    
}
int main(){
    int arr[]={12,34,6,8,9,};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=findRotation(arr,n);
    if(res==-1){
        cout<<"The array is rotated by 0 time."<<endl;
    }
    else{
        cout<<"The array is rotated by "<<res<<" times"<<endl;
    }
}