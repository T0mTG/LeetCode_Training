#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //priority_queue< vector<int>, vector<vector<int>> >q;
    vector<vector<int>>res;
    vector<int>tmp;
    sort(intervals.begin(),intervals.end()); // we sort it so that we can work with it in increasing order
    // cout<<"/////////"<<endl;
    // for(auto i:intervals)
    // {
    //     cout<<i[0]<<" "<<i[1]<<endl;
    // } 
    // cout<<"/////////"<<endl;
    for(auto i:intervals)
    {
        //cout<<i[0]<<" "<<i[1]<<endl;
        if(res.empty()) // add the first interval into the result vector
        {
            res.push_back(i);
            tmp=i; // might as well put it into the temporary slot
            continue;
        }
        if(tmp[1]>=i[0]) //if the starint point of i (interval) is smaller than the temporary -> mergable 
        {
            tmp[1]=max(i[1],tmp[1]); // get the larger ending point
            res.erase(res.begin()+res.size()-1); // erase the original interval
            res.push_back(tmp); // and push in the new merged interval
        }
        else
        {
            res.push_back(i); // if there's no overlapse, add the interval in as a new starting point
            tmp=i; // save it to be compared
        }
        cout<<tmp[0]<<" "<<tmp[1]<<endl;
    } 
    // overall, imagine a bucket of lego, you check if any pieces can be put together, if done, put it in the bucket  
    // and starting on a new set of pieces
    cout<<"/////"<<endl;
    for(auto i:res)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>>a;
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        a.push_back({x,y});
    }
    merge(a);
}


/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //priority_queue< vector<int>, vector<vector<int>> >q;
    stack<vector<int>>res;
    vector<int>tmp;
    sort(intervals.begin(),intervals.end());
    // cout<<"/////////"<<endl;
    // for(auto i:intervals)
    // {
    //     cout<<i[0]<<" "<<i[1]<<endl;
    // } 
    // cout<<"/////////"<<endl;
    for(auto i:intervals)
    {
        //cout<<i[0]<<" "<<i[1]<<endl;
        if(res.empty())
        {
            res.push(i);
            tmp=i;
            continue;
        }
        if(tmp[1]>=i[0])
        {
            tmp[1]=max(i[1],tmp[1]);
            res.pop();
            res.push(tmp);
        }
        else
        {
            res.push(i);
            tmp=i;
        }
        cout<<tmp[0]<<" "<<tmp[1]<<endl;
    } 
    vector<vector<int>>fin;    
    while(!res.empty())
    {
        fin.push_back(res.top());
        res.pop();
    }
    sort(fin.begin(),fin.end());
    for(auto i:fin)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return fin;
}
*/