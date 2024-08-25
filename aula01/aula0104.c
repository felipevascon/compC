
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa exibe 256 possiveis cores de um terminal
 *
 * $Author: felipe.farias $
 * $Date: 2024/04/20 02:58:57 $
 * $Log: aula0104.c,v $
 * Revision 1.1  2024/04/20 02:58:57  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "cores.h"

#define NUMERO_ARGUMENTOS 1
#define NUMERO_ARGUMENTOS_INVALIDO 2

int
main (int argc, char *argv[])
{

	int contador = 0;
	
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("%s\nUso: <Apenas nome programa>\n\n%s", RED, RESET);

		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	
	for (contador = 0; contador < 80; contador++)
	{
	
		printf("%s%s%d%s", BLACK, WHITE_BACKGROUND, contador / 10, RESET);

	}
	printf("\n");

	
	
	for (contador = 0; contador < 80; contador++)
	{
		
		printf("%s%s%d%s", BLACK, WHITE_BACKGROUND, contador % 10, RESET);
	}
	printf("\n\n    ");
	

	for (contador = 0; contador < 256; contador++)
	{
		printf("\e[38;5;%dm%03d\e[0m ", contador, contador);

		if (contador % 16 == 15)
		{
			printf("\n    ");
		}
	}
	
	printf("\n");

	return 0;
}

/* $RCSfile: aula0104.c,v $ */
