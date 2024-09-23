#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

vector<string> solution(vector<string> operations){
	vector<string> fans;
	vector<string> ans;
	vector<string> done;
	for(string op : operations){
		if(op[0]=='B'){
			if(ans.size()>0) {
				char popped = ans.back().back();
				if(ans.back().size()==0){
					ans.pop_back();
					done.push_back(op + "d" + popped);
				} else {
					ans.back().pop_back();
					done.push_back(op + "p" + popped);
				}
			}
		}  else if(op[0]=='I'){
			string f = "";
			for(int i = 7; i<op.length(); i++){
				f.push_back(op[i]);
			}
			ans.push_back(f);
			done.push_back(op);
		}else if(op[0]=='U'){
			if(done.size()>0) {
				string undoop = done.back();
				done.pop_back();
				if(undoop[0] == 'B'){
					if(undoop[9]=='p'){						
						ans.back().push_back(undoop.back());
					} else {
						ans.push_back("" + undoop.back());
						// ans.back().push_back(undoop.back());
					}
				} else if(undoop[0] == 'I'){
					ans.pop_back();
				}
			}
		}
		string thisans = "";
		for(string a : ans){
			thisans += a;
		}
		fans.push_back(thisans);
		peek(ans)
		peek(done)
		peek(fans)
	}
	return fans;
}
int32_t main(){
	fast_io;
	// vector<string> operations = {"INSERT Code", "INSERT Signal", "BACKSPACE", "UNDO"};
	// vector<string> operations = {"INSERT co", "INSERT d", "UNDO", "BACKSPACE", "UNDO", "INSERT ding"};
	vector<string> operations = {
		"INSERT a", "BACKSPACE", "BACKSPACE", "UNDO", "UNDO",
		 "INSERT b", "UNDO", "BACKSPACE", "UNDO"};
	peek(solution(operations))
}