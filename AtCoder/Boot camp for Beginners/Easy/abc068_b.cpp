#include<bits/stdc++.h>
using namespace std; 


int main(int argc, char const *argv[])
{
	int n, cpy; cin>>n;
	cpy = n;
	n++;
	while(n--){
		 if(ceil(log2(n)) == floor(log2(n))){
		 	return cout<<n, 0;
		 }
	}
	cout<<cpy;
}
