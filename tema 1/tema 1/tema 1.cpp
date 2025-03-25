#include <iostream>
#include <string>
using namespace std;

/*
    Clasa de bază: Animal
*/
class Animal {
protected:
    string name;       // Nume animal
    int age;           // Vârsta animalului
    string foodType;   // Tipul de hrană
    float weight;      // Greutatea animalului
    string color;      // Culoarea animalului

public:
    Animal(string n, int a, string f, float w, string c)
        : name(n), age(a), foodType(f), weight(w), color(c) {
    }

    virtual void display() const {
        cout << "Nume: " << name << "\nVârsta: " << age
            << "\nMâncare: " << foodType << "\nGreutate: " << weight
            << "\nCuloare: " << color << endl;
    }
};

/*
    Clasa derivată: Mamifer
*/
class Mamifer : public Animal {
protected:
    string diet; // Tipul de alimentație (Carnivor, Ierbivor, Omnivor)

public:
    Mamifer(string n, int a, string f, float w, string c, string d)
        : Animal(n, a, f, w, c), diet(d) {
    }

    void display() const override {
        Animal::display();
        cout << "Tip alimentație: " << diet << endl;
    }
};

/*
    Clasa derivată: Fauna Marină
*/
class FaunaMarina : public Animal {
protected:
    string category; // Crustaceu, Moluscă, etc.

public:
    FaunaMarina(string n, int a, string f, float w, string c, string cat)
        : Animal(n, a, f, w, c), category(cat) {
    }

    void display() const override {
        Animal::display();
        cout << "Categorie: " << category << endl;
    }
};

/*
    Clasa derivată: Pasare
*/
class Pasare : public Animal {
protected:
    float wingSpan; // Lungimea aripilor

public:
    Pasare(string n, int a, string f, float w, string c, float ws)
        : Animal(n, a, f, w, c), wingSpan(ws) {
    }

    void display() const override {
        Animal::display();
        cout << "Lungime aripi: " << wingSpan << " m" << endl;
    }
};

/*
    Funcția de afișare a opțiunilor pentru utilizator
*/
void showInstructions() {
    cout << "Alege tipul de animal:\n";
    cout << "1. Mamifer\n";
    cout << "2. Fauna marină\n";
    cout << "3. Pasare\n";
}

int main() {
    // Exemplu de animale predefinite
    Mamifer lion("Leu", 5, "Carne", 180.0, "Auriu", "Carnivor");
    FaunaMarina turtle("Broască țestoasă", 20, "Plante", 0.75, "Verde", "Reptilă");
    Pasare eagle("Vultur", 8, "Carne", 6.0, "Negru", 2.5);

    // Afișarea animalelor predefinite
    cout << "Animale predefinite:\n";
    lion.display();
    turtle.display();
    eagle.display();

    // Se alege tipul de animal de introdus
    int option;
    showInstructions();
    cin >> option;

    int count;
    cout << "Introduceți numărul de animale: ";
    cin >> count;

    if (option == 1) {
        Mamifer* mammals = new Mamifer[count];
        for (int i = 0; i < count; ++i) {
            string name, food, color, diet;
            int age;
            float weight;

            cout << "Introduceți informațiile pentru mamiferul " << i + 1 << ":\n";
            cout << "Nume: ";
            cin >> name;
            cout << "Vârsta: ";
            cin >> age;
            cout << "Mâncare: ";
            cin >> food;
            cout << "Greutate: ";
            cin >> weight;
            cout << "Culoare: ";
            cin >> color;
            cout << "Tip alimentație (Carnivor/Ierbivor/Omnivor): ";
            cin >> diet;

            mammals[i] = Mamifer(name, age, food, weight, color, diet);
        }

        cout << "\nMamiferele introduse sunt:\n";
        for (int i = 0; i < count; ++i) {
            mammals[i].display();
        }

        delete[] mammals;

    }
    else if (option == 2) {
        FaunaMarina* marineFauna = new FaunaMarina[count];
        for (int i = 0; i < count; ++i) {
            string name, food, color, category;
            int age;
            float weight;

            cout << "Introduceți informațiile pentru fauna marină " << i + 1 << ":\n";
            cout << "Nume: ";
            cin >> name;
            cout << "Vârsta: ";
            cin >> age;
            cout << "Mâncare: ";
            cin >> food;
            cout << "Greutate: ";
            cin >> weight;
            cout << "Culoare: ";
            cin >> color;
            cout << "Categorie (Crustaceu/Molusca): ";
            cin >> category;

            marineFauna[i] = FaunaMarina(name, age, food, weight, color, category);
        }

        cout << "\nFauna marină introdusă este:\n";
        for (int i = 0; i < count; ++i) {
            marineFauna[i].display();
        }

        delete[] marineFauna;

    }
    else if (option == 3) {
        Pasare* birds = new Pasare[count];
        for (int i = 0; i < count; ++i) {
            string name, food, color;
            int age;
            float weight, wingSpan;

            cout << "Introduceți informațiile pentru pasărea " << i + 1 << ":\n";
            cout << "Nume: ";
            cin >> name;
            cout << "Vârsta: ";
            cin >> age;
            cout << "Mâncare: ";
            cin >> food;
            cout << "Greutate: ";
            cin >> weight;
            cout << "Culoare: ";
            cin >> color;
            cout << "Lungime aripi (m): ";
            cin >> wingSpan;

            birds[i] = Pasare(name, age, food, weight, color, wingSpan);
        }

        cout << "\nPăsările introduse sunt:\n";
        for (int i = 0; i < count; ++i) {
            birds[i].display();
        }

        delete[] birds;
    }

    return 0;
}