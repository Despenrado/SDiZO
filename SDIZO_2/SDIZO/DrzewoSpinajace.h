#pragma once
#include "Krawedz.h"
#include "ElementListy.h"
#include <iostream>
#include <cstdio>

class DrzewoSpinajace {
private:

    ElementListy **T;

    Krawedz *kk;

    int rozmiarT;

    int waga, krawedzie;

    int a;

public:

    DrzewoSpinajace(int wierzcholki, int kr);

    ~DrzewoSpinajace();

    void dodajKrawedz(Krawedz k);

    void wyswietl();
};



