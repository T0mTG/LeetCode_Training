#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maximumCount(vector<int>& nums) {
    int resa=0,resb=0;
    for(auto i:nums){
        if(i<0) resa++;
        else if(i>0) resb++;
    }
    //cout<<max(resa,resb);
    return max(resa,resb);
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
    maximumCount(a);


}