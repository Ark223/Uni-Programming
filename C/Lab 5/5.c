
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
        if (students[i].name == name) {
            j = i; break;
        }
    }
    if (j >= 0)
        free(students + j);
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

int Compare(const void* i1, const void* i2)
{
    struct student *a = (struct student*)i1;
    struct student *b = (struct student*)i2;
    return strcmp(a->name, b->name);
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
        char* name;
        printf("\nNazwisko studenta:\n");
        scanf("%s", &name);
        RemoveStudent(name);
    }
    else if (exec == 2) DisplayStudents();
    else if (exec == 3) qsort(students, count, sizeof(struct student*), Compare);
    else return 0;
    goto A;
}

