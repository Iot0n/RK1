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
//1
void writeToFile(const char& fileName, const char* strNum){
    FILE* f;
    f = fopen(&fileName, "w");
        fprintf(f, "%s\n", strNum);
    fclose(f);
}
//2
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
//3
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
//4
void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = (rand())%100;
    }
}
//5
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
//6
void WorkWithFile::readFromFile(const char* fileName) {
    std::string line;
    std::ifstream in(fileName);
    if (in.is_open()) {
        while (getline(in, line)) {
            strcat(dataOfFile, line.c_str());
        }
    }
    in.close();
}
//7
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
//8
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
//9
WorkWithFile::WorkWithFile() {
    dataOfFile = (char*)malloc(257);
    dataOfFile[0] = '\0';
    prepareTestFile("sourceFile_task1.txt");
    readFromFile("sourceFile_task1.txt");
}
//10
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
//11
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
//12
std::vector<int> stringSplit(const std::string& str) {
std::stringstream input(str);
std::string data;
std::vector<int> result;
while (std::getline(input, data, ' ')) {
result.push_back(std::stoi(data));
}
return result;
}
//13
std::vector<std::vector<int>> readMatrixFromFile(const char* file) {
std::ifstream in(file);
std::vector<std::vector<int>> res;
std::string line;
if (in.is_open()) {
while (getline(in, line)) {
res.push_back(stringSplit(line));

}
}
in.close();
return res;
}
//14
void sourceFileTask1(const char* fileName) {
    WorkWithFile wf;
    wf.writeStatInfoToFile(fileName);
}
//15
Node::Node() {
    prev = NULL;
    next = NULL;
    nameNode = 0;
}
//16
Node::Node(int _nameNode){
	prev = NULL;
	next = NULL;
	nameNode = _nameNode;
};
//17
Node::~Node() {
    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    countNodes--;
}
//18
LinkedList::LinkedList() {
    Head = NULL;
    Tail = NULL;
}
//19
LinkedList::~LinkedList() {
    Node* curr = Head;
    while (curr != NULL) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}
