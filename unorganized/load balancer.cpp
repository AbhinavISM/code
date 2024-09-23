#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
vector<int> getWaitingtimes(vector<int> starts, vector<int> ends, vector<int> tasks){
	int n = starts.size();
	int k = tasks.size();
	map<int,int> starttoend;
	for(int i = 0; i<n; i++){
		starttoend[starts[i]] = ends[i];	
	}
	sort(starts.begin(), starts.end());
	vector<int> ans;
	for(int i = 0; i<k; i++){
		auto it = lower_bound(starts.begin(), starts.end(), tasks[i]);
		int tans = INT_MAX;
		if(it!=starts.end()) tans = *it-tasks[i];
		if(it!=starts.begin()){
			it--;
			if(starttoend[*it]>=tasks[i]){
				tans = 0;
			}
		}
		if(tans==INT_MAX) tans = -1;
		ans.push_back(tans);
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n,k;
	cin>>n>>k;
	vector<int> starts(n,0);
	for(int i = 0; i<n; i++){
		cin>>starts[i];
	}
	vector<int> ends(n,0);
	for(int i = 0; i<n; i++){
		cin>>ends[i];
		ends[i]--;
	}
	vector<int> tasks(k,0);
	for(int i = 0; i<k; i++){
		cin>>tasks[i];
	}
	peek(getWaitingtimes(starts, ends, tasks));
}