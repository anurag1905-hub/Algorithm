#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void BucketSort(float arr[],int n){
    vector<float>v[n];
    for(int i=0;i<n;++i){
        int bi=n*arr[i];
        v[bi].push_back(arr[i]);
    }
    for(int i=0;i<n;++i){
        sort(v[i].begin(),v[i].end());
    }
    int index=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<v[i].size();++j){
            arr[index++]=v[i][j];
        }
    }
}
void display(float arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    float arr[n];
    cout<<"Enter elements of the array:"<<endl;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<"The entered array is:"<<endl;
    display(arr,n);
    BucketSort(arr,n);
    cout<<"The sorted array is:"<<endl;
    display(arr,n);
}