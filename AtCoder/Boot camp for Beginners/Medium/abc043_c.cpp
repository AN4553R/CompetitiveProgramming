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

int N, arr[101];

int computeCost(int N, int X) 
{ 
    int cost = 0; 
    for (int i = 0; i < N; i++) 
        cost += (arr[i] - X) * (arr[i] - X); 
    return cost; 
} 

int solve() 
{ 
    int low, high; 
    low = high = arr[0]; 
    for (int i = 0; i < N; i++) { 
        if (low > arr[i]) 
            low = arr[i]; 
        if (high < arr[i]) 
            high = arr[i]; 
    } 
  
    while ((high - low) > 2) { 
        int mid1 = low + (high - low) / 3; 
        int mid2 = high - (high - low) / 3; 
  
        int cost1 = computeCost(N, mid1); 
        int cost2 = computeCost(N, mid2); 
        if (cost1 < cost2) 
            high = mid2; 
        else
            low = mid1; 
    } 
    return computeCost(N, (low + high) / 2); 
} 
int main(int argc, char const *argv[])
{
	
	cin>>N;
	rep(i,N)cin>>arr[i];
	cout<<solve();
}
