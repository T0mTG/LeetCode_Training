#include<bits/stdc++.h>
#define ll long long
using namespace std;
string compressedString(string word) {
    string res="";
    int n=word.size(),count=0;
    string tmpa;
    char tmp;
    for(int i=0;i<n;i++)
    {
        tmp=word[i];
        count=0;
        while(i<n)
        {
            if(word[i]==tmp)
            {
                i++;
                count++;
            }
            else break;
        }
        i--;
        if(count>9)
        {
            while(count>9)
            {
                res+='9';
                res+=tmp;
                count-=9;
            }
        }
        res+=to_string(count);
        res+=tmp;
        //cout<<i;
    }   
    cout<<res; 
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    string s;
    cin>>s;
    compressedString(s);



}