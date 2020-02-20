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
	void push_back_node(int value);
	node* getHead();
	static void display(node* head);
	static void concatList(node* head1, node* head2);
	static int valueAtIndex(node* head, int index, int count = 0 );
	static node* nodeAtIndex(node* head, int index, int count = 0 );
	static void insertAt(node* head, int value, int index);
	void deleteAt(int index);
};