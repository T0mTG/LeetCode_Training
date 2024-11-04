#include<bits/stdc++.h>
#define ll long long
using namespace std;
int compress(vector<char>& chars) {
    int n=chars.size();
    int count=0,j=0;
    if(n==1) return chars.size();
    string tmpa;
    vector<char>res;
    for(int i=0;i<n;i++)
    {
        char tmp=chars[i];
        count=0;
        while(i<n){
            
            if(tmp==chars[i]) {
                count++;
                i++;
            }
            else break;
            //cout<<i<<endl;
        }
        i--;
        res.push_back(tmp);
        if(count>1)
        {
            tmpa=to_string(count);
            for(auto j:tmpa) res.push_back(j);
        }
    }
    chars.clear();
    for(auto i:res){
        chars.push_back(i);
    }
    return chars.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<char>a;
    int n;
    char x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int g=compress(a);
    cout<<endl<<g;

}


/*
int compress(vector<char>& chars) {
    int n=chars.size();
    if(n==1) return chars.size();
    string res="";
    char tmp=chars[0];
    int count=1;
    for(int i=1;i<n;i++)
    {
        if(chars[i]==tmp) count++;
        else
        {
            if(count==1)
            {
                res+=tmp;
                tmp=chars[i];
            }
            else if(count>1)
            {
                res+=tmp;
                res+=to_string(count);
                count=1;
                tmp=chars[i];
            }
            if(i==n-1) break;
        }
        if(i==n-1){
            if(count==1)
            {
                res+=tmp;
                tmp=chars[i];
            }
            else if(count>1)
            {
                res+=tmp;
                res+=to_string(count);
                count=1;
                tmp=chars[i];
            }
        }
        
    }        
    chars.clear();
    for(int i=0;i<res.size();i++) chars.push_back(res[i]);
    for(auto i:chars) cout<<i<<" ";
    cout<<endl<<res.size();
    return res.size();
}
*/