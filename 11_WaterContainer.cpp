#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxArea(vector<int>& height) {
    int n=height.size();
    int l=0,r=n-1,res=0;
    while(l<r)
    {
        //find the maximum 
        res=max(res,min(height[l],height[r])*(r-l)); 
        //check if there's any higher column from left to right;
        if(height[l]<height[r]) l++;
        //check if there's any higher column from right to left;
        else r--;
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
    maxArea(a);
}


/*
    9
    1 8 6 2 5 4 8 3 7
*/