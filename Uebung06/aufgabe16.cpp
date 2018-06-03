#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Fragen: kann man statt if(!datei) auch irgendwie argc verwenden?
// Wie macht man die dynamische speicherverwaltung, delete[] laueft nicht?
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
	
	int i = 0; // Zaehlervariable fuer die while-Schleife
	string zeile; //string- Variable, die in der getline()-Funktion verwendet wird, um die Datei Zeilenweise auszulesen
	while (getline(datei, zeile)) //Ausfuehren der getline()-Funktion 
	{
		//cout << "zeile: " << zeile << '\n';
		double wert; //double-Variable wert, in der die als strings in der Variable zeile gespeicherten ausgelesenen Zahlenwerte, als doubles gespeichert werden sollen.
		wert = atof(zeile.c_str()); // atof ist ein Befehl mit dem man Strings in doubles umwandeln kann. Als Argument nimmt atof nur const char*. "zeile" ist jedoch eine string-Variable, sodass man diese erstmal durch c_str() umwandeln muss.
		//cout << "wert: " << wert << endl;
		double* array = new double[i]; //Erstellen eines double* arrays mit dem new[]-Operator fuer dynamische Speicherverwaltung.
		array[i] = wert; // Befuellen des arrays an der i-ten Stelle mit den Werten aus der Datei
		//cout << "array[" << i <<"]: " << array[i] << endl;
		cout <<  array[i] << endl;
		//cout << "i:" << i << endl;
		i++; 
		//delete[] array;
	}
	datei.close(); //Schliessen der Datei
	//delete[] array;
	//cout << "array nach delete: " << array << endl;
	return 0;
}


/*int main (int argc, char** argv)
{
	// Argumentauswertung
	ofstream datei;
	datei.open ("beispiel.txt");
	datei << "Dieser Satz kein Verb." << endl;
	datei.close();
	return 0;
}
//ofstream datei ("data.bin", ios::out | ios::app | ios::binary);
//cout << argv[0] << endl; //Ausgabe des Dateinamen !
*/
