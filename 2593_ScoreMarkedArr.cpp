#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long findScore(vector<int>& nums) {
    //the idea is to use priority queue to get both the lowest value and its index in the array
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    int n=nums.size();
    
    //init the queue by populate it with pairs of value and index
    for(int i=0;i<n;i++){
        q.push({nums[i],i});
    }

    pair<int,int> tmp;      
    int res=0,i;
    bool check[n+1];
    memset(check,0,sizeof(check));

    while(!q.empty()){
        //get the pair with lowest value
        tmp=q.top();
        q.pop();

        i=tmp.second;
        //if the element is already marked, skip 
        if(check[i]==1) continue;

        //check the element
        check[i]=1;
        res+=nums[i];
        //check its adjacent elements
        if(i+1<n) check[i+1]=1;
        if(i-1>=0) check[i-1]=1;
        //cout<<tmp.first<<" "<<tmp.second<<endl;
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
    findScore(a);
}