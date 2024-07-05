#include <stdio.h>
#include <cmath>
#include "kinematics_cal.h"

Angles IK_Calculate(Point target_point){
    Angles return_angles;

    double l1 = 36.0; double l2 = 42.0; double l3 = 84.0;
    // target position (mm)
    double x, y, z;
    x = target_point.x;
    y = target_point.y;
    z = target_point.z;
    // answer angle (rad)
    double a0, a1, a2;

    // claculate inverse kinematics (x,y,z)->(a0,a1,a2)
    // for a0
    a0 = std::atan2(y, x);
    // transfer coordinate system
    double xp = std::sqrt(x*x + y*y) - l1;
    double yp = z;
    // for a2
    double lr = std::sqrt(xp*xp + yp*yp);
    a2 = std::acos((-lr*lr + l2*l2 + l3*l3)/(2*l2*l3));
    //for a1
    a1 = std::atan2((l2-l3*std::cos(a2))*xp - l3*std::sin(a2)*yp, -l3*std::sin(a2)*xp + (-l2+l3*std::cos(a2))*yp);

    // adjust rad (-pi~0)->(-pi~pi)
    a0 = a0 + M_PI/2;



    return_angles.a0 = 180.0/M_PI * a0;
    return_angles.a1 = 180.0/M_PI * a1;
    return_angles.a2 = 180.0/M_PI * a2;

    return return_angles;
}