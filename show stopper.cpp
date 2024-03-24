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
	vector<int> a(n);
	int amax = INT_MIN;
	int bmax = INT_MIN;
	int amaxi = INT_MIN;
	int bmaxi = INT_MIN;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
		amax = max(amax, item);
		if(i!=n-1)amaxi = max(amaxi, item);
	}
	vector<int> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = item;
		bmax = max(bmax, item);
		if(i!=n-1)bmaxi = max(bmaxi, item);
	}
	// if(amax==a[n-1]&&bmax==b[n-1]){
	// 	cout<<"yes\n";
	// } else if(amaxi<=b[n-1]&&bmaxi<=a[n-1]){
	// 	cout<<"yes\n";
	// } else {
	// 	cout<<"no\n";
	// }
	bool good = true;
	for(int i = 0; i<n-1; i++){
		if(a[i]>a[n-1]&&(b[i]>a[n-1]||a[i]>b[n-1])){
			good = false;
			break;
		}
	}
	for(int i = 0; i<n-1; i++){
		if(b[i]>b[n-1]&&(a[i]>b[n-1]||b[i]>a[n-1])){
			good = false;
			break;
		}
	}
	if(good){
		cout<<"yes\n";
		continue;
	}
	good = true;
	for(int i = 0; i<n-1; i++){
		if(a[i]>b[n-1]&&(b[i]>b[n-1]||a[i]>a[n-1])){
			good = false;
			break;
		}
	}
	for(int i = 0; i<n-1; i++){
		if(b[i]>a[n-1]&&(a[i]>a[n-1]||b[i]>b[n-1])){
			good = false;
			break;
		}
	}
	if(good){
		cout<<"yes\n";
	} else {
		cout<<"no\n";
	}
}
	return 0;
}