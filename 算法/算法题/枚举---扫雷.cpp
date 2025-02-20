、//只有012三种结果，看第一个位置是否有雷 
#include<iostream>
using namespace std;

int n;
const int N =1e4 + 10;
int a[N],b[N];

int check1()
{
	a[1] = 0;//不是雷
	for(int i = 2;i <= n+1;i++)
	{
		a[i] = b[i - 1] - a[i - 1] - a[i - 2];
		if(a[i] < 0 || a[i] > 1) return 0;
	 } 
	 if(a[n + 1]) return 0;
	 else
	 	return 1;
}

int check2()
{
	a[1] = 1;//是雷
	for(int i = 2;i <= n+1;i++)
	{
		a[i] = b[i - 1] - a[i - 1] - a[i - 2];
		if(a[i] < 0 || a[i] > 1) return 0;
	 } 
	 if(a[n + 1]) return 0;
	 else
	 	return 1;
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> b[i];
	int ret = 0;
	
	ret += check1();
	ret += check2();
	cout << ret << endl;
	return 0;
}
