#include<bits/stdc++.h>
#define ll long long
using namespace std;
int jump(vector<int>& nums) {
        long long n,res=1, cur=0,furthest=0,sav=0;
        n = nums.size();
        // the whole concept is we find out the best jump possible that can be made in the allowed range of jumping -> shortest
        if (n == 1)
            return 0;
        furthest=nums[0]; // we have to start at 0 so might as well let the furthest reach is nums[0]
        sav=furthest; //sav is the furthest possible destination allowed (because we can access any place in between) at the time
        for(int i=1;i<n;i++)
        {
            if(sav>=n-1) break; //if the location we are standing is at or further than the end, we stop
            if(i<=sav) //accessing locations that are valid 
            {
                if(furthest<i+nums[i]) furthest=nums[i]+i; //if the position we are on giving better jumps, we save it to furthest
                if(i==sav)// if we are at the furthest possible destination, we will jump to the furthest position we got
                {
                    res++; 
                    sav=furthest;
                }
            }
        }
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
    cout<<jump(a);
}

//15  7 0 9 6 9 6 1 7 9 0 1 2 9 0 3
// DP approach
void dpa(vector<int>nums){
    int n=nums.size();
    int dp[n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++) //for every index smaller than i 
        {
            if(nums[j]>=i-j)//check if the number of jumps made from j can be further than the distance between i and j
            {
                //if the destination hasn't been reached, it will be the jumps made to j plus one (the jump from j to the destination)
                if(!dp[i]) dp[i]=dp[j]+1; 
                //else compare if this route of jumping is more efficient than the previouse route
                else dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    //by calculating the minimum jump needed to reach any destination, we can get the minimum jump needed to reach the end
    cout<<dp[n];
}