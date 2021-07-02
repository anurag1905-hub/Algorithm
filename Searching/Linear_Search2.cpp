#include<iostream>
using namespace std;
void search(int arr[],int n,int x){
    int left=0;
    int flag=0;
    int right=n-1;
    for(left=0;left<=right;++left){
        if(arr[left]==x){
            cout<<"Element found in array at index "<<left<<" with "<<left+1<<" attempt:"<<endl;
            flag=1;
            break;
        }
        if(arr[right]==x){
            cout<<"Element found in array at index "<<right<<" with "<<n-right<<" attempt:"<<endl;
            flag=1;
            break;
        }
        --right;
    }
    if(flag==0){
      cout<<"Element not found in array with "<<left<<" attempt:"<<endl;
    }
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
    search(arr,n,x);
}