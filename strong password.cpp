#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	string database;
	cin>>database;
	int m;
	cin>>m;
	string l;
	cin>>l;
	string r;
	cin>>r;
	int searchFrom = 0;
	bool possible = false;
	for(int i = 0; i<m; i++){
		int maxRight = -1;
		int val = -1;
		for(int j = l[i]; j<=(int)r[i]; j++){
			bool mila = false;
			for(int k = searchFrom; k<database.length(); k++){
				if(database[k]==j){
					mila = true;
					if(k>maxRight){
						maxRight = k;
						val = j;
					}
					break;
				}
			}
			if(mila==false){
				val = -1;
				break;
			} else {
				// cout<<"mila : "<<j<<" ";
			}
		}
		// cout<<maxRight<<" ";
		searchFrom = maxRight+1;
		if(val==-1){
			possible = true;
			break;
		}
	}
	if(possible){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}