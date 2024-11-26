#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findChampion(int n, vector<vector<int>>& edges) {
    bool check[n];
    int res=-1;
    memset(check,0,sizeof(check));
    for(auto a:edges)
    {
        if(a[0]!=a[1]){
            //if a team (a[1]) lose to any team (a[0]), it is marked
            check[a[1]]=1;
        }
    }
    for(int i=0;i<n;i++){
        // cout<<check[i]<<" ";
        //check for unmarked team
        if(!check[i]){
            if(res==-1) res=i; 
            else { 
                //in case there's no distinct champion
                cout<<-1;
                return-1;
            }
        }
    }
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y,k;
    cin>>n>>k;
    vector<vector<int>>a(n,vector<int>(2,0));
    for(int i=0;i<k;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    findChampion(n,a);

}

/*
3
2
0 1
1 2

*/

/*
fail dfs
void dfs(int u,bool* check,vector<int>adj[]){
    for(auto v:adj[u]){
        if(v!=u){
            if(!check[v]){
                check[v]=1;
                dfs(v,check,adj);
            }
        }
    }
    return;
}
int findChampion(int n, vector<vector<int>>& edges) {
    vector<int>adj[n+1];
    bool* check=(bool*)malloc(sizeof(bool)*(n+1));
    memset(adj,0,sizeof(adj));
    memset(check,0,sizeof(check));
    int res=-1;
    for(auto a:edges)
    {
        adj[a[0]].push_back(a[1]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<i<<":";
    //     for(auto j:adj[i]) cout<<j<<" ";
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++)
    {
        if(!check[i]) dfs(i,check,adj);
    }
    for(int i=0;i<n;i++){
        if(!check[i]){
            if(res==-1) res=i;
            else {
                cout<<-1;
                return-1;
            }
        }
    }
    cout<<res;
    return res;
}

*/