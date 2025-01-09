#include<bits/stdc++.h>
#define ll long long
using namespace std;
string removeStars(string s) {
    stack<char>a;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*'){
            a.pop();
        }
        else a.push(s[i]);
    }
    string res="";
    while(!a.empty()){
        res+=a.top();
        a.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    removeStars(s);



}