#pragma once
struct node
{
	int data;
	node* next;
};

class LinkedList
{
private:
	node* head, * tail;

public:
	void list();
	void createNode(int value);
	int valueAtIndex(int index);
};