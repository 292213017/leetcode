#include <iostream>

using namespace std;


class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int x , ListNode * nextl = NULL)
	{
		val = x;
		next =nextl;
	}
};

void Traverse(ListNode * head)
{
	// 遍历一个链表
	while(head != NULL)
	{
		cout<<head->val<<endl;
		head = head->next;
	}
}


//使用递归的方式来反转一个链表
ListNode * reverse(ListNode * head)
{
	// 使用递归的时候首先就是先写basecase，就是到最底的情况
	if(head->next == NULL) { return head;}
	ListNode * last = reverse(head->next);
	head->next->next=head;
	head->next =NULL;
	return last;
}


ListNode * successor;

ListNode * reverseN(ListNode * head , int n)
{
	//首先写basecase情况
	if(n == 1){
		successor = head->next;
		return head;
		}
	ListNode * last = reverseN(head->next,n -1);
	head->next->next = head;
	head->next = successor;
	return last;
}

ListNode * origin;

ListNode * reverseMN(ListNode * head , int m, int n)
{
	//先写basecase
	if(m == 1)
	{
		ListNode * last = reverseN(head,n);
		return last;
	}
	// 使用递归的方法往前推
	head->next = reverseMN(head->next,m-1,n-1);
	return head;

}

int main() {
	// 逆序创建一个链表
	ListNode * head = new ListNode(6);
	for(int i =5;i>0;i--)
	{
		head = new ListNode(i,head);
	}
	// //遍历链表
	// Traverse(head);

	// //反转整个链表
	// ListNode * last = reverse(head);
	// Traverse(last);

	//反转链表中的前N个节点
	// ListNode * last2 = reverseN(head,3);
	// Traverse(last2);

	// 反转链表中的一部分节点
	ListNode * last =reverseMN(head,2,4);
	Traverse(last);

	return 0;
}