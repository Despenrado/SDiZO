#include "Graf.h"
#include "Czas.h"


using namespace std;

Graf::Graf(int w, int m) {
    krawedzie = m;
    wierzcholki = w;
    macierzIncydencji = new int *[wierzcholki];
    grafNieskierowanyM = new int *[wierzcholki];
    listySasiedztwa = new ElementListy *[wierzcholki];
    grafNieskierowanyL = new ElementListy *[wierzcholki];
    K = new Krawedz[krawedzie];
    KO = new Krawedz[krawedzie];
    krawedzieOdwrotne = 0;
}

Graf::~Graf() {
    int i;
    for (int i = 0; i < wierzcholki; i++) {
        e1 = listySasiedztwa[i];
        while (e1) {
            e2 = e1;
            e1 = e1->nastepny;
            delete e2;
        }
    }
    delete[] listySasiedztwa;


    for (i = 0; i < wierzcholki; i++) delete[] macierzIncydencji[i];
    delete[] macierzIncydencji;


}

void Graf::zamienGrafNaNieskierowany() {
    int i, j;
    for (i = 0; i < wierzcholki; i++)
        grafNieskierowanyM[i] = new int[krawedzie];
    for (i = 0; i < wierzcholki; i++)
        for (j = 0; j < krawedzie; j++) {
            grafNieskierowanyM[i][j] = 0;
        }

    for (i = 0; i < wierzcholki; i++)
        grafNieskierowanyL[i] = NULL;

    for (i = 0; i < krawedzie; i++) {
        j = 0;
        while (j < krawedzieOdwrotne) {

            if (KO[j].wp == K[i].wp && KO[j].wk == K[i].wk) {
                break;
            } else j++;
        }
        if (j == krawedzieOdwrotne) {
            KO[krawedzieOdwrotne].wp = K[i].wk;
            KO[krawedzieOdwrotne].wk = K[i].wp;
            KO[krawedzieOdwrotne].waga = K[i].waga;
            krawedzieOdwrotne++;
        }
    }

    int wp, wk, waga;
    for (int i = 0; i < krawedzieOdwrotne; i++) {
        wp = KO[i].wp;
        wk = KO[i].wk;
        waga = KO[i].waga;
        e1 = new ElementListy;
        e1->w = wk;
        e1->waga = waga;
        e1->nastepny = grafNieskierowanyL[wp];
        grafNieskierowanyL[wp] = e1;
        e2 = new ElementListy;
        wp = KO[i].wk;
        wk = KO[i].wp;
        waga = KO[i].waga;
        e2->w = wk;
        e2->waga = waga;
        e2->nastepny = grafNieskierowanyL[wp];
        grafNieskierowanyL[wp] = e2;

        grafNieskierowanyM[KO[i].wp][i] = 1;
        grafNieskierowanyM[KO[i].wk][i] = 1;
    }

}

void Graf::losujKrawedzie() {
    int c = 0;
    int *T;
    int b, doDodania1, doDodania2, a, i, j;
    int liczStopien = 0;
    int *wDrzewie;
    int *nieWDrzewie;
    a = wierzcholki;
    nieWDrzewie = new int[a];
    for (i = 0; i < a; i++) {
        nieWDrzewie[i] = i;
    }
    wDrzewie = new int[a];
    b = rand() % a;
    doDodania1 = nieWDrzewie[b];
    nieWDrzewie[b] = nieWDrzewie[a - 1];
    a--;
    wDrzewie[c] = doDodania1;
    c++;

    for (i = 0; i < (wierzcholki - 1); i++) {
        b = rand() % c;
        doDodania1 = wDrzewie[b];

        b = rand() % a;
        doDodania2 = nieWDrzewie[b];
        nieWDrzewie[b] = nieWDrzewie[a - 1];
        a--;
        wDrzewie[c] = doDodania2;
        c++;
        K[i].wp = doDodania1;
        K[i].wk = doDodania2;
    }
    for (i = 0; i < (wierzcholki - 1); i++) {

        b = rand() % wierzcholki;
        swap(K[b].wk, K[b].wp);

    }

    for (i = wierzcholki - 1; i < krawedzie; i++) {
        a = wierzcholki;
        T = new int[a];
        for (int k = 0; k < a; k++) {
            T[k] = k;
        }

        b = rand() % a;
        doDodania1 = T[b];
        T[b] = T[a - 1];
        a--;
        while (true) {

            liczStopien = 0;
            for (j = 0; j < i; j++) {
                if (K[j].wp == doDodania1)
                    liczStopien++;
                if (liczStopien == wierzcholki - 1) break;
            }

            if (liczStopien == wierzcholki - 1) {
                b = rand() % a;
                doDodania1 = T[b];
                T[b] = T[a - 1];
                a--;
            } else break;
        }

        a = wierzcholki;
        for (int k = 0; k < a; k++) {
            T[k] = k;
        }

        T[doDodania1] = T[a - 1];
        a--;

        b = rand() % a;
        doDodania2 = T[b];
        T[b] = T[a - 1];
        a--;

        for (j = 0; j < i; j++) {
            while (doDodania1 == K[j].wp && doDodania2 == K[j].wk) {
                b = rand() % a;
                doDodania2 = T[b];
                T[b] = T[a - 1];
                a--;
                j = 0;
            }
        }
        K[i].wp = doDodania1;
        K[i].wk = doDodania2;
        delete[]T;
    }

    for (i = 0; i < krawedzie; i++)
        K[i].waga = (rand() % 9) + 1;

    delete[] nieWDrzewie;
    delete[] wDrzewie;
}

