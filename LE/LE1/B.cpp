#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

template <typename T>
class Vetor {
private:
    T* dados;
    int tamanho;
    int capacidade;
    void redimensionar() {
        capacidade *= 2;
        T* novo = new T[capacidade];
        for (int i = 0; i < tamanho; i++) {
            novo[i] = dados[i];
        }
        delete[] dados;
        dados = novo;
    }
public:
    Vetor() {
      tamanho = 0; capacidade = 2;
      dados = new T[capacidade];
    }

    ~Vetor() {delete[] dados;}

    int getTamanho() const {
        return tamanho;
    }

    T get(int i) const {
        return dados[i];
    }

    void set(int i, T valor) {
        dados[i] = valor;
    }

    void inserir(T valor) {
        if (tamanho == capacidade) {
            redimensionar();
        }
        dados[tamanho] = valor;
        tamanho++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    int caso = 1;

    while (cin >> s && s != "end") {
        Vetor<char> pilhas;
        for (char c : s) {
            int melhor = -1;
            for (int i = 0; i < pilhas.getTamanho(); i++) {
                if (pilhas.get(i) >= c) {
                    if (melhor == -1 ||
                        pilhas.get(i) < pilhas.get(melhor)) {
                        melhor = i;
                    }
                }
            }

            if (melhor == -1) {
                pilhas.inserir(c);
            } else {
                pilhas.set(melhor, c);
            }
        }

        cout << "Case " << caso << ": " << pilhas.getTamanho() << endl;
        caso++;
    }
    return 0;
}