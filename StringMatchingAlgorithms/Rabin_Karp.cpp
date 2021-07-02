#include<bits/stdc++.h>
using namespace std;
#define d 256 /*Number of  possible characters in input alphabet*/
void search(string pat,string text,int q){
    int M=pat.length();
    int N=text.length();
    int i,j;
    int p=0; /*Hash value for pattern*/
    int t=0; /*Hash value for text*/
    int h=1;
    for(i=1;i<=M-1;++i){
        h=(h*d)%q;
    }
    for(i=0;i<M;++i){
        p=(d*p+pat[i])%q;
        t=(d*t+text[i])%q;
    }
    for(i=0;i<=N-M;++i){
        if(p==t){
            for(j=0;j<M;++j){
                if(text[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==M){
                cout<<"Pattern found at index "<<i<<endl;
            }
        }
        
        if(i<N-M){
            t=(d*(t-text[i]*h)+text[i+M])%q;
            if(t<0){
                t=t+q;
            }
        }
    }
}
int main(){
    string text="GEEKS FOR GEEKS";
    string pat="GEEK";
    int q=101; /*A prime number*/
    search(pat,text,q);
}