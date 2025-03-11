#include<bits/stdc++.h>
#define ll long long
using namespace std;
int numberOfSubstrings(string s) {
    //the idea for this problem is to check for substring with at least 1 occurence of a,b,c and then add the rest of the
    //chars behind it to get the sum
    //for example: if you can find abc...(the rest of the string), then whether it's abca,abccc,abcbcbcbc,... it would be eligible 
    map<char,int>d;
    int res=0;
    d['a']=0;
    d['b']=0;
    d['c']=0;
    int l=0,r=0;
    d[s[0]]++;
    while(r<s.size()&&l<=r){
        if(!(d['a']&&d['b']&&d['c'])){
            //if there's not enough a,b,c, extend r to fill in
            r++;
            d[s[r]]++;
        }
        else{
            //if there's enough a,b,c, add the number of remaining chars to res
            //for example:if you can find something acb, then acba,acbad,... are also eligible
            //cout<<l<<" "<<r<<endl   ;
            res+=s.size()-r;
            d[s[l]]--;
            l++;
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
    numberOfSubstrings(s);


}