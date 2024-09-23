#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
    cin>>n;
    string s;
    cin>>s;
    int a = 1;
    int d = 1;
    set<char> setchar;
    setchar.insert(s[0]);
    for (int i = 1; i<n; i++){
        setchar.insert(s[i]);
        if (setchar.size() != d){
            a += d + 1;
            d++;
        }
        else {
            a += d;
        }
    }
    cout<<a<<endl;
}
	return 0;
}