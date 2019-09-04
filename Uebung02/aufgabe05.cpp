#include <iostream>
#include <cmath>
using namespace std;

int main ()
	{
	double grad; //Variable, die den Wert der angegebenen Grad-Zahl annimmt
	double bogenmass; //Variable, in der der ins Bogenmass umgerechnete Wert gespeichert wird
	
	cout << "Bitte Winkel angeben: ";
	cin >> grad;

	// Umrechnung der Eingabe:
	bogenmass = (2 * M_PI / 360) * grad;
	
	// Berechnung und Ausgabe von Sinus, Cosinus, Tangens:
	cout << "Sinus: " << sin(bogenmass) << endl;
	cout << "Kosinus: " << cos(bogenmass) << endl;
	cout << "Tangens: " << tan(bogenmass) << endl;
	}

/* Es laesst sich beobachten, dass an Stellen wie z.B. bei 90 Grad, wo der Tangens nicht definiert ist bzw. unendlich ergibt dennoch eine Zahl ausgegeben wird.
In dem Beispielfall ist es 1.63312e+16. Grund dafür ist dass der Wert unendlich nicht als Fließkommazahl dargestellt werden kann. 
* Entsprechend versucht der Kompiler diese Zahl zu runden und scheitert daran, sodass sich eine derartige falsche Zahl ergibt. 
* Bei 90 Grad sollte der Kosinus zudem Null ergeben. Ausgegeben wird jedoch die Zahl 6.12323e-17. Da der Winkel 90 Grad im Bogenmass Pi/2 ergibt, 
* muss der Compiler aus Pi/2 den Kosinus ziehen. Nun ist Pi eine irrationale Zahl mit unendlich vielen Nachkommastellen. 
* Die Nachkommastellen eines doubles sind in c++ jedoch begrenzt, was zu einem ähnlichen Fall wie beim Tangens führt, 
* dass es zu wiederholten Rundungsfehlern beim Herunterkomprimieren der Nachkommastellen von Pi/2 und dem Ausrechnen des Kosinus aus Pi/2 kommt. 
* Genauso verhaelt es sich beim Sinus bei 180 Grad.
* Sobald der Sinus nicht aus einem Pi-Term gezogen werden muss, wie z.B. bei 0 Grad, das auch im Bogenmass Null ergibt, 
* funktioniert die Ausgabe einer Null ohne Probleme.*/
