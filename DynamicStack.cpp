#include "DynamicStack.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	items_ = new StackItem[16];
	size_ = 0;
	init_capacity_ = 16;
	capacity_ = init_capacity_;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	items_ = new StackItem[16];
	size_ = 0;
	
	if (capacity <= 0)
	{
		init_capacity_ = 16;
		capacity_ = init_capacity_;	
	}
	else
	{
		init_capacity_ = capacity;
		capacity_ = init_capacity_;
	}
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
	items_ = NULL;
}

bool DynamicStack::empty() const
{
	return (size_ == 0);
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if (size_ == capacity_)
	{
		StackItem* temp = new StackItem[capacity_];
		
		for (int i = 0; i < size_; i++)
			temp[i] = items_[i];

		capacity_ *= 2;
		items_ = new StackItem[capacity_];
		
		for (int i = 0; i < size_; i++)
			items_[i] = temp[i];
	}
		
	items_[size_] = value;
	size_++;
}

StackItem DynamicStack::pop()
{
	if (empty())
		return EMPTY_STACK;
	
	int temp = items_[size_-1];
	items_[size_-1] = NULL;
	size_--;
	
	if ((size_ <= capacity_/4) && (capacity_/2 >= init_capacity_))
	{
		StackItem* temp = new StackItem[capacity_];
		
		for (int i = 0; i < size_; i++)
			temp[i] = items_[i];
			
		capacity_ /= 2;
		items_ = new StackItem[capacity_];
		
		for (int i = 0; i < size_; i++)
			items_[i] = temp[i];
	}
	
	return temp;
}

StackItem DynamicStack::peek() const
{
	if (empty())
		return EMPTY_STACK;
	
	return items_[size_-1];
}

void DynamicStack::print() const
{
	cout << "(";
	for (int i = size_-1; i >= 0; i--)
	{
		cout << items_[i] << " , ";
	}
	cout << ")";
}
