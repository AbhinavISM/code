#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int gcd(int x, int y){
	if(y%x==0){
		return x;
	}
	return gcd(y%x, x);
}
int lcm(int x, int y){
	return (x*y)/__gcd(x,y);
}
void solve(){
	int n;
	cin>>n;
	vector<int> divisors(n);
	vector<bool> marked(1000001,false);
	vector<bool> found(1000001, false);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		divisors[i] = item;
		found[item] = true;
	}
	sort(divisors.begin(), divisors.end());
	int checku = divisors[0]*divisors[n-1];
	for(int i = 1; i<n-1; i++){
		if(checku!=divisors[i]*divisors[n-i-1]){
			cout<<-1<<"\n";
			return;
		}
	}
	vector<int> toFindLcm;
	int smallestDivisorEver = INT_MAX;
	for(int i = n-1; i>=0; i--){
		if(marked[divisors[i]]==false){
			for(int j = 2; j*j<=divisors[i]; j++){
				if(divisors[i]%j==0){
					smallestDivisorEver = min(smallestDivisorEver, j);
					if(found[j]==false){
						cout<<-1<<"\n";
						return;
					}
					marked[j] = true;
					if(found[divisors[i]/j]==false){
						cout<<-1<<"\n";
						return;
					}
					marked[divisors[i]/j] = true;
					smallestDivisorEver = min(smallestDivisorEver, divisors[i]/j);
				}
			}
		}
	}
	for(int i = 0; i<n; i++){
		if(marked[divisors[i]]==false){
			toFindLcm.push_back(divisors[i]);
		}
	}
	int finalLcm = 1;
	for(int findlcm : toFindLcm){
		finalLcm = lcm(finalLcm, findlcm);
	}
	if(toFindLcm.size()==1){
		if(smallestDivisorEver==INT_MAX){
			finalLcm = finalLcm*finalLcm;
		} else {
			finalLcm = finalLcm*smallestDivisorEver;
		}
	}
	cout<<finalLcm<<"\n";
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