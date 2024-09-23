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
	Node* next;
	int val;
	Node(int val){
		this->val = val;
	}
};

int32_t main(){
	fast_io;
	int x,y;
	cin>>x>>y;
	if(x==0){
		cout<<y;
		return 0;
	}
	if(y==0){
		cout<<x;
		return 0;
	}
	int tempx = x;
	int tempy = y;
	Node* xlist = new Node(tempx%10);
	tempx = tempx/10;
	Node* ylist = new Node(tempy%10);
	tempy = tempy/10;
	Node* xmover = xlist;
	Node* ymover = ylist;
	while(tempx>0){
		int digit = tempx%10;
		xmover->next = new Node(digit);
		xmover = xmover->next;
		tempx /= 10;
	}
	while(tempy>0){
		int digit = tempy%10;
		ymover->next = new Node(digit);
		ymover = ymover->next;
		tempy /= 10;
	}
	// cout<<xmover->val<<" ";
	// cout<<tempx<<" "<<tempy<<"\n";
	int carry = 0;
	string xysum = "";
	int cnt = 2;
	while(xlist!=NULL&&ylist!=NULL&&cnt){
		cnt--;
		int partSum = 0;
		partSum += xlist->val;
		partSum += ylist->val;
		partSum += carry;
		int newval = partSum%10;
		carry = partSum/10;
		xysum = (((char)(newval + '0')) + xysum);
		cout<<xysum<<" ";
		xlist = xlist->next;
		ylist = ylist->next;
		cout<<xlist->val;
	}
	while(xlist!=NULL){
		int partSum = 0;
		partSum += xlist->val;
		partSum += carry;
		int newval = partSum%10;
		carry = newval/10;
		xysum = (((char)(newval + '0')) + xysum);
		xlist = xlist->next;
	}
	while(ylist!=NULL){
		int partSum = 0;
		partSum += ylist->val;
		partSum += carry;
		int newval = partSum%10;
		carry = newval/10;
		xysum = (((char)(newval + '0')) + xysum);
		ylist = ylist->next;
	}
	cout<<xysum;
	return 0;
}