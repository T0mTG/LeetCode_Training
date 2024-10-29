#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxMoves(vector<vector<int>>& grid) {
    // for this problem, we are going to implement dynamic programming
    // the basic idea is for every grid, we see if the next grid can be traversed, if yes we will add one to our tracks,
    // also, we will take max of all path to compare
    int n=grid.size(),m=grid[0].size(),tmp,res=0,check;
    int dp[n][m];
    //cout<<n<<" "<<m<<endl;
    memset(dp,0,sizeof(dp));
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(j+1<m)
            {
                //if the grid can be accessed (indicated by dp[i][j]!=0, because the basic idea is if it's larger than any number
                //before it, its dp will bethe dp before it plus one, therefore, it mustn't be zero)
                // j>0 because when we are starting at the first column (j=0), every grids in the first column have 0 in the dp storage
                if(j>0&&dp[i][j]!=0) 
                {
                    if( i-1>=0 && grid[i-1][j+1] > grid[i][j] ) dp[i-1][j+1]=max(dp[i-1][j+1], dp[i][j]+1);
                    if( grid[i][j+1] > grid[i][j] ) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+1);
                    if(i+1<n && grid[i+1][j+1] > grid[i][j] ) dp[i+1][j+1]=max(dp[i+1][j+1] ,dp[i][j]+1);
                }
                // dp[i][j]=0 is only applicable for the numbers in the first column
                else if(j==0) {
                    if( i-1>=0 && grid[i-1][j+1] > grid[i][j] ) dp[i-1][j+1]=max(dp[i-1][j+1], dp[i][j]+1);
                    if( grid[i][j+1] > grid[i][j] ) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+1);
                    if(i+1<n && grid[i+1][j+1] > grid[i][j] ) dp[i+1][j+1]=max(dp[i+1][j+1] ,dp[i][j]+1);
                }
            }
            res=max(res,dp[i][j]);
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //         res=max(res,dp[i][j]);
    //     }
    //     cout<<endl;
    // }
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1, vector<int> (m+1, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    maxMoves(a);

}

/*
4 4
2 4 3 5
5 4 9 3
3 4 2 11
10 9 13 15

3 3
3 2 4
2 1 9
1 1 7
*/
