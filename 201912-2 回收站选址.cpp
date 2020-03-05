#include<cstdio>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int maxm = 10000;
int main()
{
	vector<pair<long int, long int>> ins;
	int n;
	scanf_s("%d", &n);
	map<long int, vector<long int>> x2y;
	vector<int> fen(5, 0);
	for (int n1 = 0; n1 < n; n1++)
	{
		long int mid1, mid2;
		scanf_s("%ld %ld", &mid1, &mid2);
		ins.push_back(pair<long int, long int>(mid1, mid2));
		x2y[mid1].push_back(mid2);
	}
	for (pair<long int, vector<long int>> c : x2y)
	{
		sort(x2y[c.first].begin(), x2y[c.first].end());
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		long int x = ins[n1].first;
		long int y = ins[n1].second;
		if (x2y[x].size() >= 3)
		{
			vector<long int> ::iterator n2;
			n2 = find(x2y[x].begin(), x2y[x].end(), y);
			if (n2 == x2y[x].begin())
			{
				continue;
			}
			int fens = 0;
			if ( x2y.count(x + 1) && x2y.count(x - 1)&&(n2+1)!= x2y[x].end()&&*(n2 + 1) == y + 1 && *(n2 - 1) == y - 1 )
			{
				vector<long int> ::iterator n3, n4;
				n3 = find(x2y[x + 1].begin(), x2y[x + 1].end(), y);
				n4 = find(x2y[x - 1].begin(), x2y[x - 1].end(), y);
				if (n3 != x2y[x + 1].end() && n4 != x2y[x - 1].end())
				{
					if ((n3+1)!= x2y[x + 1].end()&&*(n3 + 1) == y + 1)
					{
						fens += 1;
					}
					if (n3!=x2y[x+1].begin()&&*(n3 - 1) == y - 1)
					{
						fens += 1;
					}
					if ((n4+1) != x2y[x - 1].end()&&*(n4 + 1) == y + 1)
					{
						fens += 1;
					}
					if (n4!=x2y[x-1].begin()&&*(n4 - 1) == y - 1)
					{
						fens += 1;
					}
					fen[fens] += 1;
				}
			}
		}
	}
	for (int n1 = 0; n1 < 5; n1++)
	{
		cout << fen[n1];
		if (n1 != 4)
		{
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}