/**
 * @file custom.cpp
 * @author ceoifung (ccf19960919@163.com)
 * @brief 自定义动作
 * @version 0.1
 * @date 2022-01-18
 *深圳市小二极客科技有限公司（小R科技）版权所有；您可以任意修改本代码，并应用于个人作品，但禁止用于商业盈利目的，小R科技保留诉诸法律追责的权利！
 *商务合作：微信18126008008；电话：18588257008；
 * @copyright Copyright (c) 2022
 * 
 */
#include "custom.h"

using namespace std;
extern XR_MovementMode _mode; 
extern bool is_custom_mode;
/**
 * @brief 打招呼动作
 * 
 */
int delay = 30 *1000;


void XR_HexapodAction_Hello()
{

    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, 150, i);
        // printf("sleep 1");
        usleep(delay);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 135; j += 5)
        {
            XR_Set_Angle_For_Leg(0, 135, 150, j);
            std::cout << "j: " << j <<  std::endl;
            usleep(delay);
        }

        for (int j = 135; j > 1; j -= 5)
        {
            XR_Set_Angle_For_Leg(0, 135, 150, j);
            std::cout << "j: " << j <<  std::endl;
            usleep(delay);
        }
    }
}

/**
 * @brief 再见动作
 * 
 */
void XR_HexapodAction_Bye()
{
    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, i, i);
        usleep(delay);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 135; j > 50; j -= 5)
        {
            XR_Set_Angle_For_Leg(0, j, 135, 135);
            usleep(delay);
        }
        for (int j = 50; j < 135; j += 5)
        {
            XR_Set_Angle_For_Leg(0, j, 135, 135);
            usleep(delay);
        }
    }
}

/**
 * @brief 盾山防御动作
 * 
 */
void XR_HexapodAction_Defense()
{

    XR_Set_Angle_For_Leg(1, 90, 100, 90);
    XR_Set_Angle_For_Leg(4, 90, 100, 90);

    XR_Set_Angle_For_Leg(1, 120, 100, 90);
    XR_Set_Angle_For_Leg(4, 60, 100, 90);

    XR_Set_Angle_For_Leg(1, 120, 90, 90); //两条中腿前移
    XR_Set_Angle_For_Leg(4, 60, 90, 90);

    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 90, i, 90);
        XR_Set_Angle_For_Leg(5, 90, i, 90);
        usleep(delay);
    }
    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, 150, 90);
        XR_Set_Angle_For_Leg(5, 180 - i, 150, 90);
        usleep(delay);
    }
    for (int i = 90; i < 175; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 135, 150, i);
        XR_Set_Angle_For_Leg(5, 45, 150, i);
        usleep(delay);
    }
    usleep(3000*1000);
}

/**
 * @brief 招财猫动作
 * 
 */
void XR_HexapodAction_FortuneCat()
{
    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 90, i, 90);
        usleep(delay);
    }
    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, 150, 90);
        usleep(delay);
    }

    for (int i = 0; i < 8; i++)
    {
        for (int i = 100; i < 135; i += 5)
        {
            XR_Set_Angle_For_Leg(0, 135, 150, i);
            usleep(delay);
        }

        for (int i = 135; i > 100; i -= 5)
        {
            XR_Set_Angle_For_Leg(0, 135, 150, i);
            usleep(delay);
        }
    }
}

/**
 * @brief 投降动作
 * 
 */
void XR_HexapodAction_Surrender()
{
    // for (int i = 0; i < 30; i += 2)
    // {
    //     XR_Set_Angle_For_Leg(1, 90 + i, 90, 90);
    //     usleep(10 * 1000);
    //     XR_Set_Angle_For_Leg(4, 90 - i, 90, 90);
    //     usleep(10 * 1000);
    // }
    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 90, i, 90);
        XR_Set_Angle_For_Leg(5, 90, i, 90);
        usleep(delay);
    }
    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, 150, 90);
        XR_Set_Angle_For_Leg(5, 180 - i, 150, 90);
        usleep(delay);
    }
    for (int i = 90; i < 175; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 135, 150, i);
        XR_Set_Angle_For_Leg(5, 45, 150, i);
        usleep(delay);
    }
    usleep(3000*1000);
}

/**
 * @brief 挑衅动作
 * 
 */
