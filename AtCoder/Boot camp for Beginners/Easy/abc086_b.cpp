#include<bits/stdc++.h>

using namespace std;  


int main() {
	
	string a, b;cin>>a>>b;
	stringstream str(a + b);
	double x;
	str>>x;
	cout<<(((sqrt(x) - floor(sqrt(x))) == 0)?"Yes":"No");
}
