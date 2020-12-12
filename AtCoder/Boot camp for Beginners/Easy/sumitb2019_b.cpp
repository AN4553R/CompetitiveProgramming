#include<bits/stdc++.h>

using namespace std;  
int main() {
	int n; cin>>n;

	int s = 0, e = 50000;

	while(s <= e){
		int mid = (s + e) / 2;
		if (int(mid * 1.08) > n)
		{
			e = mid - 1;
		}
		else if (int(mid * 1.08) < n)
		{
			s = mid + 1;
		}
		else
			return cout<<mid, 0;
	}
	cout<<":(";
}
