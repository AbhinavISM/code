#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
long long getSpecialArrayCount(vector<vector<int>> matrix, vector<int> thresold){
	vector<int> mat;
	int n = matrix.size();
	int m = matrix[0].size();
	for(int i = 0; i<n; i++){
		int a = 0;
		for(int j = 0; j<m; j++){
			if(matrix[i][j]>=thresold[j]) a = a|(1<<j);
		}
		mat.push_back(a);
	}
	vector<int> f((1<<m),0);
	for(int i = 0; i<n; i++){
		for(int mask = mat[i]; mask>0; mask = (mask-1)&mat[i]){
			f[mask]++;
		}
		f[0]++;
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		int need = mat[i]^((1<<m)-1);
		ans += f[need];
	}
	return ans;
}
int32_t main(){
	fast_io;
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m,0));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>a[i][j];	
		}
	}
	vector<int> thresold(m,0);
	for(int i = 0; i<m; i++){
		cin>>thresold[i];
	}
	cout<<getSpecialArrayCount(a, thresold);
}