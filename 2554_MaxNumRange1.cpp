#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxCount(vector<int>& banned, int n, int maxSum) {
    bool check[10006];
    int tmp=0,res=0;
    memset(check,0,sizeof(check));
    for(auto i:banned) check[i]=1;
    for(int i=1;i<=n;i++){
        if(tmp+i<=maxSum){
            if(check[i]==0){
                res++;
                tmp+=i;
            }
        }
        else break;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    maxCount(a,m,k);
}