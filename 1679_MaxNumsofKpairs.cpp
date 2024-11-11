#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxOperations(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int l=0,r=n-1,res=0,tmp;
    while(l<r)
    {
        tmp=nums[l]+nums[r];
        if(tmp==k)
        {
            res++;
            l++;
            r--;
        }
        else if(tmp<k) l++;
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
    maxOperations(a,k);
}