
# Get_next_line

Get_next_line é um projeto da grade curricular da 42 Ecole que baseia se em criar uma função que le linha apos linha um arquivo de texto

O proposito desse projeto é compreender o funcionamento das variaveis staticas e como ler arquivos em C e aprender conceitos como EOF entre outros.


## Status

Finalizado e Aprovado
![aprovado 100/100](docs/gnl_check.PNG)

## Como obter e compilar?
```
git clone https://github.com/D4rkSantana/libft.git
```
```
cd libft
```
```
make cclean
```
## Aprendizados

Linguagem C, Arrays, Funções, structs, tipos primitivos, Headers, prototipos, alocação de memoria, ponteiros, e Muitos outros.


## Referência

 - [42 São Paulo](https://www.42sp.org.br/)
 - [stdlib.h — Linux manual page](https://man7.org/linux/man-pages/man0/stdlib.h.0p.html)
 - [unistd.h — Linux manual page](https://man7.org/linux/man-pages/man0/unistd.h.0p.html)


## Uso/Exemplos

```c
#include "libft.h"

```


## Autores

- [Emerson Silva S](https://github.com/D4rkSantana)


## Etiquetas

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)





# Get_next_line #

![](https://www.nicolamanzini.com/wp-content/uploads/2018/01/get_next_line-cover.png)

Esse projeto consiste em criar uma função de leitura de arquivos, onde ele retorna uma linha por vez, independente do tamanho de buffer definido.

## como utilizar?
- utilizar a função **get_next_line(int fd, char \*\*line)**, a qual recebe o File Descriptor no primeiro parametro e o ponteiro onde sera alocado espaço e passado a linha pela função.

## Para copilar:
> gcc -D BUFFER_SIZE=32 **seu_programa.c** get_next_line.c get_next_line_utils.c get_next_line.h

ou tambem:
> clang -D BUFFER_SIZE=32 **seu_programa.c** get_next_line.c get_next_line_utils.c get_next_line.h

### Opcionalmente é permitido definir o tamanho do BUFFER_SIZE dentro do arquivo .h
> #define BUFFER_SIZE 32

Pdf do projeto incluido dentro da pasta **docs**

### by esilva-s ###