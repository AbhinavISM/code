#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n, m;
	cin>>n>>m;
	vector<vector<int>> a(n+1, vector<int> (m));
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}

	int l = 0, r = 1e9;
	int ansl, ansr;

	while(l <= r){
		int mid = l + (r-l)/2;
		map<int, int> mp;
		for(int i=1; i<=n; i++){
			int s = 0;
			for(int j=0; j<m; j++){
				if(a[i][j] >= mid) s+=(1ll<<j);
			}
			mp[s] = i;
	    }
	    int left = -1, right = -1;
	    for(int i=0; i<(1ll<<m); i++){
	    	for(int j=0; j<(1ll<<m); j++){
	    		if((i|j )== ((1ll<<m)-1)){
	    			if(mp[i] && mp[j]) left = mp[i], right = mp[j];	
	    		}
	    	}
	    }
	    if(left != -1 && right != -1){
	    	ansl = left;
	    	ansr = right;
	    	l = mid+1;
	    }
	    else{
	    	r = mid-1;
	    }
	}

	cout<<ansl<<' '<<ansr<<endl;

	return 0;
}