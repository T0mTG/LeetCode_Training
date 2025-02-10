#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int>res;
    map<long long,long long>d;
    map<long long,long long>count;
    long long tmp=0,x,y;
    for(int i=0;i<=limit;i++){
        d[i]=-1;
    }
    for(int i=0;i<queries.size();i++){
        x=queries[i][0];
        y=queries[i][1];
        if(d[x]==-1){
            count[y]++;
            if(count[y]==1) tmp++;
        }
        else{
            count[d[x]]--;
            if(count[d[x]]==0) tmp--;
            count[y]++;
            if(count[y]==1) tmp++;
        }
        d[x]=y;
        res.push_back(tmp);
    }
    //for(auto i:res) cout<<i<<" ";
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m=2,k;
    cin>>n>>k;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    queryResults(k,a);



}