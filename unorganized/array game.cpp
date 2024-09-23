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
	int k;
	cin>>k;
	vector<int> array;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		array.push_back(item);
	}
	if(k>=3){
		cout<<0<<"\n";
	}
	else if(k==1){
		int ans = INT64_MAX;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				ans = min(ans, abs(array[i] - array[j]));
			}
		}
		array.push_back(ans);
		ans = INT64_MAX;
		for(int i = 0; i<=n; i++){
			ans = min(ans, array[i]);
		}
		cout<<ans<<"\n";
	}
	else if(k==2){
		sort(array.begin(), array.end());
		int ans = INT64_MAX;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				// ans = min(ans, abs(array[i] - array[j]));
				int mval1 = abs(array[i] - array[j]);
				int mindiff = INT64_MAX;
				int l = 0;
				int r = n-1;
				while(r-l>=3){
					int m1 = l + (r - l) / 3;
        			int m2 = r - (r - l) / 3;
        			int f1 = abs(array[m1] - mval1);
        			int f2 = abs(array[m2] - mval1);
        			if (f1 < f2){
			            r = m2;
        			}
			        else{
			            l = m1;
			        }
				}
				for(int k = l; k<=r; k++){
					mindiff = min(mindiff, abs(array[k] - mval1));
				}
				ans = min({ans, mindiff, mval1});
			}
		}
		array.push_back(ans);
		ans = INT64_MAX;
		for(int i = 0; i<=n; i++){
			ans = min(ans, array[i]);
		}
		cout<<ans<<"\n";
	}
}
	return 0;
}