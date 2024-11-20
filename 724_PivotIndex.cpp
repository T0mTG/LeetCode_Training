#include<bits/stdc++.h>
#define ll long long
using namespace std;
int pivotIndex(vector<int>& nums) {
    vector<int>pre{nums};
    int n=nums.size();
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+pre[i];
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            if(pre[i-1]==pre[n-1]-pre[i]){
                cout<<i<<endl;
                return i;
            }
        }
        else{
            if(pre[n-1]-pre[i]==0){
                cout<<i<<endl;
                return i;
            }
        }
    }
    return -1;
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
    pivotIndex(a);

}