void XR_HexapodAction_Provocation()
{
    for(int i = 0; i < 30; i += 2){
        XR_Set_Angle_For_Leg(1, 90 + i, 90, 90);
        usleep(10 * 1000);
        XR_Set_Angle_For_Leg(4, 90 - i, 90, 90);
        usleep(10 * 1000);
    }
    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 90, i, 90);
        XR_Set_Angle_For_Leg(5, 90, i, 90);
        usleep(delay);
    }
    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, 150, 90);
        XR_Set_Angle_For_Leg(5, 180 - i, 150, 90);
        usleep(delay);
    }
    for (int i = 90; i < 175; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 135, 150, i);
        XR_Set_Angle_For_Leg(5, 45, 150, i);
        usleep(delay);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int i = 175; i > 0; i -= 8)
        {
            XR_Set_Angle_For_Leg(0, 135, 150, i);
            XR_Set_Angle_For_Leg(5, 45, 150, i);
            usleep(delay);
        }

        for (int i = 0; i < 175; i += 8)
        {
            XR_Set_Angle_For_Leg(0, 135, 150, i);
            XR_Set_Angle_For_Leg(5, 45, 150, i);
            usleep(delay);
        }
    }
}

/**
 * @brief 伸懒腰动作
 * 
 */
void XR_HexapodAction_Stretch()
{

    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 90, i, 90);
        XR_Set_Angle_For_Leg(5, 90, i, 90);
        usleep(delay);
    } //抬起前腿
    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(0, i, 150, 90);
        XR_Set_Angle_For_Leg(5, 180 - i, 150, 90);
        usleep(delay);
    } //前腿转到正前方

    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(1, 90, i, 90);
        XR_Set_Angle_For_Leg(4, 90, i, 90);
        usleep(delay);
    } //抬起中腿

    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(1, i, 150, 90);
        XR_Set_Angle_For_Leg(4, 180 - i, 150, 90);
        usleep(delay);
    } //中腿转到前方

    for (int i = 90; i < 170; i += 3)
    {
        XR_Set_Angle_For_Leg(2, 45, 90, i);
        XR_Set_Angle_For_Leg(3, 135, 90, i);
        usleep(delay);
    } //后腿伸直

    for (int i = 90; i < 135; i += 3)
    {
        XR_Set_Angle_For_Leg(2, 180 - i, 90, 170);
        XR_Set_Angle_For_Leg(3, i, 90, 170);
        usleep(delay);
    } //后腿并拢
    usleep(3000 * 1000);
}

/**
 * @brief 热身动作
 * 
 */
void XR_HexapodAction_Warmup()
{
    for (int i = 0; i < 6; i += 1)
    {
        for (int j = 90; j < 175; j += 3)
        {
            XR_Set_Angle_For_Leg(i, 90, j, j);
            usleep(delay);
        }

        for (int j = 175; j > 90; j -= 3)
        {
            XR_Set_Angle_For_Leg(i, 90, j, j);
            usleep(delay);
        }
    }
}

/**
 * @brief 变身板凳动作
 * 
 */
void XR_HexapodAction_Bench()
{

    for (int i = 0; i < 6; i += 1)
    {
        if (i == 0 || i == 2 || i == 3 || i == 5)
        {
            XR_Set_Angle_For_Leg(i, 90, 1, 170);
            usleep(delay);
        }
        else
        {
            XR_Set_Angle_For_Leg(i, 90, 1, 60);
            usleep(delay);
        }
    }
    usleep(3000 * 1000);
}

/**
 * @brief 不要不要动作
 * 
 */
void XR_HexapodAction_NoNoNo()
{

    XR_Set_Angle_For_Leg(1, 90, 100, 90);
    XR_Set_Angle_For_Leg(4, 90, 100, 90);

    XR_Set_Angle_For_Leg(1, 120, 100, 90);
    XR_Set_Angle_For_Leg(4, 60, 100, 90);

    XR_Set_Angle_For_Leg(1, 120, 90, 90); //两条中腿前移
    XR_Set_Angle_For_Leg(4, 60, 90, 90);

    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 80, i, 90);
        XR_Set_Angle_For_Leg(5, 80, i, 90);
        usleep(delay);
    }

    for (int i = 90; i < 175; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 135, 150, i);
        XR_Set_Angle_For_Leg(5, 45, 150, i);
        usleep(delay);
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 80; i < 110; i += 6)
        {
            XR_Set_Angle_For_Leg(0, i, 150, 175);
            XR_Set_Angle_For_Leg(5, 180 - i, 150, 175);
            usleep(delay);
        }

        for (int i = 110; i > 80; i -= 6)
        {
            XR_Set_Angle_For_Leg(0, i, 150, 175);
            XR_Set_Angle_For_Leg(5, 180 - i, 150, 175);
            usleep(delay);
        }
    }
}

