#!/bin/bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c get_next_line.h
rm get_next_line.h.gch