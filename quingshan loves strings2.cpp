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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int onecnt = 0;
	int zerocnt = 0;
	bool sgood;
	for(int i = 0; i<s.size(); i++){
		if(s[i]=='0'){
			zerocnt++;
		} else {
			onecnt++;
		}
	}
	if(s.size()%2==1||zerocnt!=onecnt){
		cout<<"-1\n";
	} else {
		int it = 300;
		vector<int> ans;
		while(it--){
			for(int i = 0; i<s.size(); i++){
				if(s[i]==s[s.size()-i-1]&&s[i]=='0'){
					ans.push_back(s.size()-i);
					s.insert(s.size()-i, "01");
					// cout<<s<<" ";
					break;
				} else if(s[i]==s[s.size()-i-1]&&s[i]=='1'){
					ans.push_back(i);
					s.insert(i, "01");
					// cout<<s<<" ";
					break;
				}
			}
			sgood = true;
			for(int i = 0; i<s.size(); i++){
				if(s[i]==s[s.size()-i-1]){
					sgood = false;
				}
			}
			if(sgood){
				break;
			}
		}
		// cout<<"\n";
		if(sgood){
			cout<<ans.size()<<"\n";
			for(int a : ans){
				cout<<a<<" ";
			}
			cout<<"\n";
		} else {
			cout<<"-1\n";
		}
	}
}
	return 0;
}