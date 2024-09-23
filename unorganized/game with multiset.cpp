#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int q;
	vector<int> f(30,0);
	cin>>q;
	while(q--){
	int t;
	cin>>t;
	int v;
	cin>>v;
	if(t==1){
		f[v]++;
	} else {
		vector<int> tf = f;
		vector<bool> need(30,false);
		int idx = 0;
		while(v>0){
			if(v%2){
				need[idx] = true;
			}
			v/=2;
			idx++;
		}
		bool good = true;
		for(int i = 29; i>= 0; i--){
			if(need[i]){
				int x = (1<<i);
				for(int j = i; j>=0&&x>0; j--){
					int y = tf[j]*(1<<j);
					if(i==1&&j==0){
					}
					if(y>=x){
						int k = (x/(1<<j));
						x-=(k*(1<<j));
						tf[j]-=k;
					} else {
						x -= tf[j]*(1<<j);
						tf[j] = 0;
					}
				}
				if(x>0){
					good = false;
					break;
				}
			}
		}
		if(good){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}
	return 0;
}