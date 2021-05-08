#include <iostream>
#include <ctime>
#include "UI.h"

using namespace std;

int main() {
    srand(time(NULL));
	cout << "=======================================================================================================================" << endl
		<< "===                                                                                                                 ===" << endl
		<< "===                                                     Projrct SDiZO 2                                             ===" << endl
		<< "===                                                    Nikita Stepanenko                                            ===" << endl
		<< "===                                                                                                                 ===" << endl
		<< "=======================================================================================================================" << endl << endl << endl;
    UI ui;
    ui.wyborMetodyGenerowaniaGrafu();
}