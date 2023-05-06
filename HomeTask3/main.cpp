#include <iostream>

using namespace std;

//������� 1. ��� ������ ����� ������������ 10 ���������.�������� �������, ������� ��������� ������ ��
//����������� ��� �� ��������, � ����������� �� �������� ��������� �������.���� �� ����� true, ����������
//���� �� ��������, ���� false, �� �� �����������.������
//2 ��������� ������� � ��� ������ � ��� ������, ������
//�������� �� ��������� ����� false.
//������� 2. �������� �������, ������� ��������� ������
//�������� ������� �� ��������, � ������ � �� �����������, ��������� ���������� �������� ���������.
//������� 3. � ������� ��������� ������ ���������
//����� � ��������� �� - 20 �� + 20. ���������� ����� ������� ������� ������������� ���������(������ ������
//�������������� �������� � ������ ������� �������������� ��������) � ������������� ��������, �����������
//����� ����.

void FillArray(int arr[],int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 30;
	
}

void FillArray2(int arr[], int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % (20 + 20)-20;
}

void PrintArray(int arr[], int const size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
}

void Sort(int arr[], int const size, bool sort = false)
{
	if (sort == true)
	{
		for (int i = 0; i < size; i++)
		{
			int buffer;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] < arr[j])
				{
					buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			int buffer;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] > arr[j])
				{
					buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
	cout << endl;
}    //������� 1

void SortNew(int arr[], int const size)
{
	for (int i = 0; i < size; i++)
	{
		int size2 = size / 2;
		int buffer;
		for (int j = i+1; j < size; j++)
		{
			if (i < size2)
			{
				if (arr[i] < arr[j])
				{
					buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
			if (i > size2)
			{
				if (arr[i] > arr[j])
				{
					buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
				}
			}
		}
	}
	cout << endl;
}           //������ 2         

void SortUpdate(int arr[], int const size) //������� 3
{
	int left = 0;
	int right = 0;
	for (int j = 0; j < size; j++)
	{
		if (arr[j] < 0) right = j;
	}

	for (int l = size; l >= 0; l--)
	{
		if (arr[l] < 0) left = l;
	}

	for (left ; left < right; left++)
	{
			int buffer;
			for (int j = left + 1; j <= right; j++)
			{
				if (arr[left] < arr[j])
				{
					buffer = arr[left];
					arr[left] = arr[j];
					arr[j] = buffer;
				}
			}	
	}
}

int main()
{
	bool sort = false;
	int const size = 14;
	int arr[size];
	FillArray(arr, size);
	PrintArray(arr, size);
	Sort(arr, size, sort);
	PrintArray(arr, size);
	SortNew(arr, size);
	PrintArray(arr, size);
	cout << endl;
	FillArray2(arr, size);
	PrintArray(arr, size);
	cout << endl;
	SortUpdate(arr, size);
	PrintArray(arr, size);
}
