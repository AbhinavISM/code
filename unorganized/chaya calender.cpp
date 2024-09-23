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
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	int year = a[0]+1;
	// cout<<year<<" ";
	for(int i = 1; i<n; i++){
		int x = year/a[i];
		int y = year%a[i];
		if(y==0){
			year++;
		} else {
			year = ((year/a[i]) + 1)*a[i] + 1;
		}
		// cout<<year<<" ";
	}
	// cout<<"\n";
	cout<<year-1<<"\n";
}
	return 0;
}