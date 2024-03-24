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
	int n;
	cin>>n;
	vector<int> a;
	vector<int> b;
	int penalty = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(a.size()==0){
			a.push_back(item);
		} else if(item<=a.back()&&(b.size()==0||b.back()<item)){
			a.push_back(item);
		} else if(item>a.back()&&(b.size()==0||b.back()>=item)){
			b.push_back(item);
		} else if(item>a.back()&&item>b.back()){
			if(a.back()<b.back()){
				a.push_back(item);
			} else {
				b.push_back(item);
			}
			penalty++;
		} else if(a.back()>=item&&b.back()>=item){
			if(a.back()<b.back()){
				a.push_back(item);
			} else {
				b.push_back(item);
			}
		}
	}
	cout<<penalty<<"\n";
}
	return 0;
}