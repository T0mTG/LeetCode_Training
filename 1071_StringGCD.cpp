#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(string s, string t){
    string tmp="";
    int n=(s.size())/(t.size());
    for(int i=0;i<n;i++){
        tmp+=t;
    }
    cout<<s<<" "<<t<<"|"<<tmp<<endl;
    if(tmp==s) return 1;
    return 0;
}
string gcdOfStrings(string str1, string str2) {
    string res;
    string tmp="";
    int n=str1.size(), m=str2.size(), tmpa;
    for(int i=0;i<min(n,m);i++){
        //add to the divisor string
        tmp+=str1[i];
        tmpa=tmp.size();
        //check if the str1 or str2 can be divided by tmp or not by its size
        //for example, if str1 has a length of 5 and tmp has 2, it's obvious that str1 can't be divided by tmp;
        if(n%tmpa==0 && m%tmpa==0){
            //check if the string tmp can be multiplied into str1 or str2
            //if checked, save it to res
            if(check(str1,tmp) && check(str2,tmp)) res=tmp;
        }
    }
    cout<<res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    gcdOfStrings(s,t);

}

/* better solution I found on leetcode

string gcdOfStrings(string str1, string str2) {
    string res="";
    if(str1+str2 == str2+str1){
        res=str1.substr(0,__gcd(str1.size(),str2.size()));
    }
    cout<<res;
    return res;
}
*/