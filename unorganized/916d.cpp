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
	vector<pair<int,int>> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = {item,i};
	}
	vector<pair<int,int>> b(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		b[i] = {item,i};
	}
	vector<pair<int,int>> c(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		c[i] = {item,i};
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	int maxi = 0;
	int f1;
	int f2;
	for(int i = n-1; i>=0; i--){
		int sum = 0;
		sum += a[i].first;
		f1 = a[i].second;
		for(int j = n-1; j>=0; j--){
			if(b[j].second!=f1){
				sum += b[j].first;
				f2 = b[j].second;
				break;
			}
		}
		for(int j = n-1; j>=0; j--){
			if(c[j].second!=f1&&c[j].second!=f2){
				sum += c[j].first;
				break;
			}
		}
		maxi = max(sum, maxi);

		sum = 0;
		sum += a[i].first;
		f1 = a[i].second;
		for(int j = n-1; j>=0; j--){
			if(c[j].second!=f1){
				sum += c[j].first;
				f2 = c[j].second;
				break;
			}
		}
		for(int j = n-1; j>=0; j--){
			if(b[j].second!=f1&&b[j].second!=f2){
				sum += b[j].first;
				break;
			}
		}
		maxi = max(sum, maxi);
		
	}
	cout<<maxi<<"\n";
}
	return 0;
}