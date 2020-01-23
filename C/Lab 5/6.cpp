
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class student {
    public:
        string name;
        string birthDate;
        int index;
        int marks[3];
};

void RemoveStudent(vector<student> &students) {
    string name = "";
    cout << "Podaj nazwisko studenta: " << endl;
    cin >> name;
    int index = -1;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) { index = i; break; }
    }
    if (index >= 0) {
        students.erase(students.begin() + index);
        cout << "Student " << name << " zostal usuniety" << endl;
    }
}

void DisplayStudents(vector<student> &students) {
    for (int i = 0; i < students.size(); i++) {
        student s = students[i];
        cout << "\nDane studenta " << i + 1 << ": " << endl;
        cout << "Nazwisko: " << s.name << endl;
        cout << "Data urodzenia: " << s.birthDate << endl;
        cout << "Indeks: " << s.index << endl;
        cout << "Oceny z 1 przedmiotu: " << s.marks[0] << endl;
        cout << "Oceny z 2 przedmiotu: " << s.marks[1] << endl;
        cout << "Oceny z 3 przedmiotu: " << s.marks[2] << endl;
    }
}

bool Comparator(const student &a, const student &b) {
    return a.name < b.name;
}

void SortAlphabetic(vector<student> &students) {
    sort(students.begin(), students.end(), Comparator);
    cout << "Posortowano studentow" << endl;
}

vector<int> NumberToVector(int a) {
    vector<int> n;
    while (a) { n.push_back(a % 10); a /= 10; }
    reverse(n.begin(), n.end());
    return n;
}

float CalcAverage(int a) {
    vector<int> n = NumberToVector(a);
    return accumulate(n.begin(), n.end(), 0.0) / n.size();
}

void FindBest(vector<student> &students) {
    int num, id = 0;
    cout << "Podaj numer przedmiotu: " << endl;
    cin >> num;
    float max = 0.0;
    for (int i = 0; i < students.size(); i++) {
        int marks = students[i].marks[num - 1];
        float aver = CalcAverage(marks);
        if (aver > max) { max = aver; id = i + 1; }
    }
    cout << "Student " << id << " ma najwyzsza ocene z tego przedmiotu: "
        << max << endl;
}

void FindAverage(vector<student> &students) {
    int id = 0;
    float aver = 0.0;
    for (int i = 0; i < students.size(); i++) {
        float marks1 = CalcAverage(students[i].marks[0]);
        float marks2 = CalcAverage(students[i].marks[1]);
        float marks3 = CalcAverage(students[i].marks[2]);
        float a = (marks1 + marks2 + marks3) / 3.0;
        if (a > aver) { aver = a; id = i + 1; }
    }
    cout << "Student " << id << " ma najwyzsza srednia ocen: " << aver << endl;
}

int main() {
    int count;
    cout << "Liczba studentow: ";
    cin >> count;
    vector<student> students;
    for (int i = 0; i < count; i++) {
        student s;
        cout << "\nDane studenta " << i + 1 << ":\nPodaj nazwisko: " << endl;
        cin >> s.name;
        cout << "Podaj date urodzenia: " << endl;
        cin >> s.birthDate;
        cout << "Podaj numer indeksu: " << endl;
        cin >> s.index;
        cout << "Podaj oceny z 1 przedmiotu: " << endl;
        cin >> s.marks[0];
        cout << "Podaj oceny z 2 przedmiotu: " << endl;
        cin >> s.marks[1];
        cout << "Podaj oceny z 3 przedmiotu: " << endl;
        cin >> s.marks[2];
        students.push_back(s);
    }
    int exec;
    A:
    cout << "\nDzialania:" << endl;
    cout << "1. Usuwanie studenta" << endl;
    cout << "2. Wyswietlanie studentow" << endl;
    cout << "3. Posortuj studentow alfabetycznie" << endl;
    cout << "4. Znajdz studenta z najwyzsza ocena z danego przedmiotu" << endl;
    cout << "5. Znajdz studenta z najwyzsza srednia ocen" << endl;
    cout << "6. Wyjscie z programu" << endl;
    cin >> exec;
    switch(exec) {
        case 1: RemoveStudent(students); break;
        case 2: DisplayStudents(students); break;
        case 3: SortAlphabetic(students); break;
        case 4: FindBest(students); break;
        case 5: FindAverage(students); break;
        default: return 0;
    }
    goto A;
}

