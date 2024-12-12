#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int,vector<int>>q;
    for(auto i:gifts){
        q.push(i);
    }
    int tmp=0,sum=0;
    while(k--){
        tmp=q.top();
        q.pop();
        tmp=sqrt(tmp);
        q.push(tmp);
    }
    while(!q.empty()){
        sum+=q.top();
        q.pop();
    }
    cout<<sum;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    pickGifts(a,k);


}