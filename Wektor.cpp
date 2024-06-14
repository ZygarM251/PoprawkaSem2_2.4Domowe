#include "Wektor.h"


Wektor::Wektor(double dx, double dy)
	:m_dx(dx), m_dy(dy)
{}
static Wektor toWektor(LiczbyZespolone& liczba)
{
	return Wektor(liczba.getRzeczywista(), liczba.getUrojona());
}