#include<bits/stdc++.h>
#define ll long long
using namespace std;
int smallestChair(vector<vector<int>>& times, int targetFriend) {
    // initiate priority queue with the first attribute being the "leaving time" and the second being the "chair index"
    // this p_queue will allow us to grab the lowest index chair with the closest leaving time
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>check;
    // first: leave time
    // second: chair index
    vector<int>req=times[targetFriend];
    int n=times.size();
    int count=0,curr=0;
    set<int>avaChair;
    sort(times.begin(),times.end());
    for(int i=0;i<n;i++)
    {
        cout<<"/////"<<endl;
        int tc=times[i][0], tg=times[i][1];
        //check and insert any vacant chair
        //if by the time friend B come, it's already friend A's time to leave, the while loop will kick not just friend A but any friends
        //whose time is up, thus, get the vacant chair
        while(!check.empty()&&tc>=check.top().first)
        {
            avaChair.insert(check.top().second);
            check.pop();
        }
        curr=0;
        // for(int j:avaChair)
        // {
        //     cout<<j<<" ";
        // }
        // cout<<endl;
        //if there is an available chair (or the list is not empty), give the friend his/her chair
        if(!avaChair.empty())
        {
            curr=*avaChair.begin();
            avaChair.erase(avaChair.begin());
        }
        // if there isn't any available chair, just create a new one :D
        else curr=count++;
        check.push({tg,curr}); //put the friend with the chair on watchlist (leaving time and chair index);
        
        //cout<<check.top().first<<" "<<check.top().second<<endl;
        //if(times[i]==req) return curr;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y,k;
    vector<vector<int>>a;
    cin>>n>>k;
    for(int i=0;i<n;i++) 
    {
        cin>>x>>y;
        vector<int>tmp;
        tmp.push_back(x);
        tmp.push_back(y);
        a.push_back(tmp);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i][0]<<endl;
    // }
    cout<<smallestChair(a,k);
}



/*
Naive solution: better used for counting min nums of chair

int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0;i<times.size();i++)
        {
            times[i].push_back(i);
        }
        sort(times.begin(),
            times.end(),
            [](const std::vector<int> &above, const std::vector<int> &below)
            {
                return (above[0] < below[0]);
            });
        int count=1,res;
        vector<int>tmp;
        tmp.push_back(times[0][1]);
        for(int i=1;i<times.size();i++)
        {
            int check=0;
            for(int j=0;j<tmp.size();j++)
            {
                if(tmp[j]<=times[i][0])
                {
                    tmp.erase(tmp.begin()+j);
                    check=1;
                    break;
                }
            }
            if(!check) count++;
            if(times[i][2]==targetFriend) res=count-1;
            tmp.push_back(times[i][1]);
        }
        return res;
    }
*/


/* Brute force:
For every time a person come, check every chair (max n chair) to see if arrival time is => previous friend's leaving time, either
update the leave time of the chair or move to the next chair

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    vector<int>req=times[targetFriend];
    int n=times.size();
    sort(times.begin(),times.end());
    int chair[n];
    memset(chair,0,sizeof(chair));
    for(int i=0;i<times.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            if(chair[j]<=times[i][0])
            {
                chair[j]=times[i][1];
                if(times[i]==req) return j;
                break;
            }
        }
    }
    return 0;
}
*/