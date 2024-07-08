#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
class Node{
public:
	int f;
	vector<Node*> children;
	Node(){
		f = 0;
		children = vector<Node*>(10,NULL);
	}
};
int noOfPossibleWords(int n, vector<string> arr, string s){
	map<int,int> chartoint;
	chartoint['a'] = 2;
	chartoint['b'] = 2;
	chartoint['c'] = 2;
	chartoint['d'] = 3;
	chartoint['e'] = 3;
	chartoint['f'] = 3;
	chartoint['g'] = 4;
	chartoint['h'] = 4;
	chartoint['i'] = 4;
	chartoint['j'] = 5;
	chartoint['k'] = 5;
	chartoint['l'] = 5;
	chartoint['m'] = 6;
	chartoint['n'] = 6;
	chartoint['o'] = 6;
	chartoint['p'] = 7;
	chartoint['q'] = 7;
	chartoint['r'] = 7;
	chartoint['s'] = 7;
	chartoint['t'] = 8;
	chartoint['u'] = 8;
	chartoint['v'] = 8;
	chartoint['w'] = 9;
	chartoint['x'] = 9;
	chartoint['y'] = 9;
	chartoint['z'] = 9;
	Node* root = new Node();
	for(string contact : arr){
		auto temp = root;
		for(char c : contact){
			if(temp->children[chartoint[c]]==NULL) temp->children[chartoint[c]] = new Node();
			temp = temp->children[chartoint[c]];
		}
		temp->f++;
	}
	for(char c : s){
		if(root->children[c-'0']==NULL) {
			return 0;
		}
		root = root->children[c-'0'];
	}
	return root->f;
}
int32_t main(){
	fast_io;
	int n;
	cin>>n;
	vector<string> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	string s;
	cin>>s;
	cout<<noOfPossibleWords(n,arr,s);
}