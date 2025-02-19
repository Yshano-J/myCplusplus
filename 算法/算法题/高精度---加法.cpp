#include<iostream>
#include<string>

using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;
string x, y;

int main()
{
	cin >> x >> y;
	la = x.size();
	lb = y.size();
	lc = max(la, lb);
	//1、逆序放入数组中
	for(int i = 0;i < la;i++) a[la - 1 - i] = x[i] - '0'; 
	for(int i = 0;i < lb;i++) b[lb - 1 - i] = y[i] - '0';
	
	//2、相加
	for(int i = 0;i < lc;i++)
	{
		c[i] += (a[i] + b[i]);
		c[i + 1] += c[i] / 10;
		c[i] %= 10; 
	}
	if(c[lc]) lc++;
	
	//3、输出
	for(int i = lc - 1;i >= 0;i--)
	{
		cout << c[i];
	 } 
	return 0;
}
