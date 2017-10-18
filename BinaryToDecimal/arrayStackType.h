#pragma once
#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

using namespace std;

const int MAX_STACK_SIZE = 10;

template <class Type>
class arrayStackType : public StackADT<Type> {
public:
	//constructor
	arrayStackType();
	arrayStackType(const arrayStackType<Type>& otherStack);
	~arrayStackType();
	void initializeStack();

	void resetStack();

	void push(const Type& newItem);

	void pop();

	Type top() const;

	bool isEmptyStack() const;

	bool isFullStack() const;

	//const arrayStackType<Type> &operator= (const ArrayStackType<Type>& otherStack);

protected:
	Type *list;
	int stackTop;

private:
	void copyStack(const arrayStackType<Type>& otherStack);

};

template<class Type>
void arrayStackType<Type>::initializeStack() {
	stackTop = 0;
}

template <class Type>
arrayStackType<Type>::arrayStackType()
{
	list = new Type[MAX_STACK_SIZE];
	stackTop = 0;
}

template <class Type>
arrayStackType<Type>::arrayStackType(const arrayStackType<Type>& otherStack)
{
	list = new Type[MAX_STACK_SIZE];
	copyStack(otherStack);
}

template <class Type>
void arrayStackType<Type>::copyStack(const arrayStackType<Type>& otherStack)
{
	stackTop = otherStack.stackTop;
	for (int i = 0; i < stackTop; i++)
		list[i] = otherStack.list[i];
}

template <class Type>
bool arrayStackType<Type>::isEmptyStack() const {
	return (stackTop == 0);
}

template <class Type>
bool arrayStackType<Type> ::isFullStack() const {
	return (stackTop == MAX_STACK_SIZE);
}

template <class Type>
void arrayStackType<Type>::push(const Type& newItem) {
	if (!isFullStack()) {
		list[stackTop] = newItem;
		stackTop++;
	}
	else
		cout << "The stack is full" << endl;

}

template <class Type>
void arrayStackType<Type>::pop() {
	if (!isEmptyStack())
	{
		stackTop--;
	}
	else
	{
		cout << "The stack is empty" << endl;
	}

}

template <class Type>
Type arrayStackType<Type>::top() const {
	if (!isEmptyStack())
		return list[stackTop - 1];

	else
	{
		cout << "Error: The stack is empty" << endl;
		exit(EXIT_FAILURE);
	}
}

template <class Type>
void arrayStackType<Type>::resetStack() {
	stackTop = 0;
}

template <class Type>
arrayStackType<Type>::~arrayStackType() {
	delete[] list;
}

#endif // !H_StackType
