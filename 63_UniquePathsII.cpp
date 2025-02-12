#include<bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size(),m=obstacleGrid[0].size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    if(obstacleGrid[0][0]==1) return 0;
    dp[0][0]=1;
    //the number of ways to get to a certain point is the sum of the ways needed to get to the point to its left and point above it
    //for example, you need to get to x, so you can get to it either by a or b
    //                            a
    //                          b x
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(obstacleGrid[i][j]==1) continue;
            if(i-1>=0){
                dp[i][j]+=dp[i-1][j];
            }
            if(j-1>=0){
                dp[i][j]+=dp[i][j-1];
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n-1][m-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    uniquePathsWithObstacles(a);



}