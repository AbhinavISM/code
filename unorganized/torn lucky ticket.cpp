#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int customcnt(vector<int>& l3, int val){
	return upper_bound(l3.begin(), l3.end(), val) - lower_bound(l3.begin(), l3.end(), val);
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<int> l1;
	vector<int> l2;
	vector<int> l3;
	vector<int> l4;
	vector<int> l5;
	vector<string> array(n);
	vector<int> sum(n);
	for(int i = 0; i<n; i++){
		string item;
		cin>>item;
		int digsum = 0;
		for(int j = 0; j<item.length(); j++){
			digsum += (item[j] - 48);
		}
		if(item.length()==1){
			l1.push_back(digsum);
		} else if(item.length()==2){
			l2.push_back(digsum);
		} else if(item.length()==3){
			l3.push_back(digsum);
		} else if(item.length()==4){
			l4.push_back(digsum);
		} else if(item.length()==5){
			l5.push_back(digsum);
		}
		array[i] = item;
		sum[i] = digsum;
	}
	
	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());
	sort(l3.begin(), l3.end());
	sort(l4.begin(), l4.end());
	sort(l5.begin(), l5.end());

	int ans = 0;
	for(int i = 0; i<n; i++){
		if(array[i].length()==1){
			ans += upper_bound(l1.begin(), l1.end(), sum[i]) - lower_bound(l1.begin(), l1.end(), sum[i]);
		} else if(array[i].length()==2){
			int val = sum[i];
			ans += upper_bound(l2.begin(), l2.end(), val) - lower_bound(l2.begin(), l2.end(), val);
		} else if(array[i].length()==3){
			int val = sum[i];
			ans += upper_bound(l3.begin(), l3.end(), val) - lower_bound(l3.begin(), l3.end(), val);
			val-=(array[i][array[i].length()-1] - 48);
			ans += upper_bound(l1.begin(), l1.end(), val - (array[i][array[i].length()-1] - 48)) - lower_bound(l1.begin(), l1.end(), val - (array[i][array[i].length()-1] - 48));
			
			val = sum[i];
			val-=(array[i][0] - 48);
			ans += upper_bound(l1.begin(), l1.end(), val - (array[i][0] - 48)) - lower_bound(l1.begin(), l1.end(), val - (array[i][0] - 48));

		} else if(array[i].length()==4){
			int val = sum[i];
			ans += customcnt(l4,val);
			val-=(array[i][array[i].length()-1] - 48);
			ans += customcnt(l2, val - (array[i][array[i].length()-1] - 48));
			val = sum[i];
			val-=(array[i][0] - 48);
			ans += customcnt(l2, val - (array[i][0] - 48));
		} else {
			int val = sum[i];
			ans += customcnt(l5, val);
			val-=(array[i][array[i].length()-1] - 48);
			ans += customcnt(l3, val - (array[i][array[i].length()-1] - 48));
			val-=(array[i][array[i].length()-2] - 48);
			ans += customcnt(l1, val - (array[i][array[i].length()-1] - 48) - (array[i][array[i].length()-2] - 48));

			val = sum[i];
			val-=(array[i][0] - 48);
			ans += customcnt(l3, val - (array[i][0] - 48));
			val-=(array[i][1] - 48);
			ans += customcnt(l1, val - (array[i][0] - 48) - (array[i][1] - 48));
		}
		// cout<<ans<<"\n";
	}
	cout<<ans;

	return 0;
}