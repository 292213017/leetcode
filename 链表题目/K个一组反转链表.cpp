#include "listnode.h"

using namespace std;

ListNode * successed;

//从这个题目中可以总结出，递归只是适用于完全一样的子类型问题
//对于有偏差的问题，还是迭代比较适合
// 这个题目中，就适用于迭代

void Traverse(ListNode * head)
{
	// 遍历一个链表
	while(head != NULL)
	{
		cout<<head->val<<endl;
		head = head->next;
	}
}

ListNode * reverseN(ListNode * head , int n)
{
    if(n== 1)
    {
        successed = head->next;
        return head;
    }
    else if(head->next == NULL)
    {
        return NULL;
    }
    ListNode * last = reverseN(head->next,n-1);
    if(last != NULL)
    {
        head->next->next = head;
        head->next = NULL;
    }
    return last;
}

ListNode * reverseKGroup(ListNode * head,int n)
{
    // 还是使用递归，先写basecase
    // basecase分为两种情况，可以满足个数与不可以的
    ListNode * last = reverseN(head,n);
    if(last == NULL)
    {
        last = head;
        successed = NULL;
    }
    if(successed != NULL)
    {
        head->next = reverseKGroup(successed,n);
    }

    return last;
}

int main()
{
    ListNode * head = new ListNode(6);
	for(int i =5;i>0;i--)
	{
		head = new ListNode(i,head);
	}
    // Traverse(head);
    ListNode * last = reverseKGroup(head,4);
    Traverse(last);
    return 0;
}