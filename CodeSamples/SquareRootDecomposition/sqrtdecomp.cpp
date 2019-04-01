// SPOJ RMQSQ

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

const int OO=1e5+5;
int N,Q,arr[OO],packet[OO],root;

int main()
{
	fast();
	carrotiq(); 
	
	cin>>N;

	root=sqrt(N+.0);
	// packet number = idx/root
	// element idx in the packet = idx%root
	
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
		int cur_min;
		if(i%root==0)
			packet[i/root]=arr[i];
		else 
			packet[i/root]=min(packet[i/root],arr[i]);
	}

	cin>>Q;
	
	for (int i = 0,l,r; i < Q; ++i)
	{
		int ans=INT_MAX;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			if(j%root ==0 && j+root-1<=r)
				ans=min(ans,packet[j/root]),j+=root-1; // min(currentMmin,minOfMyPacket)
			else ans=min(ans,arr[j]);
		}
		cout<<ans<<endl;
	}
  
}
