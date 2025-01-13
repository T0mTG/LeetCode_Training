#include<bits/stdc++.h>
#define ll long long
using namespace std;
int minimumLength(string s) {
    int res=s.size();
    int count[1000];
    memset(count,0,sizeof(count));
    for(int i=0;i<s.size();i++){
        count[s[i]]++;
        if(count[s[i]]>=3) {
            res-=2;
            count[s[i]]-=2;
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
    minimumLength(s);


}