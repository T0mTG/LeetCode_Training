#include<bits/stdc++.h>
#define ll long long
using namespace std;
string mergeAlternately(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    string res="";
    for(int i=0;i<max(n,m);i++)
    {
        if(i<n) res+=word1[i];
        if(i<m) res+=word2[i];
    }  
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,x;
    cin>>s>>x;
    mergeAlternately(s,x);
    return 0;
}