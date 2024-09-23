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
	string s;
	cin>>s;
	vector<pair<int,int>> f(26);
	map<int,set<int>> m;
	for(int i = 0; i<26; i++){
		f[i] = {0,i};
		m[i] = set<int>();
	}
	for(int i = 0; i<n; i++){
		f[s[i]-'a'].first++;
		m[s[i]-'a'].insert(i);
	}
	sort(f.begin(), f.end(), greater<pair<int,int>>());
	int cost = INT64_MAX;
	int bestSize = -1;
	for(int d = 1; d<=26; d++){
		if(n%d==0){
			int cp = 0;
			int cn = 0;
			for(int i = 0; i<d; i++){
				int chng = ((n/d) - f[i].first);
				(chng>=0)?(cp+=chng):(cn+=chng); 
			}
			int c = 0;
			if(cp>=cn){
				c += cp;
			} else {
				c += cn;
			}
			if(cost>=c){
				cost = c;
				bestSize = d;
			}
		}
	}
	vector<pair<int,int>> pbuffer;
	vector<pair<int,int>> nbuffer;
	for(int i = 0; i<bestSize; i++){
		if(f[i].first>(n/bestSize)){
			pbuffer.push_back({f[i].first-(n/bestSize),f[i].second});
		} else if(f[i].first<(n/bestSize)){
			nbuffer.push_back({(n/bestSize)-f[i].first,f[i].second});
		}
	}
	for(int i = bestSize; i<26; i++){
		if(f[i].first>0){
			pbuffer.push_back({f[i].first,f[i].second});
		}
	}
	while(nbuffer.size()>0){
		int ameer = pbuffer[0].second;
		int gareb = nbuffer[0].second;
		m[gareb].insert(*m[ameer].begin());
		m[ameer].erase(*m[ameer].begin());
		pbuffer[0].first--;
		nbuffer[0].first--;
		if(pbuffer[0].first<=0){
			pbuffer.erase(pbuffer.begin());
		}
		if(nbuffer[0].first<=0){
			nbuffer.erase(nbuffer.begin());
		}
	}
	for(auto it : m){	
		int letter = it.first;
		for(int pos : it.second){
			s[pos] = (char)(letter + 'a');
		}
	}
	cout<<cost<<"\n";
	cout<<s<<"\n";
}
	return 0;
}