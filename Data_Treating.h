#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;


void data_treating() {
    ifstream score, opear;
    opear.open("Opeartional_Process.txt", ios::app);
    score.open("score.txt", ios::app);
    ofstream N_score, N_opear;
    N_opear.open("New_Opeartional_Process.txt", ios::app);
    N_score.open("New_score.txt", ios::app);
    int linenumber;
    cin >> linenumber;
    int line = 1;
    char score_temp[10],opear_temp[1000];
    for (int s_line; line < linenumber; line++) {
        score.getline(score_temp, 10);
        opear.getline(opear_temp, 1000);
        if ((score_temp[6] > '4' && score_temp[8])||score_temp[9]) {
            int i = 0;
            while (opear_temp[i]) {
                N_opear << opear_temp[i];
                i++;
            }
            N_opear << '\n';
            i = 6;
            N_score << "score:";
            while (score_temp[i]) {
                N_score << score_temp[i];
                i++;
            }
            N_score << '\n';
        }
    }
}