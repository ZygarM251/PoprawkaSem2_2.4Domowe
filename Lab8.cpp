#include <iostream>
#include "klasy.h"

void TestPktDoKwadrat()
{
	cout << "Test konwersji punktu na kwadrat: ";
	Punkt punktA(-2, 3), punktB(0, 4.3);
	Kwadrat Kw1(punktA), Kw2(punktB);
	bool test1 = ((Kw1.getLewyDolny().getX() == -3) && (Kw1.getLewyDolny().getY() == -2));
	bool test2 = ((Kw1.getPrawyGorny().getX() == 3) && (Kw1.getPrawyGorny().getY() == 2));
	bool test3 = ((Kw2.getLewyDolny().getX() == 0) && (Kw2.getLewyDolny().getY() == -4.3));
	bool test4 = ((Kw2.getPrawyGorny().getX() == 0) && (Kw2.getPrawyGorny().getY() == 4.3));
	if (test1 && test2 && test3 && test4)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}

void TestWektorDoPkt()
{
	cout << "Test konwersji wektora na punkt: ";
	Wektor WekA(2, 3), WekB(-1, 2);
	Punkt PktA(0, 0), PktB(0, 0);
	PktA = WekA.toPunkt(1);
	PktB = WekB.toPunkt(2);
	bool testA = ((PktA.getX() == 2) && (PktA.getY() == 3));
	bool testB = ((PktB.getX() == -2) && (PktB.getY() == 4));
	if (testA && testB)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}

void TestOperatorKwadratow()
{
	cout << "Test operatora do porownania kwadratow: ";
	Punkt pktA(-2, -2), pktB(2, 2), pktC(3, 3);
	Kwadrat KwA(pktA, pktB), KwB(pktA, pktC);
	bool testA = (KwA == KwA);
	bool testB = (KwA == KwB);
	if (testA && !testB)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}

void TestOperatorPktWektor()
{
	cout << "Test operatora dla pary punkt wektor: ";
	Punkt pktA(-2, -2), pktB(2, 3);
	Wektor WekA(1, 2), WekB(2.5, 3);
	pktA = pktA + WekA;
	pktB = pktB + WekB;
	bool testA = (pktA.getX() == -1 && pktA.getY() == 0);
	bool testB = (pktB.getX() == 4.5 && pktB.getY() == 6);
	if (testA && testB)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}

void TestKwadratDoWektor() 
{
	cout << "Test konwersji kwadratu na wektor: ";
	Punkt pktA(-2, -2), pktB(2, 1), pktC(3, 3);
	Kwadrat KwA(pktA, pktB), KwB(pktA, pktC);
	Wektor WekA(0, 0), WekB(0, 0);
	WekA = static_cast<Wektor>(KwA);
	WekB = static_cast<Wektor>(KwB);
	bool testA = (WekA.getDX() == 4 && WekA.getDY() == 3);
	bool testB = (WekB.getDX() == 5 && WekB.getDY() == 5);
	if (testA && testB)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}
void TestDwaPktDoWektor() 
{
	cout << "Test konwersji 2 punktow na wektor: ";
	Punkt pktA(-2, 2), pktB(2, 2), pktC(4, 3);
	Wektor WekA(0, 0), WekB(0, 0);
	WekA = Punkt::toWektor(&pktA, &pktB);
	WekB = Punkt::toWektor(&pktA, &pktC);
	bool testA = (WekA.getDX() == 1 && WekA.getDY() == 0);
	double e = 0.01;
	bool testB = ((WekB.getDX() > 0.9865 - e || WekB.getDX() < 0.9865 + e) && (WekA.getDY() > 0.1644 + e || WekA.getDY() < 0.1644 - e));
	if (testA && testB)
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
}

int main()
{

	TestPktDoKwadrat();
	TestWektorDoPkt();
	TestOperatorKwadratow();
	TestOperatorPktWektor();
	TestKwadratDoWektor();
	TestDwaPktDoWektor();
}