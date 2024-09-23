#include<bits/stdc++.h>
#define int long long
#define ld long double
#define fast_io  ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
#define peek(v) for(auto x:v) cout<<x<<" ";cout<<"\n";
#define dpeek(v) for(vector<int> i : v) {for(int j : i){ cout<<j<<" ";} cout<<"\n";}
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        vector<char> row1;
        vector<char> row2;
        vector<char> row3;
        for(int i = 0; i<9; i++){
            char item;
            cin>>item;
            if(i<3){
                row1.push_back(item);
            } else if(i<6){
                row2.push_back(item);
            } else {
                row3.push_back(item);
            }
        }
 
        char won = '.';
        if(row1[0]==row1[1]&&row1[0]==row1[2]){
            if(won=='.')
            won = row1[0];
        }  if(row2[0]==row2[1]&&row2[0]==row2[2]){
            if(won=='.')
            won = row2[0];
        }  if(row3[0]==row3[1]&&row3[0]==row3[2]) {
            if(won=='.')
            won = row3[0];
        }  if(row1[0]==row2[0]&&row2[0]==row3[0]) {
            if(won=='.')
            won = row1[0];
        }  if(row1[1]==row2[1]&&row2[1]==row3[1]) {
            if(won=='.')
            won = row1[1];
        }  if(row1[2]==row2[2]&&row2[2]==row3[2]) {
            if(won=='.')
            won = row1[2];
        }  if(row1[0]==row2[1]&&row2[1]==row3[2]) {
            if(won=='.')
            won = row1[0];
        }  if(row1[2]==row2[1]&&row2[1]==row3[0]) {
            if(won=='.')
            won = row1[2];
        }
 
        if(won == '.') {
            cout<<"DRAW"<<"\n";
        } else if(won == '+') {
            cout<<"+"<<"\n";
        }else if(won == 'X') {
            cout<<"X"<<"\n";
        }else if(won == 'O') {
            cout<<"O"<<"\n";
        }
    }
	return 0;
}