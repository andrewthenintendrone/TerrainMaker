#pragma once
#include <vector>
#include <iostream>

template <class T>
class Array2D
{
public:

	Array2D(unsigned int width = 1, unsigned int height = 1)
	{
		m_width = width;
		m_height = height;
		m_totalSize = m_width * m_height;

		// create buffer
		m_buffer = new T[m_totalSize];
	}

	~Array2D() { delete[] m_buffer; }

	void operator = (const Array2D<T>& other)
	{
		delete[] m_buffer;

		m_width = other.m_width;
		m_height = other.m_height;
		m_totalSize = other.m_totalSize;
		
		m_buffer = new T[m_totalSize];

		for (size_t i = 0; i < m_totalSize; i++)
		{
			m_buffer[i] = other.m_buffer[i];
		}
	}

	bool operator == (const Array2D<T>& other)
	{
		if (m_width != other.m_width)
			return false;

		if (m_height != other.m_height)
			return false;

		for (unsigned int i = 0; i < m_totalSize; i++)
		{
			if (m_buffer[i] != other.m_buffer[i])
			{
				return false;
			}
		}

		return true;
	}

	const T& operator () (unsigned int x, unsigned int y) const
	{
		if (y * m_width + x < m_totalSize)
		{
			return m_buffer[y * m_width + x];
		}
		else
		{
			std::cout << "Tried to access element " << x << "-" << y << " of a " << m_width << "-" << m_height << " array" << std::endl;
			return m_buffer[0];
		}
	}

	T& operator () (unsigned int x, unsigned int y)
	{
		if (y * m_width + x < m_totalSize)
		{
			return m_buffer[y * m_width + x];
		}
		else
		{
			std::cout << "Tried to access element " << x << "-" << y << " of a " << m_width << "-" << m_height << " array" << std::endl;
			return m_buffer[0];
		}
	}

	unsigned int getWidth() const { return m_width; }
	unsigned int getHeight() const { return m_height; }
	unsigned int getTotalSize() const { return m_totalSize; }

private:

	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_totalSize;

	T* m_buffer = nullptr;
};
