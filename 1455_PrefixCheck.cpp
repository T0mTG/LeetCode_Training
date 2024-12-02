#include<bits/stdc++.h>
#define ll long long
using namespace std;
int isPrefixOfWord(string sentence, string searchWord) {
    int n=sentence.size();
        int i=0,c=1,tmp=0;
        if(sentence.find(searchWord)==0) return 1;
        while(i<n){
            if(sentence[i]==' '){
                c++;
                i++;
                tmp=sentence.find(searchWord,i);
                if(tmp==-1) return -1;
                if(tmp==i) return c;
            }
            i++;
        }
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a;
    int n,x;
    string s,c;
    getline(cin,s);
    cin>>c;
    cout<<isPrefixOfWord(s,c);


}