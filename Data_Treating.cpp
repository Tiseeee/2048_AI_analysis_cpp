#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

bool deleteLine(const std::string& filename, int lineToDelete) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        return false;
    }
    std::ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        inFile.close();
        return false;
    }

    std::string line;
    int currentLine = 1;
    while (std::getline(inFile, line)) {
        if (currentLine != lineToDelete) {
            tempFile << line << "\n";
        }
        currentLine++;
    }

    inFile.close();
    tempFile.close();
    if (std::remove(filename.c_str())){
        return false;
    }
    if (std::rename("temp.txt", filename.c_str())) {
        return false;
    }
    return true;
}


int main() {
    ifstream score, opear;
    opear.open("Opeartional_Process.txt", ios::app);
    score.open("score.txt", ios::app);
    int linenumber;
    scanf("输入需要处理的行数%d", &linenumber);
    int line = 1;
    char buffer[100];
    for (int s_line; line <linenumber; line++) {
        score.getline(buffer,line);
        if (buffer[6] <= '2') {
            deleteLine("Opeartional_Process.txt", line);
            deleteLine("score.txt", line);
        }
    }
}