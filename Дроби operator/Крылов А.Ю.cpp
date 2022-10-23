#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
void show_menu()
{
	system("cls");
	cout << "Arithmetic operations" << endl;
	cout << "Logical operations" << endl;
	cout << "Unary operations" << endl;
	cout << "=====================" << endl;
	cout << "Press ESC to exit" << endl;

}
class Drob
{
private:
	int ch;
	int zn;
	
public:
	Drob()
	{
		ch = zn = 0;
	}
	Drob(int x, int y)
	{
		ch = x;
		zn = y;
	}
	void print()
	{
		cout << ch << "/" << zn;
	}
	Drob operator+(Drob n)
	{
		Drob tmp1;
		tmp1.ch = ch * n.zn + zn * n.ch;
		tmp1.zn = zn * n.zn;
		return tmp1;
	}
	Drob operator-(Drob n)
	{
		Drob tmp1;
		tmp1.ch = ch * n.zn - zn * n.ch;
		tmp1.zn = zn * n.zn;
		return tmp1;
	}
	Drob operator*(int num)
	{
		Drob tmp1;
		tmp1.ch = ch * num;
		tmp1.zn = zn;
		return tmp1;
	}
	Drob operator*(Drob n)
	{
		Drob tmp1;
		tmp1.ch = ch * n.ch;
		tmp1.zn = zn * n.zn;
		return tmp1;
	}
	friend Drob operator*(int num, Drob n)
	{
		Drob tmp1;
		tmp1.ch = num*n.ch;
		tmp1.zn = n.zn;
		return tmp1;
	}
	Drob operator/(Drob n)
	{
		Drob tmp1;
		tmp1.ch = ch * n.zn;
		tmp1.zn = zn * n.ch;
		return tmp1;
	}
	int operator%(Drob n)
	{
		int res_1;
		ch = ch * n.zn;
		zn = zn * n.ch;
		res_1 = ch / zn;
		return res_1;
	}
			
	Drob operator ++(int n)
	{
		ch = ch + zn;
		zn = zn;
		return *this;
	}
	Drob operator --(int n)
	{
		ch = ch - zn;
		zn = zn;
		return *this;
	}
	bool operator > (Drob n)
	{
		cout << (double)ch / zn << "   " << (double)n.ch / n.zn << endl;
		return (double)ch / zn > n.ch / n.zn;
	}
	bool operator < (Drob n)
	{
		cout <<  (double)n.ch / n.zn << "   " << (double)ch / zn << endl;
		return (double)ch / zn < n.ch / n.zn;
	}
	bool operator == (Drob n)
	{
		cout << (double)ch / zn << "   " << (double)n.ch / n.zn << endl;
		return (double)ch / zn == n.ch / n.zn;
	}
	bool operator != (Drob n)
	{
		cout << (double)ch / zn << "   " << (double)n.ch / n.zn << endl;
		return (double)ch / zn != n.ch / n.zn;
	}
};


int main()
{
	system("color F0");
	const int num_menu = 3;
	int ch = 0, active_menu = 0;
	bool q;
	
	do
	{
		int num1, num2, num3, num4;
		cout << "Enter fractions" << endl;
		cin >> num1 >> num2 >> num3 >> num4;
		Drob d1(num1, num2);
		Drob d2(num3, num4);
		Drob res;
		bool exit = false;
		while (!exit)
		{
			show_menu();
			gotoxy(0, active_menu);
			ch = _getch();
			if (ch == 224) ch = _getch();
			switch (ch)
			{

			case 27: exit = true; break;
			case 72: active_menu--; break;
			case 80: active_menu++; break;
			case 13:

				if (active_menu == 0)
				{
					system("cls");
					cout << "First fraction - " << num1 << "/" << num2 << "\t" << "Second fraction - " << num3 << "/" << num4 << endl;
					cout << "**********************************************" << endl;
					res = d1 + d2;
					cout << "addition of fractions + " << endl;
					res.print();
					cout << endl;
					res = d2 - d1;
					cout << "fraction subtraction - " << endl;
					res.print();
					cout << endl;
					res = d1 * d2;
					cout << "multiplication of fractions * " << endl;
					res.print();
					cout << endl;
					cout << "division of fractions / " << endl;
					res = d1 / d2;
					res.print();
					cout << endl;
					cout << "multiplication of number * num" << endl;
					res = d1 * 7;
					res.print();
					cout << endl;
					res = d2 * 7;
					res.print();
					cout << endl;
					cout << "multiplication a number (7) by a fraction" << endl;
					res = 7 * d1;
					res.print();
					cout << endl;
					res = 7 * d2;
					res.print();
					cout << endl;
					cout << "division without remainder %" << endl;
					cout << (d1 % d2) << endl;
					system("pause");
				}
				else if (active_menu == 1)
				{
					system("cls");
					cout << "First fraction - " << num1 << "/" << num2 << "\t" << "Second fraction - " << num3 << "/" << num4 << endl;
					cout << "*****************************************" << endl;
					cout << "first fraction > second fraction?" << endl;
					cout << (d1 > d2) << endl;
					cout << "second fraction > first fraction?" << endl;
					cout << (d1 < d2) << endl;
					cout << "fractions are equal ?" << endl;
					cout << (d1 == d2) << endl;
					cout << "fractions are not equal ?" << endl;
					cout << (d1 != d2) << endl;
					system("pause");
				}
				else if (active_menu == 2)
				{
					system("cls");
					cout << "First fraction - " << num1 << "/" << num2 << "\t" << "Second fraction - " << num3 << "/" << num4 << endl;
					cout << "*****************************************" << endl;
					cout << "increment first fraction" << endl;
					res = d1++;
					res.print();
					cout << endl;
					res = d2--;
					cout << "decrement second fraction" << endl;
					res.print();
					cout << endl;
					system("pause");
				}
				break;
			}
			if (active_menu < 0) active_menu = num_menu - 1;
			if (active_menu > num_menu - 1) active_menu = 0;
		}
		system("cls");
		cout << "If you wanna continue press 1, no 0" << endl;
		cin >> q;
		system("cls");
	} while (q == 1);
	system("cls");
		
	return 0;
}


	

	

	