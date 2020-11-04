#pragma once

struct Vector2D
{
    int x;
    int y;
};

struct Scalar
{
    int x;
};

// +=, -=, *
Vector2D &operator+=(Vector2D &lhs, Vector2D &rhs);
Vector2D &operator-=(Vector2D &lhs, Vector2D &rhs);
Vector2D &operator*=(Vector2D &lhs, Vector2D &rhs);

// +, -, *
Vector2D operator+(Vector2D &lhs, Vector2D &rhs);
Vector2D operator-(Vector2D &lhs, Vector2D &rhs);
Vector2D operator*(Vector2D &lhs, Vector2D &rhs);

// Scalar
// +=, -=, *=
Vector2D &operator+=(Vector2D &lhs, int &rhs);
Vector2D &operator-=(Vector2D &lhs, int &rhs);
Vector2D &operator*=(Vector2D &lhs, int &rhs);

// Scalar
// +, -, *
Vector2D operator+(Vector2D &lhs, int &rhs);
Vector2D operator-(Vector2D &lhs, int &rhs);
Vector2D operator*(Vector2D &lhs, int &rhs);

// Scalar
// +, -, *
Vector2D operator+(int &lhs, Vector2D &rhs);
Vector2D operator-(int &lhs, Vector2D &rhs);
Vector2D operator*(int &lhs, Vector2D &rhs);

// Scalar as INT
// +=, -=, +=
// Vector2D &operator*=(int &lhs, const int &rhs);
// Vector2D &operator-=(int &lhs, const int &rhs);
// Vector2D &operator*=(int &lhs, const int &rhs);