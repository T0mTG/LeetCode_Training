#include<bits/stdc++.h>
#define ll long long
using namespace std;
double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    //you can see that if you add one to both the numbers of passing students and the totals, the rate of passing will go up 
    //the basic idea is to prioritize the pair in which the increment in ratio is the highest (using priority queue)
    priority_queue< pair<double,int>, vector<pair<double,int>> > q;

    //one math operation through out the code is: (class.student+1 / class.total+1) - (class.student / class.total);
    //-> the increment in ratio if an extra student is added to the class

    double res=0;
    int n=classes.size();
    pair<double,int>tmp;
    for(int i=0;i<n;i++){
        //init the queue by getting change in ratio and its index in the array
        tmp.first=(double)( classes[i][0]+1 ) / ( classes[i][1]+1 ) - ( (double)( classes[i][0]) / classes[i][1] );
        tmp.second=i;
        q.push(tmp);
    }
    while(extraStudents--){
        //getting and updating the pair with the highest change in ratio
        tmp=q.top();
        q.pop();
        //cout<<tmp.first<<" "<<tmp.second<<endl;

        //add one student
        classes[tmp.second][0]++;
        classes[tmp.second][1]++;

        //update the ratio after added an extra student
        tmp.first=(double)( classes[tmp.second][0]+1 ) / ( classes[tmp.second][1]+1 ) - ( (double)( classes[tmp.second][0]) / classes[tmp.second][1] );;
        
        q.push(tmp);
    }
    for(int i=0;i<n;i++)
    {
        res+=(double)classes[i][0]/classes[i][1];
        //cout<<classes[i][0]<<" "<<classes[i][1]<<endl;
    }
    res/=n;
    cout<<res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>>a;
    int n,x,k,c;
    vector<int>v(3);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[0]>>v[1];
        a.push_back(v);
    }
    maxAverageRatio(a,k);
}