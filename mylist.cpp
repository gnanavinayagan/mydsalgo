#pragma once
#include <iostream>
#include "mylist.h"

using namespace std;

List::List(): head{nullptr}, size{0} {}

List::List(node *i_node): head{i_node}, size{0} 
{
    for(;i_node!=nullptr;i_node=i_node->next,++size);
}

List::List(std::initializer_list<int> i_list)
{
    for(auto &x : i_list)
    {
        push_back(x);
        ++size;
    }
}


List::List(const List& old_list)
{
    node* from_itr = old_list.head;

    head = new node(old_list.head->data);
    node* to_itr = head;
    while(from_itr->next !=nullptr)
    {
        to_itr->next = new node(from_itr->next->data);
        to_itr = to_itr->next;
        from_itr = from_itr->next;
    }
    size = old_list.getsize();
}

List& List::operator=(const List& from_list)
{
    if(this == &from_list)
        return *this;

    node* from_itr = from_list.head;
    
    head = new node(from_list.head->data);
    node* to_itr = head;

    while(from_itr->next !=nullptr)
    {
        to_itr->next = new node(from_itr->next->data);
        to_itr = to_itr->next;
        from_itr=from_itr->next;
    }
    size = from_list.size;
    return *this;
}

List::List(List&& old_list)
{
    head = old_list.head;
    size = old_list.size;

    old_list.head = nullptr;
}

List& List::operator=(List&& old_list)
{
    if(this == &old_list)
        return *this;

    head = old_list.head;
    size = old_list.size;

    old_list.head=nullptr;
    return *this;
}

List::~List()
{
    node* tmp;
    while(head!=nullptr)
    {
        tmp = head;
        head=head->next;
        delete tmp;
    }
}


node* List::gethead() const
{
    return head;
}

size_t List::getsize() const 
{
    return size;
}
bool List::isEmpty() const
{
    return head==nullptr;
}

//adding elements
void List::insert_at(int pos, int val)
{
    ++size;
    node* newnode = new node(val);
    if(head == nullptr)
    {
        head = newnode;
        return;
    }
    if(pos==1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    node* itr = head;
    for(int i=1; (itr->next!=nullptr && (i<pos-1));i++,itr=itr->next);
    newnode->next = itr->next;
    itr->next = newnode;
}

void List::push_back(int val)
{
    node* newnode = new node(val);
    if(head==nullptr)
    {
        head = newnode;
        return;
    }
    node *itr =  head;
    for(;itr->next!=nullptr;itr=itr->next);
    itr->next = newnode;
}

void List::push_front(int val)
{
    ++size;
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

//removing elements
void List::delete_at(int pos)
{
    if(pos>size)
        return;
    if(head ==nullptr)
        return;
    if(head->next == nullptr)
    {
        if(pos == 1)
        {
            size--;
            delete head;
            head = nullptr;
            return;
        }
    }
    if(pos == 1)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    node* itr = head;
    for(int i=1; i<pos-1; i++,itr=itr->next);
    node* temp;
    temp = itr->next;
    itr->next = itr->next->next;
    delete temp;
    size--;
    return;
}

void List::pop_back()
{
    node* temp;
    if(head==nullptr)
        return;
    size--;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    node* itr = head;
    for(;itr->next->next != nullptr;itr=itr->next);
    delete itr->next;
    itr->next = nullptr;
}

void List::pop_front()
{
    if(head == nullptr)
        return;
    size--;

    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    node* temp = head;
    head = head->next;
    delete temp;
}

void List::empty()
{
    if(head == nullptr)
        return;

    node* temp = head;
    while(head!=nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void List::rec_print(node* itr)
{
    if(itr!=nullptr)
    {
        rec_print(itr->next);
        cout<<itr->data<<" ";
    }
}

void List::reverse()
{
    node* cur = head;
    node* prev = nullptr, *next=nullptr;
    while(cur!=nullptr)
    {
        next = cur->next;
        cur->next = prev;
        next = next->next;
        prev = cur;
    }
    head = prev;
}

std::ostream& operator<<(std::ostream& os, const List& list)
{
    node* itr = list.head;
    
    os<<"\nList(" << list.size<<")";
    while(itr!=nullptr)
    {
        os<<itr->data <<" " <<itr<<endl;
        itr=itr->next;
    }
    return os;
}


int main()
{
    cout<<"\nFirst program";
    return 0;
}