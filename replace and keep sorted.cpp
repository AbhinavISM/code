#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int q;
	cin>>q;
	int k;
	cin>>k;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	vector<int> precmp(n,0);
	if(n==1){
		while(q--) {
			int l,r;
			cin>>l>>r;
			cout<<k-1<<"\n";
		}
		return 0;
	}
	for(int i = 1; i<n-1; i++){
		precmp[i] = precmp[i-1];
		precmp[i] += array[i] - array[i-1] - 1;
		precmp[i] += array[i+1] - array[i] - 1;
	}
	cout<<"\n";
	while(q--){
		int l,r;
		cin>>l>>r;
		l = l-1;
		r = r-1;
		if(l==r){
			cout<<k-1<<"\n";
		} else if(r==l+1){
			cout<<(array[l]-1) + (k-array[r]) + (array[r] - array[l] - 1)*2<<"\n";
		} else {
			int a = (precmp[r-1] - precmp[l]);
			// cout<<l<<" "<<r<<"\n";
			int b = (array[l]-1) + (k-array[r]) + (array[l+1] - array[l] - 1) + (array[r] - array[r-1] - 1);
			// cout<<a<<" "<<b<<" ";
			cout<<a+b<<"\n";
		}
	}
	return 0;
}