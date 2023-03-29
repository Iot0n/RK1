#include <iostream>
#include "tasks_rk1.h"
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <vector>
#include <random>

void task_2(){
    char *binnary;
    binnary = convertDecToBin(134);
    std::cout << binnary;
    writeToFile(*"result_task2.txt", binnary);
    delete[] binnary;
}

void task_3(){
    char *hex;
    const char arr[] = {"11010111000010101"};
    hex = convertBinToHex(arr);
        std::cout << hex;
    writeToFile(*"result_task3.txt", hex);
    delete[] hex;
}

void task_4(){
    buildTree(5);
}

void task_5() {
    const int colCount = 5;
    const int rowCount = 3;
    float ar[rowCount][colCount];

    randFill((float *) ar, colCount * rowCount);

    std::ofstream fout("result_task5.txt");
    for (int i = 0; i < rowCount; i++) {
        std::vector<float> averages = averStr2DArray((float *) ar, colCount, rowCount);
        fout << "Str " << i + 1 << " --- " << std::setprecision(3) << averages[i] << std::endl;
    }
    fout.close();
}

int main() {
    task_2();
    std::cout << std::endl;
    task_3();
    std::cout << std::endl;
    task_4();
    std::cout << std::endl;
    task_5();
    return 0;
}