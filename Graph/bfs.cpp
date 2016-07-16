#include<iostream>
#include<vector>
#include<queue>
#define M 200005
using namespace std;
vector<int> gp[M];
int a[M],b[M],visited[M];
void bfs(int src)
{
	queue<int> q;
	q.push(src);
	b[src]=0;
	visited[src]=1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(auto i=gp[p].begin();i!=gp[p].end();i++)
		{
			if(!visited[*i])
			{
				q.push(*i);
				visited[*i]=1;
				b[*i]=1+b[p];
			}
		}
	}
}
