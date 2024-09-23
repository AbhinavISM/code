#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	vector<vector<int>> grid(9, vector<int> (9));
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			cin>>grid[i][j];
		}
	}
	int row = true;
	int col = true;
	int smol = true;
	for(int i = 0; i<9; i++){
		vector<bool> freq(10,false);
		for(int j = 0; j<9; j++){
			if(freq[grid[i][j]]){
				row = false;
			} else {
				freq[grid[i][j]] = true;
			}
		}
	}
	if(!row){
		// cout<<"row";
		cout<<"No";
		return 0;
	}
	for(int i = 0; i<9; i++){
		vector<bool> freq(10,false);
		for(int j = 0; j<9; j++){
			if(freq[grid[j][i]]){
				col = false;
			} else {
				freq[grid[j][i]] = true;
			}
		}
	}
	if(!col){
		// cout<<"col";
		cout<<"No";
		return 0;
	}
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			vector<bool> freq(10,false);
			for(int k = j*3; k<(j+1)*3; k++){
				for(int l = i*3; l<(i+1)*3; l++){
					if(freq[grid[k][l]]){
						smol = false;
					} else {
						freq[grid[k][l]] = true;
					}
				}
			}
		}
	}
	if(!smol){
		// cout<<"smol";
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}