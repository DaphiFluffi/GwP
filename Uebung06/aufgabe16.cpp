#include <iostream>
#include <fstream> //fuer das Arbeiten mit Dateien

using namespace std;


/*double[] programm (){
	
}*/

int main (int argc, char** argv)
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
