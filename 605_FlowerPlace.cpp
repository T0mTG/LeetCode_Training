#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(n==0) return 1;
    if(flowerbed.size()==1){
        if(flowerbed[0]==0&&n==1) return 1;
        return 0;
    }
    for(int i=0;i<flowerbed.size();i++){
        if(flowerbed[i]==0){
            if(i==flowerbed.size()-1){
                if(flowerbed[i-1]==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(i==0){
                if(flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                n--;
            }
        }
        if(n<=0) return 1;
    }
    return 0;
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
    if(canPlaceFlowers(a,k)) cout<<"let's go";
    else cout<<"nah";

}