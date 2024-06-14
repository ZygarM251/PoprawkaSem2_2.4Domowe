#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class LiczbyZespolone
{
	double czescRzecz;
	double czescUrojona;

public:

	void setRzeczywista(double liczbaRzeczywista)
	{
		if (liczbaRzeczywista > 0.0)
		{
			czescRzecz = liczbaRzeczywista;
		}
	}
	void setUrojona(double liczbaUrojona)
	{
		if (liczbaUrojona > 0.0)
		{
			czescUrojona = liczbaUrojona;
		}
	}

	double getRzeczywista() { return czescRzecz; }
	double getUrojona() { return czescUrojona; }

	LiczbyZespolone();
	LiczbyZespolone(double rzeczywista, double urojona);

	//Konwersja z double 
	LiczbyZespolone(double other);

	//Konwersja do double
	operator double();
	LiczbyZespolone operator+(LiczbyZespolone& other)
	{
		double liczbaRzeczywista = this->getRzeczywista() + other.getRzeczywista();
		double liczbaUrojona = this->getUrojona() + other.getUrojona();
		return LiczbyZespolone(liczbaRzeczywista, liczbaUrojona);
	}
	LiczbyZespolone operator-(LiczbyZespolone& other)
	{
		double liczbaRzeczywista = this->getRzeczywista() - other.getRzeczywista();
		double liczbaUrojona = this->getUrojona() - other.getUrojona();
		return LiczbyZespolone(liczbaRzeczywista, liczbaUrojona);
	}
	LiczbyZespolone operator*(LiczbyZespolone& other)
	{
		double liczbaRzeczywista = this->getRzeczywista() * other.getRzeczywista();
		double liczbaUrojona = this->getUrojona() * other.getUrojona();
		return LiczbyZespolone(liczbaRzeczywista, liczbaUrojona);
	}
	LiczbyZespolone operator/(LiczbyZespolone& other)
	{
		double liczbaRzeczywista = this->getRzeczywista() / other.getRzeczywista();
		double liczbaUrojona = this->getUrojona() / other.getUrojona();
		return LiczbyZespolone(liczbaRzeczywista, liczbaUrojona);
	}

};