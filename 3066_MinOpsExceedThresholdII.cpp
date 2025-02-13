#include<bits/stdc++.h>
#define ll long long
using namespace std;
int minOperations(vector<int>& nums, int k) {
    //use priority queue in decreasing order so you can get the two smallest number quickly
    priority_queue<long long,vector<long long>, greater<long long>>q(nums.begin(),nums.end());
    long long res=0,tmpa,tmpb;
    while(!q.empty()&&q.size()>=2&&q.top()<k){
        tmpa=q.top();
        q.pop();
        tmpb=q.top();
        q.pop();
        tmpa=min(tmpa,tmpb)*2+max(tmpa,tmpb);
        q.push(tmpa);
        res++;
    }
    //cout<<res;
    return res;
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
    minOperations(a,k);


}