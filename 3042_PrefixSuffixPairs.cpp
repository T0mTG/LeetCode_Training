#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isPrefixAndSuffix(string s, string t){
    if(s.size()>t.size()) return 0;
    int n=t.size()-s.size();
    if(t.find(s,0)==0&&t.find(s,n)==n) return 1;
    return 0;
}
int countPrefixSuffixPairs(vector<string>& words) {
    int res=0;
    int n=words.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==j) continue;
            if(isPrefixAndSuffix(words[i],words[j])) res++;
        }
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
    string x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    countPrefixSuffixPairs(a);


}