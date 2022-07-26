#pragma once
#include<vector>
#include<assert.h>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	void printList(ListNode *head) {
		if (head == nullptr)
			cout << "empty list." << endl;
		else
			while (head != nullptr)
			{
				cout << head->val << '\t';
				head = head->next;
			}
		cout << endl;
	}
	void createList(ListNode *head, int len) {
		for (int i = 1; i < len; i++)   //len-1个节点，加上head节点共len个
		{
			ListNode *node = new ListNode;   //每次都需要实例化一个ListNode
			node->val = i * i;    //为节点赋值
			node->next = nullptr;
			head->next = node;   //head指向下一个节点（即当前节点）
			head = node;     //将当前节点设为head
		}
		cout << "Create a new ListNode with len of " << len << " successfully." << endl;
	}
};
class Solution
{
public:
	//创建长度为len的单向链表
	void createList(ListNode *head, int len) {
		for (int i = 1; i < len; i++)   //len-1个节点，加上head节点共len个
		{
			ListNode *node = new ListNode;   //每次都需要实例化一个ListNode
			node->val = i * i;    //为节点赋值
			node->next = nullptr;
			head->next = node;   //head指向下一个节点（即当前节点）
			head = node;     //将当前节点设为head
		}
		cout << "Create a new ListNode with len of " << len << " successfully." << endl;
	}

	//打印链表(顺序)
	void printList(ListNode *head) {
		if (head == nullptr)
			cout << "empty list." << endl;
		else
			while (head != nullptr)
			{
				cout << head->val << '\t';
				head = head->next;
			}
		cout << endl;
	}

	//打印链表（逆序）
	void reversePrintList(ListNode *head) {
		//因为ListNode只能根据next单向索引，无法逆向回溯，所以只能将节点数值存在vector中反向输出。
		//目前只想到了这种方法。
		if (head == nullptr)
		{
			cout << "empty list." << endl;
			exit(1);
		}
		else
		{
			vector<int> node;
			while (head != nullptr)
			{
				node.push_back(head->val);
				head = head->next;
			}
			while (!node.empty())
			{
				//先输出node中的最后一个元素，再删除最后一个元素。而不是先对node做reverse再正向输出。
				cout << node.back() << '\t';
				node.pop_back();
			}
			cout << endl;
		}
	}

	//在链表尾节点添加一个新节点
	void pushBack(ListNode *head, int val) {
		ListNode *node = new ListNode(val, nullptr);   //要添加的新节点
		if (head == nullptr)
			head = node;
		else
		{
			while (head->next != nullptr)    //while循环结束后head就是尾结点了
				head = head->next;
			head->next = node;
		}
	}

	//更改链表尾节点数值
	void changeBackValue(ListNode *head, int val) {
		assert(head != nullptr);
		while (head->next != nullptr)    //while循环结束后head就是尾结点了
			head = head->next;
		head->val = val;
	}

	//删除链表尾节点
	void popBack(ListNode *head) {
		assert(head != nullptr);
		while (head->next->next != nullptr)   //while循环结束后head是倒数第二个节点，其next指向尾节点
			head = head->next;
		head->next = nullptr;   //删除尾节点
		//注意不要直接delete尾结点，因为尾结点的next是nullptr，直接delete nullptr会输出很多乱码。
	}

	//删除链表中节点值等于指定值的节点（不包括头节点）
	void deleteNode(ListNode *head, int val) {
		assert(head != nullptr);
		ListNode *node = head;    //copy一份链表
		while (head->next != nullptr)
		{
			if (head->next->val == val)
				node->next = head->next->next;
			head = head->next;
			node = node->next;
		}
	}

	//清空列表
	void clearList(ListNode *head) {
		head->next = nullptr;   //清楚头结点之后的所有节点
		//清空列表的功能一直不知道怎么实现，头结点不知道怎么删除。
	}
};

