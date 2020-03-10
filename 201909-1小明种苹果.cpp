#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<long int> shu;
	vector<long int> zhai;
	for (int n1 = 0; n1 < n; n1++)
	{
		long int mid;
		scanf_s("%ld", &mid);
		shu.push_back(mid);
		zhai.push_back(0);
		for (int n2 = 0; n2 < m; n2++)
		{
			long int cc;
			scanf_s("%ld", &cc);
			shu[n1] += cc;
			zhai[n1] -= cc;
		}
	}
	int sum = 0;
	int max = -1;
	int index;
	for (int n1 = 0; n1 < shu.size(); n1++)
	{
		sum += shu[n1];
		if (zhai[n1] > max)
		{
			index = n1 + 1;
			max = zhai[n1];
		}
	}
	printf("%ld %ld %ld", sum, index, max);
	system("pause");
	return 0;
}
/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0
*/