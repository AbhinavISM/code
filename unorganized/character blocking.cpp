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
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	int n = s1.length();
	int t,q;
	cin>>t>>q;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	set<int> bad;
	for(int i = 0; i<n; i++){
		if(s1[i]!=s2[i]){
			bad.insert(i);
		}
	}
	for(int sec=1; sec<=q; sec++){
		int type;
		cin>>type;
		while(!pq.empty()){
			auto revive = pq.top();
			if(revive.first==sec){
				pq.pop();
				if(s1[revive.second]!=s2[revive.second]){
					bad.insert(revive.second);
				}
			} else {
				break;
			}
		}
		if(type==1){
			int pos;
			cin>>pos;
			pos--;
			pq.push({sec + t, pos});
			bad.erase(pos);
		} else if(type==2){
			int string1, string2, pos1, pos2;
			cin>>string1>>pos1>>string2>>pos2;
			pos1--;
			pos2--;
			if(string1==1&&string2==1){
				char tmp = s1[pos1];
				s1[pos1] = s1[pos2];
				s1[pos2] = tmp;
			} else if(string1==1&&string2==2){
				char tmp = s1[pos1];
				s1[pos1] = s2[pos2];
				s2[pos2] = tmp;
			} else if(string1==2&&string2==1){
				char tmp = s2[pos1];
				s2[pos1] = s1[pos2];
				s1[pos2] = tmp;
			} else if(string1==2&&string2==2){
				char tmp = s2[pos1];
				s2[pos1] = s2[pos2];
				s2[pos2] = tmp;
			}
			if(s1[pos1]!=s2[pos1]){
				bad.insert(pos1);
			} else {
				bad.erase(pos1);
			}
			if(s1[pos2]!=s2[pos2]){
				bad.insert(pos2);
			} else {
				bad.erase(pos2);
			}
		} else {
			if(bad.size()==0){
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
		}
	}
}
	return 0;
}