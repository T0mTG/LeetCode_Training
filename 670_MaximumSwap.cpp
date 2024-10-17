#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maximumSwap(int num) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    // initialize a priority queue to store each number and their position in the original number
    priority_queue<pair<int,int>,vector<pair<int,int>>>q;
    // first: value    second: index
    int res=0,count=0,check=1,sav,tmp,tmpi;
    sav=num;
    // disect the number into an array of digits, it is in the reverse order tho (higher index -> closer to the start of the original number)
    while(num>0)
    {
        tmp=num%10;
        q.push({tmp,count++}); // store each number and their (reverse) position in the original number
        a.push_back(tmp);

        // if the disected digit come in an increasing order (or decreasing order from the start of the original number)
        // nothing will change, just return the original number as it is its biggest self. 
        if(tmp<=a[a.size()-1]) check=0; 
        num=(num-tmp)/10;
    } 
    if(check==1) {
        //cout<<"///1"<<endl;
        return sav; // return the original number
    }
    int n=a.size();
    //for(auto i:a) cout<<i;
    //cout<<endl;
    // we are running through the array in reversed order, or the same order as the original number.
    // this is because change in fronter digit will result in bigger number
    for(int i=n-1;i>=0;i--) 
    {
        // the way how priority queue work is that it prioritise higher value to stand at the top, if the .first are the same,
        // then the .second will be compared. Keep in mind that the array of digits is reversed
        if(a[i]==q.top().first) 
        {
            //if the first number is the same as the largest value, it will also possess greatest index in the array (or smallest index
            // in the original number). Therefore, we will eliminate it
            q.pop(); 
            continue;
        }
        else if(q.top().first>a[i])
        {
            // if there's a digit that is bigger than the digit we are at, we will inspect it
            tmp=q.top().first;
            tmpi=q.top().second;
            // we will not swap it right away, but rather, see if there's any digit with the same value but possess index closer to the
            // end of the original number
            // for example: if we swap right away, 1993 will become 9193 as the first 9 is consisdered
            // on the other hand, if we see every 9s there is, we will get 9913 
            while(q.top().first==tmp)
            {
                //cout<<q.top().first<<" "<<q.top().second<<endl;
                tmpi=q.top().second;
                q.pop();
            }
            swap(a[i],a[tmpi]);
            break;
        }
    }
    //put all the digits back into a number
    for(int i=n-1;i>=0;i--) res=res*10+a[i];
    //cout<<res<<endl;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    cin>>n;
    cout<<maximumSwap(n);
}

/*
int maximumSwap(int num) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    priority_queue<pair<int,int>,vector<pair<int,int>>>q;
    // first: value    second: index
    int res=0,count=0,check=1,sav;
    sav=num;
    while(num>0)
    {
        int tmp=num%10;
        q.push({tmp,count++});
        a.push_back(tmp);
        if(tmp<=a[a.size()-1]) check=0;
        num=(num-tmp)/10;
    } 
    if(check==1) {
        //cout<<"///1"<<endl;
        return sav;
    }
    int n=a.size();
    //for(auto i:a) cout<<i;
    //cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==q.top().first)
        {
            q.pop();
            continue;
        }
        else if(q.top().first>a[i])
        {
            swap(a[i],a[q.top().second]);
            break;
        }
    }
    for(int i=n-1;i>=0;i--) res=res*10+a[i];
    //cout<<res<<endl;
    return re
*/