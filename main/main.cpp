#include <Text.h>
#include <conio.h>

int main()
{
	cout << "User menu (available commands): \n" <<	"Press 'enter' to set current node \n" << 
	"Press 'n' to go to the next node of the same level \n" << "Press 'd' to go to the sublevel of current node \n" <<
	"Press 't' to go to the position above \n" << "Press 'space' to add node to the same level \n" << 
	"Press 'tab' to add node to the sublevel \n" << "Press 'delete' to delete current node \n" <<
	"Press 'esc' to quit \n" << endl;

	Text T;
	bool While = true;
	while (While)
	{
		char ch = getch();
		int code = static_cast<int>(ch);
		
		if (ch == 13)
		{
			system("cls");
			string str;
			cout << "Enter the title: ";
			cin >> str;
			T.SetCurr(str);
		}
		
		if (ch == 'n') 
			T.next();

		if (ch == 'd') 
			T.down();

		if (ch == 't') 
			T.top();
		
		if (ch == 32) 
		{
			system("cls");
			string str;
			cout << "Enter the title: ";
			cin >> str;
			T.addNext(str);
		}

		if (ch == 9) 
		{
			system("cls");
			string str;
			cout << "Enter the title: ";
			cin >> str;
			T.addDown(str);
		}

		if (ch == 46)
			T.deleteCurr();
		
		if (ch == 27) 
			exit(0);
	
		system("cls");
		print(T.GetHeadNode(), T.GetCurrNode());
	}

	return 0;
}