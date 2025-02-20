#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N],b[N],g[N],k[N];
int n;
int x,y;

int find()
{
	//从最上面一层开始找
	for(int i = n;i >= 1;i--)
	{
		if(x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
		{
			return i;
		}
	 } 
	 return -1;
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> g[i] >> k[i];
	cin >> x >> y;
	cout << find() << endl; 
	return 0;
 } 
