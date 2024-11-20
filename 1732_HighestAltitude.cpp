#include<bits/stdc++.h>
#define ll long long
using namespace std;
int largestAltitude(vector<int>& gain) {
    int res=0;
    int sum=0;
    for(int i=0;i<gain.size();i++){
        sum+=gain[i];
        res=max(res,sum);
    }
    cout<<res<<endl;
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
    largestAltitude(a);
    
}