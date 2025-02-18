#include<iostream>
#include<stack>

using namespace std;
int a[] = { 32,4,6,8,9,0,45,2,65 };

void QuickSort_Hoare(int left, int right)
{
	if (left >= right)
		return;
	int keyi = left;
	int begin = left, end = right;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
			right--;
		while (left < right && a[left] <= a[keyi])
			left++;
		swap(a[left], a[right]);
	}
	swap(a[keyi], a[left]);
	keyi = left;
	QuickSort_Hoare(begin, keyi - 1);
	QuickSort_Hoare(keyi + 1, end);
}

void QuickSort_Hole(int left, int right)
{
	if (left >= right)
		return;

	int key = a[left];
	int begin = left, end = right;
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
			right--;
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;

	QuickSort_Hole(begin, hole - 1);
	QuickSort_Hole(hole + 1, end);
}

void QuickSort3(int left, int right)
{
	if (left >= right)
		return;
	int keyi = left;
	int prev = left, cur = left + 1;
	int begin = left, end = right;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			swap(a[prev], a[cur]);
		cur++;
	}
	swap(a[prev], a[keyi]);
	keyi = prev;
	QuickSort3(begin, keyi - 1);
	QuickSort3(keyi + 1, end);
}

void QuickSortNonR(int left ,int right)
{
	stack<pair<int, int>>st;
	st.push({ left,right });
	
	while (st.size())
	{
		int begin = st.top().first, end = st.top().second;
		st.pop();
		int _left = begin, _right = end;
		int keyi = begin;

		while (begin < end)
		{
			while (begin < end && a[end] >= a[keyi])
				end--;
			while (begin < end && a[begin] <= a[keyi])
				begin++;
			swap(a[begin], a[end]);
		}
		swap(a[keyi], a[begin]);
		keyi = begin;

		if (keyi + 1 < _right)
			st.push({ keyi + 1,_right });
		if (_left < keyi - 1)
			st.push({ _left,keyi - 1 });
	}
}

void _MergeSort(int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int midi = (left + right) / 2;
	int begin1 = left, end1 = midi;
	int begin2 = midi + 1, end2 = right;
	_MergeSort(begin1, end1, tmp);
	_MergeSort(begin2, end2, tmp);

	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

int tmp[9];
void MergeSort(int n)
{
	_MergeSort(0, n - 1, tmp);
}

void MergeSortNonR(int n)
{
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			int j = i;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (2 * gap));
		}
		gap *= 2;
	}
}

void PrintArray()
{
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}



namespace yshano
{
	class list
	{
		
	};
}

int main()
{

//	QuickSort_Hoare(0, 8);
//	PrintArray();
//	QuickSort_Hole(0, 8);
//  PrintArray();	
//	QuickSort3(0, 8);
//	PrintArray();
//	MergeSort(9);
//	PrintArray();
//	QuickSortNonR(0, 8); 
//	PrintArray();
//	MergeSortNonR(9);
//	PrintArray();
	return 0;
}