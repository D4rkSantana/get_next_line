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