//20
void LinkedList::push_back(int nameNode) {
    Node* newNode = new Node(nameNode);
    if (Head == NULL) {
        Head = Tail = newNode;
    }
    else {
        newNode->prev = Tail;
        Tail->next = newNode;
        Tail = newNode;
    }
    Node::countNodes++;
}
//21
void LinkedList::writeToFileFromTail() {
    std::ofstream fout("output.txt");
    Node* curr = Tail;
    while (curr != NULL) {
        fout << curr->nameNode << std::endl;
        curr = curr->prev;
    }
    fout.close();
}
//22
void LinkedList::writeToFileFromHead() {
    std::ofstream fout("output.txt");
    Node* curr = Head;
    while (curr != NULL) {
        fout << curr->nameNode << std::endl;
        curr = curr->next;
    }
    fout.close();
}
//23
void LinkedList::insert(int value, int position) {
    if (position < 0 || position >= Node::countNodes) return;

    Node* newNode = new Node(value);

    if (position == 0) {
        if (Head == nullptr) {
            Head = Tail = newNode;
        }
        else {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
    }
    else if (position == Node::countNodes - 1) {
        Tail->next = newNode;
        newNode->prev = Tail;
        Tail = newNode;
    }
    else {
        Node* current = Head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    ++Node::countNodes;
}
//24
void colculateMatrix(const char* file) {
    std::vector<std::vector<int>> mat1 = readMatrixFromFile("matrix_1.txt");
    int sizeMat1 = 0;
    for (int i = 0; i < mat1.size(); i++) {
        if (i == 0) {
            sizeMat1 = mat1[i].size();
        }
        else {
            if (sizeMat1 != mat1[i].size()) {
                std::cout << "Разное кол-во столбцов" << std::endl;
                return;
            }
        }
    }
}
//25
std::vector< std::pair<int, int >> findPairs(std::vector<int> ar, int A) {
    std::map<int, int> masA{

    };

    for (int i = 0; i < ar.size(); i++) {
        int findValue = A - ar[i];
        if (masA.find(findValue) == masA.end()) {
            masA[ar[i]] = i;
        }
        else {
            return std::vector< std::pair<int, int >>{
                std::pair<int, int>{findValue, masA[findValue]},
                    std::pair<int, int>{ar[i], i},
            };
        }
    }
    int m = 0;
    int findValue;
    std::vector<int> keys;
    for (std::map<int, int> ::iterator it = masA.begin(); it != masA.end(); it++) {
        keys.push_back(it->first);
    }
    while (true) {
        m++;
        for (int i = 0; i < keys.size(); i++) {
            for (int j = i + 1; j < keys.size(); j++) {
                if (keys[i] + keys[j] == A + m || keys[i] + keys[j] == A - m) {
                    return std::vector< std::pair<int, int >>{
                        std::pair<int, int>{keys[i], masA[keys[i]]},
                            std::pair<int, int>{keys[j], masA[keys[j]]},
                    };
                }
            }
        }
    }
}
//26
int StudentInfo::addMark(const std::string& subjName, int mark, bool addSubj) {
    if (subjMark.find(subjName) == subjMark.end()) {
        if (!addSubj) {
            return 1;
        }
        subjMark[subjName] == std::pair<std::list<int>, float >{
            std::list<int>{
                mark
            },
                mark
        };
        return 2;
    }
    else {
        subjMark[subjName].first.push_back(mark);
        float avg = 0;
        for (int i : subjMark[subjName].first)
            avg += i;
        avg /= subjMark[subjName].first.size();
        subjMark[subjName].second = avg;
        return 0;
    }
}
//27
int StudentInfo::addSubj(const std::string& subjName) {
    if (subjMark.find(subjName) == subjMark.end()) {
        subjMark[subjName] = std::pair<std::list<int>, float >{
            std::list<int>{},
            0
        };
        return 0;
    }
    return 1;
}
//28
float StudentInfo::getAverMark(const std::string& subjName) {
    if (subjMark.find(subjName) == subjMark.end()) {
        return -1;
    }
    return subjMark[subjName].second;
}
//29
void StudentInfo::printInfoStudent(bool writeFile) {
    std::get<0>(infoStudent) = std::string{ "Georgiy" };
    std::get<1>(infoStudent) = std::string{ "Domanin" };
    std::get<2>(infoStudent) = (char*)"N_1";

    std::string s = std::get<0>(infoStudent);
    std::string s1 = std::get<1>(infoStudent);
    std::string s2 = std::get<2>(infoStudent);
    if (!writeFile) {
        std::ofstream out("Task8.txt", std::ios::out);
        if (out.is_open()) {
            out << std::get<0>(infoStudent) << " " << std::get<1>(infoStudent) << " : " << std::get<2>(infoStudent) << std::endl;
            for (auto it = subjMark.begin(); it != subjMark.end(); it++) {
                out << it->first << " ";
                for (auto it1 = it->second.first.begin(); it1 != it->second.first.end(); it1++) {
                    out << *it1 << " ";
                }
                out << it->second.second << " ";
            }
        }
        out.close();
    }
}
//30
void StudentInfo::writeAllInfoToFile() {
    std::get<0>(infoStudent) = std::string{ "Georgiy" };
    std::get<1>(infoStudent) = std::string{ "Domanin" };
    std::get<2>(infoStudent) = (char*)"N_1";
    std::ofstream out("Task8.txt");
    if (out.is_open()) {
        out << std::get<0>(infoStudent) << " " << std::get<1>(infoStudent) << " : " << std::get<2>(infoStudent) << std::endl;
        for (std::map<std::string, std::pair<std::list<int>, float >> ::iterator it = subjMark.begin(); it != subjMark.end(); it++) {
            out << '\t' << it->first << " :\t";
            bool first = true;
            for (int item : it->second.first) {
                if (first) {
                    out << item;
                    first = false;
                }
                else {
                    out << ", " << item;
                }
            }
            out << " -- " << it->second.second << std::endl;
        }
    }
    out.close();

}
//31
int Node::countNodes = 0;
//32

