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
	la = x.size(); lb = y.size();
	lc = la + lb;
	
	for(int i = 0;i < la;i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0;i < lb;i++) b[lb - 1 - i] = y[i] - '0';
	
	for(int i = 0;i < lb;i++)
	{
		for(int j = 0;j < la;j++)
		{
			c[i + j] += (a[j] * b[i]);
		}
	}
	
	for(int i = 0;i < lc;i++)
	{
		c[i + 1] += (c[i] / 10);
		c[i] %= 10; 
	}
	//处理前导0
	while(lc > 1 && c[lc - 1] == 0) lc--; 
	
	for(int i = lc - 1;i >= 0;i--)
		cout << c[i];
	
	return 0;
}
