#ifndef VECTOR2_H
#define VECTOR2_H
#include <iostream>
#include <cmath>

struct Vector2 {
    int X;
    int Y;
    float Xf;
    float Yf;

    Vector2();
    Vector2(int curr_posX, int curr_posY);
    Vector2(float curr_posXf, float curr_posYf);

    template <typename T1, typename T2>
    static float distanceBetweenCenters(const T1& circle1, const T2& circle2);

    template <typename T1, typename T2>
    static Vector2 deltaVector(const T1& circle1, const T2& circle2);
};


template<typename T1, typename T2>
inline float Vector2::distanceBetweenCenters(const T1& circle1, const T2& circle2)
{
    float dx = circle2.getPos().X - circle1.getPos().X;
    float dy = circle2.getPos().Y - circle1.getPos().Y;
    return std::sqrt(dx * dx + dy * dy);
}

template<typename T1, typename T2>
inline Vector2 Vector2::deltaVector(const T1& circle1, const T2& circle2)
{
    return Vector2(
        static_cast<float>(circle2.getPos().X - circle1.getPos().X),
        static_cast<float>(circle2.getPos().Y - circle1.getPos().Y)
    );
}

#endif