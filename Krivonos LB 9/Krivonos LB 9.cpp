#include <iostream>
#define MAXSIZE 3
#include <string>

class Country{
    std::string name;
    std::string capital;
    std::string language;
    int population;
    int S;
    std::string money;
    std::string statesystem;

  public:
    Country(std::string n, std::string c, std::string l, int p, int S, std::string m, std::string s) : name(n), capital(c), language(l), population(p), S(S), money(m), statesystem(s) {}
    void cprint() {
        std::cout << name << " " << capital << " " << language << " " << population << " " << S << " " << money << " " << statesystem << "\n";
    }
};

class Queue {
    Country *array[MAXSIZE];
    int front = 0;
    int end = 0;

  public:
    void qstore(Country* data) {
        if (end == MAXSIZE) {
            std::cout << "Очередь полна\n";
            return;
        }
        array[end] = data;
        end++;
    }

    Country* qretrieve() {
        if (end == front) {
            std::cout << "Очередь пуста\n";
            return NULL;
        }
        front++;
        return array[front - 1];
    }

    void qcahge(int index, Country* data) {
        if (front == end || index < 1 || index > end - front) {
            std::cout << "Некорректный индекс\n";
            return;
        }
        array[index + front -1] = data;
    }

    void qdisplay() {
        if (front == end) {
            std::cout << "Очередь пуста\n";
            return;
        }
        std::cout << "Элементы очереди:\n";
        for (int i = front; i < end; i++)
            array[i]->cprint();
        std::cout << "\n";
    }
};

class CyclicQueue {
    Country* array[MAXSIZE];
    int front = 0;
    int end = 0;
    bool passing = false;

  public:
    void qstore(Country* q) {
        if (passing && end == front) {
            std::cout << "Очередь полна\n";
            return;
        }
        array[end] = q;
        end++;
        if (end == MAXSIZE) {
            end = 0;
            passing = true;
        }
    }

    Country* qretrieve(void) {
        if (front == MAXSIZE - 1) {
            front = 0;
            passing = false;
            return array[MAXSIZE - 1];
        }
        if (!passing && front == end) {
            std::cout << "Очередь пуста\n";
            return NULL;
        }
        front++;
        return array[front - 1];
    }

    void qcahge(int index, Country* data) {
        if (front == end && passing) std::cout << "Очередь пуста\n";
        if (!passing) {
            if (index - front < 1 || index >= end - front) std::cout << "Некорректный индекс\n";
            else array[index + front - 1] = data;
        }
        else {
            if (index < 1 && index > end  + MAXSIZE - front) std::cout << "Некорректный индекс\n";
            else {
                if (index + front - 1 > MAXSIZE - 1) array[index + front - MAXSIZE - 1] = data;
                else array[index + front - 1] = data;
            }
        }
    }

    void qdisplay() {
        if (front == end) {
            std::cout << "Очередь пуста\n";
            return;
        }
        std::cout << "Элементы очереди:\n";
        if (passing) {
            for (int i = front; i < MAXSIZE; ++i)
                array[i]->cprint();
            for (int i = 0; i < end; ++i)
                array[i]->cprint();
        }
        else {
            for (int i = front; i < end; i++)
                array[i]->cprint();
        }
    }
};

int main(){ setlocale(LC_ALL, "Ru"); }