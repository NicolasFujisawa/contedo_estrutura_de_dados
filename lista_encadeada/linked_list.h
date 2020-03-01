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
public:
	void list();
	static void push_back(node* head, int value);
	static void push(node* head, int value);
	static void pushAt(node* head, int value, int index);
	node* getHead();
	static void display(node* head);
	static int at(node* head, int index, int count = 0 );
	static node* nodeAtIndex(node* head, int index, int count = 0 );
	void deleteAt(int index);
	void popAt(int index);
	void clear();
	static int size(node* head);
};