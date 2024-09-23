#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int q;
	cin>>q;
	multiset<int> l;
	multiset<int> r;
	for(int i = 0; i<q; i++){
		string s;
		cin>>s;
		// cout<<s;
		int li;
		cin>>li;
		// cout<<li;
		int ri;
		cin>>ri;
		// cout<<ri;
		// cout<<"\n";
		if(s[0]=='+'){
			l.insert(li);
			r.insert(ri);
			if(r.size()>0&&(*(r.begin()))<(*(l.rbegin()))){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		} else {
			auto lit = l.find(li);
			auto rit = r.find(ri);
			l.erase(lit);
			r.erase(rit);
			if(r.size()>0&&(*(r.begin()))<(*(l.rbegin()))){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}
	// for(int li : l){
	// 	cout<<li<<" ";
	// }
	// cout<<"\n";
	// for(int li : r){
	// 	cout<<li<<" ";
	// }
	return 0;
}