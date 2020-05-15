/*
Author: Kat Bergen
v.01 14.05.2020
source folder: C:\Users\katha\source\repos\

caculate squareroot without library imports but including loops

pad1-P1-A1-c
*/


#include <iostream>
using std::cout;
using std::cin;


// calculating squareroot via this formula --> num(n+1) = (num + startValue / num) / 2
double sqrt(const double num, const double accuracy)
{
	//variables to use in calculation/formula
	const double startValue{ num }; 
	double result{ num };

	//variables to check whether the wanted accuracy was achieved
	double difference{ -1 };
	double temporary{ num };

	//counter to check how many loops were needed to achieve wanted accuracy
	int counter{ 0 };


	while (difference < 0 || difference > accuracy)
	{
		result = (result + startValue / result) / 2;
		
		//ensures difference is always calculated 'larger number - smaller number'
		if (temporary > result)
		{
			difference = temporary - result;
		}
		else
		{
			difference = result - temporary;
		}

		temporary = result;

		++counter;
	}

	cout << "\n\nIt took " << counter << " runs to achieve an accuracy level of: " << difference << ".\n";

	return result;
}



int main()

try {
	double number{ -1 };
	double accuracy{ -1 };


	//User input for the number he wishes to calculate the squareroot of
	while (number < 0)
	{
		cout << "Bitte geben Sie eine Gleitkommazahl >= 0 ein.\n";
		cin >> number;
		cin.ignore(10000, '\n');

		if (number < 0) cout << "Der von Ihnen eingegebene Wert ist nicht größer oder gleich 0. \n\n";

		if (!cin.good())
		{
			throw std::runtime_error{ "Wrong data type" };
		}

	}

	//User input for the accuracy he wishes the squareroot to be calculated with
	while (accuracy < 0)
	{
		cout << "Bitte geben Sie an, mit welcher Genauigkeit die Berechnung erfolgen soll. Geben Sie beispielsweise '0,01' ein, wenn die Berechnung bis zur zweiten Nachkommastelle akkurat sein soll.\n";
		cin >> accuracy;

		if (accuracy < 0) cout << "Der von Ihnen eingegebene Wert ist nicht größer oder gleich 0. \n\n";

		if (!cin.good())
		{
			throw std::runtime_error{ "Wrong data type" };
		}

	}

	cout << "Die Quadratwurzel von " << number << " ist: " << sqrt(number, accuracy) << std::endl;

	return 0;
}

catch (const std::exception&)
{
	cout << "\nA wrong data type was inputted. The programm is interrupted. Please restart and retry.\n\n";
}