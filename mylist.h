#pragma once
#include "config.h"
#include <initializer_list>
using namespace std;



class List
{
private:
	node* head;
	size_t size;
public:
	List();
	List(node* i_node);
	List(std::initializer_list<int> i_list);

	//must 5
	List(const List& old_list);	
	List& operator=(const List& old_list);
	List(List&& old_list);
	List& operator=(List&& old_list);
	~List();


	node* gethead() const;
	size_t getsize() const;
	bool isEmpty() const;

	void insert_at(int pos, int val);
	void push_back(int val);
	void push_front(int val);

	void delete_at(int pos);
	void pop_back();
	void pop_front();
	void empty();

	void rec_print(node* n);
	void reverse();

	friend std::ostream& operator<<(std::ostream& os, const List& l);

};