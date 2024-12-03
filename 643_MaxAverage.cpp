#include<bits/stdc++.h>
#define ll long long
using namespace std;
double findMaxAverage(vector<int>& nums, int k) {
    double sum=0,res=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }   
    res=sum/double(k);
    for(int i=1;i<=nums.size()-k;i++)
    {
        sum-=nums[i-1];
        sum+=nums[i+k-1];
        res=max(res,sum/double(k));
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
    findMaxAverage(a,k);


}