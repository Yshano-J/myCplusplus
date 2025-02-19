#include<iostream>
#include<string>

using namespace std;

const int N = 1e6 + 10;
int a[N], c[N];
int la, lc;
string x, y;


int main()
{
	cin >> x;//高精度 / 低精度 
	la = x.size();
	lc = la;
	
	for(int i = 0;i < la;i++) a[la - 1 - i] = x[i] - '0';
	
	int b; cin >> b;
	long long t = 0; 
	for(int i = la - 1;i >= 0;i--)
	{
		t = t * 10 + a[i];
		c[i] = t / b;
		t %= b;
	}
	
	while(lc > 1 && c[lc - 1] == 0) lc--;
	
	for(int i = lc - 1;i >= 0;i--)
		cout << c[i]; 
	return 0;
}