/**
 * @brief 膜拜动作
 * 
 */
void XR_HexapodAction_Respect()
{
    XR_Set_Angle_For_Leg(1, 90, 100, 90);
    XR_Set_Angle_For_Leg(4, 90, 100, 90);

    XR_Set_Angle_For_Leg(1, 120, 100, 90);
    XR_Set_Angle_For_Leg(4, 60, 100, 90);

    XR_Set_Angle_For_Leg(1, 120, 90, 90); //两条中腿前移
    XR_Set_Angle_For_Leg(4, 60, 90, 90);

    for (int i = 90; i < 150; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 80, i, 90);
        XR_Set_Angle_For_Leg(5, 80, i, 90);
        usleep(delay);
    }

    for (int i = 90; i < 175; i += 3)
    {
        XR_Set_Angle_For_Leg(0, 135, 150, i);
        XR_Set_Angle_For_Leg(5, 45, 150, i);
        usleep(delay);
    }

    for (int j = 0; j < 6; j++)
    {
        for (int i = 90; i < 100; i += 3)
        {
            XR_Set_Angle_For_Leg(1, 120, i, 90); //屈曲
            XR_Set_Angle_For_Leg(4, 60, i, 90);
            usleep(delay);
        }

        for (int i = 100; i > 90; i -= 3)
        {
            XR_Set_Angle_For_Leg(1, 120, i, 90);
            XR_Set_Angle_For_Leg(4, 60, i, 90);
            usleep(delay);
        }
    }
}

/**
 * @brief 装死动作
 * 
 */
void XR_HexapodAction_PlayDead()
{
    for (int j = 0; j < 6; j++)
    {
        for (int i = 90; i < 175; i += 6)
        {
            XR_Set_Angle_For_Leg(j, 90, 90, i);
            usleep(delay);
        }
    }

    for (int i = 90; i < 135; i += 6)
    {
        XR_Set_Angle_For_Leg(2, 180 - i, 90, 175);
        XR_Set_Angle_For_Leg(3, i, 90, 175);
        usleep(delay);
    } //后腿并拢

    for (int i = 90; i < 135; i += 6)
    {
        XR_Set_Angle_For_Leg(0, i, 90, 175);
        XR_Set_Angle_For_Leg(5, 180 - i, 90, 175);
        usleep(delay);
    } //前腿并拢

    for (int j = 0; j < 6; j++)
    {
        for (int i = 175; i > 145; i -= 5)
        {
            XR_Set_Angle_For_Leg(2, 45, 90, i);
            XR_Set_Angle_For_Leg(3, 135, 90, i);

            XR_Set_Angle_For_Leg(0, 135, 90, i);
            XR_Set_Angle_For_Leg(5, 45, 90, i);
            usleep(delay);
        }

        for (int i = 145; i < 175; i += 5)
        {
            XR_Set_Angle_For_Leg(2, 45, 90, i);
            XR_Set_Angle_For_Leg(3, 135, 90, i);

            XR_Set_Angle_For_Leg(0, 135, 90, i);
            XR_Set_Angle_For_Leg(5, 45, 90, i);
            usleep(delay);
        }
    }
}

/**
 * @brief 展厅模式
 * 
 */
void XR_HexapodAction_Exhibition_Mode()
{
      is_custom_mode = false;
      while (1)
      {
        cout << "展厅模式 ing" << endl;
        _mode = XR_MOVEMENT_FORWARD;
        usleep(30*1000*50);
        _mode = XR_MOVEMENT_STANDBY;
        usleep(30*1000*100);
        _mode = XR_MOVEMENT_BACKWARD;
        usleep(30*1000*50);
        _mode = XR_MOVEMENT_STANDBY;
        usleep(30*1000*100);

        _mode = XR_MOVEMENT_TWIST;
        usleep(30*1000*100);
        _mode = XR_MOVEMENT_STANDBY;
        usleep(30*1000*100);

        _mode = XR_MOVEMENT_TURNLEFT;
        usleep(30*1000*50);
        _mode = XR_MOVEMENT_STANDBY;
        usleep(30*1000*100);

        _mode = XR_MOVEMENT_TURNRIGHT;
        usleep(30*1000*50);
        _mode = XR_MOVEMENT_STANDBY;
        usleep(30*1000*100);
        _mode = XR_MOVEMENT_ROTATEZ;
        usleep(30*1000*100);
        _mode = XR_MOVEMENT_STANDBY;
        usleep(30*1000*800);
      }
      

}