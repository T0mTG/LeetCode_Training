#include<bits/stdc++.h>
#define ll long long
using namespace std;
string inv(string s)
{
    string res=s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0') res[i]='1';
        else res[i]='0';
    }
    return res;
}
char findKthBit(int n, int k) {
    string s="0";
    // for now I can only think of doing the problem literally, keep building the string and pring out the k bit
    for(int i=2;i<=n;i++)
    {
        //cout<<"///"<<s.size()<<endl;
        string tmp=inv(s);
        reverse(tmp.begin(),tmp.end());
        s+='1'+tmp;
        cout<<s<<endl;
    }     
    cout<<s[k];
    return s[k-1];  
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    cin>>n>>x;
    findKthBit(n,x);


}