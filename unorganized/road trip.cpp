#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	string s;
	std::getline(std::cin, s);
	int n = s.length();
	vector<int> dis;
	for(int i = 0; i<n; i++){
		if(s[i]==','){
			string f = "";
			i++;
			while(s[i]!=';'){
				f += s[i];
				i++;
			}
			dis.push_back(stoi(f));
		}
	}
	sort(dis.begin(), dis.end());
	vector<int> ans;
	ans.push_back(dis[0]);
	for(int i = 1; i<dis.size(); i++){
		ans.push_back(dis[i] - dis[i-1]);
	}
	for(int i = 0; i<ans.size(); i++){
		if(i!=ans.size()-1)cout<<ans[i]<<",";
		else cout<<ans[i];
	}
	return 0;
}