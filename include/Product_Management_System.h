//
// Created by XingCChenSAMA on 2024/4/8.
//

#ifndef SUPERMARKET_PRODUCT_MANAGEMENT_SYSTEM_PRODUCT_MANAGEMENT_SYSTEM_H
#define SUPERMARKET_PRODUCT_MANAGEMENT_SYSTEM_PRODUCT_MANAGEMENT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
void login();                   //登录函数
//管理员登录
void menu_admin_0();            //管理员菜单0；总
void menu_admin_1();            //管理员菜单1：商品
void menu_admin_2();            //管理员菜单2：员工
void add_products();            //商品录入
void del_products();            //商品删除
void output_all_products();     //商品全部输出
void serch_products();          //商品查询
void edit_products();           //商品修改
void add_emp();                 //添加新员工
void del_emp();                 //删除员工
void output_all_emp();          //员工全部输出
void serch_emp();               //查找员工
void edit_emp();                //修改员工信息
//普通用户登录
void outbound_menu();           //出库系统菜单（销售结账）
void outbound();                //出库
double print_outbound_list();     //打印出货单
//会员积分系统
void vip_point_menu();          //积分菜单
void vip_reg();                 //会员注册
void output_all_vip();          //输出所有会员
void edit_vip();                //修改会员信息
void del_vip();
void point_check();             //查找积分
void point_use();               //使用积分
//找回密码
void findback_menu();           //找回密码菜单
void findback();                //找回密码
//进度条
void proc();                    //进度条
//获取时间
void print_Currenttime();       //打印现在时间
void get_Currenttime();         //获取当前时间
//库存提醒
void reminder();                //库存提醒
//鸡汤
void jitang();                  //随机给一句鸡汤
typedef struct data_{
    int year;
    int month;
    int day;
}DATA;


//商品结构体
typedef struct products_{
    char id[10];
    char name[20];
    double price_in;
    double price_out;
    char addr[50];
    DATA data;
    int exp;
    int num;
}products;
//员工结构体
/*typedef struct emp_{
    char id[10];
    char name[15];
    char gender[5];
    DATA data;
    char password[11];
    int  admin;
}emp;*/
typedef struct emp_{
    char id[10];
    char name[15];
    char gender[5];
    DATA data;
    char password[11];
    int  admin;         //不是为0是为1
    int  chance;        //默认为3次输错密码减一，登录成功重置次数
    int  state;         //被锁为1,正常为0
    //找回密码需要的信息↓
    char phone[15];     //手机号
    char color[15];     //颜色
    char food[20];       //食物偏好
    char addr[50];      //住址
}emp;


//出货单结构体
typedef struct products_list_temp_{
    char name[20];
    int num;
    double price;

}list_temp;
//会员卡结构体
typedef struct vipcard_{

    char id[12];
    char password[11];
    int point;

}vip;

#endif //SUPERMARKET_PRODUCT_MANAGEMENT_SYSTEM_PRODUCT_MANAGEMENT_SYSTEM_H
