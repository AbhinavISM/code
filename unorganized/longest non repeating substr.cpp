#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;
// abcdbe
int bruteForce(int n, string str){
	int maxLength = 0;
	for(int i = 0; i<n; i++){
		vector<int> charFrequency(26, 0);
		int currMaxLength = 0;
		for(int j = i; j<n; j++){
			if(charFrequency[str[j] - 'a']>0){
				break;
			}
			charFrequency[str[j] - 'a']++;
			currMaxLength = (j - i + 1);
		}
		maxLength = max(maxLength, currMaxLength);
	}
	return maxLength;
}

int optimizedApproach(int n, string str){
	int maxLength = 0;
	int i = 0; int j = 0;
	vector<int> lastOccurence(26, -1);
	while(i<n){
		int currMaxLength = (j-i+1);
		while(j<n){
			if(lastOccurence[str[j] - 'a']!=-1){
				i = lastOccurence[str[j] - 'a'];
				break;
			}
			lastOccurence[str[j] - 'a'] = j;
			currMaxLength = (j-i+1);
			j++;
		}
		i++;
		maxLength = max(maxLength, currMaxLength);
	}
	return maxLength;
}

int32_t main(){
	fast_io;
	string str;
	cin>>str;
	int n = str.length();
	cout<<optimizedApproach(n,str);
	return 0;
}