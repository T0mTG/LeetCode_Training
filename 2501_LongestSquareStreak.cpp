#include<bits/stdc++.h>
#define ll long long
using namespace std;
int longestSquareStreak(vector<int>& nums) {
    int n=nums.size(),res=0,tmp,j;
    // the idea for this problem is pretty straight forward, we power the number if it's in the array and in the number limit
    set<int>check{nums.begin(),nums.end()}; //to check if a number is in the vector
    for(auto i:nums)
    {
        tmp=0;
        j=i;
        while(check.find(j)!=check.end())
        {
            tmp++;
            if(j*j>1e5) break; //break when numbers goes out of limit
            j=j*j;
        }
        res=max(res,tmp);
    }
    
    cout<<res;
    if(res>=2) return res;
    else return -1;
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
    longestSquareStreak(a);


}