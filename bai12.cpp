#include <iostream>
#include <string>
using namespace std;

class Artist {
protected:
    int creativity;

public:
    Artist(int c) : creativity(c) {}

    void draw() {
        cout << "Artist drawing with creativity: " << creativity << endl;
        cout << "  Drawing: Concept art, character design, backgrounds" << endl;
    }

    void displayArtistInfo() {
        cout << "Artist Information:" << endl;
        cout << "  Creativity level: " << creativity << endl;
    }
};

class Coder {
protected:
    int logic;

public:
    Coder(int l) : logic(l) {}

    void code() {
        cout << "Coder writing code with logic: " << logic << endl;
        cout << "  Writing: Game engine, AI, physics, systems" << endl;
    }

    void displayCoderInfo() {
        cout << "Coder Information:" << endl;
        cout << "  Logic level: " << logic << endl;
    }
};

class GameDev : public Artist, public Coder {
private:
    string specialization;
    int yearsOfExperience;

public:
    GameDev(int c, int l, string spec, int years)
        : Artist(c), Coder(l), specialization(spec), yearsOfExperience(years) {}

    void develop() {
        cout << "=== Game Developer at work ===" << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << yearsOfExperience << " years" << endl << endl;

        cout << "--- Creative Phase (drawing) ---" << endl;
        draw();
        cout << endl;

        cout << "--- Technical Phase (coding) ---" << endl;
        code();
        cout << endl;

        cout << "=== Game development complete! ===" << endl;
        cout << "Created a game combining art and technology" << endl;
    }

    void displayGameDevInfo() {
        cout << "\n=== Game Developer Profile ===" << endl;
        cout << "Artist info: " << endl;
        displayArtistInfo();
        cout << "\nCoder info: " << endl;
        displayCoderInfo();
        cout << "\nProfessional Details:" << endl;
        cout << "  Specialization: " << specialization << endl;
        cout << "  Years of Experience: " << yearsOfExperience << endl;
    }
};

int main() {
    cout << "=== Multiple Inheritance Example: Game Developer ===" << endl << endl;

    GameDev gameDeveloper(90, 85, "Game Design & Engine Development", 5);

    gameDeveloper.develop();
    gameDeveloper.displayGameDevInfo();

    return 0;
}
