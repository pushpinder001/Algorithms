#include<iostream>
#include<vector>
#include<queue>
#define M 200005
using namespace std;
vector<int> gp[M];
int a[M],b[M],visited[M];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	b[s]=0;
	visited[s]=1;
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
