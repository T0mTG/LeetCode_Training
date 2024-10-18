#include<bits/stdc++.h>
#define ll long long
using namespace std;
int res=0;
void gen(int i,int maxi,int tmp,vector<int>& nums)
{
    if(tmp==maxi) res++;   
    if(i==nums.size()) return;
    for(i=i+1;i<nums.size();i++)
    {
        // more backtracking with more nums added to the subsets
        gen(i,maxi,tmp|nums[i],nums);
    }
    return;
}
int countMaxOrSubsets(vector<int>& nums) {
    int maxi=nums[0],n=nums.size();
    for(int i=1;i<n;i++)
    {
        // the maximum bitwise-OR subsets is the bitwise-OR of the whole array 
        maxi=maxi|nums[i];
        //cout<<nums[i]<<" "<<maxi<<endl;
    }    
    //cout<<maxi<<endl;
    for(int i=0;i<n;i++)
    {
        // backtracking by starting with each individual element of the array
        gen(i,maxi,nums[i],nums);
    }
    //cout<<res<<endl;   
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
    cout<<countMaxOrSubsets(a);
}