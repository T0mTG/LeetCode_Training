#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>res;
    stack<int>s;
    int tmp=0,a=0;
    for(int i=0;i<asteroids.size();i++){
        a=asteroids[i];
        //if there's nothing or the asteroid is moving to the right, add it to the stack
        if(s.empty()||a>0) s.push(a);
        //else (or the asteroid is moving to the left)
        else{
            //the asteroid in the stack is also moving to the left, there will be no collision
            //-> add to the stack
            if(s.top()<0){
                s.push(a);
                continue;
            }
            //if it encounter a right-moving asteroid, keep checking if the left-moving one can destroy (pop) the ones in the stack
            while(!s.empty() && abs(a)>s.top() && s.top()>0) {
                s.pop();
            }
            //if the two asteroids have the same size, destroy both
            if(!s.empty()&&abs(a)==s.top()) s.pop();
            else if(s.empty()||s.top()*a>0) s.push(a);
        }
    }
    //transfer from the stack to the vector
    while(!s.empty()){
        //cout<<s.top()<<" ";
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(),res.end());
    for(auto i:res) cout<<i<<" ";
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
    asteroidCollision(a);


}


/*
messy ah solution 

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>res;
    stack<int>s;
    s.push(asteroids[0]);
    int tmp=0,a=0;
    for(int i=1;i<asteroids.size();i++){
        a=asteroids[i];
        if(!s.empty()) tmp=s.top();
        else{
            s.push(a);
            continue;
        }
        if(a*tmp<0){
            if(tmp<0 && a>0){
                s.push(a);
            }
            else{
                if(abs(tmp)==abs(a)){
                        s.pop();
                        continue;
                }
                if(abs(tmp)>abs(a)) continue;
                while(tmp>0 && a<0 && abs(a)>abs(tmp) && !s.empty()){
                    if(abs(a)>abs(tmp)){
                        s.pop();
                        if(!s.empty()) tmp=s.top();
                        else{
                            s.push(a);
                            break;
                        }
                    }
                    if(tmp*a>0){
                        s.push(a);
                        break;
                    }
                    if(abs(a)==abs(tmp)){
                        s.pop();
                        break;
                    }
                }
            }
        }
        else s.push(a);
    }
    while(!s.empty()){
        //cout<<s.top()<<" ";
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(),res.end());
    for(auto i:res) cout<<i<<" ";
    return res;
}
*/