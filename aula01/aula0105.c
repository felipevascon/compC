
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: codigo fonte de um programa que recebe um nome
 *
 * $Author: felipe.farias $
 * $Date: 2024/04/21 04:12:00 $
 * $Log: aula0105.c,v $
 * Revision 1.1  2024/04/21 04:12:00  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cores.h"
#include "aula0101.h"


#define SUCESSO				0
#define INTERVALO_INVALIDO		2


int
main (int argc, char *argv [])
{
	us comprimentoNome = 0;
	us quantidadeEspacos;
	us quantidadeEspacosEntreNomes;

	us contador;

	char result[50];
	
	for (contador = 1; contador < argc; contador++)
	{

		comprimentoNome += strlen(argv [contador]);
	}
	
	quantidadeEspacosEntreNomes = (argc - 1) - 1;
	

	if (comprimentoNome < 1 || comprimentoNome > 50)
	{
		printf("%s\n ERRO: Comprimento do nome encontra-se fora do intervalo possivel da funcao ( 0 < nome <= 50)!\n\n%s", RED, RESET);
		exit (INTERVALO_INVALIDO);
	}
	printf("\n");

	ExibirCabecalho (100);
	
	printf("\n");

	quantidadeEspacos = (100 - (comprimentoNome + quantidadeEspacosEntreNomes))/2; 
	
	for (contador = 1; contador < quantidadeEspacos; contador++)
	{
		printf(" ");
	}

	
	printf("%s%s\"", RED, UNDERLINE_RED);

	for (contador = 1; contador < argc; contador ++)
	{
		
		strcpy (result, argv[contador]);
		
		if (contador < argc -1)
		{
			printf("%s ",result);
			
		}
		else if (contador == argc -1)
		
		{
			printf("%s",result);
		}
	}
	
	printf("\"%s", RESET);	
	
	printf("\n");
	
	ExibirHifens(100);

	return SUCESSO;

}

/* $RCSfile: aula0105.c,v $ */
