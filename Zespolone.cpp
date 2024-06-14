#include "Zepolone.h"



LiczbyZespolone::LiczbyZespolone() :
	czescRzecz(1.0), czescUrojona(1.0)
{

};

LiczbyZespolone::LiczbyZespolone(double rzeczywista, double urojona)
{
	setRzeczywista(rzeczywista);
	setUrojona(urojona);
}

//Konwersja z double 
LiczbyZespolone::LiczbyZespolone(double other) :czescRzecz(other), czescUrojona(0.0)
{};

//Konwersja do double
LiczbyZespolone::operator double()
{
	return czescRzecz;
}


