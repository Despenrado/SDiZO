#include "UI.h"

using namespace std;

void UI::wyborMetodyGenerowaniaGrafu() {

    while (naPoczatek) {
        cout << "Step I - Generation of graph:" << endl << endl << "1. Random generation" << endl
             << "2. Read from file" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1: {
                grafLosowy();
                wyborFunkcji();
            }
                break;
            case 2: {
                grafZPliku();
                wyborFunkcji();
            }
                break;
        }
    }
}

void UI::wyborFunkcji() {
    while (!naPoczatek) {

        cout << endl << "Step II - analysis of the graph using:" << endl << endl
             << "1. Show graph" << endl
             << "2. Bellman-Ford algorithm" << endl
             << "3. Dijkstra's algorithm" << endl
             << "4. Prim's algorithm" << endl
             << "5. Back to step I" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1: {
                graf->wyswietl();
                cout << endl;
            }
                break;
            case 2: {
                while (true) {
                    cout << "Enter first node: ";
                    cin >> b;
                    if (b < graf->wierzcholki) break;
                    else cout << "Graph dont have this node." << endl;
                }
				while (true) {
					cout << "Enter finish node: ";
					cin >> c;
					if (c < graf->wierzcholki) break;
					else cout << "Graph dont have this node." << endl;
				}

                while (true) {
                    int wyborReprezentacji;
                    cout << "Chose representaishon of graph" << endl << "1. incidence matrix" << endl
                         << "2. incidence list" << endl;
                    cin >> wyborReprezentacji;
                    if (wyborReprezentacji == 1) {
                        graf->macierz_Forda(b, c);
                        break;
                    } else if (wyborReprezentacji == 2) {
                        graf->lista_Forda(b, c);
                        break;
                    }
                }
            }
                break;

            case 3: {
				while (true) {
					cout << "Enter first node: ";
					cin >> b;
					if (b < graf->wierzcholki) break;
					else cout << "Graph dont have this node." << endl;
				}
				while (true) {
					cout << "Enter finish node: ";
					cin >> c;
					if (c < graf->wierzcholki) break;
					else cout << "Graph dont have this node." << endl;
				}

                while (true) {
                    int wyborReprezentacji;
					cout << "Chose representaishon of graph" << endl << "1. incidence matrix" << endl
						<< "2. incidence list" << endl;
                    cin >> wyborReprezentacji;
                    if (wyborReprezentacji == 1) {
                        graf->macierz_Dijkstra(b, c);
                        break;
                    } else if (wyborReprezentacji == 2) {
                        graf->lista_Dijkstra(b, c);
                        break;
                    }
                }
            }
                break;


            case 4: {
                while (true) {
                    int wyborReprezentacji;
					cout << "Chose representaishon of graph" << endl << "1. incidence matrix" << endl
						<< "2. incidence list" << endl;
                    cin >> wyborReprezentacji;
                    if (wyborReprezentacji == 1) {
                        graf->macierz_Prim();
                        break;
                    } else if (wyborReprezentacji == 2) {
                        graf->lista_Prim();
                        break;
                    }
                }

            }
                break;

            case 5: {
                delete graf;
                naPoczatek = true;
            }
                break;
        }
    }
}

void UI::grafLosowy() {
    naPoczatek = false;
    while (true) {
        cout << "Nuber of nodes: ";
        cin >> w;
        if (w > 1) break;
        else cout << "number must be equel or gather than 1." << endl;
    }


    int maxK = w * (w - 1);
    double minG = ceil((((double) w - 1) * 100) / (double) maxK);

    while (true) {

        cout << "Enter density (min " << minG << "%): ";
        cin >> g;
        if (g < minG || g > 100)
            cout << "this density can't crate graph." << endl;
        else
            break;
    }
    double krawedzie = ceil((maxK * g) / 100);
    graf = new Graf(w, krawedzie);
    graf->losujGraf();
}

void UI::grafZPliku() {
    naPoczatek = false;
    ElementListy *e1;
    string s, nazwa;
    int a = 0;
    int krawedzie, wierzcholki;
    cout << "enter file name: ";
    cin >> nazwa;
    //nazwa = nazwa + ".txt";
    ifstream plik(nazwa);
    if (!plik) {
        cout << "file can't open." << endl;
        naPoczatek = true;

    } else {

        {
            plik >> krawedzie >> wierzcholki;
            if (!plik || krawedzie < wierzcholki - 1 || wierzcholki <= 1 ||
                krawedzie > (wierzcholki * (wierzcholki - 1))) {
                cout << "file can't read." << endl;

                naPoczatek = true;
            } else {
                graf = new Graf(wierzcholki, krawedzie);
                while (!plik.eof()) {

                    plik >> graf->K[a].wp >> graf->K[a].wk >> graf->K[a].waga;
                    if (graf->K[a].wp >= wierzcholki || graf->K[a].wk >= wierzcholki ||
                        graf->K[a].waga < 1) {
                        cout << "edges can't read." << endl;
                        naPoczatek = true;
                        break;
                    }

                    if (plik) {
                        a++;
                    } else {
                        cout << "edges can't read." << endl;
                        naPoczatek = true;
                        break;
                    }
                }
                if (a == krawedzie) {
                    for (int i = 0; i < wierzcholki; i++)
                        graf->macierzIncydencji[i] = new int[krawedzie];
                    for (int i = 0; i < wierzcholki; i++)
                        for (int j = 0; j < krawedzie; j++) {
                            graf->macierzIncydencji[i][j] = 0;
                        }

                    for (int i = 0; i < wierzcholki; i++)
                        graf->listySasiedztwa[i] = NULL;

                    for (int i = 0; i < krawedzie; i++) {
                        int wp = graf->K[i].wp;
                        int wk = graf->K[i].wk;
                        e1 = new ElementListy;
                        e1->w = wk;
                        e1->waga = graf->K[i].waga;
                        e1->nastepny = graf->listySasiedztwa[wp];
                        graf->listySasiedztwa[wp] = e1;
                        graf->macierzIncydencji[wp][i] = 1;
                        graf->macierzIncydencji[wk][i] = -1;
                    }
                    plik.close();
                    graf->zamienGrafNaNieskierowany();
                    if (!(graf->sprawdzSpojnosc())) {
                        cout << "error at read" << endl;
                        naPoczatek = true;
                        delete graf;
                    } else {
                        wyborFunkcji();
                    }

                } else if (!naPoczatek) {
                    naPoczatek = true;
                    cout << "error at read" << endl;
                }
            }
        }
    }
}