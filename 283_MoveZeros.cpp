#include<bits/stdc++.h>
#define ll long long
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    vector<int>res;
    int c=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[c]=nums[i];
            c++;
        }
    }
    for(int i=c;i<n;i++) nums[i]=0;
    for(auto i:nums) cout<<i<<" ";
    return;
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
    moveZeroes(a);
}