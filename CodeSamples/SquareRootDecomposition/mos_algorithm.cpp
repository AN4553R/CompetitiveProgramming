// CodeForces 86D


#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
//const int dx[] = {1,-1,0,0,1,-1,1,-1};
//const int dy[] = {0,0,1,-1,1,-1,-1,1};
void carrotiq() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int OO=2e5+5;

int n,t,root,v[OO],freq[OO*10]={0};

ll ans[OO];

struct $
{
	int l,r,idx;
	$(){}
	
	$(int l,int r,int idx):l(l),r(r),idx(idx){}
	
	bool operator < (const $ & node)const {
		if(l/root!=node.l/root) // not in the same packet
			return l < node.l;
		return r < node.r;
	}	
}Q[OO];

ll calc=0;

void add(int x){
	calc-=1ll*freq[v[x]]*freq[v[x]]*v[x];
	freq[v[x]]++;
	calc+=1ll*freq[v[x]]*freq[v[x]]*v[x];
}

void remove(int x){
	calc-=1ll*freq[v[x]]*freq[v[x]]*v[x];
	freq[v[x]]--;
	calc+=1ll*freq[v[x]]*freq[v[x]]*v[x];
}

int main()
{
	fast();
	carrotiq();

	cin>>n>>t;rep(i,n)cin>>v[i];
	
	root=sqrt(n+.0);

	for (int i = 0,l,r; i < t && cin>>l>>r; ++i)
			Q[i]=$(l-1,r-1,i);
	sort(Q,Q+t);

	int l=0,r=-1;
	rep(i,t)
	{
		while(l<Q[i].l)remove(l),l++;
		
		while(l>Q[i].l)l--,add(l);

		while(r<Q[i].r)r++,add(r);
		
		while(r>Q[i].r)remove(r),r--;

		ans[Q[i].idx]=calc;
	}
	rep(i,t)cout<<ans[i]<<endl;
	
}
