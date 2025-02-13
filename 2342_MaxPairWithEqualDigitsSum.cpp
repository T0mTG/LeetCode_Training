#include<bits/stdc++.h>
#define ll long long
using namespace std;
int proc(int n){
    int tmp=0;
    while(n>0){
        tmp+=n%10;
        n/=10;
    }
    return tmp;
}
int maximumSum(vector<int>& nums) {
    int d[100000];
    int res=-1,tmp;
    memset(d,0,sizeof(d));
    for(int i=0;i<nums.size();i++){
        tmp=proc(nums[i]);
        //cout<<nums[i]<<"|"<<tmp<<endl;
        if(d[tmp]!=0){
            res=max(res,nums[i]+d[tmp]);
        }
        d[tmp]=max(d[tmp],nums[i]);
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
    maximumSum(a);
    



}   