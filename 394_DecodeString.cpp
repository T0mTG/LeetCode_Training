#include<bits/stdc++.h>
#define ll long long
using namespace std;
string mul(string s,int n){
    string tmp="";
    for(int i=0;i<n;i++){
        tmp+=s;
    }
    return tmp;
}
string decodeString(string s) {
    stack<int>num;
    stack<string>str;
    string res="";
    string tmp="",tmpa="";
    int c=0,tn=0;
    for(int i=0;i<s.size();i++){
        //if a number is detected,
        if(s[i]>='0'&&s[i]<='9'){
            tn=0;
            //we will iterate to get the full number (like 20,100,...)
            while(s[i]>='0'&&s[i]<='9'){
                tn=tn*10+s[i]-'0';
                i++;
            }
            //c (or count) is to indicate that if there is a [] in used
            c++;
            num.push(tn);

            //we will save whatever is in tmp right now and work on it later
            str.push(tmp);
            tmp="";
            continue;
        }
        if(s[i]==']'){
            //the count of [] decreased
            c--;
            //multiply the tmp by the number that we stored
            tmpa=mul(tmp,num.top());
            num.pop();
            //if the [] is not nested (or there isn't any left), append it to the result directly
            if(c==0){
                res+=tmpa;
            }
            else{
                //else, we append it to whatever we were working with before the []
                tmp=str.top()+tmpa;
                str.pop();
            }
            continue;   
        }
        if(c==0){
            //if there is no [], append it to the result directly
            res+=s[i];
        }
        else {
            tmp+=s[i];
        }
    }
    //cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    decodeString(s);


}