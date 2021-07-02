#include<iostream>
using namespace std;
int find_first_occurence(int arr[],int n,int x){
   int low=0;
   int high=n-1;
   int res=-1;
   while(low<=high){
       int mid=low+(high-low)/2;
       if(x==arr[mid]){
           res=mid;
           low=mid+1;
       }
       else if(x<arr[mid]){
           high=mid-1;
       }
       else{
           low=mid+1;
       }
   }
   return res;
}
int main(){
         int arr[20]={1,1,1,1,2,3,3,3,5,6,6,8,8,8,9,9,9,23,34,56};
         cout<<"Enter the number whose last occurence you want to find:"<<endl;
         int x;
         int n=sizeof(arr)/sizeof(arr[0]);
         cin>>x;
         int result=find_first_occurence(arr,n,x);
         if(result==-1){
             cout<<x<<" is not present in the array."<<endl;
         }
         else{
             cout<<"last occurence of "<<x<<" in the array is at index "<<result<<endl;
         }

}