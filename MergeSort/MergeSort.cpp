#include <iostream>
using namespace std;

void printArr(int* arr, const int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << "\t";
	};
	cout << endl;
};
void mergeSorted(int* arr, const int arrSize, int* arrLeft, const int arrLeftSize, int* arrRight, const int arrRightSize)
{
	int iLeft = 0, iRight = 0, i = 0;

	while (arrLeftSize > iLeft && arrRightSize > iRight)
	{
		if (arrLeft[iLeft] <= arrRight[iRight])
		{
			arr[i++] = arrLeft[iLeft++];
		}
		else
		{
			arr[i++] = arrRight[iRight++];
		}
	}
	while (arrLeftSize > iLeft)
	{
		arr[i++] = arrLeft[iLeft++];
	}
	while (arrRightSize > iRight)
	{
		arr[i++] = arrRight[iRight++];
	}
}

void mergeSort(int* arr, const int arrSize)
{
	if (arrSize <= 1)
	{
		return;
	}
	if (arrSize == 2)
	{
		if (arr[0] > arr[1])
			swap(arr[0], arr[1]);
		return;
	}


	int arrLeftSize = arrSize / 2;
	int arrRightSize = arrSize - (arrSize / 2);

	int* arrLeft = new int[arrLeftSize];
	int* arrRight = new int[arrRightSize];

	for (int i = 0; i < arrLeftSize; i++)
	{
		arrLeft[i] = arr[i];
	}
	for (int i = 0; i < arrRightSize; i++)
	{
		arrRight[i] = arr[i + arrLeftSize];
	}

	mergeSort(arrLeft, arrLeftSize);
	mergeSort(arrRight, arrRightSize);


	mergeSorted(arr, arrSize, arrLeft, arrLeftSize, arrRight, arrRightSize);



	delete[] arrLeft;
	arrLeft = nullptr;
	delete[] arrRight;
	arrRight = nullptr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	cout << "Массив до сортировки: \n";
	printArr(arr, size(arr));
	mergeSort(arr, size(arr));
	cout << "Массив после сортировки: \n";
	printArr(arr, size(arr));
}
