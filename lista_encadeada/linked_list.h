#pragma once
#include<iostream>
struct node
{
	int data;
	node* next;
};

class LinkedList
{
private:
	node* head;
	node* tail;
public:
	void list();
	void push_back(int value);
	void push(int value);
	node* getHead();
	static void display(node* head);
	static int at(node* head, int index, int count = 0 );
	static node* nodeAtIndex(node* head, int index, int count = 0 );
	void pushAt(int value, int index);
	void deleteAt(int index);
	void pop();
};