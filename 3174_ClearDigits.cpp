#include<bits/stdc++.h>
#define ll long long
using namespace std;
string clearDigits(string s) {
    string res;
    stack<char>q;
    //since the problem is to delete the number from the left, we can use stack to keep track of the
    //most recently (left-sided) character
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            //if a number was to existed, delete the most-recent-added character in the stack
            if(!q.empty()) q.pop();
        }
        else q.push(s[i]);
    }    
    //build the result string
    while(!q.empty()){
        res+=q.top();
        q.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;

}