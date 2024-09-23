#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	vector<bool> isPrime(100001, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i<100001; i++){
		if(isPrime[i]){
			for(int j = i*i; j<=100001; j+=i){
				isPrime[j] = false;
			}
		}
	}
	vector<int> primes;
	for(int i = 2; i<100001; i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n);
	unordered_map<int,int> primecnt;
	bool found = false;
	for(int k = 0; k<n; k++){
		cin>>a[k];
	}
	for(int k = 0; k<n; k++){
		int x = a[k];
		for(int i = 0; i<primes.size()&&primes[i]*primes[i]<=x; i++){
			int p = primes[i];
			if(x%p==0){
				while(x%p==0){
					x/=p;
				}
				primecnt[p]++;
			}
		}
		if(x!=1){
			primecnt[x]++;
		}
	}
	for(auto p:primecnt){
        if(p.second>1){
            found=true;
            break;
        }
    }
	if(found){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
	return 0;
}