// shiyan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "fstream"
#include "iostream"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char c = 'a';
	char a[100][20];
	int b[100];
	int i, j;
	ifstream infile;
	infile.open("E:\\学习\\程序\\shiyan\\news.txt", ios::in);
	for (i = 0; i >= 0 && i <= 99; i++)
		for (j = 0;; j++)
		{
			infile.get(c);
			if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
				a[i][j] = c;
			else { a[i][j] = '\0'; break; }
		}
	if (i > 99) cout << "wrong" << endl;
	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 19; j++)
			if (a[i][j] == '\0')
			{
				cout << "\n" << endl;
				break;
			}
			else cout << a[i][j] << endl;

			infile.close();
	return 0;
}

