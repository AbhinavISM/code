#include <bits/stdc++.h>
using namespace std;
#define I int
I main(){
I n;
cin>>n;
map<string,I>m;
while(n--){
   string s;
   cin>>s;
   m[s]++;
}
I z = 0;
for(auto&a:m)
   z = max(a.second,z);
cout<<z<<endl;
}