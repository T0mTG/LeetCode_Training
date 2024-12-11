#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rob(vector<int>& nums) {
    int n=nums.size();
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    for(int i=2;i<n;i++)
    {
        //for every house from the third house, see if stealing the house plus all the goods from the house 2 indexs (dp[i-2]) aways
        //is better than stealing the house next to it (dp[i-1]);
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
    }        
    cout<<dp[n-1];
    return dp[n-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    rob(a);


}