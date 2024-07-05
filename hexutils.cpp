/**
 * @file hexutils.cpp
 * @author ceoifung (ccf19960919@163.com)
 * @brief 16进制转换工具
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "hexutils.h"

int hexCharToInt(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    return 0;
}

/**
 * @brief 16进制字符串转bytes数组
 *
 * @param s
 * @return char*
 */
char *hexstringToBytes(std::string s)
{
    int sz = s.length();
    char *ret = new char[sz / 2];
    for (int i = 0; i < sz; i += 2)
    {
        ret[i / 2] = (char)((hexCharToInt(s.at(i)) << 4) | hexCharToInt(s.at(i + 1)));
    }
    return ret;
}

std::string bytestohexstring(char *bytes, int bytelength)
{
    std::string str("");
    std::string str2("0123456789abcdef");
    for (int i = 0; i < bytelength; i++)
    {
        int b;
        b = 0x0f & (bytes[i] >> 4);
        // char s1 = str2.at(b);
        str.append(1, str2.at(b));
        b = 0x0f & bytes[i];
        str.append(1, str2.at(b));
        // char s2 = str2.at(b);
    }
    return str;
}

// test
// int main(void)
// {
//     char ch[5] = {'1', '2', '3', '4', '5'};
//     std::string str = bytestohexstring(ch, 5);
//     std::cout << str << "," << std::endl;
//     std::string strTest = "FF0100000000ff";
//     char *sdf = hexstringToBytes(strTest);
//     for (int m = 0; m < strTest.length() / 2; m++)
//         printf("%d,", sdf[m]);
//     system("pause");
//     return 0;
// }