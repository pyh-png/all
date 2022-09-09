#pragma once
#include<iostream>
#include"ListNode.h"
#include<queue>
class Solution {
public:
	int add(int a, int b);

	string decodeString(string s);
	string dfs_kthGrammar(string start, int n, int time) {
		if (time == n) {
			return start;
		}
		string res = "";
		for (int i = 0; i < start.size(); i++) {
			if (start[i] == '0') {
				res += "01";
			}
			if (start[i] == '1') {
				res += "10";
			}
		}
		time++;
		return dfs_kthGrammar(res, n, time);
	}
	int kthGrammar(int N, int K) {
		if (N == 1 && K == 1)
			return 0;
		int a = kthGrammar(N - 1, (K + 1) / 2);  //求父结点的值；(K+1)/2为父结点的序号
		int b = -(a - 1);   //若a=0则b=1,若a=1则b=0
		if (K % 2 == 1)
			return a;   //K为奇数则其值与父结点相同
		else
			return b;
	}
	ListNode* reverseList(ListNode* head) {
		ListNode* res = nullptr;
		ListNode* temp = head;
		while (temp != nullptr) {
			ListNode* nexttemp = temp->next;
			temp->next = res;
			res = temp;
			temp = nexttemp;
		}
		return res;
	}
	int findTheWinner(int n, int k) {
		queue<int> qu;
		for (int i = 1; i <= n; i++) {
			qu.emplace(i);
		}
		while (qu.size() > 1) {
			for (int i = 1; i < k; i++) {
				qu.emplace(qu.front());
				qu.pop();
			}
			qu.pop();
		}
		return qu.front();
	}
	bool isPalindrome(ListNode* head) {
		vector<int> val_head;
		while (head!= nullptr) {

			val_head.push_back(head->val);
			head = head->next;
		}
		int left = 0;
		int right = val_head.size();
		while (left < right) {
			if (val_head[left] != val_head[right - 1])
				return false;
			left++;
			right--;
		}
		return true;

	}
};