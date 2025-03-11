#include<bits/stdc++.h>
#define ll long long
using namespace std;
string reverseVowels(string s) {
    int l=0,r=s.size()-1;
    string check="aeiouAEIOU";
    while(l<r){
        if(!isalpha(s[l])||check.find(s[l])==-1) l++; 
        else if(!isalpha(s[r])||check.find(s[r])==-1) r--;
        else{
            swap(s[l],s[r]);
            l++;
            r--;
        } 
    }
    cout<<s;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);
    reverseVowels(s);



}