#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	int loc;
	cout<<"enter loc : ";
	cin>>loc;
	int kloc = loc/1000;
	double a, b, c, d;
	if(kloc<50){
		cout<<"project type : "<<"organic\n";
		a = 2.4, b = 1.05, c = 2.5, d = 0.38;
	} else if(kloc>=50 && kloc<=300){
		cout<<"project type : "<<"semi-detached\n";
		a = 3.0, b = 1.12, c = 2.5, d = 0.35;
	} else {
		cout<<"project type : "<<"embedded\n";
		a = 3.6, b = 1.20, c = 2.5, d = 0.32;
	}
	cout<<"enter costPerPersonMonth : ";
	double effort, devTime, teamSize, productivity, cost;
	effort = a*pow(kloc,b);
	devTime = c*pow(effort,d);
	productivity = kloc/effort;
	cout<<"effort : "<<effort<<"\n";
	cout<<"development time : "<<devTime<<"\n";
	cout<<"productivity : "<<productivity<<"\n";
	return 0;
}