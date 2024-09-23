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
	bool sorted = true;
	for(int i = 1; i<n; i++){
		if(s[i]<s[i-1]){
			sorted = false;
		}
	}
	if(sorted){
		cout<<0<<"\n";
		continue;
	}
	vector<int> largestidx(n);
	largestidx[n-1] = n-1;
	for(int i = n-2; i>=0; i--){
		if(s[i]>=s[largestidx[i+1]]){
			largestidx[i] = i;
		} else {
			largestidx[i] = largestidx[i+1];
		}
	}
	char mostlrgchar = s[largestidx[0]];
	int mostlrgcnt = 0;
	for(int i = 0; i<n; i++){
		if(s[i]==mostlrgchar){
			mostlrgcnt++;
		}
	}
	set<int> lexo;
	for(int i : largestidx){
		lexo.insert(i);
	}
	vector<int> lexov;
	for(int i : lexo){
		lexov.push_back(i);
	}
	int largeLen = lexov.size();
	int i = 0;
	int j = largeLen - 1;
	while(i<j){
		char temp = s[lexov[i]];
		s[lexov[i]] = s[lexov[j]];
		s[lexov[j]] = temp;
		i++;
		j--;
	}
	sorted = true;
	for(int i = 1; i<n; i++){
		if(s[i]<s[i-1]){
			sorted = false;
		}
	}
	if(sorted){
		cout<<(largeLen-1-(mostlrgcnt-1))<<"\n";
	} else {
		cout<<-1<<"\n";
	}
}
	return 0;
}