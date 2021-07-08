// Trabalho T3 - Algoritmos e Programação
// Autor: João P. B. Fissmer

#include <iostream>
#include <ctime>

#define CLEAR system("CLS")
#define PAUSE system("PAUSE > NUL")

using namespace std;

int main() {
    const int tam = 9;
    int menu, dificuldade, operacao, copias, max_copias, jogadas, acertos, linha, coluna;
    int ind_linha, ind_coluna, valor;
    bool venceu;
    int matG[tam][tam], matJ[tam][tam];
    int matP[tam][tam] = {4, 9, 5, 2, 8, 7, 3, 6, 1,
                          7, 2, 8, 6, 1, 3, 4, 9, 5,
                          3, 6, 1, 9, 5, 4, 7, 2, 8,
                          6, 5, 3, 8, 4, 9, 2, 1, 7,
                          9, 8, 4, 1, 7, 2, 6, 5, 3,
                          2, 1, 7, 5, 3, 6, 9, 8, 4,
                          1, 3, 2, 4, 6, 5, 8, 7, 9,
                          5, 4, 6, 7, 9, 8, 1, 3, 2,
                          8, 7, 9, 3, 2, 1, 5, 4, 6};
    dificuldade = 2; // Dificuldade padrão

    while (true) {
        CLEAR;
        cout << "< Sudoku >"   << '\n';
        cout << "1. Jogar"       << '\n';
        cout << "2. Dificuldade" << '\n';
        cout << "3. Sobre"       << '\n';
        cout << "4. Fim"         << '\n';
        cin >> menu;

        switch (menu) {
            case 1:
                /* Iniciando o jogo e 'resetando' variáveis */
                venceu = false;
                jogadas = 0, acertos = 0, copias = 0;
                
                /* Definindo o número máximo de cópias da matriz gabarito em função da dificuldade */
                switch (dificuldade) {
                    case 1:
                        max_copias = (tam * tam) * 50 / 100; // 50% da matriz
                        break;
                    case 2:
                        max_copias = (tam * tam) * 35 / 100; // 35% da matriz
                        break;
                    case 3:
                        max_copias = (tam * tam) * 15 / 100; // 15% da matriz
                        break;
                }

                /* Randomizando a operação para gerar a matriz gabarito (1 a 4) */
                srand(time(NULL));
                operacao = rand() % 4 + 1;
                
                /* Gerando a matriz gabarito em função da matriz base */
                switch (operacao) {
                    case 1:
                        /* Cópia exata */
                        for (int i = 0; i < tam; ++i)
                            for (int j = 0; j < tam; ++j)
                                matG[i][j] = matP[i][j];
                        break;
                    case 2:
                        /* Matriz transposta */
                        for (int i = 0; i < tam; ++i)
                            for (int j = 0; j < tam; ++j)
                                if (i != j)
                                    matG[i][j] = matP[j][i];
                        break;
                    case 3:
                        /* Invertida por linha */
                        for (int i = 0, l = tam - 1; i < tam; ++i, --l)
                            for (int j = 0; j < tam; ++j)
                                matG[l][j] = matP[i][j];
                        break;
                    case 4:
                        /* Invertida por coluna */
                        for (int i = 0; i < tam; ++i)
                            for (int j = 0, c = tam - 1; j < tam; ++j, --c)
                                matG[i][c] = matP[i][j];
                        break;
                }

                /* Gerando a matriz jogo - inicialmente preenchendo os valores com 0 */
                for (int i = 0; i < tam; ++i)
                    for (int j = 0; j < tam; ++j)
                        matJ[i][j] = 0;
                /* Copiando um índice aleatório da matriz gabarito até que o n. máximo de cópias seja atingido */
                while (copias < max_copias) {
                    linha = rand() % tam;
                    coluna = rand() % tam;
                    /* Verificando se o valor já não foi copiado antes de copiá-lo */
                    if (matJ[linha][coluna] != matG[linha][coluna]) {
                        matJ[linha][coluna] = matG[linha][coluna];
                        ++copias;
                    }
                }

                /* Jogando o jogo até que a matriz inteira seja preenchida */
                do {
                    CLEAR;
                    cout << "< Sudoku >\n";                                 
                    
                    /* Mostrando a matriz jogo na tela */
                    for (int i = 0; i < tam; ++i) {
                        putchar('\n'); // Quebra a linha para cada linha mostrada
                        for (int j = 0; j < tam; ++j) {
                            if (matJ[i][j] == 0)
                                cout << ' ' << ' ';
                            else
                                cout << matJ[i][j] << ' ';
                        }
                    }

                    putchar('\n');
                    cout << "\nEscolha um indice vazio para modificar.\n";

                    /* Recebendo o índice até que resulte em um vazio */
                    do {
                        cout << " Digite a linha do indice: ";
                        cin >> ind_linha;
                        cout << " Digite a coluna do indice: ";
                        cin >> ind_coluna;

                        /*  Prevenindo a escolha de um índice preenchido ou fora do alcance de 1,1 a 9,9 (-1) */
                        if (ind_linha < 1 || ind_linha > 9 || ind_coluna < 1 || ind_coluna > 9)
                            cout << "Indice fora do alcance. Tente novamente.\n"; 
                        else if (matJ[ind_linha - 1][ind_coluna - 1] != 0)
                            cout << "O indice escolhido ja esta preenchido. Tente novamente.\n";
                    } while (matJ[ind_linha - 1][ind_coluna - 1] != 0);

                    --ind_linha, --ind_coluna; // Adaptando os índices inseridos à base 0
                    cout << "\nEscolha um valor para inserir no indice " << ind_linha + 1 << ", " << ind_coluna + 1 << ".\n";

                    /* Recebendo um valor do usuario ate que esteja dentro do alcance de 1 a 9 */
                    do {
                        cout << " Digite o valor: ";
                        cin >> valor;
                        /* Checando se o valor está incorreto ou fora do alcance (inserindo o valor na matriz jogo caso contrário) */
                        if (valor < 1 || valor > 9) {
                            cout << "Valor fora do alcance.\n";
                        } else if (valor != matG[ind_linha][ind_coluna]) {
                            cout << "Valor incorreto.\n";
                            PAUSE;
                        } else {
                            cout << "Valor correto.\n";
                            matJ[ind_linha][ind_coluna] = valor;
                            ++acertos;
                            PAUSE;
                        }                 
                        ++jogadas;

                        /* Checando se o jogador venceu - se o número de acertos é o número de espaços não preenchidos no início */
                        if (acertos == (tam * tam) - copias)
                            venceu = true;
                    } while (valor < 1 || valor > 9);
                } while (venceu == false);
                
                /* Mostrando o número de jogadas e acertos (porcentagem) */
                CLEAR;
                cout << "Parabens, voce venceu o jogo!\n";
                cout << " Jogadas: " << jogadas << '\n';
                cout << " Acertos: " << acertos << " (" << acertos * 100 / jogadas << "%)\n";
                PAUSE;
                break;
            case 2:
                /* Menu de dificuldades */
                CLEAR;
                cout << "Menu de dificuldades:\n";
                cout << "1. Facil   (40 valores visiveis)\n";
                cout << "2. Media   (28 valores visiveis)\n";
                cout << "3. Dificil (12 valores visiveis)\n";
                putchar('\n');
                cout << "Escolha uma dificuldade: ";
                cin >> dificuldade;

                /* Substituindo valores inválidos pela dificuldade padrão */
                if (dificuldade < 1 || dificuldade > 3)
                    dificuldade = 2;
                break;
            case 3:
                /* Menu de informações sobre o desenvolvimento do programa */
                CLEAR;
                cout << "Equipe de desenvolvimento:\n";
                cout << "   João Pedro Bona Fissmer\n";
                cout << "Professor: Rafael Ballottin Martins\n";
                cout << "Disciplina: Algoritmos e Programacao\n";
                cout << "Junho/2021\n";
                PAUSE;
                break;
            case 4:
                CLEAR;
                return 0;
            default:
                break;
        }
    }
}