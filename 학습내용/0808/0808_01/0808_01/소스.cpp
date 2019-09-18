#include <iostream>

using namespace std;

int main()
{
	int num = 0;

	cout << "숫자하나 입력해라 : ";
	cin >> num;

	int *arr = new int[num];

	for (int i = 0; i < num; i++)
		cin >> arr[i];

	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";

	cout << endl;

	delete[] arr;

	system("pause");
	return 0;
}