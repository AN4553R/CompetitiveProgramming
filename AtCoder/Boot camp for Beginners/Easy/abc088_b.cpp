#include<bits/stdc++.h>

using namespace std;  


int main() {
	
	int n; cin>>n;
	int a = 0, b = 0;
	priority_queue<int>q;
	while(n--){
		int x;cin>>x;
		q.push(x);
	}
	while(!q.empty()){

		if ((int)q.size() & 1)
			a+=q.top();
		else
			b+=q.top();
		q.pop();
	}
	cout<<abs(a - b);
}
