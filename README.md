# sudoku
sudoku no console em c++

# Descrição

Jogo de sudoku com uma matriz 9x9 gerada através da seleção de uma dentre quatro manipulações feitas a uma matriz pré-definida no código e copia uma porcentagem dessa para a matriz que será vizualizada pelo jogador.

Possui um menu principal com quatro opções:

1. Jogar: Inicia o jogo que mostra a matriz-jogo na tela e pede para que o usuário insira um índice vazio e um valor para inserir no mesmo, acabando apenas quando a matriz inteira for preenchida;

2. Dificuldade: Mostra a descrição das três dificuldades disponíveis: fácil, média é difícil; que mudam quanto da matriz original será visível ao jogador, copiando 40%, 28% e 15% da matriz, respectivamente;

3. Sobre: Mostra uma tela com informações sobre o desenvolvimento do projeto, sendo essas seus autores, data, professor e matéria;

4. Fim: define o valor de retorno da função main() e termina o jogo.


# Regras do sudoku

1. Possui uma matriz 9x9 incompleta com valores de 1 a 9;

2. Cada bloco de 3x3 possuirá os valores de 1 a 9 sem repetições;

3. O jogador deverá preencher os espaços vazios com valores dentro do alcance de forma que os blocos de 3x3 não contenham números repetidos. 
