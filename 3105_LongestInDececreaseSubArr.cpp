#include<bits/stdc++.h>
#define ll long long
using namespace std;
int longestMonotonicSubarray(vector<int>& nums) {
    int res=1,inc=0,dec=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            if(inc==0) inc=1;
            inc++;
            dec=0;
        }
        else if(nums[i-1]<nums[i]){
            if(dec==0) dec=1;
            dec++;
            inc=0;
        }
        else{
            inc=1;
            dec=1;
        }
        res=max(res,max(inc,dec));
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
    longestMonotonicSubarray(a);


}