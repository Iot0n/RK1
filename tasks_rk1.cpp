#include "tasks_rk1.h"
#include "cstdio"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <random>



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
    for (int i = 0; i < size_hex; i ++){
        hex[i] = hexboof[num-1];
        num--;
    }
    hex[size_hex] = '\0';
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 10);
    for (int i = 0; i < N; i++) {
        ar[i] = dis(gen);
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

void WorkWithFile::readFromFile(const char* fileName){

}
