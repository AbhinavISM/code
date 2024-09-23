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
	int n,m;
	cin>>n>>m;
	vector<int> k(n);
	for(int i = 0; i<n; i++){
		cin>>k[i];
	}
	sort(k.begin(), k.end());
	for(int i = 0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		int l,r;
		l = 0;
		r = n-1;
		while (r - l >=3 ) {
	        int mid1 = l + (r - l) / 3;
	        int mid2 = r - (r - l) / 3;
	        int val1 = (b-k[mid1])*(b-k[mid1]);
	        int val2 = (b-k[mid2])*(b-k[mid2]);
	        if (val1 >= val2){
	            l = mid1;
	        }
	        else{
	            r = mid2;
	        }
	    }
		bool ans = false;
	    int ansidx;
	    for(int j = l; j<=r; j++){
	    	int val = (b-k[j])*(b-k[j]);
	    	if(val<(4*a*c)){
	    		ans = true;
	    		ansidx = j;
	    	}
	    }
	    if(ans==false&&l>=1){
	    	int val = (b-k[l-1])*(b-k[l-1]);
	    	if(val<(4*a*c)){
	    		ans = true;
	    		ansidx = l-1;
	    	}
	    }
	    if(ans==false&&r<n-1){
	    	int val = (b-k[r+1])*(b-k[r+1]);
	    	if(val<(4*a*c)){
	    		ans = true;
	    		ansidx = r+1;
	    	}
	    }
	    if(ans){
	    	cout<<"YES\n";
	    	cout<<k[ansidx]<<"\n";
	    } else {
	    	cout<<"NO\n";
	    }
	}
	
}
	return 0;
}	