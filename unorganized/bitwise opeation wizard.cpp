#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;

	int maxpos = 0;
	for(int i = 1; i<n; i++){
		cout<<"? "<<maxpos<<" "<<maxpos<<" "<<i<<" "<<i<<"\n";
		cout.flush();
		char c;
		cin>>c;
		if(c=='<'){
			maxpos = i;
		}
	}
	set<int> maxorset;
	int maxorpos = maxpos;
	for(int i = 0; i<n; i++){
		if(i != maxpos){
			cout<<"? "<<maxpos<<" "<<maxorpos<<" "<<maxpos<<" "<<i<<"\n";
			cout.flush();
			char c;
			cin>>c;
			if(c=='<'){
				maxorpos = i;
				maxorset = set<int>();
				maxorset.insert(i);
			}
			if(c=='='){
				maxorset.insert(i);
			}
		}
	}
	int ans = *(maxorset.begin());
	for(int i : maxorset){
		cout<<"? "<<ans<<" "<<ans<<" "<<i<<" "<<i<<"\n";
		cout.flush();
		char c;
		cin>>c;
		if(c=='>'){
			ans = i;
		}
	}
	cout<<"! "<<maxpos<<" "<<ans<<"\n";
	cout.flush();
}
	return 0;
}