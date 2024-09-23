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
	if(s[0]=='0'){
		cout<<-1<<"\n";
		continue;
	}
	string a;
	string b;
	a += s[0];
	int i;
	for(i = 1; i<s.length(); i++){
		if(s[i]=='0'){
			a += s[i];
		} else {
			break;
		}
	}
	for(int j = i; j<s.length(); j++){
		b += s[j];
	}
	if(b.length()==0||a.length()==0){
		cout<<-1<<"\n";
		continue;
	}
	if(stoi(a)>=stoi(b)){
		cout<<-1<<"\n";
		continue;
	}
	cout<<a<<" "<<b<<"\n";
}
	return 0;
}