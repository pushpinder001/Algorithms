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
int P[100005],rank[100005];
void create(int n)
{
	for(int i=1;i<=n;i++)
		P[i]=i;
}
int find(int node){
	if(node!=P[node])
	{
		return P[node]=find(P[node]);
	}
	return node;
}
void merge_set(int x,int y){
	int x1=find(x);
	int y1=find(y);
	if(rank[x1]>=rank[y1])
	{
		P[y1]=x1;
		rank[x1]=max(rank[x1],1+rank[y1]);
	}
	else
	{
		P[x1]=y1;
		rank[y1]=max(rank[y1],1+rank[x1]);
	}
}
int main(){
	int n;
	cin>>n;
	create(n);
	merge_set(1,4);
	merge_set(2,4);
	merge_set(2,5);
	for(int i=1;i<=n;i++)
		cout<<find(i)<<' ';
	return 0;
}
