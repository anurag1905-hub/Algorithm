#include<iostream>
using namespace std;
int linearsearch(int arr[],int n,int x){
    for(int i=0;i<n;++i){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array:"<<endl;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the element you want to search in the array:"<<endl;
    cin>>x;
    int res=linearsearch(arr,n,x);
    (res==-1)?cout<<"Element not found! ":cout<<"Element is present at index "<<res;
    return 0;

}