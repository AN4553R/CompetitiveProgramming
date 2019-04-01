#define _CRT_SECURE_NO_WaRNINGS
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define endl '\n'
//const ll dx[] = {1,-1,0,0,1,-1,1,-1};
//const ll dy[] = {0,0,1,-1,1,-1,-1,1};
void courage() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const ll OO=1e8;
std::vector<pii>ans(OO);
std::vector<bool> prime(OO,true);

    

int main(int argc, char const *argv[])
{
	courage();

	for (int p=2; p*p<=OO; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=OO; i += p) 
                prime[i] = false; 
        } 
    }
    int first=-1,idx=0;
    for (int p=2; p<=OO; p++) 
       if (prime[p]) 
          {
          	if(first+2==p)
          		ans[++idx]={first,p};
          	first=p;	
          }  
	int n;
	while(scanf("%d",&n)==1){
		printf("(%d, %d)\n", ans[n].first,ans[n].second);
	}
}
