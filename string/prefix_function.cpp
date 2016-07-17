#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#define M 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;
vi F(100005);
void prefix_function(string p){
	int m=p.length();
	F[0]=0;
	F[1]=0;
	for(int i=2;i<=m;i++)
	{
		int l=F[i-1];
		while(1)
		{
			if(p[i-1]==p[l])
			{
				F[i]=l+1;
				break;
			}
			else{
				if(l==0){
					F[i]=0;
					break;
				}
				l=F[l-1];
			}
		}
	}
}
kmp(){

}
int main(){
	string str;
	cin>>str;
	prefix_function(str);
	for(int i=1;i<=str.length();i++)
		cout<<F[i]<<' ';
	return 0;
}
