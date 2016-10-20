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
	Polynomial *p = NULL;                                     //���ʽֱ�����룬ָ�������ԡ�������Ϊ��ͷ��                             
	Polynomial *temp = NULL;	
	char ii;                          //ʲô������ֱ�ӻس���ʾ�������
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
	cout << "����ʼʱ��Ϊ��" << double(start - 0)/ CLOCKS_PER_SEC <<'s'<< endl;
	cout << "�������ʱ��Ϊ��" << double(end - 0) / CLOCKS_PER_SEC <<'s'<< endl;
	cout << "��������ʱ��Ϊ��" << double(end - start)/ CLOCKS_PER_SEC <<'s'<< endl;
	system("pause");
	return 0;
}