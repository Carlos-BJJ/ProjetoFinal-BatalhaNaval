# 🚢 Batalha Naval: Sistema de Matrizes e Habilidades em C

## 📖 Sobre o Projeto
Este projeto consiste em um motor lógico para um jogo de **Batalha Naval** desenvolvido em **linguagem C**. O programa vai além do posicionamento básico, implementando um sistema de "Áreas de Efeito" (AoE) para habilidades especiais e suportando o posicionamento de frotas em quatro eixos distintos: horizontal, vertical e duas diagonais.

---

## 🎯 Atributos e Estruturas Técnicas

### 1. Gerenciamento de Espaço (Matrizes)
O código utiliza um sistema de coordenadas baseado em matrizes bidimensionais:
* **Tabuleiro Principal:** Uma matriz $10 \times 10$ que serve como o mapa do jogo.
* **Submatrizes de Habilidade:** Matrizes de $3 \times 5$ usadas para calcular padrões geométricos antes de serem transferidos para o tabuleiro global.

### 2. Lógica de Posicionamento de Navios
Os navios são representados pelo valor `4` e posicionados através de laços `for` que manipulam os índices:
* **Horizontal:** Incrementa apenas o índice da coluna.
* **Vertical:** Incrementa apenas o índice da linha.
* **Diagonais:** Incrementa simultaneamente linha e coluna, permitindo inclinações em ambos os sentidos.

### 3. Sistema de Habilidades Especiais
O grande diferencial do código é a geração dinâmica de padrões:
* **Habilidade em Cone (1):** Utiliza uma lógica de preenchimento onde a largura aumenta à medida que a linha desce, baseada na distância do centro.
* **Habilidade em Cruz (2):** Preenche uma linha e uma coluna específicas dentro da submatriz para formar o desenho de cruz.
* **Habilidade em Octaedro (3):** Utiliza um cálculo de distância variável (módulo) para criar um padrão de losango/diamante.

---

## 🛠️ Detalhes do Desenvolvimento

### ⚙️ Constantes e Pré-processamento
O uso de `#define` permite que o tamanho do tabuleiro ou das habilidades seja alterado globalmente sem a necessidade de reescrever a lógica dos laços.

### 🛡️ Validação de Bordas (Boundary Check)
O código implementa uma verificação crítica:
> Antes de transferir uma habilidade para o tabuleiro, o programa checa se `(coordenada inicial + índice atual)` é menor que o limite da matriz. Isso evita erros de **segmentation fault** e corrupção de memória.

### 📊 Representação Visual
O tabuleiro final é impresso de forma que cada valor representa um estado:
* `0`: Água / Vazio.
* `1`: Área atingida pelo Cone.
* `2`: Área atingida pela Cruz.
* `3`: Área atingida pelo Octaedro.
* `4`: Posição de um Navio.

---

## 🚀 Exemplo de Lógica: Cálculo do Octaedro
```c
// Lógica para definir a largura do preenchimento em cada linha
int dist = (i % 2 == 0) ? 0 : 1; 
if (j >= centroOcta - dist && j <= centroOcta + dist) {
    matrizHabOcta[i][j] = 3;
}
