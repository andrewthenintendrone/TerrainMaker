#pragma once
#include <vector>

template <class T, size_t W, size_t H>
class Array2D
{
public:
	const int width = W;
	const int height = H;

	Array2D() : buffer(width * height) {}

	const T& operator () (unsigned int x, unsigned int y) const
	{
		return buffer[y * width + x];
	}

	T& operator () (unsigned int x, unsigned int y)
	{
		return buffer[y * width + x];
	}

private:

	std::vector<T> buffer;
};