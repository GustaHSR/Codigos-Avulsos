#include <bits/stdc++.h>

using namespace std;

// Função que imprime o personagem enforcado de acordo com o número de erros
void PrintHangman(int errors, string tema, vector<char>& letraus) {
    switch (errors) {
        case 0:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << "      |" << endl;          
            cout << "      |          " << "Tema: " << tema << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        case 1:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << " O    |" << endl;
            cout << "      |          " << "Tema: " << tema << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        case 2:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << " O    |" << endl;
            cout << " |    |          " << "Tema: " << tema << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << endl << "Letras usadas: ";
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        case 3:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << " O    |" << endl;
            cout << "/|    |          " << "Tema: " << tema << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        case 4:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << " O    |" << endl;
            cout << "/|\\   |          " << "Tema: " << tema << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        case 5:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << " O    |" << endl;
            cout << "/|\\   |          " << "Tema: " << tema << endl;
            cout << "/     |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        case 6:
            cout << " +----+" << endl;
            cout << " |    |" << endl;
            cout << " O    |" << endl;
            cout << "/|\\   |          " << "Tema: " << tema << endl;
            cout << "/ \\   |" << endl;
            cout << "      |" << endl;
            cout << "==========" << endl;
            cout << endl << "Letras usadas: ";
            for (int i = 0; i < letraus.size(); i++) cout << letraus[i] << " ";
            cout << endl << endl;
            break;
        default:
            break;
    }
}

// Função que verifica se a letra está presente na palavra e atualiza a lista de letras usadas
bool CheckLetter(const string& word, vector<char>& used_letters, char letter) {
    bool found = false;
    for (char c : word) {
        if (c == letter) {
            found = true;
            break;
        }
    }
    if (found) {
        used_letters.push_back(letter);
    }
    return found;
}

// Função que imprime a palavra com os caracteres ainda desconhecidos representados por "_"
void PrintWord(const string& word, const vector<char>& used_letters) {
    for (char c : word) {
        if (c != ' ') {
            if (find(used_letters.begin(), used_letters.end(), c) != used_letters.end()) {
            cout << c << " ";
            } else {
                cout << "_ ";
            }
        }
        else cout << " ";
    }
    cout << endl;
}

int main() {
        vector<char>letraus;
    // Palavras para o jogo
    string tema;
    cout << "Digite o tema da frase ou palavra: ";
    getline(cin,tema);
    cout << endl << "Agora digite uma frase de acordo com o tema para outra pessoa adivinhar: ";
    string frasee;
    getline(cin,frasee);
    cout << endl;

   

    // Seleciona uma palavra aleatoriamente
    string word = frasee;

    // Inicializa as variáveis do jogo
    vector<char> used_letters;
    int num_errors = 0;
    bool game_over = false;

    // Loop principal do jogo
    while (!game_over) {
        system("clear"); // Limpa a tela
        cout << "Jogo da forca" << endl;
        PrintHangman(num_errors,tema, letraus);
        PrintWord(word, used_letters);

        // Verifica se o jogador acertou a palavra
        bool won = true;
        for (char c : word) {
            if (c == ' ') continue;
            if (find(used_letters.begin(), used_letters.end(), c) == used_letters.end()) {
                won = false;
                break;
            }
        }
        if (won) {
            cout << "Parabéns, voce acertou a frase \"" << word << "\"!" << endl;
            game_over = true;
            continue;
        }

        // Verifica se o jogador já cometeu 6 erros
        if (num_errors == 6) {
            cout << "Você perdeu! A frase era \"" << word << "\"." << endl;
            game_over = true;
            continue;
        }

        // Pede ao jogador uma letra e verifica se ela já foi usada
        cout << "Digite uma letra: ";
        char letter;
        cin >> letter;
        letraus.push_back(letter);
        if (find(used_letters.begin(), used_letters.end(), letter) != used_letters.end()) {
            cout << "Você já usou essa letra. Tente outra." << endl;
            continue;
        }

        // Verifica se a letra está na palavra e atualiza a lista de letras usadas
        if (CheckLetter(word, used_letters, letter)) {
            cout << "Boa, a letra \"" << letter << "\" está na frase." << endl;
        } else {
            num_errors++;
            cout << "Ops, a letra \"" << letter << "\" não está na frase." << endl;
        }
        sleep(1);
    }

    return 0;
}

