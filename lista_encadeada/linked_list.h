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
	node* getHead();
	static void display(node* head);
	static void concatList(node* head1, node* head2);
	static int valueAtIndex(node* head1, int index, int count = 0 );
};