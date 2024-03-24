#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> coordinates(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		coordinates[i] = item;
	}
	vector<int> speeds(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		speeds[i] = item;
	}
	ld hi = 1000000000;
	ld lo = 0;
	ld ans = INT64_MAX;
	int it = 100;
	while(it--){
		ld mid = (lo + hi)/2;
		ld maxleft = INT64_MIN;
		ld minright = INT64_MAX;
		for(int i = 0; i<n; i++){
			maxleft = max(maxleft, coordinates[i] - speeds[i]*mid);
			minright = min(minright, coordinates[i] + speeds[i]*mid);
		}
		if((maxleft+1e-7)<=minright){
			hi = mid;
			ans = min(ans, mid);
		} else {
			lo = mid;
		}
	}
	if(ans!=INT64_MAX) cout<<fixed<<setprecision(20)<<ans<<"\n";
	else cout<<-1<<"\n";
	return 0;
}