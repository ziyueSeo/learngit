#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//#include<cctype>
//#include<iterator>
#include<algorithm>
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
 char toLower(char ch){ return tolower(ch); }
int main()
{
	string str[35];
	vector<string> stri;
	int count[600];//用于计数
	int index1;
	int index2=0;
	string str1;
	ifstream infile;
	infile.open("E:\\xuexi\\chengxu\\shiyan\\news.txt",ios::in);
	if (!infile.is_open()) cout << "wrong" << endl;//用于判断文件是否被正确打开，但好像不起作用
	//stri[]初始化
	for (int k = 0; k < 599; k++)
	{
		
		count[k] = 0;
	}
	stri.push_back("\0");
	//vector<string>::iterator iter;
	//iter = stri.begin();
	//*iter = "\0";
	for (index1 = 0; index1 < 34; index1++)
	{
		getline(infile, str[index1]);
		transform(str[index1].begin(), str[index1].end(), str[index1].begin(), toLower);
		//ch = zhuanhuan(str[index1]);
		vector<string> result = split(str[index1], " "  );
		for (int i = 0; i<result.size(); i++)
		{
			str1 = result[i];
			vector<string> str2 = split(str1, ".");
			vector<string> str3 = split(str2[0], "\"");
			vector<string> str4 = split(str3[0], ",");
			if (str4[0].compare("\0")==0) break;
			//*iter="\0";
			//字符串比较并存储到stri数组中---有冲突
			for (int j = 0; j < stri.size(); j++)
			{
				//stri.front();
				//stri.push_back("\0");
				if (j<stri.size() )
				{
					if (stri[j].compare(str4[0]) == 0)
						count[j]++;
                    else 
				        {
					        stri.push_back(str4[0]);
					//stri[index2]="\0";
					//iter++;
					        break;
				        }
				}
				
			}
		//	stri[index2]=str4[0];//此处出错
			//stri.push_back(str4[0]);
			//getline(str4[0], stri[index2]);
			//index2++;
			//cout << stri << endl;
		}
	}
	for (int i = 0; i < stri.size(); i++)
		cout << stri[i] <<":"<<count[i]<<endl;
	//cout << index2 << endl;
	infile.close();
    system("pause");
		
}