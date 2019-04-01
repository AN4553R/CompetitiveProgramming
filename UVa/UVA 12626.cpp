#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<complex>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<numeric>
#include<map>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).end()),((v).begin())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define dot cout << fixed << setprecision(15);
#define vi vector<int>						
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll,ll>

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {

	
    int t;
    scanf("%d",&t);
	while (t--)
	{
		char a[700];
		scanf("%s", a);
		int count[6] = { 0 };
		int ans;
		rep(i,strlen(a))
		{
				count[0]+= a[i] == 'A';
				count[1]+= a[i] == 'R';
				count[2]+= a[i] == 'I';
				count[3]+= a[i] == 'G';
				count[4]+= a[i] == 'M';
				count[5]+= a[i] == 'T';
		}
		count[0] /= 3;
		count[1] >>=1;
		ans = min(min(min(min(min(count[0], count[1]), count[2]), count[3]), count[4]), count[5]);
		printf("%d\n", ans);
	}
}
