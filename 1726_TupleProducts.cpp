#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tupleSameProduct(vector<int>& nums) {
    unordered_map<long long, long long>d;
    set<int>a;
    long long res=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            d[nums[i]*nums[j]]++;
            if(d[nums[i]*nums[j]]>1) a.insert(nums[i]*nums[j]);
        }
    }    
    for(auto i:a){
        res+=(d[i]*(d[i]-1)/2);
    }
    cout<<res*8;
    return res*8;    
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
    tupleSameProduct(a);


}