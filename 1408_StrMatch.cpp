#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(string a,string b){
    return a.size()<b.size();
}
vector<string> stringMatching(vector<string>& words) {
    vector<string>res;
    //sort(words.begin(),words.end(),comp);
    int n=words.size();
    string tmpi,tmpj;
    for(int i=0;i<n;i++){
        tmpi=words[i];
        for(int j=0;j<n;j++){
            if(i==j) continue;
            tmpj=words[j];
            if(tmpj.find(tmpi)!=string::npos){
                res.push_back(tmpi);
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string>a;
    int n;
    string x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    stringMatching(a);


}