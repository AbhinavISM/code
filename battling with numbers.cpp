#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> A(2000001,-1);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		A[item] = 0;
	}
	int j = 0;
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		while(A[j]!=0){
			j++;
		}
		A[j] = item;
		j++;
	}
	int m;
	cin>>m;
	vector<int> C(2000001,-1);
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		C[item] = 0;
	}
	j = 0;
	for(int i = 0; i<m; i++){
		int item;
		cin>>item;
		while(C[j]!=0){
			j++;
		}
		C[j] = item;
		j++;
	}
	int ans = 1;
	for(int i = 0; i<2000001; i++){
		if(A[i]==-1&&C[i]!=-1){
			ans = 0;
			break;
		}
		if(A[i]!=-1&&C[i]!=-1){
			if(A[i]>C[i]){
				ans*=2;
				ans%=998244353;
			} else if(A[i]<C[i]){
				ans = 0;
				break;
			}
		}
		if(A[i]!=-1&&C[i]==-1){
			ans*=2;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}