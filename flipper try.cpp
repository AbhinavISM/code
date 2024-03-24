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
		int n; cin >> n;
    	vector<int> p(n);
    	for (int &e : p) cin >> e;
    	int maxi= -1;
		int maxidx = -1;
		int secmaxi = -1;
		int secmaxidx = -1;
		for(int i = 0; i<n; i++){
			if(p[i]>maxi){
				secmaxi = maxi;
				secmaxidx = maxidx;
				maxi = p[i];
				maxidx = i;
			} else if(p[i]>secmaxi){
				secmaxi = p[i];
				secmaxidx = i;
			}
		}
		// cout<<maxidx<<" ";
		if(maxidx==0&&n>1){
			maxi = secmaxi;
			maxidx = secmaxidx;
		}
		vector<int> ans(n,0);
		if(maxidx>0&&maxidx!=n-1){
			// cout<<"here1 ";
			for(int i = 0; i<maxidx; i++){
				vector<int> temp;
				for(int j = maxidx; j<n; j++){
					temp.push_back(p[j]);
				}
				for(int j = maxidx-1; j>=i; j--){
					temp.push_back(p[j]);
				}
				for(int j = 0; j<i; j++){
					temp.push_back(p[j]);
				}
				
				// cout<<"\n";

				bool replace = false;
				for(int j = 0; j<n; j++){
					if(temp[j]==ans[j]){
						continue;
					} else if(temp[j]>ans[j]){
						replace = true;
						break;
					} else {
						break;
					}
				}
				if(replace){
					for(int j = 0; j<n; j++){
						ans[j] = temp[j];
					}
					// for(int anss : temp){
					// 	cout<<anss<<" ";
					// }
					// cout<<"\n";
				}
			}
		} else if(maxidx>0&&maxidx==n-1){
			// cout<<"here2 ";
			for(int i = 0; i<maxidx; i++){
				vector<int> temp;
				for(int j = maxidx; j<n; j++){
					temp.push_back(p[j]);
				}
				for(int j = maxidx-1; j>=i; j--){
					temp.push_back(p[j]);
				}
				for(int j = 0; j<i; j++){
					temp.push_back(p[j]);
				}
				bool replace = false;
				for(int j = 0; j<n; j++){
					if(temp[j]==ans[j]){
						continue;
					} else if(temp[j]>ans[j]){
						replace = true;
						break;
					} else {
						break;
					}
				}
				if(replace){
					for(int j = 0; j<n; j++){
						ans[j] = temp[j];
					}
				}
			}
			for(int i = 0; i<=maxidx; i++){
				vector<int> temp;
				for(int j = maxidx+1; j<n; j++){
					temp.push_back(p[j]);
				}
				for(int j = maxidx; j>=i; j--){
					temp.push_back(p[j]);
				}
				for(int j = 0; j<i; j++){
					temp.push_back(p[j]);
				}
				bool replace = false;
				for(int j = 0; j<n; j++){
					if(temp[j]==ans[j]){
						continue;
					} else if(temp[j]>ans[j]){
						replace = true;
						break;
					} else {
						break;
					}
				}
				if(replace){
					for(int j = 0; j<n; j++){
						ans[j] = temp[j];
					}
				}
			}
		} else if(maxidx==0&&n==1){
			ans = p;
		}
		for(int anss : ans){
			cout<<anss<<" ";
		}
		cout<<"\n";
	}
	return 0;
}