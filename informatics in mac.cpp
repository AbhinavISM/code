#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;

int mexi(vector<int> arr)
{
sort(arr.begin(), arr.end());
int mex = 0;
for (int idx = 0; idx < arr.size(); idx++)
{
	if (arr[idx] == mex){
		mex += 1;
	}
}
return mex;
}
void solution(vector<int> a, int n, int mymex){
	multiset<int> ms;
	int mex = 0;
	for(int i = 0; i<n-1; i++){
		ms.insert(a[i]);
		if(a[i]==mex){
			for(int j = mex+1; j<=n; j++){
				if(ms.find(j)==ms.end()){
					mex = j;
					break;
				}
			}
		}
		if(mex==mymex){
			vector<int> tmp;
			for(int j = i+1; j<n; j++){
				tmp.push_back(a[j]);
			}
			if(mexi(tmp)==mymex){
				cout<<2<<"\n";
				cout<<1<<" "<<i+1<<"\n";
				cout<<i+2<<" "<<n<<"\n";
				return;	
			} else {
				cout<<-1<<"\n";
				return;
			}
		}
	}
	cout<<-1<<"\n";
}
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}
	int mymex = mexi(a);
	solution(a,n,mymex);
}
	return 0;
}