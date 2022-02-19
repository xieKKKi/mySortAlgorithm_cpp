#include "mySort.h"
#include <iostream>
#include <iterator> // for std::ostream_iterator
#include <algorithm>  // for std::copy

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	if (!v.empty()) {
		out << '[';
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}

int main()
{
	vector<int> v1 = { 12,0,2,6,5,9,7,13,16,80,55 };
	vector<int> v2 = { 12,0,2,6,5,9,7,13,16,80,55 };
	vector<int> v3 = { 12,0,2,6,5,9,7,13,16,80,55 };
	vector<int> v4 = { 12,0,2,6,5,9,7,13,16,80,55 };
	vector<int> v5 = { 12,0,2,6,5,9,7,13,16,80,55 };

	bubbleSort(v1);
	insertSort(v2);
	selectSort(v3);
	quickSort(v4);
	mergeSort(v5);

	cout << v1 << '\n';
	cout << v2 << '\n';
	cout << v3 << '\n';
	cout << v4 << '\n';
	cout << v5 << '\n';
	return 0;
}
