#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxProfit(vector<int>& prices) {
    int res=0;
    int l=0,r=1;
    while(r<prices.size()&&l<prices.size()){
        res=max(res,prices[r]-prices[l]);
        if(prices[l]>prices[r]){
            l=r;
            r+=1;
        }
        else r++;
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
    maxProfit(a);


}