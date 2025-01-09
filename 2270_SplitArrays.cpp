#include<bits/stdc++.h>
#define ll long long
using namespace std;
int waysToSplitArray(vector<int>& nums) {
    int res=0,n=nums.size();
    int d[nums.size()+1];
    d[0]=nums[0];
    for(int i=1;i<n;i++){
        d[i]=d[i-1]+nums[i];
    }
    for(int i=0;i<n-1;i++){
        if(d[i]>=d[n-1]-d[i]){
            res++;
            cout<<i<<endl;
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
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    waysToSplitArray(a);

}