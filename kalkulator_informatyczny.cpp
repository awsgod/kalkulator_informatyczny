
/* zalecam nie uzywac konsoli w pełnym oknie, aby uzyskać jak najwieksze wrazenia z uzytkowania programu :)) */


#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <bitset>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // uzywane przez "goto" informacje co do tego mozna znalezc na popularnych stronach o tematyce programowania 
COORD CursorPosition; // uzywane przez "goto" informacje co do tego mozna znalezc na popularnych stronach o tematyce programowania 

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y;                    //ustalanie zmiennych x i y dzięki temu łatwiej będzie nam pracować z tymi funkcjami w przyszlosci
	SetConsoleCursorPosition(console,CursorPosition); 
}

string naBinarna(int n) {
    string binarna = "";
    while (n > 0) {
        binarna = to_string(n % 2) + binarna; // Dodajemy resztę z dzielenia przez 2 na początek binarnej liczby.
        n /= 2; // Dziel n przez 2, by uzyskać kolejną cyfrę binarną.
    }
    return binarna; // Zwracamy liczbę binarną jako ciąg znaków.
}

string naSzesnastkowa(int n) {
    string szesnastkowa = "";
    while (n > 0) {
        int reszta = n % 16; // Obliczamy resztę z dzielenia przez 16.
        if (reszta < 10) {
            szesnastkowa = to_string(reszta) + szesnastkowa; // Jeśli reszta jest mniejsza niż 10, dodajemy ją jako cyfrę.
        } else {
            szesnastkowa = (char)('A' + reszta - 10) + szesnastkowa; // W przeciwnym razie, dodajemy ją jako literę (A-F).
        }
        n /= 16; // Dziel n przez 16, by uzyskać kolejną cyfrę szesnastkową.
    }
    return szesnastkowa; // Zwracamy liczbę szesnastkową jako ciąg znaków.
}

string naOsemkowa(int n) {
    string osemkowa = "";
    while (n > 0) {
        osemkowa = to_string(n % 8) + osemkowa; // Dodajemy resztę z dzielenia przez 8 na początek ósemkowej liczby.
        n /= 8; // Dziel n przez 8, by uzyskać kolejną cyfrę ósemkową.
    }
    return osemkowa; // Zwracamy liczbę ósemkową jako ciąg znaków.
}
// Funkcja zamieniająca liczbę na jej binarną reprezentację za pomocą kodu U1
bitset<8> zamien_na_u1(unsigned int liczba) {
    const unsigned int maksymalna_wartosc_u1 = 255;
    if (liczba > maksymalna_wartosc_u1) { // Sprawdzenie, czy liczba jest większa od maksymalnej wartości dla kodu U1
        liczba = maksymalna_wartosc_u1; // Jeśli tak, przypisujemy jej wartość maksymalną
    }
    return bitset<8>(liczba); // Zwracamy binarną reprezentację liczby w kodzie U1
}

// Funkcja zamieniająca liczbę na jej binarną reprezentację za pomocą kodu U2
bitset<8> zamien_na_u2(int liczba) {
    const int maksymalna_wartosc_u2 = 127; // Maksymalna wartość dla kodu U2
    const int minimalna_wartosc_u2 = -128; // Minimalna wartość dla kodu U2

    if (liczba > maksymalna_wartosc_u2) { // Sprawdzenie, czy liczba jest większa od maksymalnej wartości dla kodu U2
        liczba = maksymalna_wartosc_u2; // Jeśli tak, przypisujemy jej wartość maksymalną
    }
    else if (liczba < minimalna_wartosc_u2) { // Sprawdzenie, czy liczba jest mniejsza od minimalnej wartości dla kodu U2
        liczba = minimalna_wartosc_u2; // Jeśli tak, przypisujemy jej wartość minimalną
    }
    return bitset<8>(liczba); // Zwracamy binarną reprezentację liczby w kodzie U2
}

