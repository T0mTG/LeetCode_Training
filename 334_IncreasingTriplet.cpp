#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool increasingTriplet(vector<int>& nums) {
    
    int n=nums.size();
    int tmp=nums[1],tmpa=INT_MAX;
    for(int i=1;i<n;i++){
        if(nums[i]<=tmp){ //getting the smallest number
            tmp=nums[i];
        } 
        else if(tmpa<=nums[i]){ //getting the second smallest number
            tmpa=nums[i];
        }
        else return 1; //if the third smallest number appear, it means we have the increasing triplet
    }
    
    return 0;
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
    increasingTriplet(a);

}


/*
bool increasingTriplet(vector<int>& nums) {
    
    int n=nums.size();
    int a[100000],b[100000];
    b[0]=nums[0];
    a[n-1]=nums[n-1];
    cout<<b[0];
    for(int i=1;i<n;i++)
    {
        b[i]=(nums[i]<b[i-1]) ? nums[i] : b[i-1]; //find the smallest number from the left
        cout<<" "<<b[i];
    }
    cout<<endl;
    for(int i=n-2;i>=0;i--)
    {
        a[i]=(nums[i]>a[i+1]) ? nums[i] : a[i+1]; //find the biggest number from the right
    }
    for(int i=0;i<n;i++){
        if(nums[i]>b[i]&&nums[i]<a[i]) return 1; //find the second number of the triplet by comparing to the first (smallest) and the last (biggest)
    }
    
    return 0;
}
*/