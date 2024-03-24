#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(vector<int>& ais,vector<int>& bis,vector<int>& cis,vector<int>& dis,vector<int> plateswithballs, int i, int m, int k, int n){
	if(i==k+1){
		int ans = 0;
		for(int j = 1; j<=m; j++){
			if(plateswithballs[ais[j]]>0&&plateswithballs[bis[j]]>0){
				ans++;
			}
		}
		return ans;
	}
	plateswithballs[cis[i]]++;
	int result1 = solve(ais,bis,cis,dis,plateswithballs,i+1,m,k,n);
	plateswithballs[cis[i]]--;
	plateswithballs[dis[i]]++;
	int result2 = solve(ais,bis,cis,dis,plateswithballs,i+1,m,k,n);
	return max(result1,result2);
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> ais(m+1);
	vector<int> bis(m+1);
	for(int i = 1; i<=m; i++){
		cin>>ais[i]>>bis[i];
	}
	int k;
	cin>>k;
	vector<int> cis(k+1);
	vector<int> dis(k+1);
	for(int i = 1; i<=k; i++){
		cin>>cis[i]>>dis[i];
	}
	vector<int> plateswithballs(n+1,0);
	cout<<solve(ais,bis,cis,dis,plateswithballs,1,m,k,n);
	return 0;
}