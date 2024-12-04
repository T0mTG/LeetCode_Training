#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool canMakeSubsequence(string str1, string str2) {
    int i=0,l=0,res;
    while(i<str2.size()&&l<str1.size()){
        cout<<i<<" "<<l<<endl;
        //if a character from str2 can be achieved from str1, advance i (index for str2) for further checking 
        if(str2[i]=='a'){
            if(str1[l]=='z'||str1[l]=='a'){
                //cout<<str1[l]<<" "<<str2[i]<<endl;
                i++;
            }
        }
        else if(str1[l]==str2[i]|| str1[l]+1==str2[i]){
            //cout<<str1[l]<<" "<<str2[i]<<endl;
            i++;
        }
        //advancing the str1
        l++;
    }
    //if i can reach the end of the str2, it means that the it is possible to make str2 a subsequence of str1
    if(i==str2.size()) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    string s,t;
    cin>>s>>t;
    canMakeSubsequence(s,t);



}