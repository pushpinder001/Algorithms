#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int ,int > ii;
int n,m,k,d1[]={-1,1,0,0},d2[]={0,0,1,-1};
bool vis[55][55];
typedef pair<int ,ii> iii;
string s[55];
vector < iii> v;
int dfs(int i,int j){
    if(i<0 || i>n+1 || j<0 || j>m+1)
        return 0;
    if(vis[i][j])
        return 0;
    vis[i][j]=1;
    int p=1;
    for(int y=0;y<4;y++){
         if(i+d1[y]<0 || i+d1[y]>n+1 || j+d2[y]<0 || j+d2[y]>m+1)
             continue;
        if(s[i+d1[y]][j+d2[y]]=='.')
        p+=dfs(i+d1[y],j+d2[y]);}
    return p;
}
void dfs1(int i,int j)
{
    if(i<0 || i>n+1 || j<0 || j>m+1)
        return ;
    if(vis[i][j])
        return ;
    vis[i][j]=1;
    s[i][j]='*';
    for(int y=0;y<4;y++){if(i+d1[y]<0 || i+d1[y]>n+1 || j+d2[y]<0 || j+d2[y]>m+1)
        continue;
        if(s[i+d1[y]][j+d2[y]]=='.')
        {    
        dfs1(i+d1[y],j+d2[y]);}}
    return ;
}
