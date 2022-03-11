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
	
	Queue();//создание списка
	Queue(const Queue& rhs);// конструктор копирования
	Queue(Queue&& rhs) noexcept;
	void move(Node*& rhs1, Node*& rhs2) noexcept;
	void Insert(Node*& rhs1, Node*& rhs2) noexcept;
	Queue& operator=(const Queue& rhs);//оператор присваивания
	Queue& operator=(Queue&& rhs) noexcept;
	
	~Queue();// Очистка памяти, удаление списка
	int size() const;// Возвращает количество элементов в списке
	int size_high() const;
	int size_low() const;
	int size_medium() const;
	void push(int data,Priority);// Добавление элемента
	void pop();// Удаление 
	bool IsEmpty() const;//проверка на пустоту
	int getFirstValue() const;
	string getFirstPriority() const;
	friend ostream& operator<<(ostream& ost, const Queue& value);//оператор вывода
	
};
