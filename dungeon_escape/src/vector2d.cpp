#include "vector2d.hpp"

// +=, -=, *=
Vector2D &operator+=(Vector2D &lhs, Vector2D &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;

    return lhs;
}
Vector2D &operator-=(Vector2D &lhs, Vector2D &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;

    return lhs;
}
Vector2D &operator*=(Vector2D &lhs, Vector2D &rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;

    return lhs;
}

// +, -, *
Vector2D operator+(Vector2D &lhs, Vector2D &rhs)
{
    Vector2D result(lhs);

    result.x = result.x + rhs.x;
    result.y = result.y + rhs.y;

    return result;
}
Vector2D operator-(Vector2D &lhs, Vector2D &rhs)
{
    Vector2D result(lhs);

    result.x = result.x - rhs.x;
    result.y = result.y - rhs.y;

    return result;
}
Vector2D operator*(Vector2D &lhs, Vector2D &rhs)
{
    Vector2D result(lhs);

    result.x = result.x * rhs.x;
    result.y = result.y * rhs.y;

    return result;
}

// Scalar
// +=, -=, *=
Vector2D &operator+=(Vector2D &lhs, int &rhs)
{
    lhs.x += rhs;
    lhs.y += rhs;

    return lhs;
}
Vector2D &operator-=(Vector2D &lhs, int &rhs)
{
    lhs.x -= rhs;
    lhs.y -= rhs;

    return lhs;
}
Vector2D &operator*=(Vector2D &lhs, int &rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;

    return lhs;
}

// Scalar
// +, -, *
Vector2D operator+(Vector2D &lhs, int &rhs)
{
    lhs.x += rhs;
    lhs.y += rhs;

    return lhs;
}
Vector2D operator-(Vector2D &lhs, int &rhs)
{
    Vector2D result(lhs);

    result.x -= rhs;
    result.y -= rhs;

    return result;
}
Vector2D operator*(Vector2D &lhs, int &rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;

    return lhs;
}

// Scalar
// +, -, *
Vector2D operator+(int &lhs, Vector2D &rhs)
{

    lhs += rhs.x;
    lhs += rhs.y;

    return rhs;
}
Vector2D operator-(int &lhs, Vector2D &rhs)
{
    Vector2D result(rhs);

    result.x = lhs - result.x;
    result.y = lhs - result.y;

    // result.x = result.x - lhs;
    // result.y = result.y - lhs;

    return result;
}
Vector2D operator*(int &lhs, Vector2D &rhs)
{
    lhs *= rhs.x;
    lhs *= rhs.y;

    return rhs;
}