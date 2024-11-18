#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> decrypt(vector<int>& code, int k) {
    int n=code.size();
    vector<int>sum{code};
    sum[0]=code[0];
    if(k==0){
        for(int i=0;i<n;i++) code[i]=0;
        return code;
    }
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+code[i];
    }
    //for(auto i:sum) cout<<i<<" ";
    //cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(k>0)
        {
            if(i+k<n)
            {
                code[i]=sum[i+k]-sum[i];
                continue;
            }
            else if(i+k>n-1)
            {
                code[i]=sum[n-1]-sum[i];
                code[i]+=sum[i+k-n];
            }
        }
        if(k<0)
        {
            if(i+k>=0){
                if(i+k==0) code[i]=sum[i-1];
                else code[i]=sum[i-1]-sum[i+k-1];
            }
            else{
                if(i-1>=0) code[i]=sum[i-1];
                else code[i]=0;
                int tmp=i+k;
                code[i]+=sum[n-1]-sum[n+tmp-1];
                //cout<<i<<" "<<tmp<<" "<<n+tmp-1<<endl;
            }
        }
    }
    for(auto i:code) cout<<i<<" ";
    return code;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    decrypt(a,k);

    /*
    4 3
    5 7 1 4

    4 -2
    2 4 9 3
    */

}