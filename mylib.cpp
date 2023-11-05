#pragma once
#include"mylib.h"

studentas::studentas() {

    }
   std::istream& operator>>(std::istream& in, studentas& a) {
       // 'in' vietoj 'cin' 
       /*
       char kiekis;
       char pasirinkimas;
       int egz;
       int n;
       int k;

       cout << "Ar pazymiu kiekis zinomas (taip/ne)? t/n ";
       in >> kiekis;
       if (kiekis == 't') {

cout << "Kaip ivesti pazymius ivedant/random? (i/r): ";
in >> pasirinkimas;


           if (pasirinkimas == 'i') {
               cout << "Kiek pazymiu buvo semestre? ";
               in >> n;
               for (int i = 0; i < n; i++) {
                   in >> k;
                   a.paz.push_back(k);
               }
               in >> a.egz;


           }
           else if (pasirinkimas == 'r') {
cout << "Kiek pazymiu buvo semestre? ";
in >> n;
a.paz.clear();
               srand(static_cast<unsigned>(time(0)));
               for (int i = 0; i < n; i++) {
                    k = rand() % 10 + 1;
                   in >> k; a.paz.push_back(k);
               }
               egz = rand() % 10 + 1;
           }

       }

   
   else if (kiekis == 'n') {
       srand(static_cast<unsigned>(time(0)));
       cout << "Kaip ivesti pazymius ivedant/random? (i/r): ";
       in >> pasirinkimas;

       if (pasirinkimas == 'i')
       {
           cout << "Norint nustot sustabdyti pazymiu ivedima parasykite skaiciu su - " << endl;
           while (true) {
               cout << "Ivesk pazymi: ";
               in >> k;
               if (k < 0) {
                   break;
               }
               in >> k; a.paz.push_back(k);
           }
           
           cout << "Ivesk egzamino pazymi: ";
           in >> egz;
       }
       else if (pasirinkimas == 'r') {
           n = rand() % 10 + 1;
           for (int i = 0; i < n; i++) {
                k = rand() % 10 + 1;
               in >> k; a.paz.push_back(k);
           }
           egz = rand() % 10 + 1;
       }

   }
       skaiciavimo_Strategija == 'm' ? a.rezMed() : a.rezVid();*/
      return in;
   }

   std::ostream& operator<<(std::ostream& out, const studentas& a) {
    //'out' vietoj 'cout'
      /* out << a.vard << "; " << a.pav << "; ";
       for (auto& i : a.paz) {
           out << i << " : ";
       }
       out << a.egz << std::endl;*/
       return out;
   }

    studentas::studentas(string v, string p, vector<int> pp, int e): vard(v), pav(p), paz(pp), egz(e)
    {
        /*
        vard = v; pav = p; paz = pp; egz = e;
        skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
*/
    }

    studentas::studentas(const studentas & temp)
    {
        vard = temp.vard; pav = temp.pav;
        paz = temp.paz; egz = temp.egz;
        skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
    }

    studentas& studentas::operator=(const studentas & temp)
    {
        if (this == &temp) return *this;
        vard = temp.vard; pav = temp.pav;
        paz = temp.paz; egz = temp.egz;
        skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
        return *this;
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
        printf(" |%.2f        |", rez);
        printf("|%-10s      |\n", getPravarde().c_str());
    }
    void studentas::rezVid() {
        float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
        rez = sum / paz.size() * 0.4 + egz * 0.6;
    }

    void studentas::rezMed() {
        rez = mediana(paz) * 0.4 + egz * 0.6;
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
   studentas::~studentas()
    {
        vard.clear(); pav.clear(); paz.clear();
        egz = 0; rez = 0;
    }
   string studentas::getPravarde() {
           vector<string> teig = { "kietiakiai", "galvociai" };
           vector<string> neig = { " vargsiukai", "nuskriaustukai" };

           if (rez >= 5.0f) {
               pravarde = teig[rand() % teig.size()];
           }
           else {
               pravarde = neig[rand() % neig.size()];
       }
       return pravarde;
   }
    /*double galBalas(double egzaminas, const vector<double>& nd,
        double(*kriterijus)(vector<double >)= studentas::mediana) {
        if (nd.size() == 0)// patikriname ar atliko bent viena
            throw std::domain_error("studentas neatliko ne vieno");
            return galBalas(egzaminas, kriterijus(nd));//overloading
    }
    */