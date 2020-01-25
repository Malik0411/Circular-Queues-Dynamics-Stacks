#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	size_ = 0;
	capacity_ = 16;
	head_ = 0;
	tail_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[16];
	size_ = 0;
	
	if (capacity <= 0)
		capacity_ = 16;
		
	else
		capacity_ = capacity;
		
	head_ = 0;
	tail_ = 0;
}

CircularQueue::~CircularQueue()
{
	delete []items_;
	items_ = NULL;
}

bool CircularQueue::empty() const
{    
	return (size_ == 0);
}

bool CircularQueue::full() const
{
	return (size_ == capacity_);
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (full())
		return false;
		
	else if (empty())
	{
		items_[0] = value;
		head_ = 0;
		tail_ = 1;
		size_++;
		return true;
	}
	
	else if (tail_ == capacity_-1)
	{
		items_[tail_] = value;
		tail_ = 0;
		size_++;
		return true;
	}
	
	else
	{	
		items_[tail_] = value;
		tail_++;
		size_++;
		return true;
	}	
}

QueueItem CircularQueue::dequeue()
{
	if (empty())
		return EMPTY_QUEUE;
	
	else if (head_ == capacity_-1)
	{
		QueueItem temp = items_[head_];
		items_[head_] = NULL;
		head_ = 0;
		size_--;
			
		return temp;
	}
	
	else
	{	
		QueueItem temp = items_[head_];
		items_[head_] = NULL;
		head_++;
		size_--;
			
		return temp;
	}
}

QueueItem CircularQueue::peek() const
{
	if (empty())
		return EMPTY_QUEUE;
		
	return items_[head_];
}

void CircularQueue::print() const
{
	cout << "(";
	for (int i = 0; i < size_; i++)
	{
		cout << items_[i] << " , ";
	}
	cout << ")" << endl;
}
