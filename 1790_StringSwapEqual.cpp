#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool areAlmostEqual(string s1, string s2) {
    if(s1.size()!=s2.size()) return 0;
    if(s1==s2) return 1;
    int count[10000];
    memset(count,0,sizeof(count));
    int diff=0,difb=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]) diff++;
        count[s1[i]]++;
        count[s2[i]]--;
        if(diff>2) return 0;
    }  
    for(auto i:s1){
        if(count[i]!=0) return 0;
    }
    cout<<'ya';
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,c;
    cin>>s>>c;
    areAlmostEqual(s,c);
}