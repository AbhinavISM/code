#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	char c;
	cin>>c;
	int k;
	cin>>k;
	int a = 97;
	int A = 65;
	if(c>=a){
		int ans = ((((c-a)+k) + 26)%26);
		cout<<(char)(a+ans);
	} else {
		int ans = ((((c-A)+k) + 26)%26);
		cout<<(char)(A+ans);
	}
	return 0;
}