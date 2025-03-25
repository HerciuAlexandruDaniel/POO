#include <iostream>
#include <string>
using namespace std;

class Persoana {
protected:
    string nume;
    int varsta;

public:
    Persoana(string nume, int varsta)
    {
#
        this->nume = nume;
        this->varsta = varsta;

    }
    void afiseazaInformatii()
    {
        cout << "Nume: " << nume << "Varsta: " << varsta << endl;
    }
};
class Student : public Persoana {
private:
    float medie;
    friend class Admin;
public:
    Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
    {
#
        this->medie = medie;

    }
    void afiseazaInformatii()
    {
        cout << "Nume: " << nume << "Varsta: " << varsta << "Medie: " << medie << endl;
    }
};

class Admin {
public:
    void modificaMedie(Student& s, float nouaMedie)
    {
        cout << "Modific media pentru: " << s.nume << "de la" << s.medie << "la" << nouaMedie << endl;
        s.medie = nouaMedie;
    }
    void afiseazaDetaliiStudent(const Student& s) {
        cout << "Admin -> Student" << s.nume << ",Varsta: " << s.varsta << ",Medie: " << s.medie << endl;

    }
};
int main()
{
    Student s1("Gabi ", 18, 10);
    Student s2("Claudiu ", 24, 4);
    s1.afiseazaInformatii();
    s2.afiseazaInformatii();
    Admin admin;
    admin.modificaMedie(s2, 2);
    admin.afiseazaDetaliiStudent(s2);




}

