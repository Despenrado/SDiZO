#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <queue>
#include "Krawedz.h"
#include "ElementListy.h"
#include "Stos.h"
#include "DrzewoSpinajace.h"

class Graf {
public:
    Graf(int w, int m);

    ~Graf();

    Krawedz *K, *KO;
    int **macierzIncydencji, **grafNieskierowanyM;
    ElementListy **listySasiedztwa, **grafNieskierowanyL;
    int wierzcholki, krawedzie, gestosc, krawedzieOdwrotne;
    ElementListy *e1, *e2;
    bool *odwiedzone;

public:

    void macierz_Prim();

    void wyswietl();

    void lista_Prim();

    void macierz_Dijkstra(int start, int end);

    void lista_Dijkstra(int w, int end);

	void lista_Forda(int start, int end);

	void macierz_Forda(int start, int end);

    void lista_DFS(int w);

    void macierz_DFS(int w);

    bool sprawdzSpojnosc();

    void losujGraf();

    void losujKrawedzie();

    void zamienGrafNaNieskierowany();
};

