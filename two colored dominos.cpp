#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<string> mtx(n);
	for(int i = 0; i<n; i++){
		string item;
		cin>>item;
		mtx[i] = item;
	}
	vector<pair<int,int>> rowscolor(n, make_pair(0,0));
	vector<pair<int,int>> columnscolor(m, make_pair(0,0));
	for(int i = 0; i<n; i++){
		int count = 0;
		for(int j = 0; j<m; j++){
			if(mtx[i][j]!='.'){
				count++;
			}
		}
		if(count%2){
			cout<<"-1\n";
			return;
		}
	}
	for(int j = 0; j<m; j++){
		int count = 0;
		for(int i = 0; i<n; i++){
			if(mtx[i][j]!='.'){
				count++;
			}
		}
		if(count%2){
			cout<<"-1\n";
			return;
		}
	}
	for(int i = 0; i<n; i++){
			bool rowb = 0;
		for(int j = 0; j<m; j++){
			if(mtx[i][j]=='L'){
				if(rowb){
					mtx[i][j] = 'W';
					mtx[i][j+1] = 'B';
				} else {
					mtx[i][j] = 'B';
					mtx[i][j+1] = 'W';
				}
				rowb = !rowb;
			}
		}
	}
	for(int i = 0; i<n; i++){
			bool colb = 0;
		for(int j = 0; j<m; j++){
			if(mtx[i][j]=='U'){
				if(colb
					){
					mtx[i][j] = 'W';
					mtx[i+1][j] = 'B';
				} else {
					mtx[i][j] = 'B';
					mtx[i+1][j] = 'W';
				}
				colb = !colb;
			}
		}
	}
	for(int i = 0; i<n; i++){
		cout<<mtx[i]<<"\n";
	}
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	solve();
	
}
	return 0;
}