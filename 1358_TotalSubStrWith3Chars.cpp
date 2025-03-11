#include<bits/stdc++.h>
#define ll long long
using namespace std;
int numberOfSubstrings(string s) {
    map<char,int>d;
    int res=0;
    d['a']=0;
    d['b']=0;
    d['c']=0;
    int l=0,r=0;
    d[s[0]]++;
    while(r<s.size()&&l<=r){
        if(!(d['a']&&d['b']&&d['c'])){
            r++;
            d[s[r]]++;
        }
        else{
            cout<<l<<" "<<r<<endl   ;
            res+=s.size()-r;
            d[s[l]]--;
            l++;
        }
    }
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    numberOfSubstrings(s);


}