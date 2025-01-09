#include<bits/stdc++.h>
#define ll long long
using namespace std;
int prefixCount(vector<string>& words, string pref) {
    int res=0;
    for(int i=0;i<words.size();i++){
        if(words[i].find(pref)==0) res++;
    }
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string>a;
    int n;
    string x,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    prefixCount(a,k);


}