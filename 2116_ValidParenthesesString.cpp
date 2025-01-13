#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool canBeValid(string s, string locked) {
    //if the string length is odd, it can never be completed
    if(s.size()%2!=0) return 0;
    
    //stack of free parentheses
    stack<int>l;
    //stack of locked parentheses
    stack<int>lo;

    for(int i=0;i<s.size();i++){
        //store all the indices of the free parentheses
        if(locked[i]=='0'){
            l.push(i);
        }
        else{
            //store all the indices of the locked '('
            if(s[i]=='(') lo.push(i);

            if(s[i]==')'){
                //check for the locked '(' first, if there is one available, use it
                if(!lo.empty()) lo.pop();
                //otherwise, check for free ones
                else if(!l.empty()) l.pop();
                //if there is none, the string is not valid -> false
                else return 0;
            }
        }
    }

    //check for all the locked '(' and see if it can be closed with the free ones
    while(!lo.empty() && !l.empty() && l.top()>lo.top()){
        lo.pop();
        l.pop();
    }
    if(lo.empty()) return 1;
    return 0;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,k;
    cin>>s>>k;
    canBeValid(s,k);

}


/*
))()))
010100


())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(
100011110110011011010111100111011101111110000101001101001111

*/