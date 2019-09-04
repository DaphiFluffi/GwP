#include <iostream>
#include <string>

int main (){
	
	std::string satz; //Deklarieren einer string-Variable namens "satz"

	std::cout << "Float:" << std::endl; //Ausgabe des Namens des Datentypen
	std::cout << sizeof(float) << std::endl; //Ausgabe der Groesse des Datentypen

	std::cout << "Double:" << std::endl;
	std::cout << sizeof(double) << std::endl;

	std::cout << "Long Double:" << std::endl;
	std::cout << sizeof(long double) << std::endl;

	std::cout << "Char:" << std::endl;
	std::cout << sizeof(char) << std::endl;

	std::cout << "Short:" << std::endl;
	std::cout << sizeof(short) << std::endl;

	std::cout << "Int:" << std::endl;
	std::cout << sizeof(int) << std::endl;

	std::cout << "Long Int:" << std::endl;
	std::cout << sizeof(long int) << std::endl;

	std::cout << "Long Long Int:" << std::endl;
	std::cout << sizeof(long long int) << std::endl;

	std::cout << "String:" << std::endl;
	satz = "Dieser Satz kein Verb.";
	std::cout << sizeof(satz) << std::endl;
	
	return 0;
}
/*
Man erkennt, dass die unterschiedlichen Datentypen ueber unterschiedlich viel Speicher benoetigen. 
* Am wenigsten Speicher benoetigt ein "char" und am meisten ein "string".
* Die Groesse des strings hängt von der Länge des Satzes ab.
* Long int und Long Long Int sind beide 8 Byte gross, obwohl vom Namen her zu erwarten waere, dass long long int mindestens zwei Mal so gross wie long int sein wuerde.*/

