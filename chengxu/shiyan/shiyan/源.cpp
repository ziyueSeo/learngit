#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char c = 'a';
	char a[1000][20];
	//int b[100];
	int i, j;
	ifstream infile;
	infile.open("E:\\xuexi\\chengxu\\shiyan\\news.txt");
	if (!infile.is_open()) cout << "wrong" << endl;
	for (i = 0; i >= 0 && i <= 999; i++)
		for (j = 0;j<19; j++)
		{
			infile.get(c);
			if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
				a[i][j] = c;
			else { a[i][j] = '\0'; break; }
		}
	if (i > 999) cout << "wrong" << endl;
	for (i = 0; i <= 999; i++)
	{
		for (j = 0; j <= 19; j++)
			if (a[i][j] == '\0')
			{
				cout << "\n" << endl;
				break;
			}
			else cout << a[i][j] << endl;
	}
	infile.close();
	system("pause");
		
}