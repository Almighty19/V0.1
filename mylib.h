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

extern char skaiciavimo_Strategija;

//string failoVardas;


class studentas {
    string vard, pav;
    vector<int> paz;
    int egz;
    float rez;

public:
    studentas();
    studentas(string v, string p, vector<int>pp, int e);
    studentas(const studentas& temp);
    studentas& operator=(const studentas& temp);
    ~studentas();

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
    // Duomen? ?vedimo metodas (perdengtas cin)
    // Duomen? išvedimo metodas (perdengtas cout)
    // Galutinio pažymio skai?iavimo metodas (pagal median? arb? vidurk? renkasi žmogus)
    double mediana(vector<int>vec);

};