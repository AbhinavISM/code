#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

//DSU
vector<int> par(1000001);
vector<int> rnk(1000001);
vector<set<int, greater<int>>> tenLargest(1000001, set<int, greater<int>>()); 
void make_set(int n){
    for(int i = 0; i<=n; i++){
        par[i] = i;
        rnk[i] = 1;
        tenLargest[i].insert(i);
    }
}
int find_set(int a){
    if(par[a]==a){
        return a;
    }
    par[a] = find_set(par[a]);
    return par[a];
}

void union_set(int a, int b){
    int p1 = find_set(a);
    int p2 = find_set(b);
    if(p1==p2){
        return;
    }
    if(rnk[p1]>=rnk[p2]){
        par[p2] = p1;
        rnk[p1] += rnk[p2];
        for(int it : tenLargest[p2]){
        	tenLargest[p1].insert(it);
        	if(tenLargest[p1].size()>10) tenLargest[p1].erase(--tenLargest[p1].end());
        }
    } else {
        par[p1] = p2;
        rnk[p2] += rnk[p1];
        for(int it : tenLargest[p1]){
        	tenLargest[p2].insert(it);
        	if(tenLargest[p2].size()>10) tenLargest[p2].erase(--tenLargest[p2].end());
        }
    }
}

int32_t main(){
	fast_io;
	int n,q;
	cin>>n>>q;
	make_set(n);
	for(int i = 0; i<q; i++){
		int type;
		cin>>type;
		if(type==1){
			int u,v;
			cin>>u>>v;
			union_set(u,v);
		} else {
			int v,k;
			cin>>v>>k;
			int parent = find_set(v);
			if(tenLargest[parent].size()<k){
				cout<<-1<<"\n";
			} else {
				int ans;
				int i = 0;
				for(int it : tenLargest[parent]){
					ans = it;
					i++;
					if(i==k) break;
				}
				cout<<ans<<"\n";
			}
		}
	}

	return 0;
}