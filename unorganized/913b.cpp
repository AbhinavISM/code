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
	// vector<int> ans(s.length())
	stack<int> siarr;
	stack<int> liarr;
	for(int i = 0; i<s.length(); i++){
		if(s[i]>='a'&&s[i]<='z'){
			if(s[i]!='b'){
				siarr.push(i);
			} else {
				if(siarr.size()>0){
					s[siarr.top()] = '!';
					siarr.pop();
				}
			}
		} else if(s[i]>='A'&&s[i]<='Z'){
			if(s[i]!='B'){
				liarr.push(i);
			} else {
				if(liarr.size()>0){
					s[liarr.top()] = '!';
					liarr.pop();
				}
			}
		}
	}
	for(int i = 0; i<s.length(); i++){
		if(s[i]!='!'&&s[i]!='b'&&s[i]!='B') cout<<s[i];
	}
	cout<<"\n";

	// for(int a : siarr){
	// 	cout<<s[a];
	// }
	// for(int b : liarr){
	// 	cout<<s[b];
	// }
	// char lasts = '!';
	// int lsi = -1;
	// char lastl = '!';
	// int lci = -1;
	// int a = 1;
	// int b = 1;
	// if(liarr.size()>=1){
	// 	 lastl = s[liarr[0]];
	// 	 lci = liarr[0];
	// 	 a = 0;	
	// }
	// if(siarr.size()>=1){
	// 	 lasts = s[siarr[0]];
	// 	 lsi = siarr[0];
	// 	 b = 0;
	// }

	// for(int i = 0; i<s.length(); i++){
	// 	if(s[i]=='b'&&lasts!='!'&&lsi<i){
	// 		s[lsi] = '!';
	// 		if(b+1<siarr.size()){
	// 			b++;
	// 			lsi = siarr[b];
	// 			lasts = s[siarr[b]];
	// 		} else {
	// 			lasts = '!';
	// 			lsi = -1;
	// 		}
	// 	} else if(s[i]=='B'&&lastl!='!'&&lci<i){
	// 		s[lci] = '!';
	// 		if(a+1<liarr.size()){
	// 			a++;
	// 			lci = liarr[a];
	// 			lastl = s[liarr[a]];
	// 		} else {
	// 			lastl = '!';
	// 			lci = -1;
	// 		}
	// 	}
	// }
	// for(int i = 0; i<s.length(); i++){
	// 	if(s[i]!='!'&&s[i]!='b'&&s[i]!='B') cout<<s[i];
	// }
	// cout<<"\n";
}
	return 0;
}