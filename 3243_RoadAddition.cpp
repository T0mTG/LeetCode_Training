#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int>adj[n+1];
    vector<int>fin;
    bool check[n+1];
    for(int i=0;i<n-1;i++){
        adj[i].push_back(i+1);
    }
    int d[n+1],res,t=n-1;
    for(auto a:queries){
        // for every query, run bfs again (dijkstra is better but i don't know how to use yet) to find the shortest path
        res=n-1;
        adj[a[0]].push_back(a[1]);

        // checking
        // for(int i=0;i<n;i++){
        //     cout<<i<<":";
        //     for(auto j:adj[i]){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"////"<<endl;
        
        memset(check,0,sizeof(check));
        memset(d,0,sizeof(d));
        queue<int>q;
        check[0]=1;

        //initiate the queue with neighbouring node of 0
        for(auto v:adj[0]){
            d[v]=1;
            if(!check[v]){
                check[v]=1;
                q.push(v);
            }
            if(v==t){
                res=min(res,d[v]);
            }
        }

        // bfs implementation
        while(!q.empty()){
            int u=q.front();
            //cout<<u<<endl;
            for(auto v:adj[u]){
                if(d[v]==0) d[v]=d[u]+1;
                else d[v]=min(d[v],d[u]+1);
                if(!check[v]){
                    check[v]=1;
                    q.push(v);
                }
                if(v==t){
                    res=min(res,d[v]);
                    break;
                }
            }
            q.pop();
        }
        fin.push_back(res);
    }
    
    //for(auto i:fin) cout<<i<<" ";
    return fin;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y,k;
    cin>>n>>k;
    vector<vector<int>>a(k,vector<int>(2,0));
    for(int i=0;i<k;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    shortestDistanceAfterQueries(n,a);

}   


/*
5 3
2 4
0 2
0 4
*/