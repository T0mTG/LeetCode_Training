#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target){
    int l=0,r=numbers.size(),sum;
    while(l<r){
        sum=numbers[l]+numbers[r];
        if(sum==target) return {l+1,r+1};
        if(sum>target) r--;
        else l++;
    }
    return {};
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
    twoSum(a,k);


}