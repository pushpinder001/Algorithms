#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
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
int main(){
    time_t start=clock();
    //freopen("inp.txt",'r',stdin);
    //freopen("out.txt",'w',stdout)
    ios_base::sync_with_stdio(0);
    int test, kas=0;
    cin>>test;
    while( test-- ){
        cout<<"Case #"<<++kas<<": ";
    }
    cerr << " Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}
