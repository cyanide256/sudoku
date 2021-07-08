# Descrição

Jogo de sudoku com uma matriz 9x9 gerada através da seleção de uma dentre quatro manipulações feitas a uma matriz pré-definida no código e da cópia de uma porcentagem dessa para a matriz que será vizualizada pelo jogador.

Possui um menu principal com quatro opções:

1. Jogar: Inicia o jogo que mostra a matriz-jogo na tela e pede para que o usuário insira um índice vazio e um valor para inserir no mesmo, acabando apenas quando a matriz inteira for preenchida;

2. Dificuldade: Mostra a descrição das três dificuldades disponíveis e pede para que o jogador insira uma, sendo essas: fácil, média é difícil; que mudam quanto da matriz original será visível ao jogador, sendo 50%, 35% e 15% da matriz completa, respectivamente;

3. Sobre: Mostra uma tela com informações sobre o desenvolvimento do projeto, sendo essas seus autores, data, professor e matéria;

4. Fim: define o valor de retorno da função *main()* e termina o jogo.

# Regras do sudoku

* Possui uma matriz 9x9 incompleta com valores de 1 a 9;

* Cada bloco de 3x3 possuirá os valores de 1 a 9 sem repetições;

* O jogador deverá preencher os espaços vazios com valores dentro do alcance de forma que os blocos de 3x3 não contenham números repetidos.

# Geração da matriz do jogo

O algoritmo declara três *arrays* 9x9, inicializando a primeira com os valores pré-definidos pelo enunciado do trabalho e chega na matriz-jogo conforme as etapas a seguir:

1. Gera a matriz-gabarito a partir da pré-definida, realizando de forma aleatória uma das quatro modificações a seguir:
    1. Cópia exata da matriz;
    2. Matriz transposta;
    3. Matriz invertida por linha;
    4. Matriz invertida por coluna.
2. Preenche toda a matriz-jogo com o valor 0;
3. Copia uma porcentagem de valores derivada da dificuldade da matriz-gabarito à matriz-jogo, escolhendo índices aleatórios e vazios.
