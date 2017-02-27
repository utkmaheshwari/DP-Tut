#include<bits/stdc++.h>
#define vv vector< vector<long long> >
using namespace std;

long long r,c,l,i,j,cnt;
string s;

long long maxi(long long x, long long y){
	return (x>y)?x:y;
}

int main(){
	cin>>r>>c;
	cin.ignore();
	getline(cin,s);
	l=s.size();
	s[l-1]=',';
	vv ans(c+1,vector<long long>(r+1,0));
	vv direc(c+1,vector<long long>(r+1,0));
	vector<long long> temp(4,0);
	i=1;
	j=0;
	while(i!=l){
		if(s[i]==','){
			temp[j]=cnt;
			cnt=0;
			j=0;
			if(temp[1]==temp[3]){
				if(direc[temp[1]][maxi(temp[0],temp[2])]==0){
					direc[temp[1]][maxi(temp[0],temp[2])]=1;
				}
				else{
					direc[temp[1]][maxi(temp[0],temp[2])]=3;
				}
			}
			else{
				if(direc[maxi(temp[1],temp[3])][temp[0]]==0){
					direc[maxi(temp[1],temp[3])][temp[0]]=2;
				} 
				else{
					direc[maxi(temp[1],temp[3])][temp[0]]=3;
				}	
			}
		}
		else if(s[i]==' '){
			temp[j++]=cnt;
			cnt=0;	
		} 
		else if(s[i]=='\"'){
			
		}
		else{
			cnt=cnt*10;
			cnt=cnt+(s[i]-'0');
		}
		i++;
	}
	
	ans[0][0]=1;
	for(i=0;i<=c;i++){
		for(j=0;j<=r;j++){
			if(i==0||j==0){
				if(i==0&&j==0){
					continue;	
				} 
				else if(direc[i][j]!=0){
					ans[i][j]=0;	
				}
				else{
					ans[i][j]=(i==0)?ans[0][j-1]:ans[i-1][0];	
				} 
			}
			else{
				if(direc[i][j]==0){
					ans[i][j]=ans[i-1][j]+ans[i][j-1];	
				} 
				else if(direc[i][j]==1){
					ans[i][j]=ans[i-1][j];	
				} 
				else if(direc[i][j]==2){
					ans[i][j]=ans[i][j-1];	
				}
			}
		}
	}
	cout<<ans[c][r]<<endl;
	return 0;
}

