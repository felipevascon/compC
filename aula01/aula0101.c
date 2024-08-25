
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: implementacao das funcoes
 *
 * $Author: felipe.farias $
 * $Date: 2024/04/20 01:45:02 $
 * $Log: aula0101.c,v $
 * Revision 1.2  2024/04/20 01:45:02  felipe.farias
 * Adicionado prototipo para ExibirHifen
 *
 * Revision 1.1  2024/04/20 00:41:10  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>

#include "cores.h"
#include "aula0101.h"

void
ExibirCabecalho (us numeroColunas)
{

	int contador, divisao;


	for(contador = 0; contador < numeroColunas; contador++)
	{
	
		printf("%s%s%d%s", BLACK, WHITE_BACKGROUND, contador / 100, RESET);

	}
	printf("\n");
	

	for(contador = 0; contador < numeroColunas; contador++)
	{
		divisao = contador / 10;
		if(divisao < 10)
		{
			printf("%s%s%d%s", BLACK, WHITE_BACKGROUND, divisao, RESET);
		}
		else
		{
			printf("%s%s%d%s", BLACK, WHITE_BACKGROUND, divisao % 10, RESET);
		}
	
	}
	printf("\n");

	
	for(contador = 0; contador < numeroColunas; contador++)
	{
	
		printf("%s%s%d%s", BLACK, WHITE_BACKGROUND, contador % 10, RESET); 
	
	
	}
	printf("\n");
}


void
ExibirHifens (us numeroHifens)
{
	
	int contador;
	
	printf("\n");
	for(contador = 0; contador < numeroHifens; contador++)
	{
		printf("-");
	}
	printf("\n\n");
}
/* $RCSfile: aula0101.c,v $ */
