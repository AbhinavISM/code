#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i : v) {for(auto j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
string rec(int &level, int k, string p, set<char> choice){
	if(choice.size()==0) {
		level++;
		if(level==k) return p;
		else return "";
	}
	string ans;
	for(char i : choice){
		set<char> tmp = choice;
		tmp.erase(i);
		ans = rec(level, k, p+i, tmp);
		if(ans!=""){return ans;}
	}
	return ans;
}
string getPermutation(int n, int k) {
	set<char> choice;
	for(int i = 1; i<=n; i++){
		choice.insert(48+i);
	}
	int level = 0;
    return rec(level,k,"",choice);
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int k;
	cin>>k;
	peek(getPermutation(n,k));
}