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
//			//�� 
//			int k = (j % 10) * 1000 
//			+ (j / 10) * 100 
//			+ (i % 10) * 10 +
//			 i / 10;
//			//����
//			int m = k * 10000 + i * 100 + j;
//			if(m >= x && m <= y) ret++; 
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}

int reverse_num(int x)
{
	//�õ�λ��
	int tmp = x;
	int t = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		t++;
	}
	//ÿ�εõ���λ������λ���������Ӧ�Ĵ��������Ӧλ���Գ�λ��
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
