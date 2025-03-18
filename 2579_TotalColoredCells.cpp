#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long coloredCells(int n) {
    if(n==1) return 1;
    //first approach: you can (draw and) see that
    // n=   1     2     3      4
    //      1     5     13     25
    //        +4    +8     +12
    //then, we can implement the loop as follow 
    // long long res=1;
    // for(int i=1;i<=n;i++){
        //     res+=(i-1)*4;
    // }
    
    //second approach
    //from the first approach, we can see that res= 1 + 4*1 + 4*2 + ... + 4*(n-1)
    //                                            = 1 + 4*(1+2+3+...+n-1)
    //                                            = 1 + 4*n*(n-1)/2
    //                                            = 1 + 2*n*(n-1)
    long long res=2LL*n*(n-1)+1;
    //res= 1 + 2*n*(n-1);
    //cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n;
    cin>>n;
    coloredCells(n);
}