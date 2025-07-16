#pragma once

class CTexture;

struct Vec2
{
	float x;
	float y;

public:
	float Length()
	{
		return sqrt(x * x + y * y);
	}

	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);

		x /= fLen;
		y /= fLen;
		
		return *this;
	}

public:
	Vec2 operator + (const Vec2& _vOther) { return Vec2(x + _vOther.x, y + _vOther.y); }
	Vec2 operator - (const Vec2& _vOther) { return Vec2(x - _vOther.x, y - _vOther.y); }
	Vec2 operator * (const Vec2& _vOther) { return Vec2(x * _vOther.x, y * _vOther.y); }
	Vec2 operator / (const Vec2& _vOther) { 
		assert(_vOther.x == 0.f || _vOther.y == 0.f);
		return Vec2(x + _vOther.x, y + _vOther.y); 
	}

	Vec2& operator = (POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}
public:
	Vec2()
		: x(0.f)
		, y(0.f)
	{ }
	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{ }
	Vec2(long _x, long _y)
		: x((float)_x)
		, y((float)_y)
	{}
	Vec2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{ }
	Vec2(POINT _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{ }
};

struct TextureDeleter {
	void operator()(CTexture* p) const {
		delete p;
	}
};

inline int randint(int min, int max)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}