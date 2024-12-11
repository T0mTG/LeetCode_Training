#include<bits/stdc++.h>
#define ll long long
using namespace std;
int longestSubarray(vector<int>& nums) {
    //my advice is to try on problem 1004 first
    int n=nums.size();
    int l=0,r=0,count=0,res=0,tmp=0;

    if(n==1) return 0;

    tmp=nums[0];
    if(nums[0]==0) count=1;
    
    while(l<=r&&r<nums.size()){
        //cout<<l<<" "<<r<<" "<<tmp<<" "<<count<<endl;
        
        //if the count of zeros is still smaller than 1, expand the range by r+1 to check the next number
        if(count<=1){
            r++;
            if(r==nums.size()) break;
            tmp+=nums[r];
            if(nums[r]==0) count++;
        }
        //else, shrink the range
        else{
            l++;
            tmp-=nums[l-1];
            if(nums[l-1]==0) count--;
        }
        if(count<=1){
            //cout<<l<<" "<<r<<":"<<tmp<<endl;
            //count is added to compensate for that one element needed to be deleted later on
            res=max(res,tmp+count);
        }
    }   
    //we have to delete one element because the problem said so :v
    cout<<res-1;
    return res-1; 
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
    longestSubarray(a);
}


/*
8
0 1 1 1 0 1 1 0 1
*/