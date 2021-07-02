#include<iostream>
using namespace std;
void search(string text,string pattern){
    int N=text.length();
    int M=pattern.length();
    for(int i=0;i<=N-M;++i){
        int j;
        for(j=0;j<M;++j){
            if(text[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==M){
           cout<<"Pattern found at index "<<i<<endl; 
        }
    }
}
int main(){
    string text="AABAACAADAABAAABAA";
    string pattern="AABA";
    search(text,pattern);
    return 0;
}