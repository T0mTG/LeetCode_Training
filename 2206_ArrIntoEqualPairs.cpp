#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool divideArray(vector<int>& nums) {
    int d[1000];
    memset(d,0,sizeof(d));
    int c=0;
    for(auto i:nums){
        d[i]++;
        if(d[i]%2==0&&d[i]!=0) c--;
        else c++;
    }
    if(c==0) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    divideArray(a);


}