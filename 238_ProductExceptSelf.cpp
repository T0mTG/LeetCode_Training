#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int prod=1;
    int check=0;
    vector<int>res;
    //if there is two or more zeros, the product would just be zero lol
    for(auto i:nums)
    {
        if(i==0)
        {
            check++;
            if(check>=2) {
                for(int j=0;j<nums.size();j++) res.push_back(0);
                cout<<"ded"<<endl;
                return res;
            }
            else continue;
        }
        prod*=i;
    }
    cout<<"//"<<prod<<endl;
    for(auto i:nums)
    {
        if(check==1)
        {
            if(i==0) res.push_back(prod);
            else res.push_back(0);
        }
        else res.push_back(prod/i);
    }
    for(auto i:res) cout<<i<<" "<<endl;
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
    productExceptSelf(a);
}