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
	while(t--){
	int n,x;
	cin>>n>>x;
	//base cases
	if(x>n){
		cout<<-1<<"\n";
		continue;
	}
	if(x==n){
		cout<<n<<"\n";
		continue;
	}
	if((n&x)!=x){
		cout<<-1<<"\n";
		continue;
	}

	//way 1 (CORRECT)
	// bitset<64> nbits(n);
	// bitset<64> xbits(x);
	
	// bool bad = false;
	// int idx;
	// for(int i = 63; i>=0; i--){
	// 	if(nbits.test(i)==1&&xbits.test(i)==0){
	// 		idx = i;
	// 		break;
	// 	}
	// }
	// for(int i = 0; i<idx; i++){
	// 	if(xbits.test(i)==1){
	// 		bad = true;
	// 	}
	// }
	// if(bad){
	// 	cout<<-1<<"\n";
	// 	continue;
	// }
	// int sum = 0;
	// for(int i = 0; i<=idx; i++){
	// 	sum += ((int)nbits.test(i))*(1ll<<i);
	// }
	// int cost = (1ll<<(idx+1)) - sum;
	// if((n&(n+cost))==x)cout<<n+cost<<"\n";
	// else cout<<-1<<"\n";

	//way 2 using binary search (CORRECT TOO)
	int lo = n+1;
	int hi = 5000000000000000000ll;
	int ans = 5000000000000000001ll;
	bitset<64> nbits(n);
	while(hi>=lo){
		int m = lo + (hi-lo)/2;

		//errichto way to calculate rangeAndFromNtoM
		// int rangeAndFromNtoM = 0;
		// for(int i = 63; i>=0; i--){
		// 	if((m&(1ll<<i))!=(n&(1ll<<i))){
		// 		break;
		// 	} else {
		// 		rangeAndFromNtoM |= (m&(1ll<<i));
		// 	}
		// }

		//my way to calculate rangeAndFromNtoM
		int rangeAndFromNtoM = 0;
		bitset<64> mbits(m);
		int idx;
		for(int i = 63; i>=0; i--){
			if(mbits.test(i)==1&&nbits.test(i)==0){
				idx = i;
				break;
			}
		}
		for(int i = idx + 1; i<=63; i++){
			if((mbits.test(i)&&nbits.test(i))){
				rangeAndFromNtoM += ((int)mbits.test(i))*(1ll<<i);
			}
		}

		if(rangeAndFromNtoM==x){
			hi = m - 1;
			ans = min(ans,m);
		} else if(rangeAndFromNtoM<x){
			hi = m - 1;
		} else {
			lo = m + 1;
		}
	}
	if(ans==5000000000000000001ll) cout<<-1<<"\n";
	else cout<<ans<<"\n";
}
	return 0;
}