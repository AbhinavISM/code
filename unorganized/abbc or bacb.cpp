#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	vector<int> alengths;
	int currlen = 0;
	int totalAsum = 0;
	bool nestedB = false;
	for(int i = 0; i<s.length(); i++){
		if(s[i]=='A'){
			totalAsum++;
			currlen++;
		} else {
			if(currlen>0){
				alengths.push_back(currlen);
			} else {
				nestedB = true;
			}
			currlen = 0;
		}
		if(i==s.length()-1&&s[i]=='A'){
			alengths.push_back(currlen);
		}
	}
	int ans = 0;
	if(s[0]=='A'&&s[s.length()-1]=='A'&&!nestedB){
		for(int alen : alengths){
			ans = max(ans, totalAsum-alen);
		}
	} else {
		ans = totalAsum;
	}
	cout<<ans<<"\n";
}
	return 0;
}