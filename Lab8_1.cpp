#include <iostream>
#include"Wektor.h"
#include"Zepolone.h"


int main()
{
	LiczbyZespolone liczba(5.5, 4.6);
	cout << "Z = " << liczba.getRzeczywista() << " + i" << liczba.getUrojona() << endl;

	cout << LiczbyZespolone(3.0).getRzeczywista()<<" do double "<< LiczbyZespolone(4.0).getUrojona()<<endl;

	cout << LiczbyZespolone(double(liczba))<<endl;


	LiczbyZespolone liczba1(2.2, 3.2), liczba2(5.0, 7.2);

	double liczbyRzeczywisteD = liczba1.getRzeczywista() + liczba2.getRzeczywista();
	double liczbyUrojoneD = liczba1.getUrojona() + liczba2.getUrojona();
	cout << "Dodawanie: " << liczbyRzeczywisteD << "+ i" << liczbyUrojoneD << endl;

	double liczbyRzeczywisteO = liczba1.getRzeczywista() - liczba2.getRzeczywista();
	double liczbyUrojoneO = liczba1.getUrojona() - liczba2.getUrojona();
	cout << "Odejmowanie: " << liczbyRzeczywisteO << "+ i" << liczbyUrojoneO << endl;

	double liczbyRzeczywisteM = liczba1.getRzeczywista() * liczba2.getRzeczywista();
	double liczbyUrojoneM = liczba1.getUrojona() * liczba2.getUrojona();
	cout << "Mnożenie: " << liczbyRzeczywisteM << "+ i" << liczbyUrojoneM<<endl;

	double liczbyRzeczywisteDZ = liczba1.getRzeczywista() / liczba2.getRzeczywista();
	double liczbyUrojoneDZ = liczba1.getUrojona() / liczba2.getUrojona();
	cout << "Dzielenie: " << liczbyRzeczywisteD << "+ i" << liczbyUrojoneDZ << endl;



}

