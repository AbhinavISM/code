#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

int32_t main(){
	fast_io;
	string str;
	cin>>str;
	string substr;
	cin>>substr;
	bool ans = true;
	for(int i = str.length()-1; i>=0; i--){
		bool found = true;
		int ti = i;
		for(int j = substr.length()-1; j>=0; j--){
			if(ti<0) {
				found = false;
				break;
			}
			if(substr[j]!=str[ti]&&str[ti]!='?') {
				found = false;
				break;
			}
			ti--;
		}
		if(found){
			ans = false;
			int ti = i;
			for(int j = substr.length()-1; j>=0; j--){
				str[ti] = substr[j];
				ti--;
			}
			for(int i = 0; i<str.length(); i++){
				if(str[i]=='?') str[i] = 'a';
			}
			cout<<str;
			break;
		}
	}
	if(ans) cout<<-1;
}