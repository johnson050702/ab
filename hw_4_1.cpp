#include <iostream>
using namespace std;

void input(int &hour,int &minute) {
	cout << "�п�J�ɶ��p�ɡC(0-23)\n";
	cin >> hour;
	cout << "�п�J�����C(0-59)\n";
	cin >> minute;
}

void convertTime(int &hour,int &minute,char &am_pm) {
	//�W�L12.
	if (hour >= 12) {
		am_pm = 'P';
		if (hour > 12) {
			hour -= 12;
		}
	}
	else
	{
		am_pm = 'A';
		if (hour = 0) {
			hour = 12;
		}
	}
}

void output(int hour,int minute,char am_pm) {
	cout << "�ഫ�᪺�ɶ�:" << hour << ":";
	if (minute < 10) {
		cout << "0";
	}
	cout << minute<<" "<<am_pm<<".M" << endl;
}

int main(void) {
	int hour, minute;
	char am_pm='A';
	char again;

	do {
		input(hour, minute);
		convertTime(hour, minute, am_pm);
		output(hour, minute, am_pm);

		cout << "�٭n��\n";
		cin >> again;
	} while (again == 'Y' || again == 'y');
	return 0;
}