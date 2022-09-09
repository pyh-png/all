#include<iostream>
#include"include\solution.h"
#include<math.h>
#include<algorithm>
#include <sys/types.h>
#include<string>
using namespace std;
#define ipt(x) cin>>x
enum weekday { TCP,th,ch };
struct point
{
	int a;
	int b;
};
int sum(int n, int m, int k,vector<point> tem,int max_s) {
	int res=0;
	for (int start = 0; start < max_s - k; start++) {
		int sum = 0;
		for (point points:tem) {
			if (points.b < start + k && points.b>start) {
				sum++;
			}
		}
		if (sum > res) {
			res = sum;
		}
	}
	return res;
}
int getCnt(vector<int> &tree, int k) {
	
	int res = 1;
	sort(tree.begin(), tree.end());
	for (int i = tree.size() - 1; i > 0; i--) {
		int r = tree[i];
		int temp = 1;
		for (int j = 0; j < i; i++) {
			if (tree[j]>=r-k) {
				temp++;
			}
		}
		if (res < temp) {
			res = temp;
		}
	}
	return res;
}
#pragma pack(2)
struct fun {
	int i;
	char c;
	double d;
	char a;
};

int n;
int a[101];
int vis[101];
void dfs(int pos) {
	if (pos == n + 1) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		vis[i] = 1;
		a[pos] = i;
		for (int j = 1; j <= pos; j++) {
			cout << a[j];
		}
		cout << endl;
		dfs(pos + 1);
		vis[i] = 0;
	}
}
typedef struct st1
{
	int a : 7;
	int b : 2;
	int c : 7;
}st_s;
int f(unsigned int val) {
	val = (val & 0x55555555) + ((val & 0xaaaaaaaa) >> 1);
	val = (val & 0x33333333) + ((val & 0xcccccccc) >> 2);
	val = (val & 0x0f0f0f0f) + ((val & 0xf0f0f0f0) >> 4);
	val = (val & 0x00ff00ff) + ((val & 0xff00ff00) >> 8);
	val = (val & 0x0000ffff) + ((val & 0xffff0000) >> 16);


	return val;
}
#define AREA(A,B) ((A)*(B))
string removeDup(string s, int k, bool de) {
	int left = 0;
	int right = 0;
	string res = "";
	while( left < s.size()) {
		int temp = 0;
		right = left;
		while (s[right] == s[left]&&right<s.size()) {
			temp++;
			right++;
		}
		if (temp < k) {
			for(int i=0;i<temp;i++)
				res += s[left];
		}
		if (temp >= k) {
			de = false;
		}
		left = right;
	}
	if (de) {
		return res;
	}
	de = true;
	return removeDup(res, k, de);
}
#define MAX(a,b) ((a)>(b)?(a):(b))
int main() {
	int a = 5, b = 0;
	int c = MAX(++a, b);
	int d = MAX(++a, b + 10);
	printf("a");

}