#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int sumMoreThaneqL(vector<int> &array, int l, int i, int n){
	int lo = i+1;
	int hi = n-1;
	int ans = INT64_MAX;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(array[mid] + array[i] >= l){
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}
int sumLessThaneqR(vector<int> &array, int r, int i, int n){
	int lo = i+1;
	int hi = n-1;
	int ans = INT64_MIN;
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(array[mid] + array[i] <= r){
			ans = max(ans, mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> array(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array[i] = item;
	}
	sort(array.begin(), array.end());
	int ans = 0;
	for(int i = 0; i<n; i++){
		int a = sumMoreThaneqL(array,l,i,n);
		int b = sumLessThaneqR(array,r,i,n);
		if(a==INT64_MAX||b==INT64_MIN){
			continue;
		} else {
			ans += (b-a+1);
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}