#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct parabola {
	int a;
	int b;
	int c;
};
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> k(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>k[i];
	}
	vector<parabola> pb(m, parabola());
	for(int i = 0; i<m; i++){
		int a,b,c;
		cin>>pb[i].a>>pb[i].b>>pb[i].c;
	}
	sort(k.begin(), k.end());

	for(int i = 0; i<m; i++){
		auto it = lower_bound(k.begin(), k.end(), pb[i].b);
		if(it==k.end()) {
			it--;
		}
		if((pb[i].b - *it)*(pb[i].b - *it) - 4*pb[i].a*pb[i].c < 0) {
			cout<<"YES\n";
			cout<<*it<<"\n";
			continue;
		}
		if(it!=k.begin()){
			it--;
			if((pb[i].b - *it)*(pb[i].b - *it) - 4*pb[i].a*pb[i].c < 0) {
				cout<<"YES\n";
				cout<<*it<<"\n";
				continue;
			}
		}
		cout<<"NO\n";
	}

	// for(int i = 0; i<m; i++){
	// 	int r = n-1;
	// 	int l = 0;
	// 	while(r-l>=3){
	// 		int m1 = l + (r - l) / 3;
    //     	int m2 = r - (r - l) / 3;
    //     	int f1 = (pb[i].b - k[m1])*(pb[i].b - k[m1]);
    //     	int f2 = (pb[i].b - k[m2])*(pb[i].b - k[m2]);
    //     	if(f1<f2){
    //     		r = m2;
    //     	} else {
    //     		l = m1;
    //     	}
	// 	}
	// 	bool yes = false;
	// 	for(int j = l; j<=r; j++){
	// 		if((pb[i].b - k[j])*(pb[i].b - k[j]) - 4*pb[i].a*pb[i].c < 0) {
	// 			cout<<"YES\n";
	// 			cout<<k[j]<<"\n";
	// 			yes = true;
	// 			break;
	// 		}
	// 	}
	// 	if(!yes){
	// 		cout<<"NO\n";
	// 	}
	// }
}
	return 0;
}