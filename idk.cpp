#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int i = 0;
	int j = n-1;
	vector<int> tmp;
	while(i<j){
		if(a[i]==a[j]){
			tmp.push_back(a[i]);
			j--;
			i++;
		} else if(a[i]<a[j]){
			a[i+1]+=a[i];
			i++;
		} else if(a[i]>a[j]){
			a[j-1]+=a[j];
			j--;
		}
	}
	vector<int> ans;
	for(int i = 0; i<tmp.size(); i++){
		ans.push_back(tmp[i]);
	}
	if(i==j) ans.push_back(a[i]);
	reverse(tmp.begin(), tmp.end());
	for(int i = 0; i<tmp.size(); i++){
		ans.push_back(tmp[i]);
	}
	peek(ans)
}