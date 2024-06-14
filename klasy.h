#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


class Wektor;

class Punkt
{
	double m_x = 0.0, m_y = 0.0;
public:
	void setXY(double x, double y)
	{
		m_x = x;
		m_y = y;
	}
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	Punkt(double x, double y)
		:m_x(x), m_y(y)
	{}
	Punkt() {}

	//Konwersja Wektor -> Punkt
	static Wektor toWektor(const Punkt* a, const Punkt* b);

	//Operator dwuargumentowy pary Punkt Wektpr
	Punkt operator+ (const Wektor& inny);

};

class Kolo
{
	double m_promien = 1.0;
	Punkt m_srodek;
public:
	void setPromien(double r)
	{
		m_promien = (r > 0) ? r : 0;
	}
	void setSrodek(Punkt p)
	{
		m_srodek = p;
	}
	double getPromien() const { return m_promien; }
	Punkt getSrodek() const { return m_srodek; }
	Kolo(Punkt sr, double r)
		: m_srodek(sr), m_promien(r)
	{}
};

class Kwadrat
{
	Punkt m_lewy_dolny, m_prawy_gorny;
public:
	void setRogi(Punkt ld, Punkt pg)
	{
		m_lewy_dolny = ld;
		m_prawy_gorny = pg;
	}
	Punkt getLewyDolny() const { return m_lewy_dolny; }
	Punkt getPrawyGorny() const { return m_prawy_gorny; }
	Kwadrat(Punkt ld, Punkt pg)
		:m_lewy_dolny(ld), m_prawy_gorny(pg)
	{}
	Kwadrat(const Punkt& punkt)
	{
		double X = -punkt.getX();
		double Y = -punkt.getY();

		Punkt punktPrzeciwlegly(0.0 + X, 0.0 + Y);

		m_lewy_dolny = punkt;
		m_prawy_gorny = punktPrzeciwlegly;
	}

	double obliczPole() const
	{
		double dx = m_prawy_gorny.getX() - m_lewy_dolny.getX();
		double dy = m_prawy_gorny.getY() - m_lewy_dolny.getY();
		double przekatna = sqrt(dx * dx + dy * dy);
		double bok = przekatna / sqrt(2);
		return bok * bok;
	}

	bool operator== (const Kwadrat& inny) 
	{
		return this->obliczPole() == inny.obliczPole();
	}

	operator Wektor();
};

class Wektor
{
	double m_dx = 0.0, m_dy = 0.0;
public:
	void setDXY(double dx, double dy)
	{
		m_dx = dx;
		m_dy = dy;
	}
	double getDX() const { return m_dx; }
	double getDY() const { return m_dy; }
	double dlugosc() const { return sqrt(m_dx * m_dx + m_dy * m_dy); }
	Wektor(double dx, double dy)
		:m_dx(dx), m_dy(dy)
	{}

	//Konwersja Wektor -> Punkt
	Punkt toPunkt(int n);

};


//Konwersja Wektor-?> Punkt
Punkt Wektor::toPunkt(int n) {
	Punkt wynik(n * m_dx, n * m_dy);
	return wynik;
}

Wektor Punkt::toWektor(const Punkt* a, const Punkt* b) {
	double x = b->m_x - a->m_x;
	double y = b->m_y - a->m_y;
	double dlugosc = sqrt(x * x + y * y);
	x = x / dlugosc;
	y = y / dlugosc;
	Wektor wynik(x, y);
	return wynik;
}

Punkt Punkt::operator+ (const Wektor& inny) {
	double x = m_x + inny.getDX();
	double y = m_y + inny.getDY();
	Punkt wynik(x, y);
	return wynik;
}

Kwadrat::operator Wektor()
{
	double x = m_prawy_gorny.getX() - m_lewy_dolny.getX();
	double y = m_prawy_gorny.getY() - m_lewy_dolny.getY();
	Wektor wynik(x, y);
	return wynik;
}