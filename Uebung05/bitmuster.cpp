#include <iostream>
#include <string>

using namespace std;

/*Funktion nimmt ein Zeichen entgegen und interpretiert dessen ASCII-Zahlenwert im Binaersystem. 
 * Gibt ein String mit dem Binaermuster zurueck.*/
string bitmuster(char zeichen)
{
	string muster; //Variable, in der das Binaermuster des Zeichens gespeichert wird
	
	for (int i = 1; i <= 128; i = i * 2){ 	// zaehlt die Bitstellen hoch 00000001 = 1, 00000010 = 2, ...
		int a;	// Speicherstelle fuer das ergebnis vom Bitvergleich
		a = i & int(zeichen); 	// Der &-Operator darf nicht in der if-Bedingung ausgeführt werden.
		/*Wenn an der Bitstelle der Zahl eine 1 steht gibt der &-Operator den Dezimalwert dieser Bitstelle wieder.
		 *  Darum wird eine Fallunterscheidung in 0 und nicht 0 benoetigt.*/
		if(a == 0){
			muster = "0" + muster;
		}else{  
			muster = "1" + muster;
		}
	}
	return muster;
}
