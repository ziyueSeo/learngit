#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char chara = 'a';//�����ж�������ַ��Ƿ���ϱ�׼
	char chars[100][30];//���ڽ����ַ�
	//int count[100];//���ڼ���
	int index1;
	int index2;
	ifstream infile;
	infile.open("E:\\xuexi\\chengxu\\shiyan\\news.txt",ios::in);
	if (!infile.is_open()) cout << "wrong" << endl;//�����ж��ļ��Ƿ���ȷ�򿪣�������������
	for (index1 = 0; index1 >= 0 && index1 <= 99; index1++)//������ѭ�����������ַ�
		for (index2 = 0;index2<29; index2++)
		{
			infile.get(chara);
			if ((chara >= 'a'&&chara <= 'z') || (chara >= 'A'&&chara <= 'Z'))//������ĸ�������뵽�����У������ǣ�������\0���������ڲ�ѭ��
				chars[index1][index2] = chara;
			else { chars[index1][index2] = '\0'; break; }
		}
	if (index1 > 99) cout << "wrong" << endl;//�����жϵ��������Ƿ񳬹����鳤�ȣ������������ã�Ӧ�����ҵ�˼·������
	for (index1 = 0; index1 <= 99; index1++)//��������ַ���������ַ��Ƿ���ȷ�ı����뵽�����С�
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