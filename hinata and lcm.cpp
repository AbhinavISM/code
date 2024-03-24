#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
struct primeData {
	int count;
	int mini;
	int secondmin;
};
int32_t main(){
	fast_io;

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

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	map<int,primeData> primeMap;
	for(int k = 0; k<n; k++){
		int x = a[k];
		for(int i = 0; i<primes.size()&&primes[i]*primes[i]<=x; i++){
			int p = primes[i];
			int pf = 0;
			if(x%p==0){
				while(x%p==0){
					pf++;
					x/=p;
				}
				if(primeMap.find(p)==primeMap.end()){
					primeMap[p] = {0,INT_MAX,INT_MAX};
				}
				primeMap[p].count++;
				if(pf<=primeMap[p].mini){
					primeMap[p].secondmin = primeMap[p].mini;
					primeMap[p].mini = pf;
				} else if(pf<primeMap[p].secondmin&&pf>primeMap[p].mini){
					primeMap[p].secondmin = pf;
				}
			}
		}
		if(x!=1){
			int p=x;
			int pf = 1;
			if(primeMap.find(p)==primeMap.end()){
				primeMap[p] = {0,INT_MAX,INT_MAX};
			}
			primeMap[p].count++;
			if(pf<=primeMap[p].mini){
				primeMap[p].secondmin = primeMap[p].mini;
				primeMap[p].mini = pf;
			} else if(pf<primeMap[p].secondmin&&pf>primeMap[p].mini){
				primeMap[p].secondmin = pf;
			}
		}
	}
	int ans = 1;
	for(auto it : primeMap){
		int p = it.first;
		int pcnt = it.second.count;
		int pmini = it.second.mini;
		int psmini = it.second.secondmin;
		if(pcnt<n-1){
			continue;
		}
		if(pcnt==n-1){
			psmini = pmini;
		}
		while(psmini>0){
			ans *= p;
			psmini--;
		}
	}
	cout<<ans;
}