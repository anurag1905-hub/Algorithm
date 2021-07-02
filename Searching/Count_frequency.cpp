#include<iostream>
using namespace std;
int left(int arr[],int n,int x){
    int low=0,high=n-1,res=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            res=mid;
            high=mid-1;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int right(int arr[],int n,int x){
    int low=0,high=n-1,res=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            res=mid;
            low=mid+1;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int findCount(int arr[],int n,int x){
    int left_occurence=left(arr,n,x);
    int right_occurence=right(arr,n,x);
    if(left_occurence==-1||right_occurence==-1){
        return -1;
    }
    return right_occurence-left_occurence+1;
}
int main(){
    int arr[]={1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the element whose frequency you want to find:"<<endl;
    cin>>x;
    int result=findCount(arr,n,x);
    if(result==-1){
        cout<<x<<" doesn't exist in the array:"<<endl;
    }
    else{
    cout<<"The frequency of "<<x<<" is "<<result<<endl;
    }
}