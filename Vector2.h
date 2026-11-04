

#pragma once

struct Vector2
{
    int x = 0;
    int y = 0;

    Vector2(int x = 0, int y = 0) : x(x), y(y) {}

    Vector2 operator+(const Vector2& o) const { return Vector2(x + o.x, y + o.y); }
    Vector2 operator-(const Vector2& o) const { return Vector2(x - o.x, y - o.y); }
    bool operator==(const Vector2& o) const { return x == o.x && y == o.y; }
};