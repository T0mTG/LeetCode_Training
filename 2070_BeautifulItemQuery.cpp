#include<bits/stdc++.h>
#define ll long long
using namespace std;
int binSearch(vector<vector<int>>& items,int k){ 
    int l=0,r=items.size()-1,mid,res=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(items[mid][0]>k) r=mid-1;
        else{
            res=max(res,items[mid][1]);
            l=mid+1;
        }
    }
    return res;
}
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        cout<<"\\\\\\"<<endl;
        int n=items.size(), m=queries.size(), ma=0;
        vector<int>res(m);
        sort(items.begin(), items.end());
        for(int i=0;i<n;i++){
            ma=max(ma,items[i][1]);
            items[i][1]=ma;
            cout<<items[i][0]<<" "<<items[i][1]<<endl;
        }
        for(int i=0;i<m;i++){
            res[i]=binSearch(items,queries[i]);
            cout<<res[i]<<" ";
        }
        return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>>a;
    vector<int>q;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        vector<int>tmp;
        cin>>x>>y;
        tmp.push_back(x);
        tmp.push_back(y);
        a.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        q.push_back(x);
    }
    maximumBeauty(a,q);
}

/*
5 6
1 2 
3 2
2 4
5 6
3 5
1 2 3 4 5 6
*/