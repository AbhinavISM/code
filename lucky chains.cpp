#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	vector<bool> isPrime(10000001, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i<10000001; i++){	
		if(isPrime[i]){
			for(int j = i*i; j<=10000001; j+=i){
				isPrime[j] = false;
			}
		}
	}
	vector<int> primes;
	for(int i = 2; i<10000001; i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	// cout<<primes.size();
	int t;
	cin>>t;
	while(t--){
	int x,y;
	cin>>x>>y;
	int ans = INT64_MAX;
	int temp = abs(x-y);
	for(int p : primes){
		if(p*p>temp){
			break;
		}
		if(temp%p==0){
			if(x%p!=0) ans = min(ans,(p-(x%p)));
			else {ans = 0;break;}
			while(temp%p==0){
				temp/=p;
			}
		}
	}
	if(temp!=1){
		int p = temp;
		if(x%p!=0) ans = min(ans,(p-(x%p)));
		else {ans = 0;}
	}
	if(ans!=INT64_MAX)cout<<ans<<"\n";
	else cout<<-1<<"\n";
}
	return 0;
}