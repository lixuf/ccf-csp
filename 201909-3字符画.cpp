#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<map>
using namespace std;
struct node
{
	int r, g, b;
	node(int _r, int _g, int _b) :r(_r), g(_g), b(_b) {};
};
int main()
{
	int ro, l, r1, l1;
	cin >> l >> ro >> l1 >> r1;
	int row = ro / r1;
	int line = l / l1;
	stringstream ss;
	vector<vector<node>> list;
	for (int n1 = 0; n1 < ro; n1++)
	{
		vector<node> hang;
		for (int n2 = 0; n2 < l; n2++)
		{
			string ins;
			cin >> ins;
			if (ins.size() == 2)
			{
				ss << hex << string(2, ins[1]);
				int mid;
				ss >> mid;
				ss.clear();
				hang.push_back(node(mid, mid, mid));
			}
			else if (ins.size() == 4)
			{
				ss << hex << string(2, ins[1]);
				int r;
				ss >> r;
				ss.clear();
				ss << hex << string(2, ins[2]);
				int g;
				ss >> g;
				ss.clear();
				ss<<hex<<string(2, ins[3]);
				int b;
				ss >> b;
				ss.clear();
				hang.push_back(node(r, g, b));
			}
			else
			{
				int r, g, b;
				ss << hex << ins.substr(1, 2);
				ss >> r;
				ss.clear();
				ss << hex << ins.substr(3, 2);
				ss >> g;
				ss.clear();
				ss << hex << ins.substr(5.2);
				ss >> b;
				ss.clear();
				hang.push_back(node(r, g, b));
			}
		}
		list.push_back(hang);
	}
	map<char, string> c2s;
	for (char n1 = '0'; n1 <='9'; n1++)
	{
		c2s[n1] = "\\x3" + string(1, n1);
	}
	for (char n1 = 'a'; n1 <= 'f'; n1++)
	{
		char mid ;
		mid = n1 - 'a' + '1';
		c2s[n1] = "\\x4" +string(1,mid);
	}
	int size = (r1*l1);
	int prer=0, preg=0, preb=0;
	for (int n1 = 0; n1 < ro; n1+=r1)
	{
		for (int n2 = 0; n2 < l; n2+=l1)
		{
			int r=0, g=0, b=0;
			for (int n3 = n1, tt = 0; tt < r1; tt++, n3++)
			{
				for (int n4 = n2, ff = 0; ff < l1; ff++, n4++)
				{
					r += list[n3][n4].r;
					g += list[n3][n4].g;
					b += list[n3][n4].b;
				}
			}
			r /= size;
			g /= size;
			b /= size;
			if (r==prer&&g==preg&&b==preb)
			{
				cout << "\\x20";
			}
			else if(r==0&&g==0&&b==0)
			{
				
				cout << "\\x1B\\x5B\\x30\\x6D\\x20";
			}
			else
			{
				string rr[3];
				ss <<dec<< r;
				ss >> rr[0];
				ss.clear();
				ss <<dec<<g;
				ss >> rr[1];
				ss.clear();
				ss <<dec<< b;
				ss >> rr[2];
				ss.clear();
	
				cout << "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
				for (int n6 = 0; n6 < 3; n6++)
				{
					if (rr[n6].size() == 1)
					{
						cout <<  c2s[rr[n6][0]];
					}
					else if(rr[n6].size()==2)
					{
						cout << c2s[rr[n6][0]]<< c2s[rr[n6][1]];
					}
					else
					{
						cout << c2s[rr[n6][0]] << c2s[rr[n6][1]] << c2s[rr[n6][2]];
					}
					if (n6 == 2)
					{
						cout << "\\x6D\\x20";
					}
					else
					{
						cout << "\\x3B";
					}
				}

			}
			prer = r;
			preg = g;
			preb = b;
		}
		if (!(prer == 0 && preg == 0 && preb == 0))
		{
			cout << "\\x1B\\x5B\\x30\\x6D\\x0A";
		}
		else
		{
			cout<<"\\x0A";
		}
		prer = 0;
		preg = 0;
		preb = 0;
	}
	system("pause");
	return 0;
}
/*
4 2
2 1
#010203
#290203
#010203
#014403
	#111111
	#0
	#000000
	#111

	2 2
	1 1
	#111111
	#0
	#000000
	#111
*/