#pragma once

class Vector2 {

private :
	int x;
	int y;

public:
	Vector2(int x, int y) : x(x), y(y) {}

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y+ other.y);
	}

	Vector2 operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2& operator=(const Vector2& other) {
		if (this != &other) {   
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	bool operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	int GetX() const { return x; }
	int GetY() const { return y; }
};