#include<bits/stdc++.h>
using namespace std;
long long proc(vector<int>& nums,long long l, long long target){
    long long n=nums.size();
    long long r=n-1,res=0;
    //see problem #2824 if ur stuck
    while(l<r)
    {
        //cout<<l<<": "<<nums[l]<<" || "<<r<<": "<<nums[r]<<endl;
        if(nums[l]+ nums[r]<target){ 
            //if the sum between the two ends is smaller than the target, than for every number between l and r
            //combines with nums[l] will also be smaller target, this is true because we sorted the array
            res+=r-l;
            //increase l to check the next number
            l++; 
        }
        else r--;
    }
    return res;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    cout<<"///"<<endl;
    long long n=nums.size();
    sort(nums.begin(), nums.end());
    // for(auto i:nums) cout<<i<<" ";
    // cout<<endl;

    // proc is basically a two-pointer function that finds the number of pairs that have the sum < target
    
    // so we find the number of pairs <= upper (or < upper+1), including pairs that have sum smaller than lower
    
    // then, we find the amount of pairs < lower to eliminate
    // hence res= proc(...,upper+1) - proc(...,lower+1)
    
    long long res=proc(nums,0,upper+1)-proc(nums,0,lower);

    //visualization
    //                                                  lower           upper
    //Sums of pairs:                           ///////////////////////////////////////
    //Number of pairs from proc(..., upper+1): ////////////////////////////////|
    //Number of pairs from proc(..., lower+1): ///////////////|
    //Res:                                               |////////////////|
    
    //cout<<proc(nums,0,upper+1)<<" || "<<proc(nums,0,lower)<<endl;
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x,l,u;
    cin>>n>>l>>u;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    countFairPairs(a,l,u);
}

/*
6 3 6
0 1 7 4 4 5

5 11 11
1 7 9 2 5
*/