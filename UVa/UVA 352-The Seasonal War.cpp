#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define pb push_back
#define po pop_back
#define pf push_front
#define mp make_pair
#define all(v) ((v).begin()),((v).end())
#define st first
#define nd second
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll>vll;

char grid[1000][1000];
bool vis[1000][1000];
int row,clm;
bool valid(int x,int y){
	return(x<row && x>=0 && y<clm && y>=0);
}
void one(int r,int c){
	if(!valid(r,c) || vis[r][c])return;
	vis[r][c]=1;
	 int sx[]={1,-1,0,0,-1,-1,1,1},sy[]={0,0,1,-1,-1,1,1,-1};
	rep(g,8)if(grid[r+sx[g]][c+sy[g]]=='1')one(r+sx[g],c+sy[g]);
}
void zero()
{memset(vis,0,sizeof(vis));}   /*rep(i,1000)rep(t,1000)vis[i][t]=0;*/

int main()
{
	int x;
	for(int i=1;cin>>x;i++)
	{
		int on=0;
		zero();
		row=clm=x;
		rep(i,row)rep(t,clm)cin>>grid[i][t];

		rep(i,row)rep(t,clm)
						 if(grid[i][t]=='1'&& !vis[i][t])
						    one(i,t),on++;
		cout
		    <<"Image number "
			<<i<<" contains "
			<<on<<" war eagles."
			<<endl;
	}
}
