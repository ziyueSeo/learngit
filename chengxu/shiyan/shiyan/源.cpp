#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char chara = 'a';//用于判断输入的字符是否符合标准
	char chars[100][30];//用于接收字符
	//int count[100];//用于计数
	int index1;
	int index2;
	ifstream infile;
	infile.open("E:\\xuexi\\chengxu\\shiyan\\news.txt",ios::in);
	if (!infile.is_open()) cout << "wrong" << endl;//用于判断文件是否被正确打开，但好像不起作用
	for (index1 = 0; index1 >= 0 && index1 <= 99; index1++)//这两个循环用于输入字符
		for (index2 = 0;index2<29; index2++)
		{
			infile.get(chara);
			if ((chara >= 'a'&&chara <= 'z') || (chara >= 'A'&&chara <= 'Z'))//若是字母，则输入到数组中，若不是，则输入\0，并结束内层循环
				chars[index1][index2] = chara;
			else { chars[index1][index2] = '\0'; break; }
		}
	if (index1 > 99) cout << "wrong" << endl;//用于判断单词数量是否超过数组长度，不过不起作用，应该是我的思路有问题
	for (index1 = 0; index1 <= 99; index1++)//用于输出字符串，检查字符是否正确的被输入到数组中。
	{
		for (index2 = 0; index2 <= 29; index2++)
			if (chars[index1][index2] == '\0')
			{
				cout << "\n" << endl;
				break;
			}
			else cout << chars[index1][index2] << endl;
	}
	infile.close();
	system("pause");
		
}