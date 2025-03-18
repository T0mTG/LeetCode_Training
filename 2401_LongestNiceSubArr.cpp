#include<bits/stdc++.h>
#define ll long long
using namespace std;
int longestNiceSubarray(vector<int>& nums) {
    int tmp=0,res=0;
    //tmp is used to track used bits
    int l=0;
    for(int i=0;i<nums.size();i++){
        //check if nums[i] share any bits with tmp, if yes, then shrink (increase the l) to eliminate them
        while(tmp&nums[i]!=0){
            //the ^ operation
            //let two nums a and b, a^b would create the number that have bits unique to only a or only b
            //for example: 5 is 0101, and 9 is 1001, then 5^9 = 12 or 1100
            //this would help us eliminate bits shared by both number
            tmp^=nums[l];
            l++;
        }
        //add the new number to the tmp for tracking
        tmp|=nums[i];
        res=max(res,i-l+1);
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
    longestNiceSubarray(a);
    
}