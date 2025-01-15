#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool checkValidString(string s) {
    stack<int>l;
    stack<int>q;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            //store the "("
            l.push(i);
        }
        else if(s[i]==')'){
            //if the stack l is not empty, there is an "(" that can be used
            //therefore, pop the "(" (or complete the parenthese)
            if(!l.empty()) l.pop();
            //else, check for the "*" available to complete the parenthese
            else if(!q.empty()) q.pop();
            //otherwise, this string is invalid (for example: " )() "  )
            else return 0;
        }
        //store indices of * for use later on
        else q.push(i);
    }
    //check for the remaining "(" and complete them using "*"
    //the "(" can only complete if there is "*" with index larger than theirs
    while(!l.empty() && !q.empty() && q.top()>l.top()){
        l.pop();
        q.pop();
    }
    //if there's nothing left, the string is valid
    if(l.empty()) {
        cout<<"ya";
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    checkValidString(s);


}