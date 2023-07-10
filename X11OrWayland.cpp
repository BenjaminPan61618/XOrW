
/*
 * XOrW / X11OrWayland.cpp
 * 
 * 
 * Copyright 2023 benjamin <benjamin@fedora>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
 // 注意：请在图形界面下的 Linux 操作系统运行此程序 (无法保证能在 Android 设备和其他 UNIX / 类 UNIX 系统上运行)
 // 此程序遵循 GPL 协议，具体请见上方的块注释：

 // 用途介绍:
 // 本程序可以简单鉴别当前 Linux 桌面会话采用的显示服务器是 X11, Wayland 还是其它小众的显示服务器。
 
 
#include <iostream>
#include <stdlib.h>
#include <string>
char *getenv(const char *name);
int system(const char *string);
using namespace std;

class XORW
{
	public:
	void DirectReturn(){
	cout<<"当前会话为: "; 				    //由于cout的特性，这一行文本将会存入缓冲区中, 并不会立即输出
	cout.flush();						    //运用这一句刷新缓冲区，让cout语句得以输出
	system("echo $XDG_SESSION_TYPE");  //system()语句会调用系统命令，系统的echo会立即输出内容
}
	int GetAndReturn(string str){
	if (str == "x11")
	return 1;
	else if (str == "wayland" || str == "Wayland")
	return 0;
	else
	return -1;}
	void menu(){
	cout<<"Wayland or X11 V1.0 (GPL 协议授权)"<<endl<<"请在图形界面下的 Linux 操作系统运行此程序。"<<endl<<"请选择返回方式"<<endl<<"1.直接返回 - 通过调用 Shell 命令让系统进行返回"<<endl<<"2.(伪)布尔值返回 - 程序将通过获取环境变量的方式得到当前会话的类型"<<endl<<"请选择:";
	}
	};

int main()
{
XORW XorW;
char choice;
int retval;
string ret;
ret = getenv("XDG_SESSION_TYPE"); 		 //这一语句用于获取系统的XDG_SESSION_TYPE环境变量
XorW.menu();
cin.get(choice);
switch(choice){
	case '1':
	XorW.DirectReturn();
	break;
	case '2':
	retval = XorW.GetAndReturn(ret);
	if (retval == 1)
	cout<< "X11 = true" << endl << "Wayland = false" << endl;
	else if (retval == 0)
	cout<< "X11 = false" << endl << "Wayland = true" << endl;
	else
	cout<< "X11 = false" << endl << "Wayland = false" << endl;
	break;
	default:
	cout<<"Exiting...";}

return 0;			                   //若没有手动flush, cout此时才会将缓冲区的东西刷新并打印出内容
}
