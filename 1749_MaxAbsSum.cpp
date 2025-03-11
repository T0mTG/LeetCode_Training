#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxAbsoluteSum(vector<int>& nums) {
    int n=nums.size();
    //these are for finding the biggest number
    int dp[100000];
    dp[0]=nums[0];
    int resa=nums[0];

    //these are for finding the lowest number
    int dpneg[100000];
    dpneg[0]=nums[0];
    int resb=nums[0];

    for(int i=1;i<n;i++){
        //see problem 53 Max Subarray Sum
        //compare if it's better to add nums[i] to the sum/number before it (dp[i-1]) or the nums[i] alone is better 
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        resa=max(resa,dp[i]);
        
        //it's the same idea as above, except we are finding for the lowest number by using min
        //compare if it's better to add nums[i] to the sum/number before it (dpneg[i-1]) or the nums[i] alone is better 
        dpneg[i]=min(dpneg[i-1]+nums[i],nums[i]);
        resb=min(resb,dpneg[i]);
    }
    //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    //cout<<max(resa,abs(resb));
    return max(resa,abs(resb));
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
    maxAbsoluteSum(a);


}