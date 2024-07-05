typedef struct Point {
    double x;    // X座標
    double y;    // Y座標
    double z;    // Z座標
} Point;

typedef struct Angles {
    double a0;    // X座標
    double a1;    // Y座標
    double a2;    // Z座標
} Angles;

Angles IK_Calculate(Point);