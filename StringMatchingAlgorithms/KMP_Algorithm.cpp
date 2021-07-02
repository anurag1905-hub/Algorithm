#include<iostream>
using namespace std;
void computeLPSArray(string pat,int M,int lps[]){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMPSearch(string txt,string pat){
    int M=pat.length();
    int N=txt.length();
    int lps[M];
    computeLPSArray(pat,M,lps);
    int i=0,j=0;
    while(i<N){
        if(pat[j]==txt[i]){
            ++i;
            ++j;
        }
        if(j==M){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<N&&pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }
}
int main(){
    string txt="ABABDABACDABABCABAB";
    string pat="ABABCABAB";
    KMPSearch(txt,pat);
}