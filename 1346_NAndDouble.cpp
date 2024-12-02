#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool checkIfExist(vector<int>& arr) {
    int d[10006],da[10006],c=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==0) c++;
        if(arr[i]>=0) d[arr[i]]=1;
        else da[abs(arr[i])]=1;
    }
    if(c>1) return 1;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            if(arr[i]>0){
                if(d[arr[i]*2]==1) return 1;
            }
            else if(da[abs(arr[i]*2)]==1) return 1;
        }
    }
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
    checkIfExist(a);


}