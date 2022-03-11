#pragma once
#include <iostream>


using namespace std;

enum class Priority 
{
	rear_high,
	rear_medium,
	rear_low,
};

class Queue
{
private:
	struct Node
	{
		int data;
		Node* next;
		Priority priority;
	};
	int count;
	int size_h;
	int size_m;
	int size_l;
	Node* head;
	Node* rear_h;
	Node* rear_m;
	Node* rear_l;
	void clear();
	void Clone(const Queue&);
	

public:
	
	Queue();//�������� ������
	Queue(const Queue& rhs);// ����������� �����������
	Queue(Queue&& rhs) noexcept;
	void move(Node*& rhs1, Node*& rhs2) noexcept;
	void Insert(Node*& rhs1, Node*& rhs2) noexcept;
	Queue& operator=(const Queue& rhs);//�������� ������������
	Queue& operator=(Queue&& rhs) noexcept;
	
	~Queue();// ������� ������, �������� ������
	int size() const;// ���������� ���������� ��������� � ������
	int size_high() const;
	int size_low() const;
	int size_medium() const;
	void push(int data,Priority);// ���������� ��������
	void pop();// �������� 
	bool IsEmpty() const;//�������� �� �������
	int getFirstValue() const;
	string getFirstPriority() const;
	friend ostream& operator<<(ostream& ost, const Queue& value);//�������� ������
	
};
