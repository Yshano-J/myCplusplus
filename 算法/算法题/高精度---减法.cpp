#include<iostream>
#include<string>

using namespace std;
const int N = 1e6 + 10; 
int a[N],b[N],c[N];
int la,lb,lc;
string x,y;

bool cmp_min(string& x,string& y)
{
	if(x.size() != y.size()) return x.size() < y.size();
	else return x < y;
}

int main()
{
	cin >> x >> y;
	//保证大减小 
	if(cmp_min(x, y))
	{
		swap(x, y);
		cout << "-";
	}
	la = x.size(); lb = y.size();
	lc = max(la, lb);
	
	//逆序放入数组 
	for(int i = 0;i < la;i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0;i < lb;i++) b[lb - 1 - i] = y[i] - '0';
	
	for(int i = 0;i < lc ;i++)
	{
		c[i] += (a[i] - b[i]);
		if(c[i] < 0)
		{
			c[i] += 10;
			c[i + 1]--;
		}
	}
	//去除前导0 
	while(lc > 1 && c[lc - 1] == 0) lc--;
	for(int i = lc - 1;i >= 0;i--)
		cout << c[i];
	return 0;
 } 
