/*////////////
MergeSort   //
*/////////////

#include<iostream>
#include<conio.h>
#include<time.h>
#include<random>
#include <functional>


using namespace std;

template<typename T>
void arrayFilling(T arr, int size)
{
	srand(time(NULL));
	for (int i(0); i < size; i++)
	{
		arr[i] = rand() % 10 + 1;
	}
}
template<typename T>
void arrayOutput(T arr, int size)
{
	for (int i(0); i < size; i++)
	{
		cout << arr[i] << " ";
	}

}

template<typename T>
void MergeSort(T a[], size_t l)
{
	size_t BlockSizeIterator;
	size_t BlockIterator;
	size_t LeftBlockIterator;
	size_t RightBlockIterator;
	size_t MergeIterator;

	size_t LeftBorder;
	size_t MidBorder;
	size_t RightBorder;
	for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2)
	{
		for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
		{
			//Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
			//левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
			LeftBlockIterator = 0;
			RightBlockIterator = 0;
			LeftBorder = BlockIterator;
			MidBorder = BlockIterator + BlockSizeIterator;
			RightBorder = BlockIterator + 2 * BlockSizeIterator;
			RightBorder = (RightBorder < l) ? RightBorder : l;
			int* SortedBlock = new int[RightBorder - LeftBorder];

			//Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
			while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
			{
				if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator])
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
					LeftBlockIterator += 1;
				}
				else
				{
					SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
					RightBlockIterator += 1;
				}
			}
			//После этого заносим оставшиеся элементы из левого или правого блока
			while (LeftBorder + LeftBlockIterator < MidBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
				LeftBlockIterator += 1;
			}
			while (MidBorder + RightBlockIterator < RightBorder)
			{
				SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
				RightBlockIterator += 1;
			}

			for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
			{
				a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
			}
			delete SortedBlock;
		}
	}
}

template<typename T>
void mergeSort(T arr[], int left, int right)
{
	if (left + 1 >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left,right,mid);
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
	MergeSort(arr, size);
	cout << "\nОтсортированный массив:\n";
	arrayOutput(arr, size);



	_getch();
	return 0;
}