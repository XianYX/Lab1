#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <ctime>
#include "polynomial.h"
#include "WordTag.h"

using namespace std;
int main()
{
	time_t	start = clock();
	int flag = -1;
	string pol;
	Polynomial *p = NULL;                                     //表达式直接输入，指令输入以“！”作为开头，                             
	Polynomial *temp = NULL;	
	char ii;                          //什么都不输直接回车表示程序结束
	ii=cin.get();
	while (ii != '\n')
	{
		if (ii == '!')
		{
			string ord;
			if (p == NULL)
			{
				temp = p;
			}	
			else
			{
				if (temp)
					temp->~Polynomial();
				temp = new Polynomial(*p);	
			}
			getline(cin, ord);
			DealOrder(ord, temp);
		}
		else
		{
			pol.clear();
			if(p)
				p->~Polynomial();
			while (ii != '\n')
			{
				if (ii != ' ')
					pol += ii;
				ii = cin.get();
			}
			p = expression(pol);
			if (p)
				p->display();		
		}
		ii = cin.get();
	}
	
	
	time_t	end = clock();
	cout << "程序开始时间为：" << double(start - 0)/ CLOCKS_PER_SEC <<'s'<< endl;
	cout << "程序结束时间为：" << double(end - 0) / CLOCKS_PER_SEC <<'s'<< endl;
	cout << "程序运行时间为：" << double(end - start)/ CLOCKS_PER_SEC <<'s'<< endl;
	system("pause");
	return 0;
}