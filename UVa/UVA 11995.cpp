/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WaRNINGS*/
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
typedef unsigned long long ull;
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
//#define P 1000000007
#define endl '\n'

const ll dx[] = {1,-1,0,0,1,-1,1,-1};
const ll dy[] = {0,0,1,-1,1,-1,-1,1};

void file() {
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


int main(int argc, char const *argv[])
{
	file();
	
	int i,j,k,l,n,opt,tmp,temp;
   

    while(cin>>n) {
        stack<int> S;
        queue<int> Q;
        priority_queue<int> P;
        bool ss ,qq, pp;

        ss = pp = qq = true;
        while(n--) {
            scanf("%d %d",&opt,&tmp); 

            if(opt == 1) {
                if(ss)
                    S.push(tmp);
                if(qq)
                    Q.push(tmp);
                if(pp)
                    P.push(tmp);
            }
            else if(opt == 2) {
                if(ss) {
                    if(!S.empty() && S.top() == tmp) {
                        S.pop();
                    }
                    else ss = false;
                }
                if(qq) {
                    if(!Q.empty() && Q.front() == tmp) {
                        Q.pop();
                    }
                    else 
                        qq = false;
                }
                if(pp) {
                    if(!P.empty() && P.top() == tmp) {
                        P.pop();
                    }
                    else pp = false;
                }
            }
        }

        if(ss && !pp && !qq)
        	puts("stack");
        else if(!ss && !pp && qq)
        	puts("queue");
            
        else if(!ss && pp && !qq)
            puts("priority queue");
           
        else if(pp || qq || ss)
        	puts("not sure");
            
        else
        	puts("impossible");
    }
}
