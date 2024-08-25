
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Exibicao dos tamanhos tipos basicos/ modificadores de sinal/ largura
 *
 * $Author: felipe.farias $
 * $Date: 2024/04/22 03:09:46 $
 * $Log: aula0106.c,v $
 * Revision 1.1  2024/04/22 03:09:46  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "cores.h"
#include "aula0101.h"

#define SUCESSO		0

int main ()
{

	ExibirHifens (100);

	printf("%sTamanhos dos Tipos Basicos%s\n\n", UNDERLINE_WHITE, RESET);

	
	printf("%svoid:   %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(void), sizeof(void) == 1 ? "byte" : "bytes", RESET);
	printf("%schar:   %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(char), sizeof(char) == 1 ? "byte" : "bytes", RESET);
	printf("%sint:    %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(int),    sizeof(int) == 1 ?"byte" : "bytes", RESET);
	printf("%sfloat:  %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(float),  sizeof(float) == 1 ? "byte" : "bytes", RESET);
	printf("%sdouble: %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW,  sizeof(double), sizeof(double) == 1 ? "byte" : "bytes", RESET);


	ExibirHifens (100);

	printf("%sTamanhos dos Modificadores de Sinal%s\n\n", UNDERLINE_WHITE, RESET);

	printf("%ssigned:   %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s \n",GREEN,YELLOW, sizeof(signed),   sizeof(signed) == 1 ? "byte" : "bytes", RESET);
	printf("%sunsigned: %s \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(unsigned), sizeof(unsigned) == 1 ? "byte" : "bytes", RESET);


	ExibirHifens (100);

	printf("%sTamanhos dos Modificadores de Largura%s\n\n", UNDERLINE_WHITE, RESET);

	printf("%sshort:   %s  \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(short), sizeof(short) == 1 ? "byte" : "bytes", RESET);
	printf("%slong:    %s  \t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(long), sizeof(long) == 1 ? "byte" : "bytes", RESET);
	printf("%slong long: %s\t\t\t\t\t\t\t\t\t\t   %lu %s %s\n",GREEN,YELLOW, sizeof(long long), sizeof(long long) == 1 ? "byte" : "bytes", RESET);

	ExibirHifens (100);

	return SUCESSO;

}

/* $RCSfile: aula0106.c,v $ */
