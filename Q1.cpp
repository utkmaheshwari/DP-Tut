#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;

int n, i, a[60],x[60], y[60], j, ans;
string s, num;

int main(){
	getline(cin,s);
	istringstream iss(s);
	i=0;
	while(getline(iss, num, ',')) {
		a[++i] = stoi(num);
	}
	n=i;
	
	for(i=0;i<=n;++i){
		x[i]=y[i]=1;
	}
	for(i=2;i<=n;++i){
		for(j=1;j<=i;++j){
			if(a[i]>a[j]){
				x[i]=max(x[i],y[j]+1);
			}
			else if(a[i]<a[j]){
				y[i]=max(y[i],x[j]+1);
			}
			else{
				x[i]=max(x[i],x[j]);
				y[i]=max(y[i],y[j]);
			}
		}
	}
	ans=0;
	for(i=0;i<=n;++i){
		ans=max(ans,max(x[i],y[i]));
	}
	cout<<ans<<endl;
	return 0;
}
