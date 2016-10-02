#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#define inf -1000000000000000
#define M 1000000007
#define sz 100005
#define pb push_back
typedef long long ll;
using namespace std;
ll ST[4*sz],lST[4*sz],sST[4*sz],rST[4*sz],a[sz];
void build(ll tl,ll tr,ll p){
	if(tl==tr)
	{
		ST[p]=a[tl];
    	lST[p]=ST[p];
        rST[p]=ST[p];
        sST[p]=ST[p];
		return ;
	}
	ll tm=(tl+tr)/2;
	build(tl,tm,2*p);
	build(tm+1,tr,2*p+1);
	ST[p]=ST[2*p]+ST[2*p+1];
	lST[p]=ST[p];
	rST[p]=ST[p];
	sST[p]=ST[p];
}

void update(ll tl,ll tr,ll pos,ll v,ll p)
{
	if(tl==tr)
	{
		ST[p]=v;
		lST[p]=v;
		rST[p]=v;
		sST[p]=v;
		return ;
	}
	ll tm=(tl+tr)/2;
	if(pos<=tm)
		update(tl,tm,pos,v,2*p);
	else
		update(tm+1,tr,pos,v,2*p+1);
	ST[p]=max(max(ST[2*p],ST[2*p+1]),rST[2*p]+lST[2*p+1]);
	lST[p]=max(sST[2*p]+lST[2*p+1],lST[2*p]);
    rST[p]=max(rST[2*p+1],rST[2*p]+sST[2*p+1]);
    sST[p]=sST[2*p]+sST[2*p+1];
    if(ST[p]<inf)
    	ST[p]=inf;
    if(lST[p]<inf)
    	lST[p]=inf;
    if(rST[p]<inf)
    	rST[p]=inf;
    if(sST[p]<inf)
    	sST[p]=inf;
}
int main(){
	ios_base::sync_with_stdio(0);
	ll n,k;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	build(1,n,1);
	//cout<<ST[1]<<endl;
	for(int i=1;i<n;i++)
    {
        cin>>k;
        update(1,n,k,inf,1);
        cout<<ST[1]<<endl;
    }
    cout<<"0\n";
	return 0;
}
