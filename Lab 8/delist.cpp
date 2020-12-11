#include "delist.h"
#include <iostream>
using namespace std;

  DEList::DEList(){
		start = nullptr;
		end = nullptr;
	}
  // Destructor to clean-up memory of current list
  DEList::~DEList(){
		DEItem* item = start;
		DEItem* temp;
		while(item!=nullptr){
			temp = item;
			item = temp->next;
			delete temp;
		}
		return;
	}
  // returns a Boolean 'true' if the list is empty
  bool DEList::empty(){
		if(start==nullptr&&end==nullptr)
			return true;
		return false;
	}
  // returns number of items in the list
  int DEList::size(){
		if(empty())
			return -1;
		int count = 0;
		DEItem* item = start;
		while(item != nullptr) {
			count++;
			item = item->next;
		}
		return count;
	}
  // returns front item or -1 if empty list
  int DEList::front(){
		if(empty())
			return -1;
		return start->val;
	}
  // returns back item or -1 if empty list
  int DEList::back(){
		if(empty())
			return -1;
		return end->val;
	}
  // Adds a new integer to the front of the list
  void DEList::push_front(int new_val){
		DEItem* item = new DEItem();
		item->val = new_val;
		item->prev = nullptr;
		item->next = start;
		if(!empty())
			start->prev = item;
		start = item;
		if(end==nullptr){
			end = item;
		}
	}
  // Adds a new integer to the back of the list
  void DEList::push_back(int new_val){
		DEItem* item = new DEItem();
		item->val = new_val;
		item->prev = end; 
		item->next = nullptr;
		if(!empty())
			end->next = item;
		end = item;
		if(start==nullptr){
			start = item;
		}
	}
  // Removes the front item of the list (if it exists)
  void DEList::pop_front(){
		DEItem *temp = start;
		if(size()>1){
			start->next->prev = nullptr;
			start = start->next;
		}
		else{
			start = nullptr;
			end = nullptr;
		}
		delete temp;
		}
  // Removes the back item of the list (if it exists)
  void DEList::pop_back(){
		DEItem *temp = end;
		if(size()>1){
			end->prev->next = nullptr;
			end = end->prev;
		}
		else{
			start = nullptr;
			end = nullptr;
		}
		delete temp;
	}
