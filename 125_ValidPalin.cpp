#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isPalindrome(string s) {
    string tmp="";
    for(auto i:s){
        if(isalpha(i)||isdigit(i)) tmp+=tolower(i);
    }  
    cout<<tmp<<endl;
    int l=0,r=tmp.size()-1;
    while(l<r){
        if(tmp[l]==tmp[r]) {
            l++;
            r--;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    string s;
    getline(cin,s);
    isPalindrome(s);
}