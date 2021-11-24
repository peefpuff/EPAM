#include "matrix.h"

matrix::matrix(int rows = 5, int columns = 5) : rows_(rows), columns_(columns)
{
	arr = new int* [rows_];
	for (int i = 0; i < rows_; ++i)
		arr[i] = new int[columns_];

//��������� ������ ����� ���������� ������� � ��������� �� -50 �� 200
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(-50, 200);

	for (int i = 0; i < rows_; ++i)
		for (int j = 0; j < columns_; ++j)
			arr[i][j] = dist(gen);
}

matrix::~matrix()
{
	for (int i = 0; i < rows_; ++i)
		delete[] arr[i];
	delete[] arr;
}

void matrix::print()
{
	for (int i = 0; i < rows_; ++i)
	{
		for (int j = 0; j < columns_; ++j)
			cout << std::setw(5) << arr[i][j];
		cout << endl;
	}
	for (int i = 0; i < columns_; ++i) cout << "-----";
	cout << endl;
}

//�������: ���������� ����� ��������� � ��� ��������, ������� �������� ���� �� ���� ������������� �������

//������ �� ������� ���������� �� ��������, � �� �� ������� ��� ������
void doTask(matrix& m)
{
	for (int i = 0; i < m.columns_; ++i)
	{
		for (int j = 0; j < m.rows_; ++j)
		{
			if (m.arr[j][i] < 0) // ���� ������������� ������� � �������
			{
				int result {0};
				// �������� ���������� ������� j, �.�. ��� ������ ����� ������ ����������� �������,
				// �� ���������� ����� �� ������� �� ����� ������
				// � ������������ � ���� ���� (������ 45) �� ����� �� ����� �������� 
				// ���������� 4 ����� =)
				for (j = 0; j < m.rows_; ++j) 
					result += m.arr[j][i];
				cout << "sum in the column " << i << ": " << result << endl;
				break;
			}
		}
	}
}
