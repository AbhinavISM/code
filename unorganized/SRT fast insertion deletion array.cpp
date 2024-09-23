#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;

class SRT {
	vector<deque<int>> arr;
	int size;
	int sqrtsize;
public:

	SRT(int size, vector<int>& elements){
		this->size = size;
		int tmptr = 0;
		this->sqrtsize = sqrt(size);
		for(int i = 0; i<=sqrtsize; i++){
			deque<int> tmp;
			for(int j = 0; j<=sqrtsize; i++){
				if(tmptr>=size){
					break;
				}
				tmp.push_back(elements[tmptr]);
				tmptr++;
			}
			this->arr.push_back(tmp);
		}
	}
	int getElement(int idx){

	}
	int getSize(){
		return size;
	}
	void insert(int idx, int val){

	}
	void remove(int idx){

	}
	void show(){

	}
};

int32_t main(){
	fast_io;
	return 0;
}