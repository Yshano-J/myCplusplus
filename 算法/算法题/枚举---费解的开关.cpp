#include<iostream>
#include<cstring>

using namespace std;

const int N = 10;
int n = 5;
int a[N];//用二进制表示，存储灯的状态
int t[N]; 

//计算x的二进制中有多少个1 
int calc(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x &= x-1;
	}
	return cnt;
}
int main()
{
	int T; cin >> T;
	while(T--)
	{
		memset(a, 0, sizeof(a));
		
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				char ch; cin >> ch;
				if(ch == '0') a[i] |= (1 << j);
				//让a[i]的第j位变成1 
			}
		}
		
		int ret = 0x3f3f3f3f;
		//枚举第一行所有的按法 
		for(int i = 0;i < (1 << n);i++)
		{
			memcpy(t,a,sizeof(a));
			int push = i;
			int num = 0; 
			for(int j = 0;j < n;j++)
			{
				num += calc(push);
				t[j] = t[j] ^ push 
				^ (push << 1) ^ (push>>1);
				t[j] &= (1 << n) - 1;
				//修改下一行的状态 
				t[j + 1] ^= push;
				
				//下一行的按法 
				push = t[j];
			}
			if(t[n - 1] == 0) ret = min(ret, num);
		}
		if(ret > 6) cout <<"-1" << endl;
		else
			cout << ret << endl;
	}
	return 0;	
} 



