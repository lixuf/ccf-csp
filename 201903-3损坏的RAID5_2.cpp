#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, s, l;
string t2s = "0123456789ABCDEF";
string list[1005];
void xo(string & x, string y)
{
	
	for (int n1 = 0; n1 < 8; n1++)
	{
		int x1, y1;
		if (x[n1] >= '0'&&x[n1] <= '9')x1 = x[n1] - '0';
		else x1=x[n1] - 'A' + 10;
		if (y[n1] >= '0'&&y[n1] <= '9')y1 = y[n1] - '0';
		else y1 = y[n1] - 'A' + 10;
		x[n1] = t2s[(x1^y1)];
	}
	
}
string xorr ( int start,int pan)
{
	string bi(8, '0');
	for (int n1 = 0; n1 < n; n1++)
	{
		if (n1 != pan)xo(bi, list[n1].substr(start, 8));
	}
	return bi;
}
int main()
{
	ios::sync_with_stdio(false);
	int maxsize;
	cin >> n >> s >> l;
	for (int n1 = 0; n1 < l; n1++)
	{
		int index;
		cin >> index;
		cin >> list[index];
		maxsize = list[index].size();
	}
	int m;cin >> m;
	int flag = (n - l) >= 2;
	while (m--)
	{
		int kuai;cin >> kuai;
		int tiao = kuai / s;
		int row = tiao / (n - 1);
		int rowrank = tiao % (n - 1);
		int pan;
		int pn = n - row % n - 1;
		if (n - 1 - pn > rowrank)pan = pn + 1 + rowrank;
		else pan = rowrank - (n - 1 - pn);
		int start = row * 8 * s + (kuai%s) * 8;
		if (start >= maxsize)cout << "-\n";
		else if (list[pan].size() == 0)
		{
			if (flag) cout << "-\n";
			else cout << xorr(start, pan) << "\n";
		}
		else cout << list[pan].substr(start, 8) << "\n";
	}
	system("pause");
	return 0;
}
/*
3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5

2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
3
0
1
1000
*/