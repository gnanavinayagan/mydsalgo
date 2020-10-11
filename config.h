#include <iostream>
#include <initializer_list>


struct node
{
public:
	int data;
	node* next;

	node(): data(0), next(nullptr){}
	node(int val): data(val), next(nullptr){}
};