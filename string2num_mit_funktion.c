// Programm zur Konvertierung von Zeichenketten/Strings in Zahlen
// Autor: Fabian Prestros
// Datum: 04.12.2020
#include <stdio.h>
#include <string.h>
#include <math.h>

// Funktion wandelt Zeichenkette in Ganze Zahl um
void zeichen_in_int(char eingabe[20], int ausgabe[2])
{
	int laenge = 0;
	int zahl = 0;
	int ziffer = 0;
	int fehler = 0;
	int start = 0;

	laenge = strlen(eingabe);

	if (eingabe[0] == '-')
		start = 1;

	for (int i = start; i < laenge; i++)
	{
		if (eingabe[i] < '0' || eingabe[i] > '9')
			fehler++;
		else
		{
			zahl = zahl * 10;
			ziffer = eingabe[i];
			zahl = zahl + (ziffer - '0');
		}
	}

	if (start == 1)
		zahl = zahl * (-1);
	
	ausgabe[0] = fehler;
	ausgabe[1] = zahl;
}

// Ausgabe der Ganzen Zahl
void ausgabefunktion_int(int ausgabe[2])
{
	if (ausgabe[0] == 0)
		printf("Ergebnis = %d\n", ausgabe[1]*2);
	else
		printf("Fehlercodes = %d\n", ausgabe[0]);
}

// Funktion wandelt Zeichenkette in Fließkommazahl um
void zeichen_in_double(char eingabe[20], double ausgabe[2])
{
	int laenge = 0;
	double zahl = 0;
	double ziffer = 0;
	int fehler = 0;
	int start = 0;
	int punkt = 0;
	int nachkomma;

	laenge = strlen(eingabe);

	if (eingabe[0] == '-')
		start = 1;

	for (int i = start; i < laenge; i++)
	{
		if (eingabe[i] == '.')
		{
			punkt++;
			nachkomma = i;
		}

		else
		{
			if (punkt == 0)
				if (eingabe[i] < '0' || eingabe[i] > '9')
					fehler++;
				else
				{
					zahl = zahl * 10;
					ziffer = eingabe[i];
					zahl = zahl + (ziffer - '0');
				}
			else if (punkt == 1)
			{
				if (eingabe[i] < '0' || eingabe[i] > '9')
					fehler++;
				else
				{
					ziffer = eingabe[i];
					zahl = zahl + (ziffer - '0') * pow(10, -(i-nachkomma));
				}
			}
			else
				fehler++;
		}
	}

	if (start == 1)
		zahl = zahl * (-1);

	ausgabe[0] = fehler;
	ausgabe[1] = zahl;
}

// Ausgabe der Fließkommazahl
void ausgabefunktion_double(double ausgabe[2])
{
	if (ausgabe[0] == 0)
		printf("Ergebnis = %lf\n", ausgabe[1] * 2);
	else
		printf("Fehlercodes = %lf\n", ausgabe[0]);
}

int main()
{
	int i;
	int laenge;
	int punkt = {0};
	char eingabe[20] = {0};
	int int_ausgabe[2] = {0};
	double double_ausgabe[2] = {0};
	
	// Zeichenkette einlesen
	printf("Bitte gebeb Sie eine Zahl ein: ");
	gets_s(eingabe, 20);
	
	laenge = strlen(eingabe);

	for (i = 0; i < laenge; i++)
	{
		if(eingabe[i] == '.')
			punkt++;
	}
	
	if (punkt == 0)
	{
		zeichen_in_int(eingabe, int_ausgabe);
		ausgabefunktion_int(int_ausgabe);
	}
	else
	{
		zeichen_in_double(eingabe, double_ausgabe);
		ausgabefunktion_double(double_ausgabe);
	}
}