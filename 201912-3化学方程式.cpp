#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<char> res(n, 'N');
	for (int n1 = 0; n1 < n; n1++)
	{
		map<string, int> list;
		string ins;
		cin >> ins;
		string::iterator ens;
		string::iterator eqs = find(ins.begin(), ins.end(), '=');
		string chu[2];
		string ins1(ins.begin(), eqs);
		string ins2(eqs+1, ins.end());
		chu[0] = ins1;
		chu[1] = ins2;
		int flag = 0;
		vector<pair<string, int>> kuohao;
		for (int ind = 0; ind < 2; ind++)
		{
			int biao;
			if (ind == 0)
			{
				biao = 1;
			}
			else
			{
				biao = -1;
			}
			for (; chu[ind].size() != 0;)
			{
				ens = find(chu[ind].begin(), chu[ind].end(), '+');
				string ele(chu[ind].begin(), ens);
				if (ens == chu[ind].end())
				{
					chu[ind].clear();
				}
				else
				{
					chu[ind].erase(chu[ind].begin(), ens + 1);
				}//主系数
				int pre = 1;
				for (int n2 = 0; n2 < ele.size(); n2++)
				{
					if (!(ele[n2] >= '0'&&ele[n2] <= '9'))
					{
						string si(ele.begin(), ele.begin() + n2);
						if (si.size() != 0)
						{
							pre = stoi(si);
						}
						ele.erase(ele.begin(), ele.begin() + n2);
						break;
					}
				}

				
				//分割元素 括号独立
				for (int n2 = 0; n2 < ele.size(); )
				{
					int tui = 0;
					if (n2 + 1 != ele.size() && ele[n2+1] >= 'a'&&ele[n2+1] <= 'z')
					{
						tui += 1;
					}
					else if(ele[n2]=='(')
					{
						tui = ele.find_last_of(')');
					}
					string element(ele.begin(), ele.begin() + 1 + tui);
					ele.erase(ele.begin(), ele.begin() + 1 + tui);
					int shu = 1;
					for (int n3 = 0; n3 <= ele.size(); n3++)
					{
						if (!(ele[n3] >= '0'&&ele[n3] <= '9')|| n3 >=ele.size())
						{
							string si(ele.begin(), ele.begin() + n3);
							if (si.size() != 0)
							{
								shu = stoi(si);
							}
							ele.erase(ele.begin(), ele.begin() + n3);
							break;
						}
					}
					if (element[0] != '(')
					{
						if (list.count(element))
						{
							list[element] += (shu*biao*pre);
						}
						else
						{
							list[element] = (shu*biao*pre);

						}
					}
					else
					{
						kuohao.push_back(pair<string, int>(element, shu*biao*pre));
					}
			
				}
			

			}
	
		}

		for (int n2 = 0; n2 < kuohao.size(); n2++)
		{
			int pre = kuohao[n2].second;
			string ele (kuohao[n2].first.begin()+1,kuohao[n2].first.end()-1);
			
			//分割元素 括号独立
			for (int n2 = 0; n2 < ele.size(); )
			{
				int tui = 0;
				if (n2 + 1 != ele.size() && ele[n2 + 1] >= 'a'&&ele[n2 + 1] <= 'z')
				{
					tui += 1;
				}
				else if (ele[n2] == '(')
				{
					tui = ele.find(')');
				}
				string element(ele.begin(), ele.begin() + 1 + tui);
				ele.erase(ele.begin(), ele.begin() + 1 + tui);
				int shu = 1;
				for (int n3 = 0; n3 <= ele.size(); n3++)
				{
					if (!(ele[n3] >= '0'&&ele[n3] <= '9') || n3 >= ele.size())
					{
						string si(ele.begin(), ele.begin() + n3);
						if (si.size() != 0)
						{
							shu = stoi(si);
						}
						ele.erase(ele.begin(), ele.begin() + n3);
						break;
					}
				}
				if (element[0] != '(')
				{
					if (list.count(element))
					{
						list[element] += (shu*pre);
					}
					else
					{
						list[element] = (shu*pre);
					}
				}
				else
				{
					kuohao.push_back(pair<string, int>(element, shu*pre));
				}
			}
		

		}

		
		int fl = 1;
		for (pair<string, int> c : list)
		{
			if (c.second != 0)
			{
				res[n1] = 'N';
				fl = 0;
				break;
			}
		}
		if (fl)
		{
			res[n1] = 'Y';
		}
	}
	for (int n1 = 0; n1 < res.size(); n1++)
	{
		cout << res[n1];
		if (n1 != res.size() - 1)
		{
			cout << "\n";
		}
	}
	
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



*/