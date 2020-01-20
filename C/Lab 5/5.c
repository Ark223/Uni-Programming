
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student
{
    char name[25];
    char birthDate[10];
    int index;
    int marks[3];
};

int count;
struct student* students;

void RemoveStudent(char* name)
{
    int j = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp((students + i)->name, name) == 0) {
            j = i; break;
        }
    }
    int n = count;
    if (j >= 0 && j < n) {
        n--;
        for (int k = j; k < n; k++)
            students[k] = students[k + 1];
        free(&students[count]);
        count--;
    }
}

void DisplayStudents()
{
    for (int i = 0; i < count; i++)
    {
        printf("\nDane studenta %d:\n", i + 1);
        printf("Nazwisko: %s\n", (students + i)->name);
        printf("Data urodzenia: %s\n", (students + i)->birthDate);
        printf("Indeks: %d\n", (students + i)->index);
        printf("Oceny z 1 przedmiotu: %d\n", (students + i)->marks[0]);
        printf("Oceny z 2 przedmiotu: %d\n", (students + i)->marks[1]);
        printf("Oceny z 3 przedmiotu: %d\n", (students + i)->marks[2]);
    }
}

void SortAlphabetic() {
    int swapped = 0;
    struct student temp;
    do {
        swapped = 0;
        for (int i = 0; i < count - 1; i++) {
            int c = strcmp((students + i)->name, (students + i + 1)->name);
            if (c > 0) {
                temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}

float CalcAverage(int a) {
    int b = a;
    size_t size = 0;
    while (b) { b /= 10; size++; }
    int marks[size];
    int i = size - 1;
    while (a > 0) {
        int d = a % 10;
        a /= 10;
        marks[i] = d;
        i--;
    }
    float aver = 0;
    for (int i = 0; i < size; i++) aver += marks[i];
    aver /= size;
    return aver;
}

void FindAverage() {
    int studentId = 0;
    float max = 0.0;
    for (int i = 0; i < count; i++) {
        float aver1 = CalcAverage((students + i)->marks[0]);
        float aver2 = CalcAverage((students + i)->marks[1]);
        float aver3 = CalcAverage((students + i)->marks[2]);
        float a = (aver1 + aver2 + aver3) / 3.0;
        if (a > max) max = a;
        studentId = i + 1;
    }
    printf("Student %d ma najwieksza srednia ocen: %lf\n", studentId, max);
}

void FindBest(int subjectId) {
    int studentId = 0;
    float max = 0.0;
    for (int i = 0; i < count; i++) {
        int marks = (students + i)->marks[subjectId];
        float aver = CalcAverage(marks);
        if (aver > max) max = aver;
        studentId = i + 1;
    }
    printf("Student %d ma najwyzsza ocene z tego przedmiotu: %lf\n", studentId, max);
}

int main()
{
    printf("Liczba studentow: ");
    scanf("%d", &count);
    students = (struct student*)malloc(count * sizeof(struct student));
    for (int i = 0; i < count; i++) {
        printf("\nDane studenta %d:\nNazwisko:\n", i + 1);
        scanf("%s", &(students + i)->name);
        printf("Data urodzenia:\n");
        scanf("%s", &(students + i)->birthDate);
        printf("Numer indeksu:\n");
        scanf("%d", &(students + i)->index);
        printf("Oceny studenta z 1 przedmiotu:\n");
        scanf("%d", &(students + i)->marks[0]);
        printf("Oceny studenta z 2 przedmiotu:\n");
        scanf("%d", &(students + i)->marks[1]);
        printf("Oceny studenta z 3 przedmiotu:\n");
        scanf("%d", &(students + i)->marks[2]);
    }
    int exec = 0;
    A:
    printf("\nDzialania:\n");
    printf("1. Usuwanie studenta\n");
    printf("2. Wyswietlanie studentow:\n");
    printf("3. Posortuj studentow alfabetycznie\n");
    printf("4. Znajdz studenta z najwyzsza ocena z danego przedmiotu\n");
    printf("5. Znajdz studenta z najwyzsza srednia ocen\n");
    printf("6. Wyjscie z programu\n");
    scanf("%d", &exec);
    if (exec == 1) {
        char name[25];
        printf("Nazwisko studenta:\n");
        scanf("%s", &name);
        RemoveStudent(name);
    }
    else if (exec == 2) DisplayStudents();
    else if (exec == 3) SortAlphabetic();
    else if (exec == 4) {
        int subject;
        printf("Podaj numer przedmiotu:\n");
        scanf("%d", &subject);
        FindBest(subject - 1);
    }
    else if (exec == 5) FindAverage();
    else return 0;
    goto A;
}

