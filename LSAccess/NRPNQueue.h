#pragma once

#include <queue>

class NRPNQueue: public std::queue <unsigned int>
{
public:
	NRPNQueue()
	{};
	
	void Push(unsigned int nNRPN)
	{
		m_NRPNQueue.push(nNRPN);
	};

	unsigned int Front()
	{
		return m_NRPNQueue.front();
	};

	void Pop()
	{
		m_NRPNQueue.pop();
	};

private:
	std::queue <unsigned int> m_NRPNQueue;
};
