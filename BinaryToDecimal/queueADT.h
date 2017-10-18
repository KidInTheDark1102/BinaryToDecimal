#pragma once
class queueADT {
public: 
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;

	virtual char front() const = 0;
	virtual char back() const = 0;

	virtual void addQueue(const char& queueElement) = 0;
	virtual void deleteQueue() = 0;

};