#include<iostream>
using namespace std;
#define ipt(x) cin>>x
int add(int a, int b);
int main() {
	int a = 1;
	int b = 1;
	ipt(a);
	cout << a << endl;
	return 0;
}
int add(int a, int b) {
	return a + b;
}