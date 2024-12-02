#include<bits/stdc++.h>
#define ll long long
using namespace std;
int minimumObstacles(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size(),res=0    ;
    deque< pair<int,int> >q;
    //intialize the array used for direction of up, down, left, right
    int di[4]={-1,1,0,0};
    int dj[4]={0,0,-1,1};

    int dist[n][m];
    for(int i=0;i<n;i++){
        //setting the default distance to a large number so we can find optimal route later on
        for(int j=0;j<m;j++) dist[i][j]=n*m; 
    }
    dist[0][0]=0;
    q.push_front({0,0});
    pair<int,int>u;
    int i,j;
    while(!q.empty()){
        u=q.front();
        q.pop_front();
        for(int k=0;k<4;k++){
            //get the next cell in the grid to examine
            i=u.first+di[k];
            j=u.second+dj[k];
            //making sure it's not out of bound
            if((i>=0&&i<n) && (j>=0&&j<m)){
                //get the optimal distance
                if(dist[i][j]>dist[u.first][u.second]+grid[i][j]){
                    dist[i][j]=dist[u.first][u.second]+grid[i][j];
                    //if the grid weight is 1, push it to the back
                    if(grid[i][j]) q.push_back({i,j});
                    //otherwise, push it to the front
                    else q.push_front({i,j});
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dist[i][j]<<" ";
    //     cout<<endl;
    // }
    return dist[n-1][m-1]; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    minimumObstacles(a);


}

/*
3 3
0 1 1
1 1 0
1 1 0

3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
*/