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

	//��ӡ����(˳��)
	void printList(ListNode *head);

	//��ӡ��������
	void reversePrintList(ListNode *head);

	//������β�ڵ����һ���½ڵ�
	void pushBack(ListNode *head, int val);

	//��������β�ڵ���ֵ
	void changeBackValue(ListNode *head, int val);

	//ɾ������β�ڵ�
	void popBack(ListNode *head);

	//ɾ�������нڵ�ֵ����ָ��ֵ�Ľڵ㣨������ͷ�ڵ㣩
	void deleteNode(ListNode *head, int val);
	
	//����б�
	void clearList(ListNode * head);
};