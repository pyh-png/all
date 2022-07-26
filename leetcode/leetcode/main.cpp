#include<iostream>
#include"include\solution.h"
using namespace std;
#define ipt(x) cin>>x
int main() {
	int a, b;
	ipt(a);
	ipt(b);
	Solution s;
	cout << s.add(a,b) << endl;
	return 0;
}