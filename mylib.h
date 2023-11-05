#pragma once

#include<iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdio>
// kai kuriu include dar nereikia naudoti bet as vistiek palikau kitam kartui

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::domain_error;
using std::sort;
using std::ifstream;
using std::find;
using std::find_if;
using std::search;
using std::copy;
using std::remove;
using std::remove_if;
using std::remove_copy;
using std::remove_copy_if;
using std::transform;
using std::partition;
using std::stable_partition;

class studentas {

private:
        string vard;
    string pav;
    vector<int> paz;
    int egz;
float rez;
string pravarde;

public:
char skaiciavimo_Strategija;

    studentas();
    

    studentas(const studentas& temp);   
    studentas& operator=(const studentas& temp);
    
    ~studentas();

 studentas(string v, string p, vector<int>pp, int e);
    // Getter
    inline string getVardas() { return vard; }
    inline int getPazNr() { return paz.size(); }

    // Setter
    inline void setVardas(string& t) { vard = t; }
    void printas();
    void printasRez();
    void rezVid();
    void rezMed();
    void failas(const string& failoVardas, vector<studentas>& grupe);
    void findPravarde();

friend std::istream& operator>>(std::istream& in, studentas& a);//Duomenu ivedimo metodas
friend std::ostream& operator<<(std::ostream& out, const studentas& a);// Duomenu isvedimo metodas
    // Duomen? ?vedimo metodas (perdengtas cin)
    // Duomen? išvedimo metodas (perdengtas cout)
    // Galutinio pažymio skai?iavimo metodas (pagal median? arb? vidurk? renkasi žmogus)
    double mediana(vector<int>vec);

    inline bool operator<(const studentas& other) const {
        // Palygina vardus ir pavardes pagal abecele
        if (vard < other.vard)
            return true;
        if (vard > other.vard)
            return false;
        return pav < other.pav;

    }
    string getPravarde();
    

};
extern vector<studentas> grupe;