int main()
{  
 	HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); //wybieranie kolorów znaków w konsoli. Dostępne kolory: (FOREGROUND_RED FOREGROUND_GREEN FOREGROUND_BLUE) Kolory mozna mieszać, oraz zmieniac intensywność itp.
	
	int wybor=0,  x=10; //deklarujemy zmienne, wybor odpowiada za wybieranie funkcji programu, x  (w tym przypadku x=10) za miejsce pierwszego wyboru w menu, tam strzałka pojawia się jako pierwsza
	bool running = true; //dzięki tej linijce kodu, program jest w stanie działac az do wybrania funkcji "Zakoncz"
	
	gotoXY(50,5); cout << "Menu glowne";
	gotoXY(38,7);  cout << "Po menu poruszasz sie strzalkami :)";
	
	
	while(running)
	{   
		gotoXY(40,9);  cout << "============================";
        gotoXY(40,10);  cout << "= 1:                       =";
		gotoXY(40,11);  cout << "= 2:                       =";
		gotoXY(40,12);  cout << "= 3:                       =";
		gotoXY(40,13); cout << "= 4:                       =";
		gotoXY(40,14); cout << "= 5:                       =";			
		gotoXY(40,15); cout << "=          Zakoncz         =";
		gotoXY(40,16);  cout << "============================";
		system("pause>nul"); // Funkcja >null pozwala na brak wyswietlania komunikatu
		
		if(GetAsyncKeyState(VK_DOWN) && x != 15) // Ta część kodu odpowiada za poprawne działanie strzałki w dół, dzięki temu strzałka nie będzie wychodzić poza wyznaczony UWAGA WARTOŚCI po " != " MUSZĄ BYC ZMIENIANE ZA KAZDYM RAZEM KIEDY DODAMY NOWĄ FUNKCJE W MENU
			{
				gotoXY(38,x); cout << "  ";
				x++;
				gotoXY(38,x); cout << "->";
				wybor++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 10) // Analogicznie jak do kodu u góry, tylko, ze tymrazem jest to strzałka w góre
			{
				gotoXY(38,x); cout << "  ";
				x--;
				gotoXY(38,x); cout << "->";
				wybor--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Ta linijka kodu pozwala na odczytanie wcisniętego "Enter" przez uzytkownika, tak aby program mógł wybrac daną funkcje
			
			
			
			switch(wybor){           //Wszystko sprowadza się do tej cześci, mianowicie tutaj znajdują sie głowne funkcje programu, w tym przypadku będą to zadania :))
				
				case 0: {
					
					gotoXY(30,16);
					 int dziesietna;
    				 cout << "Podaj liczbe dziesietna: ";
					 cin >> dziesietna; // Wczytujemy liczbę dziesiętną od użytkownika.
					 cout << "Liczba w systemie binarnym: " << naBinarna(dziesietna) << endl; // Wywołujemy funkcję naBinarna() i wyświetlamy wynik.
					
					break;
				}
					
					
				case 1: {
					gotoXY(30,16);
					int dziesietna;
    				cout << "Podaj liczbe dziesietna: ";
					cin >> dziesietna; // Wczytujemy liczbę dziesiętną od użytkownika.
					cout << "Liczba w systemie szesnastkowym: " << naSzesnastkowa(dziesietna) << endl; // Wywołujemy funkcję naSzesnastkowa i wyświetlamy wynik.
					break;
				}
					
				case 2: {
					gotoXY(30,16);
					int dziesietna;
    				cout << "Podaj liczbe dziesietna: ";
					cin >> dziesietna; // Wczytujemy liczbę dziesiętną od użytkownika.
					cout << "Liczba w systemie osemkowym: " << naOsemkowa(dziesietna) << endl; // Wywołujemy funkcję naOsemkowa() i wyświetlamy wynik.
					
					break;
				}
					
				case 3: {
					gotoXY(30,16);
					 
    				 unsigned int liczba; // Liczba, która ma być przekonwertowana na jej binarną reprezentację
    				 
    				 cout << "Podaj nieujemna liczbe "<< endl;
    				 cin >> liczba; // Wczytanie liczby od użytkownika

    				bitset<8> liczba_binarna_u1 = zamien_na_u1(liczba); // Przypisanie wartości binarnej reprezentacji liczby w kodzie U1 do zmiennej
    				cout << "Liczba " << liczba << " w kodzie U1: " << liczba_binarna_u1 << endl; // Wyświetlenie wyniku konwersji
					
					break;
				}
					
				case 4: {
					gotoXY(30,16);
					int liczba; // Liczba, która ma być przekonwertowana na jej binarną reprezentację
    				cout << "Podaj liczbe do konwersji na kod U2: ";
    				cin >> liczba; // Wczytanie liczby od użytkownika

    				bitset<8> liczba_binarna_u2 = zamien_na_u2(liczba); // Przypisanie wartości binarnej reprezentacji liczby w kodzie U2 do zmiennej
    				cout << "Liczba " << liczba << " w kodzie U2: " << liczba_binarna_u2 << endl; // Wyświetlenie wyniku konwersji
					
					break;
				}
				
				case 5: {
					gotoXY(30,16);
					cout << "Aktualnie program zakonczyl swoje dzialanie, mozesz wylaczyc okno konsoli!!";
					running = false;
				}
				
			}
				
		}		
		
	}
	
	
	return 0;
}