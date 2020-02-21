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
	void pushAt(int value, int index);
	node* getHead();
	static void display(node* head);
	static int at(node* head, int index, int count = 0 );
	static node* nodeAtIndex(node* head, int index, int count = 0 );
	void deleteAt(int index);
	void pop_back();
	void popAt(int index);
	void clear();
	static int size(node* head);
};