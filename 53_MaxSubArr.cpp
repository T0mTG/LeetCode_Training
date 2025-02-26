#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxSubArray(vector<int>& nums) {
    int dp[100000];
    int n=nums.size(),res;
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        //compare if it's better to add nums[i] to the sum/number before it (dp[i-1]) or the nums[i] alone is better 
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        res=max(res,dp[i]);
    }
    //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    return res;
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
    maxSubArray(a);


}   



/*
9
-2 1 -3 4 -1 2 1 -5 4
*/