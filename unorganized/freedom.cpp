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
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		int item;
		cin>>item;
		a[i] = item;
	}

    int answer = 0;
    map<int,int>m;
    for(auto &ele : a) {
        if(ele-1!=0&&((3*ele)%(ele-1))==0) answer += m[(3*ele)/(ele-1)];
        if(ele-1!=0&&((3*ele)%(ele-1))==0) m[(3*ele)/(ele-1)]++;
    }
    cout << answer << "\n";
}
	return 0;
}