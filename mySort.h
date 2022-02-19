#pragma once
#include <vector>
using namespace std;

void quick_Sort(vector<int> &v, int left, int right)
{
	if (left >= right) return;
	int i = left, j = right, pivot = v[left];  //最左边为基准
	while (i < j)
	{
		while (v[j] >= pivot && i < j)
			--j;
		while (v[i] <= pivot && i < j)
			++i;
		if (i < j)
			swap(v[i], v[j]);
	}
	v[left] = v[i];
	v[i] = pivot;  //原pivot不再参与下一次排序
	quick_Sort(v, left, i - 1);
	quick_Sort(v, i + 1, right);
}
void quickSort(vector<int> &v)
{
	int size = v.size();
	quick_Sort(v, 0, size - 1);
}


void merge(vector<int>& v, int left, int mid, int right) {
	vector<int> temp = v;
	int i = left, j = mid + 1;
	int index = left;
	while (i <= mid || j <= right) {
		if (i > mid) {
			v[index++] = temp[j];
			j++;
		}
		else if (j > right) {
			v[index++] = temp[i];
			i++;
		}
		else if (temp[i] < temp[j]) {
			v[index++] = temp[i];
			i++;
		}
		else {
			v[index++] = temp[j];
			j++;
		}
	}
}
void merge_Sort(vector<int> &v, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	merge_Sort(v, left, mid);
	merge_Sort(v, mid + 1, right);
	if (v[mid] > v[mid + 1]) 
	{
		merge(v, left, mid, right);
	}
}
void mergeSort(vector<int> &v)
{
	int size = v.size();
	merge_Sort(v, 0, size - 1);
}

void bubbleSort(vector<int> &v)
{
	int size = v.size();
	for (int i = 0; i < size ; ++i)
	{
		bool flag = true;  //如果没有交换过，说明已经排序完成，提前终止排序
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (v[j] > v[j + 1])
			{
				flag = false;
				swap(v[j], v[j + 1]);
			}
		}
		if (flag) return;
	}
}

void selectSort(vector<int>& v) {
	int size = v.size();
	for (int i = 0; i < size - 1; i++) {
		int index = 0;
		for (int j = 1; j < size - i; j++) {
			if (v[j] > v[index]) {
				index = j;
			}
		}
		swap(v[index], v[size - 1 - i]);
	}
}

void insertSort(vector<int>& v) 
{
	int n = v.size();
	for (int i = 1; i < n; i++) 
	{
		for (int j = i; j > 0; j--) 
		{
			if (v[j] < v[j - 1])
			{
				swap(v[j], v[j - 1]);
			}
			else 
			{
				break;
			}
		}
	}
}