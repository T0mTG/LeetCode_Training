#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isSubsequence(string s, string t) {
    int n=s.size();
    int m=t.size();
    if(s=="") return 1;
    //cout<<n<<endl<<m<<endl;
    int l=0,la=0;
    for(int i=0;i<m;i++)
    {
        if(s[l]==t[i]){
            l++;
            if(n==1){
                cout<<"yay";
                return 1;
            }
        }
        cout<<l<<endl;
        if(l==n){
            cout<<"yay";
            return 1;
        }
    }
    cout<<"nah"; 
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    isSubsequence(s,t);
}