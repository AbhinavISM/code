#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int binsrch(int zero, int one, int lo, int hi, vector<int>& onecnt, vector<int>& zerocnt, int n){
	int ans = max(zero,one);
	while(hi>=lo){
		int mid = lo + (hi-lo)/2;
		if(one + onecnt[n-1] - ((n-1-mid<0)?0:onecnt[n-1-mid])>=zero - (zerocnt[n-1] - ((n-1-mid<0)?0:zerocnt[n-1-mid]))){
			ans = min(max(one + onecnt[n-1] - ((n-1-mid<0)?0:onecnt[n-1-mid]), (zero - (zerocnt[n-1] - ((n-1-mid<0)?0:zerocnt[n-1-mid])))), ans);
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	return ans;
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	vector<int> onecnt(s.length(),0);
	vector<int> zerocnt(s.length(),0);
	for(int i = 0; i<s.length(); i++){
		if(s[i]=='1'){
			onecnt[i]++;
		} else {
			zerocnt[i]++;
		}
	}
	for(int i = 1; i<s.length(); i++){
		onecnt[i]+=onecnt[i-1];
		zerocnt[i]+=zerocnt[i-1];
	}
	int zero = zerocnt[s.length()-1];
	int one = 0;
	int ans = INT64_MAX;
	for(int i = 0; i<s.length(); i++){
		int lo = 0;
		int hi = s.length()-i;
		ans = min(ans, binsrch(zero,one,lo,hi,onecnt,zerocnt,s.length()));
		if(s[i]=='1'){
			one++;
		} else {
			zero--;
		}
	}
	cout<<ans<<"\n";
}
	return 0;
}