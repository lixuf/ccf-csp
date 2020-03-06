#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<time.h>
using namespace std;

vector<pair<string, int>>kuohao;
map<string, int> s2i;
vector<string> ele;

void chu2(string ins, int x)
{
	
	int pre = 1;
	int ind = 0;
	for (; ind < ins.size(); ind++)
	{
		if (!(ins[ind] >= '0'&&ins[ind] <= '9'))
		{
			if (ind != 0)
			{
				pre = stoi(ins.substr(0, ind));
			}
			break;
		}
	}
	for (; ind < ins.size(); ind++)
	{
		if (ins[ind] == '(')
		{
			int miipre = 1;
			int index = ins.find_last_of(')');
			int index2;
			for (index2 = index + 1; index2 <= ins.size(); index2++)
			{
				if (index2 >= ins.size() || !(ins[index2] >= '0'&&ins[index2] <= '9'))
				{
					if (ind != 0 && index2 - index - 1 != 0)
					{
						miipre = stoi(ins.substr(index + 1, index2 - index - 1));
					}
					break;
				}
			}
			chu2(ins.substr(ind + 1, index - ind - 1), miipre*pre*x);
			//4Zn + 10HNO3 = 4Zn(NO3)2 + NH4NO3 + 3H2O
			ind = index2 - 1;
			continue;
		}
		string el = ins.substr(ind, 1);
		int mipre = 1;
		if (ind + 1 < ins.size() && ins[ind + 1] >= 'a'&&ins[ind + 1] <= 'z')
		{
			el += ins[ind + 1];
			ind++;
		}
		int nn = 1;
		while (1)
		{
			if (ind + nn >= ins.size() || !(ins[ind + nn] >= '0'&&ins[ind + nn] <= '9'))
			{
				if (nn != 1)
				{
					mipre = stoi(ins.substr(ind + 1, nn - 1));
				}
				break;
			}
			else
			{
				nn++;
			}
		}
		ind = ind + nn - 1;
		if (s2i.count(el))//4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
		{
			s2i[el] += (x*pre*mipre);
		}
		else
		{
			s2i[el] = (x*pre*mipre);
		}
	}
	
}
void chuli(string ins, int x)
{

	for (int ind = 0; ind < ins.size(); ind++)
	{
		if (ins[ind] == '+')
		{
			continue;

		}
		int st = ind;
		int pre = 1;
		for (; ind < ins.size(); ind++)
		{
			if (!(ins[ind] >= '0'&&ins[ind] <= '9'))
			{
				if (ind != 0&&st-ind!=0)
				{
					pre = stoi(ins.substr(st, ind-st));
				}
				break;
			}
		}
		for (; ind < ins.size(); ind++)
		{
			if (ins[ind] == '+')
			{
				break;

			}
			if (ins[ind] == '(')
			{
				int miipre = 1;
				int index = ins.find_last_of(')');
				int index2;
				for (index2 = index + 1; index2 <= ins.size(); index2++)
				{
					if (index2 >= ins.size() || !(ins[index2] >= '0'&&ins[index2] <= '9'))
					{
						if (ind != 0 && index2 - index - 1 != 0)
						{
							miipre = stoi(ins.substr(index + 1, index2 - index - 1));
						}
						break;
					}
				}
				chu2(ins.substr(ind + 1, index - ind - 1), miipre*pre*x);
				//4Zn + 10HNO3 = 4Zn(NO3)2 + NH4NO3 + 3H2O
				ind = index2 - 1;
				continue;
			}
			string el = ins.substr(ind, 1);
			int mipre = 1;
			if (ind + 1 < ins.size() && ins[ind + 1] >= 'a'&&ins[ind + 1] <= 'z')
			{
				el += ins[ind + 1];
				ind++;
			}
			int nn = 1;
			while (1)
			{
				if (ind + nn >= ins.size() || !(ins[ind + nn] >= '0'&&ins[ind + nn] <= '9'))
				{
					if (nn != 1)
					{
						mipre = stoi(ins.substr(ind + 1, nn - 1));
					}
					break;
				}
				else
				{
					nn++;
				}
			}
			ind = ind + nn - 1;
			if (s2i.count(el))//4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
			{
				s2i[el] += (x*pre*mipre);
			}
			else
			{
				s2i[el] = (x*pre*mipre);
			}
		}
	}
	

}

int main()
{
	
	int n;
	cin >> n;

	for (int n1 = 0; n1 < n; n1++)
	{
		s2i.clear();
		kuohao.clear();
		string ins;
		cin >> ins;
		int ind;
		ind = ins.find('=');
		if (ind == -1)
		{
			continue;
		}
		chuli(ins.substr(0, ind), 1);
		chuli(ins.substr(ind + 1, ins.size()), -1);
		int flag = 1;
		for (pair<string, int> c : s2i)
		{
			if (c.second)
			{
				flag = 0;
				printf("N");
				break;
			}
		}
		if (flag)
		{
			printf("Y");
		}
		if (n1 + 1 !=n)
		{
			printf("\n");
		}
		}

	system("pause");
	return 0;
}
/*
11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Na(Au(CN)2)+4NaOH=4Au+8NaCN+2H2O+O2
Cu+As=Cs+Au

2
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Na(Au(CN)2)+4NaOH=4Au+8NaCN+2H2O+O2
*/
