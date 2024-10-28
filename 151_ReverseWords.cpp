#include<bits/stdc++.h>
#define ll long long
using namespace std;
string reverseWords(string s) {
    string res;
    string tmp="";
    int check=0;
    // im ded, i failed at easier problem lol
    for(int i=0;i<=s.size();i++)
    {
        if(((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))&&i<s.size())
        {
            tmp+=s[i];
            check=1;
            //cout<<s[i];
        }
        else
        {
            //cout<<check<<" "<<tmp<<endl;
            if(check==1) 
            {
                if(res!="") res=tmp+" "+res;
                else res=tmp;
            }
            tmp="";
            check=0;
        }
    }
    
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s="the sky is blue";
    //getline(cin,s);
    reverseWords(s);


}

