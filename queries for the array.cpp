#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
void solve(string s){
	char lastsort = '2';
	int totalplus = 0;
	int totalminus = 0;
	int totallen = 0;
	int subplus = 0;
	int subminus = 0;
	int subtotal = 0;
	bool touch_1 = false;
	bool touch1 = false;
	for(int i = 0; i<s.length(); i++){
		if(s[i]=='+'){
			totallen++;
			totalplus++;
			subplus++;
			subtotal++;
			if(subtotal==1){
				touch1 = true;
			} else if(subtotal==-1){
				touch_1 = true;
			}
		} else if(s[i]=='-'){
			totallen--;
			totalminus++;
			subminus++;
			subtotal--;
			if(subtotal==1){
				touch1 = true;
			} else if(subtotal==-1){
				touch_1 = true;
			}
		} else if(s[i]=='0'){
			if(totallen<=1){
				// cout<<"here1 ";
				cout<<"NO\n";
				return;
			}
			if(subtotal==0&&lastsort!='0'){
				cout<<"NO\n";
				return;
			}
			if(!(subplus>subminus||((subplus==subminus)&&touch_1))){
				// cout<<"here2 ";
				cout<<"NO\n";
				return;
			}
			subplus = 0;
			subminus = 0;
			subtotal = 0;
			lastsort = '0';
			touch_1 = false;
			touch1 = false;
		} else {
			if(subtotal==0&&(lastsort=='0')){
				cout<<"NO\n";
				return;
			}
			if(totallen<=1){
			}
			else if(!(subminus>subplus||((subplus==subminus)&&touch_1)||lastsort=='2')){
				// cout<<"here3 ";
				cout<<"NO\n";
				return;
			}
			subplus = 0;
			subminus = 0;
			subtotal = 0;
			lastsort = '1';
			touch_1 = false;
			touch1 = false;
		}
	}
	cout<<"YES\n";
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	solve(s);
}
	return 0;
}