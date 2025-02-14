#include<bits/stdc++.h>
#define ll long long
using namespace std;
int halveArray(vector<int>& nums) {
    priority_queue<double>q;
    int res=0;
    double tmp=0,sum=0,i;
    for(auto i:nums){
        q.push(i);
        sum+=i;
    }
    while(tmp<sum/2){
        i=q.top()/2;
        tmp+=i;
        cout<<q.top()<<" "<<i<<endl;
        q.pop();
        q.push(i);
        res++;
    }
    cout<<res;
    return res;    
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
    halveArray(a);    


}