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
	string s;
	cin>>s;
	string hrs = "";
	hrs+=s[0];
	hrs+=s[1];
	string mns = "";
	mns+=s[3];
	mns+=s[4];
	int hr = stoi(hrs);
	int mn = stoi(mns);
	// cout<<hr<<" "<<mn<<"\n";
	bool AM = true;
	if(hr>=12){
		AM = false;
	}
	if(AM){
		if(hr==0){
			if(mn<10){
				cout<<12<<":"<<0<<mn<<" AM\n";
			}
			else cout<<12<<":"<<mn<<" AM\n";
		} else{
			if(hr<10&&mn<10){
				cout<<0<<hr<<":"<<0<<mn<<" AM\n";
			} else if(hr<10){
				cout<<0<<hr<<":"<<mn<<" AM\n";
			} else if(mn<10){
				cout<<hr<<":"<<0<<mn<<" AM\n";
			} else {
				cout<<hr<<":"<<mn<<" AM\n";
			}
		}
	} else {
		if(hr==12){
			if(mn<10){
			cout<<hr<<":"<<0<<mn<<" PM\n";
			} 
			else cout<<hr<<":"<<mn<<" PM\n";
		} else {
			if(hr-12<10&&mn<10){
				cout<<0<<hr-12<<":"<<0<<mn<<" PM\n";
			} else if(hr-12<10){
				cout<<0<<hr-12<<":"<<mn<<" PM\n";
			} else if(mn<10){
				cout<<hr-12<<":"<<0<<mn<<" PM\n";
			} else {
				cout<<hr-12<<":"<<mn<<" PM\n";
			}
		}
	}
}
	return 0;
}