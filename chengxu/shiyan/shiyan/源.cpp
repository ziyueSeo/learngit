#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 vector< string> split( string str,  string pattern)
{
	      string::size_type pos;
	      vector< string> result;
	      str += pattern;//扩展字符串以方便操作
	      int size = str.size();
		    for (int i = 0; i<size; i++)
		    {
		        pos = str.find(pattern, i);
		       if (pos<size)
			         {
			            string s = str.substr(i, pos - i);
			           result.push_back(s);
			           i = pos + pattern.size() - 1;
			         }
		     }
	     return result;
	 }
int main()
{
	string str[35];
	string stri[500];
	int count[500];//用于计数
	int index1;
	int index2=0;
	string str1;
	ifstream infile;
	infile.open("E:\\xuexi\\chengxu\\shiyan\\news.txt",ios::in);
	if (!infile.is_open()) cout << "wrong" << endl;//用于判断文件是否被正确打开，但好像不起作用
	//stri[]初始化
	for (int k = 0; k < 500; k++)
		stri[k] = "\0";
	for (index1 = 0; index1 < 34; index1++)
	{
		getline(infile, str[index1]);
		vector<string> result = split(str[index1], " "  );
		for (int i = 0; i<result.size(); i++)
		{
			str1 = result[i];
			vector<string> str2 = split(str1, ".");
			vector<string> str3 = split(str2[0], "\"");
			vector<string> str4 = split(str3[0], ",");
			//字符串比较并存储到stri数组中---有冲突
			/*for (int j = 0; j <= index2; j++)
			{
				if (stri[j] != "\0")
				{
					if (stri[j] == str4[0])
						count[index2]++;
					
				}
				else 
				{
					stri[index2] = str4[0];
					index2++;
					break;
				}
			}*/
			stri[index2] = str4[0];//此处出错
			//getline(str4[0], stri[index2]);
			index2++;
			cout << str4[0] << endl;
		}
	}
	/*for (int i = 0; i < 499; i++)
		cout << stri[i] << endl;*/
	infile.close();
    system("pause");
		
}