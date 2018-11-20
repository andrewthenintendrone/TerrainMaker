#include "Bitmask.h"

Bitmask::Bitmask(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
	if (a)
	{
		m_byte |= 1;
	}
	if (b)
	{
		m_byte |= 2;
	}
	if (c)
	{
		m_byte |= 4;
	}
	if (d)
	{
		m_byte |= 8;
	}
	if (e)
	{
		m_byte |= 16;
	}
	if (f)
	{
		m_byte |= 32;
	}
	if (g)
	{
		m_byte |= 64;
	}
	if (h)
	{
		m_byte |= 128;
	}
}

bool Bitmask::getBit(int index)
{
	return (m_byte >> index) & (uint8_t)1;
}

void Bitmask::setBit(int index, bool value)
{
	m_byte ^= (-(uint8_t)value ^ m_byte) & ((uint8_t)1 << index);
}
