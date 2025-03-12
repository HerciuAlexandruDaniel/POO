#include <iostream>
#include <vector>
#include <algorithm>

class Persoana {
private:
    std::string nume;
    int varsta;
    float medie;

public:
    // Constructor cu parametri
    Persoana(const std::string& nume_persoana, int varsta_persoana, float medie_persoana)
        : nume(nume_persoana), varsta(varsta_persoana), medie(medie_persoana) {
        std::cout << "Obiectul a fost creat pentru: " << nume << std::endl;
    }

    ~Persoana() {
        // Destructor
        std::cout << "Obiectul a fost distrus pentru: " << nume << std::endl;
    }

    void afiseazaDetalii() const {
        std::cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << std::endl;
    }

    float getMedie() const {
        return medie;
    }
};

int main() {
    int numarStudenti;
    std::cout << "Introduceti numarul de studenti: ";
    std::cin >> numarStudenti;

    // Crearea unui vector de pointeri pentru studenți
    std::vector<Persoana*> studenti;

    for (int i = 0; i < numarStudenti; ++i) {
        std::string nume;
        int varsta;
        float medie;

        // Citirea informațiilor pentru fiecare student
        std::cout << "Numele studentului " << i + 1 << ": ";
        std::cin >> nume;
        std::cout << "Varsta studentului " << i + 1 << ": ";
        std::cin >> varsta;
        std::cout << "Media studentului " << i + 1 << ": ";
        std::cin >> medie;

        // Crearea unui obiect de tip Persoana și adăugarea lui în vector
        studenti.push_back(new Persoana(nume, varsta, medie));
    }

    // Afișarea detaliilor despre studenți
    std::cout << "\nLista studentilor:\n";
    for (auto& student : studenti) {
        student->afiseazaDetalii();
    }

    // Găsirea studentului cu media maximă
    Persoana* studentMaxMedie = studenti[0];
    for (auto& student : studenti) {
        if (student->getMedie() > studentMaxMedie->getMedie()) {
            studentMaxMedie = student;
        }
    }
    std::cout << "\nStudentul cu cea mai mare medie este:\n";
    studentMaxMedie->afiseazaDetalii();

    // Sortarea studentilor dupa medie (descrescator)
    std::sort(studenti.begin(), studenti.end(), [](Persoana* a, Persoana* b) {
        return a->getMedie() > b->getMedie();
        });

    // Afișarea studenților sortați
    std::cout << "\nStudentii sortati dupa medie (descrescator):\n";
    for (auto& student : studenti) {
        student->afiseazaDetalii();
    }

    // Eliberarea memoriei
    for (auto& student : studenti) {
        delete student;
    }

    return 0;
}

