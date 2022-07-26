#pragma once
#include<vector>
#include<assert.h>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	int n;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	void createList(ListNode *head, int len);

	//打印链表(顺序)
	void printList(ListNode *head);

	//打印链表（逆序）
	void reversePrintList(ListNode *head);

	//在链表尾节点添加一个新节点
	void pushBack(ListNode *head, int val);

	//更改链表尾节点数值
	void changeBackValue(ListNode *head, int val);

	//删除链表尾节点
	void popBack(ListNode *head);

	//删除链表中节点值等于指定值的节点（不包括头节点）
	void deleteNode(ListNode *head, int val);
	
	//清空列表
	void clearList(ListNode * head);
};