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
	static void push_back(node* head, int value);
	static void push(node* head, int value);
	static void push_at(node* head, int value, int index);
	static void display(node* head);
	static int at(node* head, int index, int count = 0 );
	static void pop_back(node* head);
	static void pop(node* head);
	static void pop_at(node* head, int index, int count = 0);
	static void clear(node* head);
	static int size(node* head);
};