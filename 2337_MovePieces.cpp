#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool canChange(string start, string target) {
    queue<pair<char,int>>s,t;
    //get the letter and its position
    for(int i=0;i<start.size();i++){
        if(start[i]!='_') s.push({start[i],i});
    }
    for(int i=0;i<target.size();i++){
        if(target[i]!='_') t.push({target[i],i});
    }
    pair<char,int>i,j;
    while(!s.empty()){
        i=s.front();
        s.pop();
        j=t.front();
        t.pop();
        //since all letters can not pass each other, it means that if there's a different in order between 
        //the two string, the string target cannot be obtained
        if(i.first!=j.first) return 0;
        else{
            //if the letter is L, its position in the start string can't be lefter than its counterpart in the target string
            if(i.first=='L'){
                if(i.second<j.second) return 0;
            }

            //the same goes for R, its position in the start string can't be righter than its counterpart in the target string
            if(i.first=='R'){
                if(i.second>j.second) return 0;
            }
        }
    }
    return 1; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    string s,t;
    cin>>s>>t;
    cout<<canChange(s,t);


}