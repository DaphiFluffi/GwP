#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char** argv)
{
	cout << "Datei: "; // Einlesen des Dateinamens vom User ueber argv[0], weil dort der Dateiname standarsmassig gespeichert wird
	cin >> argv[0];
	
	ifstream datei; //Erstellen eines ifstream-Objekts namens datei. Ich benutze ifstream, weil datei nur eingelesen werden soll. 
	datei.open (argv[0], ios::in); // Oeffnen der Datei mit Uebergabe des eingelesenen Dateinamens argv[0] und des Modus ios::in, um anzugeben, dass die Datei nur num Einlesen verwendet werden soll.
	if(!datei) {  // Falls man die Datei nicht oeffnen kann ...
		//... wird mit cerr (dem Standardausgabestream) eine Fehlermeldung ausgegeben ...
		cerr << "Programm beim Oeffnen der Datei " << argv[0] << " gescheitert." << "\n" 
		<< "Bitte speichern Sie die zuoeffnende Datei in demselben Verzeichnis wie dieses Programm ab und geben sie beim naechsten Ausfuehren den richtigen Dateinamen ein." << endl;
		return 1; //... und das Programm beendet. Mit return 1 wird signalisiert, dass beim Ausfuehren ein Fehler unterlaufen ist.
	}
	
	int i = 0; // Zaehlervariable fuer die while-Schleifen
	string zeile; //string- Variable, die in der getline()-Funktion verwendet wird, um die Datei Zeilenweise auszulesen
	while (getline(datei, zeile)) //erste while-Schleife, die die Anzahl der Zeilen in der Datei durch Erhoehen der Zahlervariable auszaehlt
	{
		i++;
	}
	
	double* darray = new double[i]; //Erstellen eines double-Arrays "darray" mit dem new[]-Operator für die dynamische Speicherverwaltung
	datei.close(); //Schliessen der Datei
	datei.open(argv[0], ios::in); //Erneutes Oeffnen der Datei, da durch den getline()-Befehl in der ersten while-Schleife der Pointer am Ende der Datei steht und wir die Datei vom Anfang wieder einlesen moechten
	while (getline(datei, zeile))
	{
		double wert; //double-Variable wert, in der die als strings in der Variable zeile gespeicherten ausgelesenen Zahlenwerte, als doubles gespeichert werden sollen
		wert = atof(zeile.c_str()); // "atof" ist ein Befehl mit dem man Strings in doubles umwandeln kann. Als Argument nimmt atof nur const char*. "zeile" ist jedoch eine string-Variable, sodass man diese erstmal durch c_str() umwandeln muss.
		darray[i] = wert; // Nacheinander Befuellen der i Stellen in darray mit den Werten aus der eingelesenen Datei
		cout <<  darray[i] << endl;
	}
	delete[] darray; //Freigeben des fuer das array beanspruchten Speicherplatzes nach Ende des Programms
	return 0;
}
