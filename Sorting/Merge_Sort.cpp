#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int r){
   int n1=m-l+1;
   int n2=r-m;
   int i=0,j=0;
   int L[n1],R[n2];
   for(int i=0;i<n1;++i){
       L[i]=arr[l+i];
   }
   for(int j=0;j<n2;++j){
       R[j]=arr[m+1+j];
   }
   int k=l;
   while(i<n1&&j<n2){
       if(L[i]<=R[j]){
         arr[k]=L[i];
         ++i;
       }
       else{
           arr[k]=R[j];
           j++;
       }
       ++k;
   }
   while(i<n1){
       arr[k]=L[i];
       i++;
       k++;
   }
   while(j<n2){
       arr[k]=R[j];
       j++;
       k++;
   }
}
void mergesort(int arr[],int l,int r){
   if(l>=r){
       return;
   }
   int m=l+(r-l)/2;
   mergesort(arr,l,m);
   mergesort(arr,m+1,r);
   merge(arr,l,m,r);
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
    cout<<"The entered array is:"<<endl;
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n-1);
    cout<<endl<<"The sorted array is."<<endl;
    print(arr,n);

}