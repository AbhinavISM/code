#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool doesitfit(vector<int> array, int n, int mid, int h){
	sort(array.begin()+1,array.begin()+mid+1,greater<int>());
	int i;
	for(i = 1; i<mid; i+=2){
		int maxi = max(array[i], array[i+1]);
		h-=maxi;
	}
	if(i==mid){
		h-=array[i];
	}
	if(h>=0){
		return true;
	} else {
		return false;
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int h;
	cin>>h;
	vector<int> array(n+1);
	for(int i = 1; i<=n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	int lo = 1;
	int hi = n;
	int ans = 0;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		bool fit = doesitfit(array, n, mid, h);
		if(fit){
			lo = mid+1;
			ans = max(ans,mid);
		} else {
			hi = mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}