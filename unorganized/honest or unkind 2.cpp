#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int solve(int i, vector<vector<pair<int,int>>> &alltestimonies, int &n, vector<int> honestornot){
	if(i==n){
		int ans = 0;
		for(int i = 0; i<n; i++){
			if(honestornot[i]==1){
				ans++;
			}
		}
		return ans;
	}
	if(honestornot[i]==-1){
		int notake;
		notake = solve(i+1, alltestimonies, n, honestornot);
		int take = -1;
		honestornot[i] = 1;
		for(int j = 0; j<alltestimonies[i].size(); j++){
			if(honestornot[alltestimonies[i][j].first]==-1){
				honestornot[alltestimonies[i][j].first] = alltestimonies[i][j].second;
				if(alltestimonies[i][j].second==1){
					int check = 1;
					for(int j = 0; j<alltestimonies[i].size(); j++){
						if(honestornot[alltestimonies[i][j].first]==-1){
							honestornot[alltestimonies[i][j].first] = alltestimonies[i][j].second;
						} else if(honestornot[alltestimonies[i][j].first]!=alltestimonies[i][j].second){
							check = 0;
						}
					}
					if(check==0){
						take = 0;
						break;
					}
				}
			} else if(honestornot[alltestimonies[i][j].first]!=alltestimonies[i][j].second){
				take = 0;
			}
		}
		if(take==-1){
			take = solve(i+1, alltestimonies, n, honestornot);
		}
		return max(take,notake);
	} else if(honestornot[i]==1){
		int take = -1;
		for(int j = 0; j<alltestimonies[i].size(); j++){
			if(honestornot[alltestimonies[i][j].first]==-1){
				honestornot[alltestimonies[i][j].first] = alltestimonies[i][j].second;
			} else if(honestornot[alltestimonies[i][j].first]!=alltestimonies[i][j].second){
				take = 0;
			}
		}
		if(take==-1){
			return solve(i+1, alltestimonies, n, honestornot);
		}
		else {
			return 0;
		}
	} else {
		return solve(i+1, alltestimonies, n, honestornot);
	}
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<vector<pair<int,int>>> alltestimonies(n);
	for(int i = 0; i<n; i++){
		int a;
		cin>>a;
		vector<pair<int,int>> testimonies(a);
		for(int j = 0; j<a; j++){
			int person;
			cin>>person;
			int claim;
			cin>>claim;
			testimonies[j] = {(person-1),claim};
		}
		alltestimonies[i] = testimonies;
	}
	vector<int> honestornot(n,-1);
	cout<<solve(0,alltestimonies,n,honestornot);
	return 0;
}