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
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int ui,vi;
        cin>>ui>>vi;
        edges[ui].push_back(vi);
        edges[vi].push_back(ui);
    }
    if(n==1){
        cout<<0<<endl;
        continue;
    }
    int a = 1;
    for(int i = 1; i<=n; i++){
        if ((edges[i].size()) > 2)a += edges[i].size()-2;
    }
    a = (a/2) + 1;
    cout<<a<<"\n";
}
	return 0;
}