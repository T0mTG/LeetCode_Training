#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    //priority queue is used to store nums's value and index in the order of low-to-high value
    //which mean, every q.top() will return the lowest value number in the array
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    
    int n=nums.size();
    pair<int,int>tmp;
    for(int i=0;i<n;i++)
    {
        tmp.first=nums[i];
        tmp.second=i;
        q.push(tmp);
    }     
    while(k--){
        //get the pair with lowest value and its index and then pop it to erase it
        tmp=q.top();
        q.pop();
        //cout<<tmp.first<<" "<<tmp.second<<endl;
        nums[tmp.second]*=multiplier;

        //update the pair and add it back into the queue
        tmp.first=nums[tmp.second];
        q.push(tmp);
    }
    
    return nums;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x,k,c;
    cin>>n>>k>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    getFinalState(a,k,c);
}