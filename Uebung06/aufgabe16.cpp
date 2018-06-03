#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char** argv)
{
	/*string filename; //erstellen eines String filename, damit man den dateinamen einlesen kann 
	cout << "Datei: "; //einlesen des strings filename vom benutzer
	cin >> filename;*/
	
	cout << "Datei: "; //einlesen des strings filename vom benutzer
	cin >> argv[0];
	
	ifstream input;
//	input.open (filename, ios::in); 
	input.open (argv[0], ios::in);
	if(!input) {  // Überprüfung ob Datei geöffnet wurde //wie macht man das mit argc?
		//cerr << "Programm beim Oeffnen der Datei " << filename << " gescheitert." << "\n" 
		//<< "Bitte speichern Sie die zuoeffnende Datei in demselben Verzeichnis wie dieses Programm ab und geben sie beim naechsten Ausfuehren den richtigen Dateinamen ein." << endl;
		cerr << "Programm beim Oeffnen der Datei " << argv[0] << " gescheitert." << "\n" 
		<< "Bitte speichern Sie die zuoeffnende Datei in demselben Verzeichnis wie dieses Programm ab und geben sie beim naechsten Ausfuehren den richtigen Dateinamen ein." << endl;
		return 1;
	}
	int i = 0;
	string line;
	while (getline(input, line))
	{
		cout << "line: " << line << '\n';
		double wert;
		wert = atof(line.c_str()); 
		cout << "wert: " << wert << endl;
		double* array = new double[i];
		array[i] = wert;
		cout << "array[" << i <<"]: " << array[i] << endl;
		cout << "i:" << i << endl;
		i++;
		//delete[] array;
	}
	input.close();
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
