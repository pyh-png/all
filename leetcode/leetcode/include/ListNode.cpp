#include"ListNode.h"
void ListNode::createList(ListNode *head, int len) {
	for (int i = 1; i < len; i++)   //len-1���ڵ㣬����head�ڵ㹲len��
	{
		ListNode *node = new ListNode;   //ÿ�ζ���Ҫʵ����һ��ListNode
		node->val = i;    //Ϊ�ڵ㸳ֵ
		node->next = nullptr;
		head->next = node;   //headָ����һ���ڵ㣨����ǰ�ڵ㣩
		head = node;     //����ǰ�ڵ���Ϊhead
	}
	cout << "Create a new ListNode with len of " << len << " successfully." << endl;
}

//��ӡ����(˳��)
void ListNode::printList(ListNode *head) {
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

//��ӡ��������
void ListNode::reversePrintList(ListNode *head) {
	//��ΪListNodeֻ�ܸ���next�����������޷�������ݣ�����ֻ�ܽ��ڵ���ֵ����vector�з��������
	//Ŀǰֻ�뵽�����ַ�����
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
			//�����node�е����һ��Ԫ�أ���ɾ�����һ��Ԫ�ء��������ȶ�node��reverse�����������
			cout << node.back() << '\t';
			node.pop_back();
		}
		cout << endl;
	}
}

//������β�ڵ����һ���½ڵ�
void ListNode::pushBack(ListNode *head, int val) {
	ListNode *node = new ListNode(val, nullptr);   //Ҫ��ӵ��½ڵ�
	if (head == nullptr)
		head = node;
	else
	{
		while (head->next != nullptr)    //whileѭ��������head����β�����
			head = head->next;
		head->next = node;
	}
}

//��������β�ڵ���ֵ
void ListNode::changeBackValue(ListNode *head, int val) {
	assert(head != nullptr);
	while (head->next != nullptr)    //whileѭ��������head����β�����
		head = head->next;
	head->val = val;
}

//ɾ������β�ڵ�
void ListNode::popBack(ListNode *head) {
	assert(head != nullptr);
	while (head->next->next != nullptr)   //whileѭ��������head�ǵ����ڶ����ڵ㣬��nextָ��β�ڵ�
		head = head->next;
	head->next = nullptr;   //ɾ��β�ڵ�
	//ע�ⲻҪֱ��deleteβ��㣬��Ϊβ����next��nullptr��ֱ��delete nullptr������ܶ����롣
}

//ɾ�������нڵ�ֵ����ָ��ֵ�Ľڵ㣨������ͷ�ڵ㣩
void ListNode::deleteNode(ListNode *head, int val) {
	assert(head != nullptr);
	ListNode *node = head;    //copyһ������
	while (head->next != nullptr)
	{
		if (head->next->val == val)
			node->next = head->next->next;
		head = head->next;
		node = node->next;
	}
}

//����б�
void ListNode::clearList(ListNode *head) {
	head->next = nullptr;   //���ͷ���֮������нڵ�
	//����б�Ĺ���һֱ��֪����ôʵ�֣�ͷ��㲻֪����ôɾ����
}