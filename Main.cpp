#include "mylib.h"


char pas;
int main() {
    srand(static_cast<unsigned>(time(NULL)));
vector<studentas> grupe;
vector<int> pp;
  string vard, pav;
  char skaiciavimo_Strategija;
  char kiekis;
 char pasirinkimas;
int egz, n, k;

     vector<studentas>vStud;

    cout << "Kaip skaiciuoti galutini? V/m: ";
    cin >> skaiciavimo_Strategija;

    cout << "Pasirinkite ivedimo buda rankinis (h) / nuskaitant is failo (f): ";
     cin >> pas;



     if (pas == 'H' || pas == 'h') {
         cout << "Iveskite studentu skaiciu: ";
         int studentuSkaicius;
         cin >> studentuSkaicius;

         for (int i = 0; i < studentuSkaicius; i++) {
  

             cout << "Ivesk studenta " << i + 1 << " varda: ";
             cin >> vard;

             cout << "Ivesk studenta " << i + 1 << " pavarde: ";
             cin >> pav;



             cout << "Ar pazymiu kiekis zinomas (taip/ne)? t/n ";
             cin >> kiekis;
             if (kiekis == 't') {

                 cout << "Kaip ivesti pazymius ivedant/random? (i/r): ";
                 cin >> pasirinkimas;


                 if (pasirinkimas == 'i') {
                     cout << "Kiek pazymiu buvo semestre? ";
                     cin >> n;
                     for (int i = 0; i < n; i++) {
                         cin >> k;
                         pp.push_back(k);
                     }
                     cin >> egz;


                 }
                 else if (pasirinkimas == 'r') {
                     cout << "Kiek pazymiu buvo semestre? ";
                     cin >> n;
                     pp.clear();
                     for (int i = 0; i < n; i++) {
                         k = rand() % 10 + 1;
                         pp.push_back(k);
                     }
                     egz = rand() % 10 + 1;
                 }

             }


             else if (kiekis == 'n') {
                 
                 cout << "Kaip ivesti pazymius ivedant/random? (i/r): ";
                 cin >> pasirinkimas;
                 if (pasirinkimas == 'i')
                 {
                     cout << "Norint nustot sustabdyti pazymiu ivedima parasykite skaiciu su - " << endl;
                     while (true) {
                         cout << "Ivesk pazymi: ";
                         cin >> k;
                         if (k < 0) {
                             break;
                         }
                         cin >> k; pp.push_back(k);
                     }

                     cout << "Ivesk egzamino pazymi: ";
                     cin >> egz;
                 }
                 else if (pasirinkimas == 'r') {
                     n = rand() % 10 + 1;
                     for (int i = 0; i < n; i++) {
                         k = rand() % 10 + 1;
                         pp.push_back(k);
                     }
                     egz = rand() % 10 + 1;
                 }

             }
             studentas *K =new studentas(vard, pav, pp, egz);
             if (skaiciavimo_Strategija == 'v') {
                 K->rezVid();
             }
             else if (skaiciavimo_Strategija == 'm') {
                 K->rezMed();
             }
             grupe.push_back(*K);
             delete K;
         }

     }

    else if (pas == 'F' || pas == 'f') {

        ifstream failas("kursiokai.txt");

        if (!failas.is_open()) {
            cout << "Klaida: Nepavyko atidaryti failo! " << endl;
        }
        string header;
        getline(failas, header);
        string vardas, pavarde;
        vector<int> pazymiai;
        int egzaminas;

        // Nuskaito virsu ir ji atspausdina


        while (failas >> vardas >> pavarde) {
            pazymiai.clear(); // isvalo po kiekvienos eilutes

            // Nuskaityti pazymius
            for (int i = 0; i < 15; i++) {
                int pazymys;
                failas >> pazymys;
                pazymiai.push_back(pazymys);
            }

            // Nuskaito egzamino paz
            failas >> egzaminas;
//nuskaito duomenys
            studentas student(vardas, pavarde, pazymiai, egzaminas);


            grupe.push_back(student);
        }

        failas.close();
    }

    cout << endl << grupe.size() << endl;
    printf("%-10s|%20s", "Vardas", "Pavarde");
    for (int i = 0; i < grupe[0].getPazNr(); i++)
        printf("%s%d", " ND", i + 1);
    printf("%10s|\n", "Egzaminas");
    for (auto& a : grupe) a.printas();
    cout << endl;

    std::sort(grupe.begin(), grupe.end());
    printf("|%-10s|%20s|", "Vardas", "Pavarde" );
    printf("%10s|\n", skaiciavimo_Strategija == 'm' ? " |Galutinis (m)" : " |Galutinis(v)");

    for (auto& a : grupe) a.printasRez();
    system("pause");
}