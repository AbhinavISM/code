#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x;cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

string solution(vector<string> commands){
	vector<string> file;
	for(string command : commands){
		if(command=="cd /"){
			file = vector<string>();
		} else if(command=="cd .."){
			if(file.size()>0) file.pop_back();
		} else if(command=="cd ."){
			//do nothing
		} else {
			string f = "";
			for(int i = 3; i<command.length(); i++){
				f.push_back(command[i]);
			}
			file.push_back(f);
		}
	}
	string ans = "";
	for(string f : file){
		ans.push_back('/');
		ans += f;
	}
	if(ans=="") return "/";
	return ans;
}
int32_t main(){
	fast_io;
	vector<string> commands = {"cd users", "cd .", "cd admin", "cd /", "cd volumes"};
	peek(solution(commands))
}