#ifndef RK1_TASKS_RK1_H
#define RK1_TASKS_RK1_H


#include <vector>
#include <map>
#include <list>
#include <tuple>
#include <string>
#include <variant>


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

struct Node {
	Node* next;
	Node* prev;
	int nameNode;	
	static int countNodes;
	Node();
	Node(int _nameNode);
	~Node();
};

class LinkedList {
private:
	Node* Head;
	Node* Tail;
public:
	LinkedList();
	~LinkedList();

	void insert(int nameNode, int position);
	void push_back(int nameNode);
	void writeToFileFromTail();
	void writeToFileFromHead();
};

std::vector<std::vector<int>> readMatrixFromFile(const char* file);

std::vector<int> stringSplit(const std::string& str);

void colculateMatrix(const char* file);

std::vector<std::pair<int, int>> findPairs(std::vector<int> ar, int A);

class StudentInfo {
private:
	std::tuple<std::string, std::string, char*> infoStudent;
	std::map<std::string, std::pair<std::list<int>, float >> subjMark;
public:
	int addMark(const std::string& subjName, int mark, bool addSubj = false);
	int addSubj(const std::string& subjName);
	float getAverMark(const std::string& subjName);
	void printInfoStudent(bool writeFile = false);
	void writeAllInfoToFile();
	
};

void writeToFile(const char& fileName, const char* strNum);

char* convertBinToHex(const char* binNum);

void buildTree(int height);

std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);

void randFill(float* ar, int N);

bool checkBrackets (const char* str);

void sourceFileTask1(const char* fileName);

struct charcount {
	char symbol;
	int counter;
};

void sourceFileTask1(const char* fileName);

#endif //RK1_TASKS_RK1_H
