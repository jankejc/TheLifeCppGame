#include <iostream>
#include "Swiat.h"

int main()
{
	char kolejna_tura = 'a';
	Swiat swiat(20, 20);
	swiat.wizytowka();
	while (kolejna_tura != 'q')
	{
		cout << endl << "Kliknij \"p\", aby wykonac ture lub \"q\" aby wyjsc." << endl;
		kolejna_tura = _getch();
		if (kolejna_tura != 'q')
		{
			swiat.wykonajTure();
			system("cls");
			swiat.rysujSwiat();
			swiat.wypiszStatystyki();
		}
	}
		
	
	

    return 0;
}

