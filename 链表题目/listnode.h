#include<iostream>

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