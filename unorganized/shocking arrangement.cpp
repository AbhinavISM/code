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
	int n;
	cin>>n;
	multiset<int, greater<int>> pos;
	multiset<int> neg;
	int maxi = INT64_MIN;
	int mini = INT64_MAX;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		if(item>=0) pos.insert(item);
		else neg.insert(item);
		maxi = max(maxi, item);
		mini = min(mini, item);
	}
	if(pos.size()==n){
		cout<<"No\n";
		continue;
	}
	int val = maxi - mini;
	vector<int> ans;
	int sum = 0;
	for(int i = 0; i<n&&pos.size()>0&&neg.size()>0; i++){
		if(sum + *pos.begin() < val){
			ans.push_back(*pos.begin());
			sum += *pos.begin();
			pos.erase(pos.begin());
		} else {
			ans.push_back(*neg.begin());
			sum += *neg.begin();
			neg.erase(neg.begin());
		}
	}
	if(pos.size()>0){
		for(int p : pos){
			sum+=p;
			ans.push_back(p);
		}
	}
	if(neg.size()>0){
		for(int n : neg){
			sum+=n;
			ans.push_back(n);
		}
	}
	bool good = true;
	bool lastpos;
	if(ans[n-1]>=0){
		lastpos = true;
	} else {
		lastpos = false;
	}
	int newsum = 0;
	for(int i = n-1; i>=0; i--){
		if(lastpos){
			if(ans[i]>=0){
				newsum += abs(ans[i]);
			} else {
				break;
			}
		} else {
			if(ans[i]<0){
				newsum += abs(ans[i]);
			} else {
				break;
			}
		}
	}
	if(newsum>=val){
		good = false;
	}
	if(good){
		cout<<"Yes\n";
		peek(ans)
	} else {
		cout<<"No\n";
		peek(ans)
	}
	// int sum = 0;
	// bool inc = true;
	// for(int i = 0; i<n; i++){
	// 	if(pos.size()==0||neg.size()==0){
	// 		break;
	// 	}
	// 	if(inc&&sum+*pos.begin()<0){
	// 		sum += *pos.begin();
	// 		ans.push_back(*pos.begin());
	// 		pos.erase(pos.begin());
	// 	} else if(inc){
	// 		sum = *neg.begin();
	// 		ans.push_back(*neg.begin());
	// 		neg.erase(neg.begin());
	// 		inc = false;
	// 	}
	// 	if((!inc)&&abs(sum+*neg.begin())<val){
	// 		sum += *neg.begin();
	// 		ans.push_back(*neg.begin());
	// 		neg.erase(neg.begin());
	// 	} else if((!inc)){
	// 		sum = *pos.begin();
	// 		ans.push_back(*pos.begin());
	// 		pos.erase(pos.begin());
	// 		inc = true;
	// 	}
	// }
	// int sum2 = 0;
	// if(pos.size()>0){
	// 	for(int p : pos){
	// 		sum+=p;
	// 		sum2+=p;
	// 		ans.push_back(p);
	// 	}
	// }
	// if(neg.size()>0){
	// 	for(int n : neg){
	// 		sum+=n;
	// 		sum2+=n;
	// 		ans.push_back(n);
	// 	}
	// }
	// if(abs(sum)>=val||abs(sum2)>=val){
	// 	cout<<"NO\n";
	// } else {
	// 	cout<<"YES\n";
		// peek(ans)
	// }
}
	return 0;
}