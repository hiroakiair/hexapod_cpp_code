#include <iostream>
#include <hexapod/xr_hexapod_loop.h>
#include <hexapod/hexapod.h>
#include "custom.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
// 運動学ライブラリ
#include "kinematics_cal.h"

bool is_custom_mode = false;
#define PWM "PWM"   // PWMサーボ
#define UART "Uart" // シリアルバスサーボ

// ロボットタイプ
#define XR_ROBOT_TYPE_HEXAPOD "XR_ROBOT_TYPE_HEXAPOD"     // 六足
#define XR_ROBOT_TYPE_QUADRUPED "XR_ROBOT_TYPE_QUADRUPED" // 四足
XR_MovementMode _mode = XR_MOVEMENT_STANDBY;              // デフォルトは立つ待機モード
int ms_delay = 1000;
int del_t = 5;

int main(){
    hexapod::Hexapod.setRobotType(XR_ROBOT_TYPE_HEXAPOD); // ロボットのタイプを六足モードに設定
    XR_Action_Speed(5);                                   // 速度を5に初期化
    hexapod::Hexapod.init(
        _mode == XR_MOVEMENT_STANDBY,
        "www.xiao-r.com by liuviking",
        UART,
        true); // 六足のコアドライバの初期化、パラメータを変更しないでください！
    std::chrono::system_clock::time_point  start, end; // 型は auto で可
    // // ver1
    // 目標値
    Point target_p;
    target_p.x = 78.0; target_p.y = -20.0; target_p.z = -70;
    for (int k=0; k<30; k+=1){
        for (int i=0; i<40; i+=1){
            target_p.y = target_p.y + 1.0;
            target_p.z = target_p.z + 1.0;
            std::cout << "target_p.y: " << target_p.y << std::endl;
            Angles angles_0 = IK_Calculate(target_p);
            std::cout << "IKの計算結果(a0, a1, a2): " << angles_0.a0 << ", " << angles_0.a1 << ", " << angles_0.a2  << std::endl;
            XR_Set_Angle_For_Leg(0, angles_0.a0, angles_0.a1, angles_0.a2);
            usleep(del_t*ms_delay);
        }
        std::cout << "end_increment" << std::endl;
        for (int i=40; i>0; i-=1){
            target_p.y = target_p.y - 1.0;
            target_p.z = target_p.z - 1.0;
            std::cout << "target_p.y: " << target_p.y << std::endl;
            Angles angles_0 = IK_Calculate(target_p);
            std::cout << "IKの計算結果(a0, a1, a2): " << angles_0.a0 << ", " << angles_0.a1 << ", " << angles_0.a2  << std::endl;
            XR_Set_Angle_For_Leg(0, angles_0.a0, angles_0.a1, angles_0.a2);
            usleep(del_t*ms_delay);
        }
        std::cout << "end_decrement" << std::endl;
    }

    // ver2
    // XR_Set_Angle_For_Leg(0, 0, 0, 0);
    // usleep(1000*ms_delay);
    // XR_Set_Angle_For_Leg(0, 0, 120, 90);
    // usleep(1000*ms_delay);
    // for (int i = 90; i < 135; i += 1)
    // {
    //     start = std::chrono::system_clock::now(); // 計測開始時間
    //     XR_Set_Angle_For_Leg(0, i, 150, 90);
    //     usleep(del_t*ms_delay);
    //     end = std::chrono::system_clock::now();  // 計測終了時間
    //     double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    //     std::cout << "経過時間: " << elapsed << " ms" << std::endl;
    // }
    // for (int i = 90; i < 175; i += 1)
    // {
    //     XR_Set_Angle_For_Leg(0, 135, 150, i);
    //     usleep(del_t*ms_delay);
    // }

    // // XR_Run_Action_Loop
    // for (int i = 0; i < 1000; i += 1)
    // {
    //     XR_Run_Action_loop(XR_MOVEMENT_FORWARD);
    //     end = std::chrono::system_clock::now();  // 計測終了時間
    //     double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    //     std::cout << "経過時間: " << elapsed << " ms" << std::endl;
    // }
    // for (int i = 0; i < 1000; i += 1)
    // {
    //     XR_Run_Action_loop(XR_MOVEMENT_BACKWARD);
    //     end = std::chrono::system_clock::now();  // 計測終了時間
    //     double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
    //     std::cout << "経過時間: " << elapsed << " ms" << std::endl;
    // }

    return 0;
}