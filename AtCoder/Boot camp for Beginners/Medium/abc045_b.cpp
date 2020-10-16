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


int main(int argc, char const *argv[])
{

	string a,b,c;cin>>a>>b>>c;
	reverse(all(a));
	reverse(all(b));
	reverse(all(c));
	char nxt = 'a';
	while(1)
	{
		if (nxt == 'a')
		{
			if(a.empty())return cout<<"A",0;
			nxt = a.back();
			a.pop_back();
		}
		if (nxt == 'b')
		{
			if(b.empty())return cout<<"B",0;
			nxt = b.back(), b.pop_back();
		}
		if (nxt == 'c')
		{
			if(c.empty())return cout<<"C",0;
			nxt = c.back(), c.pop_back();
		}
	}
}	