void Graf::losujGraf() {
    int i, j;
    for (i = 0; i < wierzcholki; i++)
        macierzIncydencji[i] = new int[krawedzie];
    for (i = 0; i < wierzcholki; i++)
        for (j = 0; j < krawedzie; j++) {
            macierzIncydencji[i][j] = 0;
        }

    for (i = 0; i < wierzcholki; i++)
        listySasiedztwa[i] = NULL;

    losujKrawedzie();
    zamienGrafNaNieskierowany();
    for (i = 0; i < krawedzie; i++) {
        int wp = K[i].wp;
        int wk = K[i].wk;
        int waga = K[i].waga;
        e1 = new ElementListy;
        e1->w = wk;
        e1->waga = waga;
        e1->nastepny = listySasiedztwa[wp];
        listySasiedztwa[wp] = e1;

        macierzIncydencji[wp][i] = 1;
        macierzIncydencji[wk][i] = -1;
    }

}

bool Graf::sprawdzSpojnosc() {
    Stos stos;
    int w, u, i;
    int licz = 0;

    odwiedzone = new bool[wierzcholki];
    for (i = 0; i < wierzcholki; i++) {
        odwiedzone[i] = false;
    }

    stos.push(0);
    odwiedzone[0] = true;

    while (!stos.empty()) {
        w = stos.top();
        stos.pop();
        licz++;
        for (e1 = grafNieskierowanyL[w]; e1; e1 = e1->nastepny) {
            u = e1->w;
            if (!odwiedzone[u]) {
                odwiedzone[u] = true;
                stos.push(u);
            }
        }
    }
    delete[]odwiedzone;
    if (licz == wierzcholki)
        return true;

    else return false;
}

