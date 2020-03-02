#pragma once

struct node
{
	int data;
	node* next;
};

class LinkedList2
{
public:
	LinkedList2();
	~LinkedList2();
	static void push_back(node* curr);
	static void push(node* curr);
	static void push_at(node* curr);
	static void size(node* curr);
	static void at(node* curr);
	static void pop_back(node* curr);
	static void pop(node* curr);
	static void pop_at(node* curr);

private:

};

LinkedList2::LinkedList2()
{
}

LinkedList2::~LinkedList2()
{
}

