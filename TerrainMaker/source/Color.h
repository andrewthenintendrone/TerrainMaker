#pragma once
#include <cstdint>
#include <algorithm>

class Color
{
public:

	// constructors

	Color()
	{
		value = 0xFFFFFF;
	}

	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}

	Color(uint32_t hexCode)
	{
		value = hexCode;
	}

	// union
	union
	{
		struct
		{
			uint8_t a;
			uint8_t b;
			uint8_t g;
			uint8_t r;
		};
		uint32_t value;
	};

	void operator = (const Color& other)
	{
		value = other.value;
	}

	Color operator + (const Color& other) const
	{
		return Color(value + other.value);
	}

	void operator += (const Color& other)
	{
		value += other.value;
	}

	Color operator - (const Color& other) const
	{
		return Color(value - other.value);
	}

	void operator -= (const Color& other)
	{
		value -= other.value;
	}

#pragma region constants

	static Color AliceBlue()
	{
		return Color(0xF0F8FFFF);
	}

	static Color AntiqueWhite()
	{
		return Color(0xFAEBD7FF);
	}

	static Color Aqua()
	{
		return Color(0x00FFFFFF);
	}

	static Color Aquamarine()
	{
		return Color(0x7FFFD4FF);
	}

	static Color Azure()
	{
		return Color(0xF0FFFFFF);
	}

	static Color Beige()
	{
		return Color(0xF5F5DCFF);
	}

	static Color Bisque()
	{
		return Color(0xFFE4C4FF);
	}

	static Color Black()
	{
		return Color(0x000000FF);
	}

	static Color BlanchedAlmond()
	{
		return Color(0xFFEBCDFF);
	}

	static Color Blue()
	{
		return Color(0x0000FFFF);
	}

	static Color BlueViolet()
	{
		return Color(0x8A2BE2FF);
	}

	static Color Brown()
	{
		return Color(0xA52A2AFF);
	}

	static Color BurlyWood()
	{
		return Color(0xDEB887FF);
	}

	static Color CadetBlue()
	{
		return Color(0x5F9EA0FF);
	}

	static Color Chartreuse()
	{
		return Color(0x7FFF00FF);
	}

	static Color Chocolate()
	{
		return Color(0xD2691EFF);
	}

	static Color Coral()
	{
		return Color(0xFF7F50FF);
	}

	static Color CornflowerBlue()
	{
		return Color(0x6495EDFF);
	}

	static Color Cornsilk()
	{
		return Color(0xFFF8DCFF);
	}

	static Color Crimson()
	{
		return Color(0xDC143CFF);
	}

	static Color Cyan()
	{
		return Color(0x00FFFFFF);
	}

	static Color DarkBlue()
	{
		return Color(0x00008BFF);
	}

	static Color DarkCyan()
	{
		return Color(0x008B8BFF);
	}

	static Color DarkGoldenRod()
	{
		return Color(0xB8860BFF);
	}

	static Color DarkGray()
	{
		return Color(0xA9A9A9FF);
	}

	static Color DarkGrey()
	{
		return Color(0xA9A9A9FF);
	}

	static Color DarkGreen()
	{
		return Color(0x006400FF);
	}

	static Color DarkKhaki()
	{
		return Color(0xBDB76BFF);
	}

	static Color DarkMagenta()
	{
		return Color(0x8B008BFF);
	}

	static Color DarkOliveGreen()
	{
		return Color(0x556B2FFF);
	}

	static Color DarkOrange()
	{
		return Color(0xFF8C00FF);
	}

	static Color DarkOrchid()
	{
		return Color(0x9932CCFF);
	}

	static Color DarkRed()
	{
		return Color(0x8B0000FF);
	}

	static Color DarkSalmon()
	{
		return Color(0xE9967AFF);
	}

	static Color DarkSeaGreen()
	{
		return Color(0x8FBC8FFF);
	}

	static Color DarkSlateBlue()
	{
		return Color(0x483D8BFF);
	}

	static Color DarkSlateGray()
	{
		return Color(0x2F4F4FFF);
	}

	static Color DarkSlateGrey()
	{
		return Color(0x2F4F4FFF);
	}

	static Color DarkTurquoise()
	{
		return Color(0x00CED1FF);
	}

	static Color DarkViolet()
	{
		return Color(0x9400D3FF);
	}

	static Color DeepPink()
	{
		return Color(0xFF1493FF);
	}

	static Color DeepSkyBlue()
	{
		return Color(0x00BFFFFF);
	}

	static Color DimGray()
	{
		return Color(0x696969FF);
	}

	static Color DimGrey()
	{
		return Color(0x696969FF);
	}

	static Color DodgerBlue()
	{
		return Color(0x1E90FFFF);
	}

	static Color FireBrick()
	{
		return Color(0xB22222FF);
	}

	static Color FloralWhite()
	{
		return Color(0xFFFAF0FF);
	}

	static Color ForestGreen()
	{
		return Color(0x228B22FF);
	}

	static Color Fuchsia()
	{
		return Color(0xFF00FFFF);
	}

	static Color Gainsboro()
	{
		return Color(0xDCDCDCFF);
	}

	static Color GhostWhite()
	{
		return Color(0xF8F8FFFF);
	}

	static Color Gold()
	{
		return Color(0xFFD700FF);
	}

	static Color GoldenRod()
	{
		return Color(0xDAA520FF);
	}

	static Color Gray()
	{
		return Color(0x808080FF);
	}

	static Color Grey()
	{
		return Color(0x808080FF);
	}

	static Color Green()
	{
		return Color(0x008000FF);
	}

	static Color GreenYellow()
	{
		return Color(0xADFF2FFF);
	}

	static Color HoneyDew()
	{
		return Color(0xF0FFF0FF);
	}

	static Color HotPink()
	{
		return Color(0xFF69B4FF);
	}

	static Color IndianRed()
	{
		return Color(0xCD5C5CFF);
	}

	static Color Indigo()
	{
		return Color(0x4B0082FF);
	}

	static Color Ivory()
	{
		return Color(0xFFFFF0FF);
	}

	static Color Khaki()
	{
		return Color(0xF0E68CFF);
	}

	static Color Lavender()
	{
		return Color(0xE6E6FAFF);
	}

	static Color LavenderBlush()
	{
		return Color(0xFFF0F5FF);
	}

	static Color LawnGreen()
	{
		return Color(0x7CFC00FF);
	}

	static Color LemonChiffon()
	{
		return Color(0xFFFACDFF);
	}

	static Color LightBlue()
	{
		return Color(0xADD8E6FF);
	}

	static Color LightCoral()
	{
		return Color(0xF08080FF);
	}

	static Color LightCyan()
	{
		return Color(0xE0FFFFFF);
	}

	static Color LightGoldenRodYellow()
	{
		return Color(0xFAFAD2FF);
	}

	static Color LightGray()
	{
		return Color(0xD3D3D3FF);
	}

	static Color LightGrey()
	{
		return Color(0xD3D3D3FF);
	}

	static Color LightGreen()
	{
		return Color(0x90EE90FF);
	}

	static Color LightPink()
	{
		return Color(0xFFB6C1FF);
	}

	static Color LightSalmon()
	{
		return Color(0xFFA07AFF);
	}

	static Color LightSeaGreen()
	{
		return Color(0x20B2AAFF);
	}

	static Color LightSkyBlue()
	{
		return Color(0x87CEFAFF);
	}

	static Color LightSlateGray()
	{
		return Color(0x778899FF);
	}

	static Color LightSlateGrey()
	{
		return Color(0x778899FF);
	}

	static Color LightSteelBlue()
	{
		return Color(0xB0C4DEFF);
	}

	static Color LightYellow()
	{
		return Color(0xFFFFE0FF);
	}

	static Color Lime()
	{
		return Color(0x00FF00FF);
	}

	static Color LimeGreen()
	{
		return Color(0x32CD32FF);
	}

	static Color Linen()
	{
		return Color(0xFAF0E6FF);
	}

	static Color Magenta()
	{
		return Color(0xFF00FFFF);
	}

	static Color Maroon()
	{
		return Color(0x800000FF);
	}

	static Color MediumAquaMarine()
	{
		return Color(0x66CDAAFF);
	}

	static Color MediumBlue()
	{
		return Color(0x0000CDFF);
	}

	static Color MediumOrchid()
	{
		return Color(0xBA55D3FF);
	}

	static Color MediumPurple()
	{
		return Color(0x9370DBFF);
	}

	static Color MediumSeaGreen()
	{
		return Color(0x3CB371FF);
	}

	static Color MediumSlateBlue()
	{
		return Color(0x7B68EEFF);
	}

	static Color MediumSpringGreen()
	{
		return Color(0x00FA9AFF);
	}

	static Color MediumTurquoise()
	{
		return Color(0x48D1CCFF);
	}

	static Color MediumVioletRed()
	{
		return Color(0xC71585FF);
	}

	static Color MidnightBlue()
	{
		return Color(0x191970FF);
	}

	static Color MintCream()
	{
		return Color(0xF5FFFAFF);
	}

	static Color MistyRose()
	{
		return Color(0xFFE4E1FF);
	}

	static Color Moccasin()
	{
		return Color(0xFFE4B5FF);
	}

	static Color NavajoWhite()
	{
		return Color(0xFFDEADFF);
	}

	static Color Navy()
	{
		return Color(0x000080FF);
	}

	static Color OldLace()
	{
		return Color(0xFDF5E6FF);
	}

	static Color Olive()
	{
		return Color(0x808000FF);
	}

	static Color OliveDrab()
	{
		return Color(0x6B8E23FF);
	}

	static Color Orange()
	{
		return Color(0xFFA500FF);
	}

	static Color OrangeRed()
	{
		return Color(0xFF4500FF);
	}

	static Color Orchid()
	{
		return Color(0xDA70D6FF);
	}

	static Color PaleGoldenRod()
	{
		return Color(0xEEE8AAFF);
	}

	static Color PaleGreen()
	{
		return Color(0x98FB98FF);
	}

	static Color PaleTurquoise()
	{
		return Color(0xAFEEEEFF);
	}

	static Color PaleVioletRed()
	{
		return Color(0xDB7093FF);
	}

	static Color PapayaWhip()
	{
		return Color(0xFFEFD5FF);
	}

	static Color PeachPuff()
	{
		return Color(0xFFDAB9FF);
	}

	static Color Peru()
	{
		return Color(0xCD853FFF);
	}

	static Color Pink()
	{
		return Color(0xFFC0CBFF);
	}

	static Color Plum()
	{
		return Color(0xDDA0DDFF);
	}

	static Color PowderBlue()
	{
		return Color(0xB0E0E6FF);
	}

	static Color Purple()
	{
		return Color(0x800080FF);
	}

	static Color RebeccaPurple()
	{
		return Color(0x663399FF);
	}

	static Color Red()
	{
		return Color(0xFF0000FF);
	}

	static Color RosyBrown()
	{
		return Color(0xBC8F8FFF);
	}

	static Color RoyalBlue()
	{
		return Color(0x4169E1FF);
	}

	static Color SaddleBrown()
	{
		return Color(0x8B4513FF);
	}

	static Color Salmon()
	{
		return Color(0xFA8072FF);
	}

	static Color SandyBrown()
	{
		return Color(0xF4A460FF);
	}

	static Color SeaGreen()
	{
		return Color(0x2E8B57FF);
	}

	static Color SeaShell()
	{
		return Color(0xFFF5EEFF);
	}

	static Color Sienna()
	{
		return Color(0xA0522DFF);
	}

	static Color Silver()
	{
		return Color(0xC0C0C0FF);
	}

	static Color SkyBlue()
	{
		return Color(0x87CEEBFF);
	}

	static Color SlateBlue()
	{
		return Color(0x6A5ACDFF);
	}

	static Color SlateGray()
	{
		return Color(0x708090FF);
	}

	static Color SlateGrey()
	{
		return Color(0x708090FF);
	}

	static Color Snow()
	{
		return Color(0xFFFAFAFF);
	}

	static Color SpringGreen()
	{
		return Color(0x00FF7FFF);
	}

	static Color SteelBlue()
	{
		return Color(0x4682B4FF);
	}

	static Color Tan()
	{
		return Color(0xD2B48CFF);
	}

	static Color Teal()
	{
		return Color(0x008080FF);
	}

	static Color Thistle()
	{
		return Color(0xD8BFD8FF);
	}

	static Color Tomato()
	{
		return Color(0xFF6347FF);
	}

	static Color Turquoise()
	{
		return Color(0x40E0D0FF);
	}

	static Color Violet()
	{
		return Color(0xEE82EEFF);
	}

	static Color Wheat()
	{
		return Color(0xF5DEB3FF);
	}

	static Color White()
	{
		return Color(0xFFFFFFFF);
	}

	static Color WhiteSmoke()
	{
		return Color(0xF5F5F5FF);
	}

	static Color Yellow()
	{
		return Color(0xFFFF00FF);
	}

	static Color YellowGreen()
	{
		return Color(0x9ACD32FF);
	}


#pragma endregion

};