#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Zepolone.h"


using namespace std;

class Wektor
{

	double m_dx = 0.0, m_dy = 0.0;
public:
	Wektor setDXY(double dx, double dy)
	{
		m_dx = dx;
		m_dy = dy;
	}
	double getDX() const { return m_dx; }
	double getDY() const { return m_dy; }
	double dlugosc() const { return sqrt(m_dx * m_dx + m_dy * m_dy); }
	Wektor(double dx, double dy);
	static Wektor toWektor(LiczbyZespolone& liczba);
};