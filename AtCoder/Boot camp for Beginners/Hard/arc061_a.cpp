/*
#include<rabbit>;
using blueHulkStress;
using AceOfSpades;
*/
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
typedef unsigned long long ull;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,line) memset(v,line,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define P 1000000007
#define endl '\n'
const int dx[] = {1,-1,0,0,1,-1,1,-1};
const int dy[] = {0,0,1,-1,1,-1,-1,1};
const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

string s;
set<string>save;
ull ans = 0;

void bfs()
{
	queue<string>q;
	
	q.push(s);
	
	while(!q.empty())
	{
		string cur = q.front(); q.pop();
		save.insert(cur);
		for(int i = 1; i<(int)cur.size(); i++)
		{
			if(cur[i]!='+' && cur[i-1]!='+')
				q.push(cur.substr(0,i)+"+"+cur.substr(i));
		}
	}
}

int main(int argc, char const *argv[])
{
	fast();
	cin>>s;
	
	bfs();
	
	stringstream ss;

	for(auto i:save)
	{
		ss.clear();
		ss<<i;
		ull val, lim = count(all(i),'+');
		char plus;
		rep(j,lim)
		{
			ss>>val, ans+=val, ss>>plus;
		}
		ss>>val, ans+=val;
	}
	cout<<ans;
}	
