#include<bits/stdc++.h>
#define ll long long
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int res=0, l=0, r=0, count=0, tmp=0;
    //special case: k=0 or no zero can be flipped -> find the longest consecutives ones
    if(k==0){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                tmp++;
                res=max(res,tmp);
            }
            else tmp=0;
        }
        return res;
    }
    
    tmp=nums[0];
    if(nums[0]==0) count=1;
    //initialize res for the case of nums[0];
    res=count+tmp;

    while(l<=r&&r<nums.size()){
        //cout<<l<<" "<<r<<" "<<tmp<<" "<<count<<endl;
        
        //if the count of zeros is still smaller than k, expand the range by r+1 to check the next number
        if(count<=k){
            r++;
            if(r==nums.size()) break;
            tmp+=nums[r];
            if(nums[r]==0) count++;
        }
        //if the amount of zeros exceeds k, shrink the range by l+1 until the count of zeros is <= k
        else{
            l++;
            tmp-=nums[l-1];
            if(nums[l-1]==0) count--;
        }
        if(count<=k){
            //cout<<l<<" "<<r<<":"<<tmp<<endl;
            //if the range is legit, compare it and put it to res;  
            res=max(res,tmp+count);
        }
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
    longestOnes(a,k);


}

/*
10 2
1 1 1 0 0 0 1 1 1 1 0

4 1
0 0 1 1
*/