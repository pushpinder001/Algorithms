#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#define M 1000000007
#define sz 100005
#define pb push_back
typedef long long ll;
using namespace std;
int ST[4*sz],a[sz];
void build(int tl,int tr,int p){
	if(tl==tr)
	{
		ST[p]=a[tl];
		return ;
	}
	int tm=(tl+tr)/2;
	build(tl,tm,2*p);
	build(tm+1,tr,2*p+1);
	ST[p]=min(ST[2*p],ST[2*p+1]);
}
int query(int tl,int tr,int l,int r,int p){
	if(tl>=l&&tr<=r)
		return ST[p];
	if(tr<l||tl>r)
		return 100000;
	int tm=(tl+tr)/2;
	return min(query(tl,tm,l,r,2*p),query(tm+1,tr,l,r,2*p+1));
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,n,1);
	int l,r;
	cin>>l>>r;
	cout<<query(1,n,l,r,1);
	return 0;
}
