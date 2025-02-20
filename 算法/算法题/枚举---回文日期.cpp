#include<iostream>

using namespace std;

int day[] = {0 ,31,29,31,30,31,30,31,31,30,31,30,31};

int x, y;

//int main()
//{
//	cin >> x >> y;
//	int ret = 0;
//	for(int i = 1;i <= 12;i++)
//	{
//		for(int j = 1;j <= day[i];j++)
//		{
//			//年 
//			int k = (j % 10) * 1000 
//			+ (j / 10) * 100 
//			+ (i % 10) * 10 +
//			 i / 10;
//			//日期
//			int m = k * 10000 + i * 100 + j;
//			if(m >= x && m <= y) ret++; 
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}

int reverse_num(int x)
{
	//得到位数
	int tmp = x;
	int t = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		t++;
	}
	//每次得到个位数，个位数乘以相对应的次数到达对应位（对称位）
	int ret = 0;
	for (int i = 0; i < t; i++)
	{
		int m = x % 10;
		x /= 10;
		for (int j = 0; j < t - 1 - i; j++)
		{
			m *= 10;
		}
		ret += m;
	}
	return ret;
}

int main()
{
	cin >> x >> y;
	int ret = 0;
	for (int i = x; i <= y; i++)
	{
		int year = i / 10000;
		int month = (i % 10000) / 100;
		int day = (i % 10000) % 100;
		if (month >=1 && month <= 12 
			&& day >= 1 && day <= days[month] 
			&& i == reverse_num(i)) ret++;
	}
	cout << ret << endl;
	return 0;
}
