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
	void rec(vector<int> &nums, int i, int n, vector<int> subset, vector<vector<int>>&ans){
		if(i==n) {ans.push_back(subset); return;}
		int idx = i+1;
		while(idx<n&&nums[idx]==nums[i]) idx++;
		rec(nums, idx, n, subset, ans);
		subset.push_back(nums[i]);
		rec(nums, i+1, n, subset, ans);
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        rec(nums, 0, nums.size(), vector<int>(), ans);
        return ans;
    }
};
int32_t main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
}
	return 0;
}