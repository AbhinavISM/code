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
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	bool good = true;
	for(int i = n-2; i>=0; i--){
		if(a[i]>a[i+1]){
			if(a[i]<=9){
				good = false;
				break;
			}
			vector<int> aidig;
			int tmp = a[i];
			while(tmp!=0){
				aidig.push_back(tmp%10);
				tmp/=10;
			}
			reverse(aidig.begin(), aidig.end());
			// peek(aidig)
			for(int j = 1; j<aidig.size(); j++){
				if(aidig[j]<aidig[j-1]){
					good = false;
				}
			}
			if(aidig[aidig.size()-1]>a[i+1]){
				good = false;
				break;
			}
			a[i] = aidig[0];
		}
	}
	if(good){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}