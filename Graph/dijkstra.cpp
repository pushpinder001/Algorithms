#include<bits/stdc++.h>
#define sz 100005
#define M_V 987654321
#define ii pair<int,int>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
vector<vector<ii > > gp(sz);
vi D(sz,M_V),parent(sz,-1);
void dijkstra(int sr)
{
	set<ii > s;
	D[sr]=0;
	s.insert(mp(0,sr));
	while(!s.empty())
	{
		ii p1=*s.begin();
		s.erase(s.begin());
		int v=p1.ss,d=p1.ff;
		for(auto it:gp[v])
		{
			int v2=it.ff,len=it.ss;
			if(D[v]+len<D[v2])
			{
				if(D[v2]!=M_V)
				{
					s.erase(s.find(mp(D[v2],v2)));
				}
				D[v2]=len+D[v];
				s.insert(mp(D[v2],v2));
				parent[v2]=v;
			}
		}
	}
}
int main(){
	int n,m,l1,l2,w;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>l1>>l2>>w;
		gp[l1].pb(mp(l2,w));
		gp[l2].pb(mp(l1,w));
	}
	dijkstra(0);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<D[i]<<" ";
	cout<<endl;
	return 0;
}
