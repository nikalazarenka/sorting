/*////////////
QuickSort   //
*/////////////

#include<iostream>
#include<conio.h>
#include<time.h>
#include<random>

using namespace std;

template<typename T>
void arrayFilling(T arr,int size)
{
	srand(time(NULL));
	for (int i(0); i < size; i++)
	{
		arr[i] = rand() % 10 + 1;
	}
}
template<typename T>
void arrayOutput(T arr,int size)
{
	for (int i(0); i < size; i++)
	{
		cout << arr[i] << " ";
	}

}
template<typename T>
void quickSort(T arr, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = arr[left];
	while (left < right)
	{
		while ((arr[right] >= pivot) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			arr[left] = arr[right];
			left++;
		}
		while ((arr[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			arr[right] = arr[left];
			right--;
		}
	}
		arr[left] = pivot;
		pivot = left;
		left = l_hold;
		right = r_hold;
		if (left < pivot)
			quickSort(arr, left, pivot - 1);
		if (right > pivot)
			quickSort(arr, pivot + 1, right);
	

}


int main(int* argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	int size = 0;

	cout << "Введите кол-во элементов массива:";
	cin >> size;

	int* arr = new int[size];
	arrayFilling(arr, size);
	cout << "Исходный массив:\n";
	arrayOutput(arr, size);
	quickSort(arr, 0, size-1);
	cout << "\nОтсортированный массив:\n";
	arrayOutput(arr, size);



	_getch();
	return 0;
}