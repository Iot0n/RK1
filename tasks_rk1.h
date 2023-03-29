#ifndef RK1_TASKS_RK1_H
#define RK1_TASKS_RK1_H

#include <vector>

class WorkWithFile {
private :
    char* dataOfFile;
    void readFromFile(const char* fileName);	//функция чтения из файла
    void prepareTestFile(const char* fileName);	//функция для создания тестового файла

public :
    WorkWithFile();
    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);
};

char* convertDecToBin(int number);

void writeToFile(const char& fileName, const char* strNum);

char* convertBinToHex(const char* binNum);

void buildTree(int height);

std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);

void randFill(float* ar, int N);

#endif //RK1_TASKS_RK1_H
