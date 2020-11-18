#include "Vector2.h"


Vector2::Vector2()
{
	x = y = 0.0f;
}

Vector2::Vector2(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

Vector2& Vector2::Add(const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2& Vector2::Subtract(const Vector2& vec)
{

	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2& Vector2::Multiply(const Vector2& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

Vector2& Vector2::Divide(const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	return this->Add(vec);
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	return this->Subtract(vec);
}


Vector2& Vector2::operator*=(const Vector2& vec)
{
	return this->Multiply(vec);
}

Vector2& Vector2::operator/=(const Vector2& vec)
{
	return this->Divide(vec);
}

Vector2& operator+(Vector2& v1, const Vector2& v2)
{
	return v1.Add(v2);
}

Vector2& operator-(Vector2& v1, const Vector2& v2)
{
	return v1.Subtract(v2);
}

Vector2& operator*(Vector2& v1, const Vector2& v2)
{
	return v1.Multiply(v2);
}

Vector2& operator/(Vector2& v1, const Vector2& v2)
{
	return v1.Subtract(v2);
}

std::ostream& operator<<(std::ostream& stream, const Vector2& vec)
{
	stream << "x::::" << vec.x << ",y:::::" << vec.y;
	return stream;
}



