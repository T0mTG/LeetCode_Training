#include<bits/stdc++.h>
#define ll long long
using namespace std;
int uniquePaths(int m, int n) {
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }       
    cout<<dp[m][n]<<endl;
    return dp[m][n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    cin>>n>>x;
    uniquePaths(n,x);
}