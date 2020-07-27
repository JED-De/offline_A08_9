#include <iostream>
#include <string>
using namespace std;

int main()
{
	int hoehe;
	int  stufenhoehe;
	int links, rechts;
	do
	{
	cout << "Bitte die Hoehe des Tannenbaums eingeben: ? ";
	cin >> hoehe;
	} while (hoehe <= 1);

	do
	{
		cout << "Bitte die Hoehe jeder Stufe eingeben: ? ";
		cin >> stufenhoehe;
	} while (stufenhoehe > hoehe &&  stufenhoehe <= 1);
	string* canvas = new string[hoehe];
	links = rechts = hoehe;
	for (int i = 0; i < hoehe; i++)
	{
		for (int j = 0; j < hoehe*2; j++)
		{
			canvas[i] += '+';
		}
	}
	int zaehler = 1;
	for (int i = 0; i < hoehe; i++)
	{
		for (int j = 0; j < hoehe * 2; j++)
		{
			if (j == links || j == rechts)
			{
				canvas[i].at(j) = '*';
				if (((i+ zaehler) % stufenhoehe) == 0)
				{
					zaehler++;
				//	if (zaehler == 1)
				//	{
				//		stufenhoehe--;
				//	}
					canvas[i].at(links) = '*';
					canvas[i].at(rechts) = '*';
					for (int k = 0; k < 2; k++)
					{
						links++;
						rechts--;
						canvas[i].at(links) = '*';
						canvas[i].at(rechts) = '*';

					}
					break;
				}
			}
		}
		links--;
		rechts++;
	}
	for (int i = 0; i < hoehe; i++)
	{
		for (int j = 0; j < hoehe*2; j++)
		{
			cout << canvas[i].at(j);
		}
		cout << '\n';
	}
		system("PAUSE");
	return 0;
}
