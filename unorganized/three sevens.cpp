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
	int m;
	cin>>m;
	vector<vector<int>> dayparticipants;
	multiset<int> allparticipants;
	for(int i = 0; i<m; i++){
		int n;
		cin>>n;
		dayparticipants.push_back(vector<int>(n));
		for(int j = 0; j<n; j++){
			cin>>dayparticipants[i][j];
			allparticipants.insert(dayparticipants[i][j]);
		}
	}
	vector<int> ans;
	for(int i = 0; i<m; i++){
		for(int people : dayparticipants[i]){
			allparticipants.erase(allparticipants.find(people));
		}
		bool found = false;
		for(int people : dayparticipants[i]){
			if(allparticipants.find(people)==allparticipants.end()){
				found = true;
				ans.push_back(people);
				break;
			}
		}
		if(!found){
			break;
		}
	}
	if(ans.size()==m){
		peek(ans);
	} else {
		cout<<-1<<"\n";
	}
}
	return 0;
}