#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WaRNINGS
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
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define P 1000000007
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

ll temp[1000005];
ll  merge(ll arra[],ll l,ll r)
{
    ll mid=(l+r)/2;
    ll i=l,j=mid+1,k=l;
    ll inversion=0;
    while(i<=mid && j<=r)
    {
        if (arra[i]<=arra[j])
        {
            temp[k++]=arra[i++];
        }
        else
        {
            temp[k++]=arra[j++];
            inversion = inversion + mid-i+1;
        }

    }

    while (i<=mid)
    {
        temp[k++]=arra[i++];
    }
    while(j<=r)
    {
        temp[k++]=arra[j++];
    }
    for (i=l; i<=r; i++)
    {
        arra[i]=temp[i];
    }
    return inversion;
}

ll merge_sort(ll a[],ll l,ll r)
{
    long long mid,inversion=0;
    if (r>l)
    {
        mid=(l+r)/2;
        inversion=merge_sort(a,l,mid);
        inversion+=merge_sort(a,mid+1,r);
        inversion+=merge(a,l,r);
    }
    return inversion;
}

int main(int argc, char const *argv[])
{
	file();

	ll n;
    while(scanf("%lld",&n))
    {
        ll i;
        ll a[n];
        for (i=0; i<n; i++)
        {
            cin>>a[i];
        }
        ll ans;
        ans=merge_sort(a,0,n-1);
        if(ans%2==1)
          cout<<"Marcelo"<<endl;
        else
            cout<<"Carlos"<<endl;
    }
}
