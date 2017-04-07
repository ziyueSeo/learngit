#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Cstring>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;
//分割字符串
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
 char toLower(char ch){ return tolower(ch); }
int main()
{
	string str[35];
	vector<string> stri;
	int cou[600];//用于计数
	map <string, int> rate;
	pair<map<string, int>::iterator, bool> Insert_Pair;
	string str1;
	ifstream infile;
	infile.open("E:\\xuexi\\chengxu\\shiyan\\news.txt",ios::in);
	if (!infile.is_open()) cout << "wrong" << endl;//用于判断文件是否被正确打开，但好像不起作用
	//stri[]和cou[]初始化
	for (int k = 0; k < 599; k++)
	{
		cou[k] = 1;
	}
	stri.push_back("\0");
	for (int index1 = 0; index1 < 34; index1++)
	{
		getline(infile, str[index1]);
		transform(str[index1].begin(), str[index1].end(), str[index1].begin(), toLower);
		//ch = zhuanhuan(str[index1]);
		vector<string> result = split(str[index1], " "  );
		for (int index2 = 0; index2<result.size(); index2++)
		{
			str1 = result[index2];
			vector<string> str2 = split(str1, ".");
			vector<string> str3 = split(str2[0], "\"");
			vector<string> str4 = split(str3[0], ",");
			//如果有空字符串就跳过
			if (str4[0].compare("\0")==0) break;
			//将筛选之后的字符串存到stri中
			for (int index3 = 0; index3 < stri.size(); index3++)
			{
				if (index3<stri.size() )
				{
					if (stri[index3]==str4[0])
						cou[index3]++;
                    else 
				        {
					        stri.push_back(str4[0]);
					        break;
				        }
				}
				
			}
		}
	}
	//字符串比较，如果前面的和后面的一样计数器加1，并且将后面的删除
	for (int index1 = 0; index1 < stri.size(); index1++)
	{
		for (int index2 = index1 + 1; index2 < stri.size(); index2++)
		{
			if (stri[index1].compare(stri[index2]) == 0)
			{
				cou[index1]++;
				stri.erase(stri.begin() + index2, stri.begin() + index2+1);
			}
		}
	}
	//排序
	for (int index1 = 0; index1 < 10; index1++)
	{
		for (int in = index1+1; in < stri.size(); in++)
		{
			if (cou[index1] < cou[in])
			{
				int a = cou[in];
				cou[in] = cou[index1];
				cou[index1] = a;
				string st = stri[in];
				stri[in] = stri[index1];
				stri[index1] = st;
			}
		}
	}
	//输出前十个
	for (int index1 = 0; index1 < 10; index1++)
	{
		cout << stri[index1] << ":" << cou[index1] << endl;
	}
	infile.close();
    system("pause");
		
}