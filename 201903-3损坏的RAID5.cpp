#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<char, string> s2s;
map<string, char> six2t;
int main()
{
	s2s['0'] = "0000";
	s2s['1'] = "0001";
	s2s['2'] = "0010";
	s2s['3'] = "0011";
	s2s['4'] = "0100";
	s2s['5'] = "0101";
	s2s['6'] = "0110";
	s2s['7'] = "0111";
	s2s['8'] = "1000";
	s2s['9'] = "1001";
	s2s['A'] = "1010";
	s2s['B'] = "1011";
	s2s['C'] = "1100";
	s2s['D'] = "1101";
	s2s['E'] = "1110";
	s2s['F'] = "1111";
	for (pair<char, string> c : s2s)
	{
		six2t[c.second] = c.first;
	}
	int sizeins;
	int n, s, l;
	cin >> n >> s >> l;
	vector<string> hard(n,"=");
	vector<string> hui(n, "=");
	int flag = 0;
	if (n == l + 1 || n == l)
	{
		flag = 1;
	}
	for (int n1 = 0; n1 < l; n1++)
	{
		int index;
		cin >> index;
		string ins;
		cin >> ins;
		sizeins = ins.size();
		hard[index] = ins;
		if (flag)
		{
			string inss = "";
			for (int n2 = 0; n2 < ins.size(); n2++)
			{
				inss += s2s[ins[n2]];
			}
			hui[index] = inss;
		}
	}
	int m;
	cin >> m;
	for (int n1 = 0; n1 < m; n1++)
	{
		int index;
		cin >> index;
		int tiaon = index / s;
		int row = tiaon / (n - 1);
		int rown = tiaon % (n - 1);
		int pn =(n-1)-row % n;
		tiaon = pn +1+ rown;
		if (tiaon > (n - 1))
		{
			tiaon = tiaon - n ;
		}
		
		if (hui[tiaon][0] == '=')
		{
			hui[tiaon].clear();
			if (flag)
			{
				for (int n5 = 0; n5 < 4*sizeins; n5++)
				{
					char ff='9';
					for (int n4 = 0; n4 < n; n4++)
					{
						if (n4 != tiaon)
						{
							if (ff == '9')
							{
								ff = hui[n4][n5];
							}
							else
							{
								if (ff == hui[n4][n5])ff = '0';
								else ff = '1';
							}
						}
					}
					hui[tiaon]+=ff;
				}
			}
			else
			{
				cout << "-";
				if (n1 != m - 1)
				{
					cout << "\n";
				}
				continue;
			}
			hard[tiaon].clear();
			for (int n4 = 0,n5=0; n4 <sizeins;n4++,n5+=4)
			{
				hard[tiaon]+= six2t[hui[tiaon].substr(n5, 4)];
			}
		}
		int pianyi = index % s;
		int ros = row * s*8 + 8*pianyi;
		if (ros > hard[tiaon].size())
		{
			cout << "-";
			if (n1 != m - 1)
			{
				cout << "\n";
			}
			continue;
		}
		cout << hard[tiaon].substr(ros, 8);
		if (n1 != m - 1)
		{
			cout << "\n";
		}
	}
	
	return 0;

}
/*
3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5
*/