#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
using namespace std;
int32_t main(){
	fast_io;
	string time;
	cin>>time;
	int hour = 0;
	int minute = 0;
	bool foundcolon = false;
	int factor = 10;
	for(int i = 0; i<time.length(); i++){
		if(time[i]==':'){
			foundcolon = true;
			factor = 10;
			continue;
		}
		if(!foundcolon){
			hour+=(time[i]-48)*factor;
			factor = 1;
		} else {
			minute += (time[i]-48)*factor;
			factor = 1;
		}
	}
	bool ispalindrome = true;
	for(int i = 0; i<2; i++){
		if(time[i]!=time[4-i]){
			ispalindrome = false;
		}
	}
	int ans = 0;
	while(!ispalindrome){
		minute++;
		ans++;
		if(minute>=60){
			hour++;
			minute%=60;
		}
		if(hour>=24){
			hour%=24;
		}
		char s0 = (char)(48 + (hour/10)%10);
		char s1 = (char)(48 + (hour%10));
		char s2 = ':';
		char s3 = (char)(48 + (minute/10)%10);
		char s4 = (char)(48 + (minute%10));
		time = "";
		time += s0;
		time += s1;
		time += s2;
		time += s3;
		time += s4;
		ispalindrome = true;
		for(int i = 0; i<2; i++){
			if(time[i]!=time[4-i]){
				ispalindrome = false;
			}
		}
	}
	cout<<ans;
	return 0;
}