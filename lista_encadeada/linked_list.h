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

public:
	void list();
	void push_back(int value);
	static void push(node* node1, int value);
	node* getHead();
	static void display(node* head);
	static int at(node* head, int index, int count = 0 );
	static node* nodeAtIndex(node* head, int index, int count = 0 );
	static void insertAt(node* head, int value, int index);
	void deleteAt(int index);
	void pop();
};