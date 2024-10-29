#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n=candies.size(),k=extraCandies,ma=0;
    vector<bool>res;
    for(auto i:candies) ma=max(ma,i);
    for(auto i:candies)
    {
        if(i+k>=ma) res.push_back(1);
        else res.push_back(0);
    }
    for(auto i:res) cout<<i<<" ";
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
    kidsWithCandies(a,k);

}