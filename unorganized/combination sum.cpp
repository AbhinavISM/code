#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
class Solution {
public:
	void rec(vector<int> &candidates, int i, int n, int target,
	 vector<int> combination, vector<vector<int>> &ans){
		if(target==0){
			ans.push_back(combination);
			return;
		} else if(target<0||i>=n){
			return;
		}
		rec(candidates, i+1, n, target, combination, ans);
		combination.push_back(candidates[i]);
		rec(candidates, i, n, target - candidates[i], combination, ans);
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        rec(candidates, 0, candidates.size(), target, vector<int>(), ans);
        return ans;
    }
};
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	int target;
	cin>>target;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	dpeek(Solution().combinationSum(a,target));
}
