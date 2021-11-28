#pragma once
#include <cassert>
#include "PriorityQueueLinkedList.h"
template <class T, class CMP>

class PriorityQueue
{

public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}

	~PriorityQueue();


	//Priority Queue Functions

	void push(T val)
	{
		assert(m_elements.GetSize() < m_size);


		if(m_elements.GetSize() == 0)
		{
			m_elements.Push_Front(val);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			CMP cmp; // Placeholder for comparisons

			while(it.isValid())
			{
				if(cmp(val, *it))
				{
					break;
				}
			}

			if(it.isValid())
			{
				m_elements.Insert_Before(it, val);
			}
			else
			{
				m_elements.Push_Front();
			}
		}
	}

	void pop()
	{
		m_elements.Pop_Front();
	}


	//helper functions


	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();
		return *it;
	}
	T& back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
		
	}

	int getSize()
	{
		return m_elements.GetSize();
	}

	int getMaxSize()
	{
		return m_size;
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}
	void resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}


private:
	LinkedList<T> m_elements;
	int m_size;
};
