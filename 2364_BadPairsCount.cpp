#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long countBadPairs(vector<int>& nums) {
    //the idea for this problem is instead of finding bad pairs, we find the good pairs first
    //then subtract them from the total pairs

    //good pair:
    //j-i==nums[j]-nums[i]
    //->  i-nums[i]==j-nums[j]
    unordered_map<int,int>a;
    long long res=0,n=nums.size(),tmp;
    for(int i=0;i<n;i++){
        tmp=i-nums[i];
        res+=a[tmp];
        a[tmp]++;
        //cout<<i<<" "<<nums[i]<<"||"<<tmp<<" "<<a[tmp]<<endl;
    }   
    cout<<n*(n-1)/2-res;
    return n*(n-1)/2-res;
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
    countBadPairs(a);
}