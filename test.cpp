#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
    fast_io;    
    for(int i = 0; i<19; i++){
        int a;
        cin>>a;
        string s1;
        cin>>s1;
        string s2;
        cin>>s2;
        if(i==18){
            cout<<a<<"\n"<<s1<<"\n"<<s2;
        }
    }
}