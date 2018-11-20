#pragma once
#include <cstdint>

class Bitmask
{
public:

	Bitmask() {};
	Bitmask(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h);

	bool getBit(int index);

	void setBit(int index, bool value);

	uint8_t getByte() const { return m_byte; }

private:

	uint8_t m_byte = 0;
};