#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int>res;
    int check[100];
    memset(check,0,sizeof(check));
    int tmp=0;
    for(int i=0;i<A.size();i++){
        check[A[i]]++;
        if(check[A[i]]==2) tmp++;
        check[B[i]]++;
        if(check[B[i]]==2) tmp++;
        res.push_back(tmp);
    }
    for(auto i:res) cout<<i<<" ";
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    vector<int>b;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        b.push_back(x);
    }
    findThePrefixCommonArray(a,b);



}



/*
super weird approach
my idea was to count elements in each array seperately, and check them if they have appeared in both array or not, then 
save the number of commons into tmp

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int>res;
    int counta[100],countb[100];
    memset(counta,0,sizeof(counta));
    memset(countb,0,sizeof(countb));
    int tmp=0;
    for(int i=0;i<A.size();i++){
        counta[A[i]]++;
        countb[B[i]]++;
        tmp=0;
        for(int j=0;j<=i;j++){
            if(counta[A[j]]>0&&countb[A[j]]>0){
                tmp++;
            }
        }
        res.push_back(tmp);
    }
    for(int i=0;i<A.size();i++){
        int g=A[i];
        cout<<counta[A[i]]<<" "<<countb[A[i]]<<endl;
    }
    for(auto i:res) cout<<i<<" ";
    return res;
}
*/