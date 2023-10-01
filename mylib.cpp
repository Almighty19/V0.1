#include "mylib.h"

studentas::studentas() {
    // kolkas dar pasirinkti ivedimo budo negalima
    /* cout << "Pasirinkite įvedimo būdą rankinis (h) / nuskaitant iš failo (f)";
     char pas; cin >> pas;
     if (pas == 'H' || pas == 'h') {*/
    cout << "Ivesk varda: "; cin >> vard;
    cout << "Ivesk pavarde: "; cin >> pav;
    cout << "Kiek pazymiu buvo semestre? ";
    int n; cin >> n;

    cout << "Kaip ivesti pazymius ivedant/random? (i/r): ";
    char pasirinkimas; cin >> pasirinkimas;

    srand(static_cast<unsigned>(time(0)));

    if (pasirinkimas == 'i') {
        for (int i = 0; i < n; i++) {
            int k;
            cout << "Ivesk " << i + 1 << " semestro pazymi: ";
            cin >> k; paz.push_back(k);
        }
        cout << "Ivesk egzamino pazymi: "; cin >> egz;
    }
    else if (pasirinkimas == 'r') {
        for (int i = 0; i < n; i++) {
            int k = rand() % 10 + 1;
            paz.push_back(k);
        }
        egz = rand() % 10 + 1;
    }
    else {
        throw std::domain_error("Neteisingas pasirinkimas: ");
    }
    // Kolkas dar neveikia duomenu failo nuskaitymas atsiranda kazkokios klaidos pasidubliavimo ir glitchas su <studentas> grupe
    //  }
     /* else if (pas == 'f' || pas == 'F') {

         ifstream failas("kursiokai.txt");

          if (failas.is_open()) {
              int n;
              failas >> n;
              grupe.reserve(n);

              for (int i = 0; i < n; i++) {
                  string vardas, pavarde;
                  int pazymiuSk;
                  vector<int> pazymiai;

                  while (failas >> vardas >> pavarde >> pazymiuSk) {
                      pazymiai.clear(); // Išvalome senus pažymius
                      for (int i = 0; i < pazymiuSk; i++) {
                          int pazymys;
                          failas >> pazymys;
                          pazymiai.push_back(pazymys);
                      }
                      int egzaminas;
                      failas >> egzaminas;

                      studentas naujasStudentas(vardas, pavarde, pazymiai, egzaminas);
                      grupe.push_back(naujasStudentas);
                  }
                  failas.close();
              }
          else {
              cout << "Klaida atidarant faila!" << endl;
          }
          */

    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}
        studentas::studentas(string v, string p, vector<int> pp, int e)
{
    vard = v; pav = p; paz = pp; egz = e;
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}

studentas::studentas(const studentas& temp)
{
    vard = temp.vard; pav = temp.pav;
    paz = temp.paz; egz = temp.egz;
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}

studentas& studentas::operator=(const studentas& temp)
{
    if (this == &temp) return *this;
    vard = temp.vard; pav = temp.pav;
    paz = temp.paz; egz = temp.egz;
    skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
    return *this;
}

studentas::~studentas()
{
    vard.clear(); pav.clear(); paz.clear();
    egz = 0; rez = 0;
}

void studentas::printas()
{
    printf("%-10s|%20s", vard.c_str(), pav.c_str());
    for (auto& a : paz)printf("%3d|", a);
    printf("%10d|\n", egz);
}
void studentas::printasRez()
{
    printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
    printf("%.2f|\n", rez);
}
void studentas::rezVid() {
    float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
    rez = sum / paz.size() * 0.4 + egz * 0.6;
}
void studentas::rezMed()
{
    rez = mediana(paz) * 0.4 * egz * 0.6;
}
double studentas::mediana(vector<int>vec) {
    typedef vector<double>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2.0 : vec[vid] / 1.0;
}
/*double galBalas(double egzaminas, const vector<double>& nd,
    double(*kriterijus)(vector<double >)= studentas::mediana) {
    if (nd.size() == 0)// patikriname ar atliko bent viena
        throw std::domain_error("studentas neatliko ne vieno");
        return galBalas(egzaminas, kriterijus(nd));//overloading
}
*/