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
int ST[400005],lazy[400005]={0};
int query(int tl,int tr,int l,int r,int p){
	if(lazy[p]!=0)
	{
		ST[p]+=lazy[p];
		if(tl!=tr)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
		}
		lazy[p]=0;
	}
	if(tl>=l&&tr<=r)
		return ST[p];
	if(tr<l||tl>r)
		return 0;
	int tm=(tl+tr)/2;
	ST[p]=max(ST[2*p],ST[2*p+1]);
	return max(query(tl,tm,l,r,2*p),query(tm+1,tr,l,r,2*p+1));
}
void update(int tl,int tr,int l,int r,int p,int val)
{
	if(lazy[p]!=0)
	{
		ST[p]+=lazy[p];
		if(tl!=tr)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
		}
		lazy[p]=0;
	}
	if(tr<l||tl>r)
		return ;
	if(tl>=l&&tr<=r){
		ST[p]+=val;
		if(tl!=tr)
		{
			lazy[2*p]+=val;
			lazy[2*p+1]+=val;
		}
		return;
	}
	int tm=(tl+tr)/2;
	update(tl,tm,l,r,2*p,val);
	update(tm+1,tr,l,r,2*p+1,val);
	ST[p]=max(ST[2*p],ST[2*p+1]);
}
