#include "Cycl_list.h"

int main()
{
	Cycl_List current;
	int size = 0;
	cout << "Enter the size of the list: ";
	cin >> size;
	current.Initialization(size);
	current.Printing();

	cout << "Checking the list for a cycle using slow and fast pointers: ";
	if (HasCycl_by_Slow_and_Fast_Pointers(current))
		cout << "This list has a cycle" << endl;
	else
		cout << "This list doesn't have a cycle" << endl;

	cout << "Checking the list for a cycle using reverse: ";
	if (HasCycl_by_reverse(current))
		cout << "This list has a cycle" << endl;
	else
		cout << "This list doesn't have a cycle" << endl;

	current.Printing();

	system("pause");
	return 0;
}
	


	