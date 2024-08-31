#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    string surname;
    int course;

    Student(string name, string surname, int cource)
        : name(name), surname(surname), course(cource) {}

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Student& student)
    {
        os << "Name: " << student.name << ", Surname: " << student.surname << ", Course: " << student.course;
        return os;
    }
};

// Функция для заполнения вектора случайными данными
void fillVector(vector<Student>& students)
{
    students.push_back(Student("Ivan", "Ivanov", 3));
    students.push_back(Student("Petr", "Petrov", 2));
    students.push_back(Student("Alex", "Sidorov", 1));
    students.push_back(Student("John", "Doe", 4));
    students.push_back(Student("Jane", "Smith", 1));
}

// Функция для печати содержимого вектора
void printVector(const vector<Student>& students)
{
    for (const auto& student : students)
    {
        cout << student << endl;
    }
    cout << endl;
}

int main()
{
    vector<Student> students;

    // Заполнение вектора данными
    fillVector(students);

    cout << "Original vector: " << endl;
    printVector(students);

    // Сортировка по именам по возрастанию
    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
        return a.name < b.name;
    });
    cout << "Sorted by name: " << endl;
    printVector(students);

    // Стабильная сортировка по фамилиям
    stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
       return a.surname < b.surname;
    });
    cout << "Stably sorted by surname: " << endl;
    printVector(students);

    // Перемещение самых младших курсов в начало списка
    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
        return a.course < b.course;
    });
    rotate(students.begin(), students.begin() + 3, students.end());

    cout << "Three youngest students moved to the beginning: " << endl;
    printVector(students);

    return 0;
}


















