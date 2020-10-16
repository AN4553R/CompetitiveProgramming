#include<bits/stdc++.h>
using namespace std;

int main(){

	long long  A , B; cin>>A>>B;		
	long long ans = 0, cnt = 1;

	while(cnt < B)
	{
		cnt += (A - 1);
		ans++;
	}
	cout<<ans;

}
