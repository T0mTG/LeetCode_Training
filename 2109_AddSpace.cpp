#include<bits/stdc++.h>
#define ll long long
using namespace std;
string addSpaces(string s, vector<int>& spaces) {
    string res;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(j<spaces.size()){
            if(i==spaces[j]){
                res+=' ';
                j++;
            }
        }
        res+=s[i];
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
    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    addSpaces(s,a);



}