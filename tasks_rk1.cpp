#include "tasks_rk1.h"
#include "cstdio"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <fstream>
#include <stack>

char* convertDecToBin(int number){
    char binnaryboof[64];
    int num = 0;
    while (number) {
        if (number % 2 == 1)
            binnaryboof[num] = '1';
        else
            binnaryboof[num] = '0';
        number /= 2;
        num++;
    }
    char *binnary = new char[num+1];
    binnary[num] = '\0';
    for (int i = 0; num>0; i++, num--)
        binnary[i] = binnaryboof[num-1];
    return binnary;
}

void writeToFile(const char& fileName, const char* strNum){
    FILE* f;
    f = fopen(&fileName, "w");
        fprintf(f, "%s\n", strNum);
    fclose(f);
}

char* convertBinToHex(const char* binNum){
    char binboof[64] = {};
    for (int i = 0; i < 64; i++)
        binboof[i] = '0';
    int size = strlen(binNum);
    int num = size;
    for (int i = 0; i < num; i++){
        binboof[i] = binNum[size-1];
        size--;
    }
    int size_hex = num;
    size_hex += (4 - num%4);
    size_hex /= 4;
    char *hexboof = new char[size_hex]();
    int number_hex = 0, step = 1;
    int j = 0;
    for (int i = 0; i < size_hex*4;i+=4){
        for (int n = 0; n < 4; n++){
            for (int q = 0; q < n; q++) {
                    step *= 2;
            }
            number_hex += (step)*(binboof[n+i]-48);
            step = 1;
        }
        if (number_hex < 10)
            hexboof[j] = number_hex+48;
        else
            hexboof[j] = number_hex+55;
        j++;
        number_hex = 0;
    }
    char *hex = new char[size_hex];
    num = size_hex;
    int count = 0;
    for (int i = 0; i < size_hex; i ++){
	if (hexboof[num-1] == 48 && i == 0){
		num--;
		i--;
		count++;
		continue;
	}
	hex[i] = hexboof[num-1];
        num--;
    }
    hex[size_hex - count] = '\0';
    delete[] hexboof;
    return hex;
}

void buildTree(int height){
    int tab = (height - 1);
    for (int i = 0; i <= height; i++){
        for (int t = tab;t >= 0; t--){
            std::cout << " ";
        }
        tab--;
        for (int h = i*2-1; h > 0; h--)
            std::cout << "*";
        std::cout << std::endl;
    }
}

void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = (rand())%100;
    }
}

std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount) {
    std::vector<float> result;
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += ar[i * colCount + j];
        }
        float average = sum / colCount;
        result.push_back(average);
    }
    return result;
}

void WorkWithFile::readFromFile(const char* fileName) {
    std::string line;
    std::ifstream in(fileName);
    std::string* data = new std::string();
    if (in.is_open()) {
        while (getline(in, line)) {
            data->append(line);
        }
    }
    in.close();
    dataOfFile = (char*)data->c_str();
    delete data;
}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    std::map<char, int> m;

    for (int i = 0;*(dataOfFile+i) != '\0'; i++) {
        if (m.find(*(dataOfFile + i)) == m.end()) {
            m[*(dataOfFile + i)] = 1;
        }
        else {
            m[*(dataOfFile + i)] += 1;
        }
    }
    std::ofstream out(outFile);
    if (out.is_open()) {
        for (auto const& item : m)
        {
            out << item.first << '\t' << item.second << std::endl;
        }
    }
    out.close();
}

void WorkWithFile::prepareTestFile(const char* fileName) {
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z'};

    std:: string res = "";
    for (int i = 0; i < 256; i++)
        res = res + alphabet[rand() % 26];
    std::ofstream out(fileName);
    if (out.is_open()) {
        out << res << std::endl;
    }
    out.close();

}

WorkWithFile::WorkWithFile() {
    prepareTestFile("sourceFile_task1.txt");
    readFromFile("sourceFile_task1.txt");
}

WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}

bool checkBrackets (const char* str){
	std::stack<char> stc;
for (int i = 0; *(str + i) != '\0'; i++) {
if (*(str + i) == '(' || *(str + i) == '<' || *(str + i) == '{' || *(str + i) == '[') {
	stc.push(*(str +i));
}
else if (!stc.empty()) {
if (*(str + i) == ')' && stc.top() == '(') {
	stc.pop();
}
else if (*(str + i) == '}' && stc.top() == '{') {
	stc.pop();
}
else if (*(str + i) == '>' && stc.top() == '<') {
	stc.pop();
}
else if (*(str + i) == ']' && stc.top() == '[') {
	stc.pop();
			}
		}
	}
return stc.empty();
}
