#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
int solution(vector<int> numbers, vector<int> pattern){
	int n = numbers.size();
	int m = pattern.size();
	int ans = 0;
	for(int i=0; i<n; i++){
		vector<int> thisPattern;
		for(int j=i+1; j<i+1+m&&j<n; j++){
			if(numbers[j]>numbers[j-1]){
				thisPattern.push_back(1);
			} else if(numbers[j]==numbers[j-1]){
				thisPattern.push_back(0);
			} else {
				thisPattern.push_back(-1);
			}
		}
		peek(thisPattern)
		if(thisPattern==pattern) ans++;
	}
	return ans;
}

int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	vector<int> b(m,0);
	for(int i = 0; i<m; i++){
		cin>>b[i];
	}
	cout<<solution(a,b);
	return 0;
}