void Graf::macierz_DFS(int w) {
    int i, j;
    Czas czas;
    Stos stos;
    odwiedzone = new bool[wierzcholki];
    for (i = 0; i < wierzcholki; i++) {
        odwiedzone[i] = false;
    }
    cout << "Graph non-directional:" << endl;

    cout << "      ";
    for (i = 0; i < krawedzieOdwrotne; i++) {
        cout << setw(3) << i;

    }
    cout << endl << "      ";
    for (i = 0; i < krawedzieOdwrotne; i++) {
        cout << setw(3) << "-";

    }

    cout << endl;
    for (i = 0; i < wierzcholki; i++) {
        cout << setw(3) << i << " | ";
        for (int j = 0; j < krawedzieOdwrotne; j++)
            cout << setw(3) << grafNieskierowanyM[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "Weight:";
    for (i = 0; i < krawedzieOdwrotne; i++) {
        cout << setw(3) << KO[i].waga;
    }
    cout << endl << endl;
    cout << "Visited nodes:" << endl;
    czas.czasStart();
    stos.push(w);
    while (!stos.empty()) {

        w = stos.top();
        stos.pop();

        if (!odwiedzone[w]) {
            odwiedzone[w] = true;
            for (i = krawedzie - 1; i >= 0; i--) {
                if (grafNieskierowanyM[w][i] != 0)
                    for (j = 0; j < wierzcholki; j++)
                        if (j != w && grafNieskierowanyM[j][i] != 0) {
                            if (!odwiedzone[j]) {
                                stos.push(j);
                            }
                        }

            }
            cout << w << ", ";
        }
    }
    cout << endl << endl;

    czas.czasStop();
    cout << endl << "Time: " << czas.czasWykonania() << endl;
    delete[]odwiedzone;
    stos.~Stos();
}

void Graf::lista_DFS(int w) {
    Czas czas;
    Stos stos;
    int u, i;

    odwiedzone = new bool[wierzcholki];
    for (i = 0; i < wierzcholki; i++) {
        odwiedzone[i] = false;
    }
    cout << endl << "Graph non-directional: " << endl;
    for (i = 0; i < wierzcholki; i++) {
        cout << "[" << i << "] =";
        e1 = grafNieskierowanyL[i];
        while (e1) {
            cout << setw(3) << e1->w << "(" << e1->waga << ") ";
            e1 = e1->nastepny;
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "Visited peaks:" << endl << endl;
    czas.czasStart();
    stos.push(w);

    while (!stos.empty()) {
        w = stos.top();
        stos.pop();

        if (!odwiedzone[w]) {
            odwiedzone[w] = true;
            for (e1 = grafNieskierowanyL[w]; e1; e1 = e1->nastepny) {
                u = e1->w;
                if (!odwiedzone[u]) {
                    stos.push(u);
                }
            }
            cout << w << ", ";
        }

    }
    czas.czasStop();
    cout << endl << "Time: " << czas.czasWykonania() << endl;
    delete[]odwiedzone;
    stos.~Stos();
}

void Graf::macierz_Dijkstra(int start, int end) {
	Czas czas;
	int* drogaWagi = new int[wierzcholki];
	int* nieOdwiedzone = new int[wierzcholki];
	int minindex, min, tmp;
	for (int i = 0; i < wierzcholki; i++)
	{
		drogaWagi[i] = INT_MAX;
		nieOdwiedzone[i] = 1;
	}
	drogaWagi[start] = 0;

	czas.czasStart();
	do
	{
		minindex = INT_MAX;
		min = INT_MAX;
		for (int i = 0; i < wierzcholki; i++)
		{
			if (nieOdwiedzone[i] == 1 && drogaWagi[i] < min)
			{
				min = drogaWagi[i];
				minindex = i;
			}
		}
		if (minindex != INT_MAX)
		{
			for (int i = 0; i < krawedzie; i++)
			{
				if (macierzIncydencji[minindex][i] == 1)
				{
					tmp = min + K[i].waga;
					if (tmp < drogaWagi[K[i].wk])
					{
						drogaWagi[K[i].wk] = tmp;
					}
				}
	
		}
			if (minindex < wierzcholki)  
			{
				nieOdwiedzone[minindex] = 0;
			}
		}
	} while (minindex < INT_MAX);

	int* drogaWierzcholki = new int[wierzcholki];
	int koniec = end;
	drogaWierzcholki[0] = end;
	int indexPrev = 1;
	int wagaDrogi = drogaWagi[end];
	cout << "Smallest way from " << start << " to " << end << ":" << endl;
	if (drogaWagi[end] == INT_MAX)
	{
		cout << "NO way" << endl;
	}
	else
	{
		while (koniec != start)
		{
			for (int i = 0; i < krawedzie; i++)
			{
				if(macierzIncydencji[koniec][i] == -1)
				{
					int tmp = wagaDrogi - K[i].waga;
					if (tmp == drogaWagi[K[i].wp])
					{
						wagaDrogi = tmp;
						koniec = K[i].wp;
						drogaWierzcholki[indexPrev] = K[i].wp;
						indexPrev++;
					}
				}
			}
		}
		for (int i = indexPrev - 1; i >= 0; i--)
		{
			cout << drogaWierzcholki[i] << " ";
		}
		cout << setw(5) << "(" << drogaWagi[end] << ")";
	}
	
	czas.czasStop();
	cout << endl << endl << "Time: " << czas.czasWykonania() << endl;
	cout << endl;
	cout << endl;

}

void Graf::lista_Dijkstra(int w, int end) {
    int korzen, wezel, rozmiarKopca, ojciec, lewySyn, prawySyn, kosztMin, synMin, syn, *koszta, *poprzednicy, *kopiec, *pozycjaKopiec;
    Czas czas;
    Stos stos;
    int szerokosc, i, j;
    koszta = new int[wierzcholki];
    poprzednicy = new int[wierzcholki];
    odwiedzone = new bool[wierzcholki];
    kopiec = new int[wierzcholki];
    pozycjaKopiec = new int[wierzcholki];

    for (i = 0; i < wierzcholki; i++) {
        koszta[i] = INT_MAX;
        poprzednicy[i] = -1;
        odwiedzone[i] = false;
        kopiec[i] = pozycjaKopiec[i] = i;
    }
    czas.czasStart();
    rozmiarKopca = wierzcholki;

    koszta[w] = 0;
    wezel = kopiec[0];
    kopiec[0] = kopiec[w];
    kopiec[w] = wezel;
    pozycjaKopiec[w] = 0;
    pozycjaKopiec[0] = w;

    for (i = 0; i < wierzcholki; i++) {
        korzen = kopiec[0];

        kopiec[0] = kopiec[--rozmiarKopca];
        pozycjaKopiec[kopiec[0]] = ojciec = 0;
        while (true) {
            lewySyn = ojciec + ojciec + 1;
            prawySyn = lewySyn + 1;
            if (lewySyn >= rozmiarKopca) break;
            kosztMin = koszta[kopiec[lewySyn]];
            synMin = lewySyn;
            if ((prawySyn < rozmiarKopca) && (kosztMin > koszta[kopiec[prawySyn]])) {
                kosztMin = koszta[kopiec[prawySyn]];
                synMin = prawySyn;
            }
            if (koszta[kopiec[ojciec]] <= kosztMin)
                break;
            wezel = kopiec[ojciec];
            kopiec[ojciec] = kopiec[synMin];
            kopiec[synMin] = wezel;
            pozycjaKopiec[kopiec[ojciec]] = ojciec;
            pozycjaKopiec[kopiec[synMin]] = synMin;
            ojciec = synMin;
        }

        odwiedzone[korzen] = true;

        if (listySasiedztwa[korzen] != NULL)
            for (e1 = listySasiedztwa[korzen]; e1; e1 = e1->nastepny)
                if (!odwiedzone[e1->w] && (koszta[e1->w] > koszta[korzen] + e1->waga)) {
                    koszta[e1->w] = koszta[korzen] + e1->waga;
                    poprzednicy[e1->w] = korzen;

                    for (syn = pozycjaKopiec[e1->w]; syn; syn = ojciec) {
                        ojciec = syn / 2;
                        if (koszta[kopiec[ojciec]] <= koszta[kopiec[syn]])
                            break;
                        wezel = kopiec[ojciec];
                        kopiec[ojciec] = kopiec[syn];
                        kopiec[syn] = wezel;
                        pozycjaKopiec[kopiec[ojciec]] = ojciec;
                        pozycjaKopiec[kopiec[syn]] = syn;
                    }
                }
		if (e1 != NULL && e1->w == end) break;
    }
    

    cout << "Smallest way from  " << w << " to " << end << ":"<< endl;
    for (i = end; i < end+1; i++) {
        szerokosc = -2;



        if (koszta[i] == INT_MAX || koszta[i] < 0)
            cout << "NO ay" << endl;
        else {
            for (j = i; j > -1; j = poprzednicy[j]) {
                stos.push(j);
                szerokosc = szerokosc + 2;
            }

            while (!stos.empty()) {
                cout << stos.top() << " ";
                stos.pop();
            }
            //for (j = 0; j < wierzcholki - szerokosc; j++)
              //  cout << " ";
            cout << "	(" << koszta[i] << ")" << endl;
        }
		
    }
	czas.czasStop();
	cout << endl << "Time: " << czas.czasWykonania() << endl;
	cout << endl;
    cout << endl << endl;
}

void Graf::lista_Forda(int start, int end)
{
	Czas czas;
	bool zmiana = true;
	int* drogaWagi = new int[wierzcholki];
	int minindex, min, tmp;
	for (int i = 0; i < wierzcholki; i++)
	{
		drogaWagi[i] = INT_MAX;
	}
	drogaWagi[start] = 0;

	czas.czasStart();
	ElementListy* el;
	while (zmiana)
	{
		zmiana = false;
		for (int i = 0; i < wierzcholki; i++)
		{
			el = listySasiedztwa[i];
			while(el)
			{
					if (drogaWagi[i] < INT_MAX && drogaWagi[el->w] > drogaWagi[i] + el->waga)
					{
						drogaWagi[el->w] = drogaWagi[i] + el->waga;
						zmiana = true;
					}
					el = el->nastepny;
			}
		}
	}
	int* drogaWierzcholki = new int[wierzcholki];
	int koniec = end;
	drogaWierzcholki[0] = end;
	int indexPrev = 1;
	int wagaDrogi = drogaWagi[end];
	cout << "Smallest way from  " << start << " to " << end << ":" << endl;
	if (drogaWagi[end] == INT_MAX)
	{
		cout << "NO way" << endl;
	}
	else
	{
		while (koniec != start)
		{
			for (int i = 0; i < krawedzie; i++)
			{
				if (macierzIncydencji[koniec][i] == -1)
				{
					int tmp = wagaDrogi - K[i].waga;
					if (tmp == drogaWagi[K[i].wp])
					{
						wagaDrogi = tmp;
						koniec = K[i].wp;
						drogaWierzcholki[indexPrev] = K[i].wp;
						indexPrev++;
					}
				}
			}
		}
		for (int i = indexPrev - 1; i >= 0; i--)
		{
			cout << drogaWierzcholki[i] << " ";
		}
		cout << setw(5) << "(" << drogaWagi[end] << ")";
	}
	czas.czasStop();
	cout << endl << endl << "Time: " << czas.czasWykonania() << endl;
	cout << endl << endl;
}

void Graf::macierz_Forda(int start, int end)
{
	Czas czas;
	bool zmiana = true;
	int* drogaWagi = new int[wierzcholki];
	int minindex, min, tmp;
	for (int i = 0; i < wierzcholki; i++)
	{
		drogaWagi[i] = INT_MAX;
	}
	drogaWagi[start] = 0;

	czas.czasStart();
	while (zmiana)
	{
		zmiana = false;
		for (int i = 0; i < krawedzie; i++)
		{
			for (int j = 0; j < wierzcholki; j++)
			{
				if (macierzIncydencji[j][i] == 1)
				{
					if (drogaWagi[K[i].wp] < INT_MAX && drogaWagi[K[i].wk] > drogaWagi[K[i].wp] + K[i].waga)
					{
						drogaWagi[K[i].wk] = drogaWagi[K[i].wp] + K[i].waga;
						zmiana = true;
					}
					break;
				}
			}
		}
	}
	int* drogaWierzcholki = new int[wierzcholki];
	int koniec = end;
	drogaWierzcholki[0] = end;
	int indexPrev = 1;
	int wagaDrogi = drogaWagi[end];
	cout << "Smallest way from  " << start << " to " << end << ":" << endl;
	if (drogaWagi[end] == INT_MAX)
	{
		cout << "NO way" << endl;
	}
	else
	{
		while (koniec != start)
		{
			for (int i = 0; i < krawedzie; i++)
			{
				if (macierzIncydencji[koniec][i] == -1)
				{
					int tmp = wagaDrogi - K[i].waga;
					if (tmp == drogaWagi[K[i].wp])
					{
						wagaDrogi = tmp;
						koniec = K[i].wp;
						drogaWierzcholki[indexPrev] = K[i].wp;
						indexPrev++;
					}
				}
			}
		}
		for (int i = indexPrev - 1; i >= 0; i--)
		{
			cout << drogaWierzcholki[i] << " ";
		}
		cout << setw(5) << "(" << drogaWagi[end] << ")";
	}
	czas.czasStop();
	cout << endl << "Time: " << czas.czasWykonania() << endl;
	cout << endl << endl;
}

void Graf::macierz_Prim() {

    int w, i, j, g;
    Czas czas;
    Krawedz krawedz;
    priority_queue<Krawedz, vector<Krawedz>, Krawedz> kolejka;
    DrzewoSpinajace *drzewo = new DrzewoSpinajace(wierzcholki, krawedzie);
    odwiedzone = new bool[wierzcholki];
    for (i = 0; i < wierzcholki; i++) {
        odwiedzone[i] = false;
    }

    cout << "Graph non-directional:" << endl;

    cout << "      ";
    for (i = 0; i < krawedzieOdwrotne; i++) {
        cout << setw(3) << i;

    }
    cout << endl << "      ";
    for (i = 0; i < krawedzieOdwrotne; i++) {
        cout << setw(3) << "-";

    }

    cout << endl;
    for (i = 0; i < wierzcholki; i++) {
        cout << setw(3) << i << " | ";
        for (int j = 0; j < krawedzieOdwrotne; j++)
            cout << setw(3) << grafNieskierowanyM[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "Weight:";
    for (i = 0; i < krawedzieOdwrotne; i++) {
        cout << setw(3) << KO[i].waga;
    }
    cout << endl << endl;
    czas.czasStart();

    w = 0;
    odwiedzone[w] = true;
    for (i = 1; i < wierzcholki; i++) {
        for (g = 0; g < krawedzieOdwrotne; g++) {

            if (grafNieskierowanyM[w][g] != 0)
                for (j = 0; j < wierzcholki; j++)
                    if (j != w && grafNieskierowanyM[j][g] != 0 && !odwiedzone[j]) {
                        krawedz.wp = w;
                        krawedz.wk = j;
                        krawedz.waga = KO[g].waga;
                        kolejka.push(krawedz);

                    }
        }
        do {
            krawedz = kolejka.top();
            kolejka.pop();

        } while (odwiedzone[krawedz.wk]);

        drzewo->dodajKrawedz(krawedz);
        odwiedzone[krawedz.wk] = true;
        w = krawedz.wk;

    }
    czas.czasStop();
    cout << endl << "Time: " << czas.czasWykonania() << endl;
    cout << "Minimum spanning tree:";
    drzewo->wyswietl();
    delete drzewo;
}

void Graf::lista_Prim() {
    int w, i;
    Czas czas;
    Krawedz k;
    priority_queue<Krawedz, vector<Krawedz>, Krawedz> kolejka;
    DrzewoSpinajace *drzewo = new DrzewoSpinajace(wierzcholki, krawedzie);
    odwiedzone = new bool[wierzcholki];
    for (i = 0; i < wierzcholki; i++) {
        odwiedzone[i] = false;
    }
    cout << endl << "Graph non-directional: " << endl << endl;
    for (i = 0; i < wierzcholki; i++) {
        cout << "[" << i << "] =";
        e1 = grafNieskierowanyL[i];
        while (e1) {
            cout << setw(3) << e1->w << "(" << e1->waga << ") ";
            e1 = e1->nastepny;
        }
        cout << endl;
    }
    cout << endl;
    czas.czasStart();
    w = 0;
    odwiedzone[w] = true;

    for (i = 1; i < wierzcholki; i++) {

        for (e1 = grafNieskierowanyL[w]; e1; e1 = e1->nastepny) {
            if (!odwiedzone[e1->w]) {
                k.wp = w;
                k.wk = e1->w;
                k.waga = e1->waga;
                kolejka.push(k);
            }
        }
        do {
            k = kolejka.top();
            kolejka.pop();

        } while (odwiedzone[k.wk]);

        drzewo->dodajKrawedz(k);
        odwiedzone[k.wk] = true;
        w = k.wk;

    }

    czas.czasStop();
    cout << endl << "Time: " << czas.czasWykonania() << endl;
    cout << endl;
    cout << "Minimum spanning tree:";
    drzewo->wyswietl();
    delete drzewo;
}

void Graf::wyswietl() {
    cout << "incidence matrix:" << endl;
    int i;
    cout << "      ";
    for (i = 0; i < krawedzie; i++) {
        cout << setw(3) << i;

    }

    cout << endl << "      ";
    for (i = 0; i < krawedzie; i++) {
        cout << setw(3) << "-";

    }

    cout << endl;
    for (i = 0; i < wierzcholki; i++) {
        cout << setw(3) << i << " | ";
        for (int j = 0; j < krawedzie; j++)
            cout << setw(3) << macierzIncydencji[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "Weight:";
    for (i = 0; i < krawedzie; i++) {
        cout << setw(3) << K[i].waga;
    }

	cout << endl << endl << "incidence list:" << endl;
    for (i = 0; i < wierzcholki; i++) {
        cout << "[" << i << "] =";
        e1 = listySasiedztwa[i];
        while (e1) {
            cout << setw(3) << e1->w << "(" << e1->waga << ") ";
            e1 = e1->nastepny;
        }
        cout << endl;
    }
}