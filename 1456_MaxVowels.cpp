#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxVowels(string s, int k) {
    int d[1000];
    memset(d,0,sizeof(d));
    d['a']=1;
    d['e']=1;
    d['o']=1;
    d['u']=1;
    d['i']=1;
    int sum=0,res=0;
    if(k==1){
        for(int i=0;i<s.size();i++) {
            if(d[s[i]]) return 1;
        } 
    }
    for(int i=0;i<k;i++) 
    {
        if(d[s[i]]) sum++;
    }  
    res=sum;
    int l=0,r=k-1;
    while(r<s.size()){
        l++;
        r++;
        if(d[s[l-1]]) sum--;
        if(d[s[r]]) sum++;
        res=max(res,sum);
    } 
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    string s;
    cin>>s;
    cin>>n;
    maxVowels(s,n);

}