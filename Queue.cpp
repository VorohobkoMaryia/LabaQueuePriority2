#include <iostream>
#include "Queue.h"
#pragma warning(disable : 4996)

using namespace std;

void Queue::clear()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		pop();
	}
}
Queue::~Queue()
{
	clear();
}
void Queue::Clone(const Queue& rhs)
{
	
	Node* tmp = rhs.head;
	while (tmp != nullptr)
	{
		push(tmp->data, tmp->priority);
		tmp = tmp->next;
	}
}

Queue::Queue()
{
	count = 0;
	head = nullptr;
	rear_h = nullptr;
	rear_m = nullptr;
	rear_l = nullptr;
}
Queue::Queue(const Queue& rhs)
{
	clear();
	Clone(rhs);
}
Queue::Queue(Queue&& rhs) noexcept 
{
	move(head, rhs.head);
	move(rear_h, rhs.rear_h);
	move(rear_m, rhs.rear_m);
	move(rear_l, rhs.rear_l);
	
}
void Queue::move(Node*& rhs1, Node*& rhs2) noexcept 
{
	rhs1 = rhs2;
	rhs2 = nullptr;
}

Queue& Queue::operator=(const Queue& rhs)
{
	if (this != &rhs)
	{
		clear();
		Clone(rhs);
	}
	return *this;
}
Queue& Queue::operator= (Queue&& rhs) noexcept 
{
	if (this != &rhs)
	{
		clear();
		move(head, rhs.head);
		move(rear_h, rhs.rear_h);
		move(rear_m, rhs.rear_m);
		move(rear_l, rhs.rear_l);
	}
	return *this;
}
void Queue::Insert(Node*& rhs1, Node*& rhs2) noexcept 
{
	rhs1->next = rhs2;
	rhs2 = rhs1;
}
int Queue::size() const
{
	return count;
}
int Queue::size_high() const 
{
	return size_h;
}

int Queue::size_low() const 
{
	return size_l;
}

int Queue::size_medium() const 
{
	return size_m;
}
int Queue::getFirstValue() const
{
	if (count == 0)
		throw exception("ERROR: queue is empty");
	return head->data;
}
string Queue::getFirstPriority() const
{
	if (count == 0)
	{
		throw exception("ERROR: queue is empty");
	}
	switch (head->priority)
	{
	case Priority::rear_low:
		return "low";
	case Priority::rear_medium:
		return "medium";
	case Priority::rear_high:
		return "high";
	}
}
void Queue::push(int Data, Priority priority)
{
	Node* tmp = new Node;
	tmp->data = Data;
	tmp->priority = priority;
	count++;
	switch (priority)
	{
	case Priority::rear_high:
	{
		if (rear_h != nullptr)
		{
			Insert(tmp, rear_h->next);
		}
		else
		{
			Insert(tmp, head);
		}
		rear_h = tmp;
		size_h++;
		break;
	}
	case Priority::rear_medium: 
	{
		if (rear_m != nullptr) 
		{
			Insert(tmp, rear_m->next);
		}
		else if (rear_h != nullptr)
		{
			Insert(tmp, rear_h->next);
		}
		else 
		{
			Insert(tmp, head);
		}
		rear_m = tmp;
		size_m++;
		break;
	}
	case Priority::rear_low:
	{
		if (rear_l != nullptr)
		{
			Insert(tmp, rear_l->next);
		}
		else if (rear_m != nullptr)
		{
			Insert(tmp, rear_m->next);
		}
		else if (rear_h != nullptr)
		{
			Insert(tmp, rear_h->next);
		}
		else 
		{
			Insert(tmp, head);
		}
		rear_l = tmp;
		size_l++;
		break;
	}
	}
}

bool Queue::IsEmpty() const
{
	return (count == 0);
}
void Queue::pop()
{
	if (count == 0)
		throw exception("ERROR: queue is empty");

	Node* tmp = head;
	
	switch (head->priority) 
	{
	case Priority::rear_high:
	 rear_h = nullptr;
	 size_h--;
	 break;

	case Priority::rear_medium:
	 rear_m = nullptr;
	 size_m--;
	 break;

	case Priority::rear_low:
	 rear_l = nullptr;
	 size_l--;
	 break;
	}

	if (count== 1) 
	{
		head = nullptr;
	}
	else 
	{
		head = head->next;
	}
	delete tmp;
	count--;


}
ostream& operator<<(ostream& ost, const Queue& value)//оператор вывода
{
	Queue::Node* tmp = value.head;
	ost << "Список :\n";
	while (tmp != nullptr) 
	{
		ost << tmp->data << "\n";
		tmp = tmp->next;
	}
	return ost;
}