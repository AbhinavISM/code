#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t; 
    while(t--){
       int n;
    cin>>n;
    char trump ;
    cin >> trump;
    map<char,set<int>> mp;
    for(int i=0;i<2*n;i++){
        string s;
        cin >> s;
        mp[s[1]].insert(s[0]-'0');
    }
    int t = mp[trump].size();
    int err = 0;
    for(auto i:mp){
        if(i.first!=trump){
            err += i.second.size()%2;
        }
    }
    // cout<<err<<" "<<t<<" ";
    if((err+t)%2!=0 || t<err){
        cout<<"IMPOSSIBLE\n";
        continue;
    }
    for(auto i:mp){
        while(i.second.size()>0 && i.first!=trump){
            auto num = (i.second.begin());
            cout<<(*num)<<i.first<<" ";
            i.second.erase(num);
            if(i.second.size() > 0){
                num = (i.second.begin());
                cout<<(*num)<<i.first<<endl;
                i.second.erase(num);
            }
            else{
                num = (mp[trump].begin());
                cout<<(*num)<<trump<<endl;
                mp[trump].erase(num);
            }
        }
    }
    while(mp[trump].size()>0){
        auto num = (mp[trump].begin()); 
        cout<<(*num)<<trump<<" ";
        mp[trump].erase(num);
        num = (mp[trump].begin());
        cout<<(*num)<<trump<<endl;
        mp[trump].erase(num);
    }
   }
    return 0;
}