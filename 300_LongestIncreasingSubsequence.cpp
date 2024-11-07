#include<bits/stdc++.h>
#define ll long long
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size(),res=0;
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>nums[i-1]) dp[i]=dp[i-1]+1;
        else {
            for(int j=0;j<i;j++)
            {
                //by finding the amount of numbers that are smaller than nums[i], we can find the number with the most lower numbers
                //before it up until the point of i
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1); 
            }
            res=max(res,dp[i]);
        }
    }  
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
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
    lengthOfLIS(a);


}

/*
10 9 2 5 3 7 101 18
*/