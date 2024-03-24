#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int m;
	cin>>m;
	set<int> s;
	int minus1 = 0;
	int minus2 = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item==-1){
			minus1++;
		} else if(item==-2){
			minus2++;
		} else {
			s.insert(item);
		}
	}
	vector<int> gaps;
	int lastleft = 0;
	for(int pt : s){
		gaps.push_back(pt-lastleft-1);
		lastleft = pt;
	}
	gaps.push_back(m-lastleft);
	// peek(gaps)
	int totalgap = 0;
	if(totalgap>=minus1){
		int ans = 0;
		for(int i = 0; i<gaps.size(); i++){
			ans += gaps[i];
		}
		ans = min(ans, minus2);
		ans += s.size();
		cout<<ans<<"\n";
		continue;
	}
	int i;
	for(i = 0; i<gaps.size(); i++){
		totalgap += gaps[i];
		if(totalgap>=minus1){
			break;	
		}
	}
	if(i==gaps.size()){
		cout<<s.size() + min(minus1,totalgap)<<"\n";
		continue;
	}
	int ans1 = 0;
	for(int j = i+1; j<gaps.size(); j++){
		ans1 += gaps[j];
	}
	// cout<<ans1<<"\n";
	
	ans1 = min(ans1, minus2);
	ans1 += min(totalgap, minus1);
	ans1 += s.size();
	totalgap -= gaps[i];
	int ans2 = 0;
	for(int j = i; j<gaps.size(); j++){
		ans2 += gaps[j];
	}
	ans2 = min(ans2, minus2);
	ans2 += min(totalgap, minus1);
	ans2 += s.size();
	cout<<max(ans1, ans2)<<"\n";
}
	return 0;
}