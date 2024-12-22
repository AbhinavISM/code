#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(auto i:v) {for(auto j:i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
//ordered_set s;
//s.order_of_key(key) -> number of elements smaller than key in set
//*s.find_by_order(idx) -> element at index idx in set
vector<int> solution2(vector<string> commands){
	//cp ls mv
	int cp = 0;
	int ls = 0;
	int mv = 0;
	for(string &c : commands){
		if(c=="cp") cp++;
		else if(c=="ls") ls++;
		else if(c=="mv") mv++;
		else {
			int idx = c[1] - '0';
			c = commands[idx-1];
			if(c=="cp") cp++;
			else if(c=="ls") ls++;
			else if(c=="mv") mv++;
		}
	}
	return {cp, ls, mv};
}

void swapRows(vector<vector<int>>& matrix, int row1, int row2) {
    swap(matrix[row1], matrix[row2]);
}

void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {
    int rows = matrix.size();
    for (int i = 0; i < rows; ++i) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

void reverseRow(vector<vector<int>>& matrix, int row) {
    reverse(matrix[row].begin(), matrix[row].end());
}

void reverseColumn(vector<vector<int>>& matrix, int col) {
    int rows = matrix.size();
    for (int i = 0; i < rows / 2; ++i) {
        swap(matrix[i][col], matrix[rows - 1 - i][col]);
    }
}

void rotateClockwise(vector<vector<int>>& matrix) {
    int m = matrix.size();     // number of rows
    int n = matrix[0].size();  // number of columns
    vector<vector<int>> rotated(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][m - 1 - i] = matrix[i][j];
        }
    }
    matrix = rotated;
}

vector<vector<int>> solution3(vector<vector<int>> matrix, vector<string> commands){
	for(string c : commands){
		stringstream ss1(c);
		vector<string> input;
		string element;
		while (ss1 >> element) {
		    input.push_back(element);
		}
		if(input[0]=="swapRows"){
			int a = stoi(input[1]);
			int b = stoi(input[2]);
			swapRows(matrix, a, b);
		}
		if(input[0]=="swapColumns"){
			int a = stoi(input[1]);
			int b = stoi(input[2]);
			swapColumns(matrix, a, b);
		}
		if(input[0]=="reverseRow"){
			int a = stoi(input[1]);
			reverseRow(matrix, a);
		}
		if(input[0]=="reverseColumn"){
			int a = stoi(input[1]);
			reverseColumn(matrix, a);
		}
		if(input[0]=="rotate90Clockwise"){
			rotateClockwise(matrix);
		}
	}
	return matrix;
}
int32_t main(){
	fast_io;
	int n, m;
	cin>>n>>m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>matrix[i][j];		
		}	
	}
	int k; cin>>k;
	cin.ignore();
	vector<string> commands(k);
	for(int i = 0; i<k; i++){
		getline(cin, commands[i]);
	}
	dpeek(solution3(matrix, commands));
}