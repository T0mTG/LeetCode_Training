#include<bits/stdc++.h>
#define ll long long
using namespace std;
int countPairs(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int l=0,r=n-1,res=0;
    while(l<r)
    {
        //cout<<l<<": "<<nums[l]<<" || "<<r<<": "<<nums[r]<<endl;
        if(nums[l]+ nums[r]< target){ 
            //if the sum between the two ends is smaller than the target, than for every number between l and r
            //combines with nums[l] will also be smaller target, this is true because we sorted the array
            res+=r-l;
            //increase l to check the next number
            l++;
            //r=n-1;
        }
        // if the sum of nums[l] and nums[r] is bigger than the target, we will reduce r, which will results in nums
        // with lower values (as the array is sorted)
        else r--;
    }
    cout<<res;
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
    countPairs(a,k);

}

/*
5 2
-1 1 2 3 1

7 -2
-6 2 5 -2 -7 -1 3

*/
