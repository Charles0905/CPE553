/*
Title: CPE553-hw7
Author: Chenhui Yang
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class GameOfLife {
    private:
        int* life;
        int* next;
        int x, y;
        int generation, frequence;

    public:
        //void computeNext(); // compute the next generation
        //void print() const; // display the board
        GameOfLife(string str) {
            ifstream is(str);
            is >> x >> y >> generation >> frequence;
            x += 2;
            y += 2;

            life = new int[x * y];
            int i = 0;
            for (; i < x; i++) {
                *(life + i) = 0;
                //cout << i << endl;
            }
        
            string line;
            // skip first line
            getline(is, line);
            while (getline(is, line)) { 
                *(life + i) = 0;
                i++;
                for (int j = 0; j < y - 2; j++) {
                    *(life + i) = (line.at(j) == '*') ? 1 : 0;
                    i++;
                }
                *(life + i) = 0;
                i++;
            }
            for (; i < x; i++) {
                *(life + i) = 0;
                //cout << i << endl;
            }
        }

        void ComputeNext() {
            next = new int[x * y];
            for (int i = 1; i < x; i++) {
                for (int j = 1; j < y; j++) {
                    int countAlive = 0;
                    for (int r = -1; r <= 1; r++) {
                        for (int c = -1; c <= 1; c++) {
                            countAlive += life[(i + r) * y + (j + c)];
                        }
                    }
                    countAlive -= life[i * y + j];

                    if ((life[i * y + j] == 1) && countAlive < 2) {
                        next[i * y + j] = 0;
                    }
                    else if ((life[i * y + j] == 1) && countAlive > 3) {
                        next[i * y + j] = 0;
                    }
                    else if ((life[i * y + j] == 0) && countAlive == 3) {
                        next[i * y + j] = 1;
                    }
                    else {
                        next[i * y + j] = life[i * y + j];
                    }
                }
            }
            life = next;
        }

        void print() {
            for (int gen = 0; gen <= generation; gen++) {
                if (gen % frequence == 0) {
                    cout << "generation: " << gen << endl;
                    for (int i = 1; i < x; i++) {
                        string str = "";
                        for (int j = 1; j < y; j++) {
                            str += (life[i * y + j] == 1) ? '*' : '.';
                        }
                        cout << str << endl;
                    }
                }
                ComputeNext();
            }
        }

        friend ostream& operator <<(ostream& s, const GameOfLife& g) {
            for (int i = 1; i < g.x; i++) {
                string str = "";
                for (int j = 1; j < g.y; j++) {
                    str += (g.life[i * g.y + j] == 1) ? '*' : '.';
                }
                s << str << endl;
            }
            return s;
        }
};


int main() {
    //https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
    // generate game of life specified in the data file
    GameOfLife g("gameoflife.dat");
    g.print();
}