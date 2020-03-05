#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> list(4, 0);
	int t = 0;
	for (int n1 = 1; n1 <=n; n1++)
	{
		if (t > 3)
		{
			t = 0;
		}
		if (n1 % 7 == 0)
		{
			list[t] += 1;
			n++;
			t++;
			continue;
		}
		else 
		{

			int ge = n1 % 10;
			int shi = n1 % 100-ge;
			int bai = n1 % 1000 - shi - ge;
			if (ge == 7 || shi == 70||bai==700)
			{
				list[t] += 1;
				n++;
				t++;
				continue;
			}
		}
		
		t++;
	}
	for (int n1 = 0; n1 < 4; n1++)
	{
		cout << list[n1];
		if (n1 != 3)
		{
			cout << "\n";
		}
	}

	return 0;
}