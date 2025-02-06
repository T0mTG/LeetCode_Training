#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxAscendingSum(vector<int>& nums) {
    int res=nums[0],tmp=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1]){
            tmp+=nums[i];
        }
        else tmp=nums[i];
        res=max(res,tmp);
    }    
    cout<<res;
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
    maxAscendingSum(a);


}