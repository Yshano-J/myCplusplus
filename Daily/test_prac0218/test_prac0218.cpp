#include<iostream>
using namespace std;

const int N = 110;
int ne[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		ne[i] = i + 1;
	}
	ne[n] = 1;

	int cur = n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			cur = ne[cur];
		}
		cout << ne[cur] << " ";
		ne[cur] = ne[ne[cur]];
	}
	return 0;
}