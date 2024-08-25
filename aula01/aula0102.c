/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: tratamento de erros/implementacao main/chamada da funcao ExibirCabecalho
 *
 * $Author: felipe.farias $
 * $Date: 2024/04/20 00:41:10 $
 * $Log: aula0102.c,v $
 * Revision 1.1  2024/04/20 00:41:10  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "cores.h"
#include "aula0101.h"

#define NUMERO_ARGUMENTOS				2

#define SUCESSO						0	
#define NUMERO_ARGUMENTOS_INVALIDO			3		
#define INTERVALO_INVALIDO				4
#define ARGUMENTO_CARACTER_INVALIDO			5

#define END_OF_STRING					'\0'

int
main (int argc, char*argv[])
{
	unsigned short numero;
	unsigned long numeroColunas;
	char *validacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
	
		printf ("%s \n ERRO: NUMERO DE ARGUMENTOS INVALIDO!  \n\n %s", RED, RESET);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	numeroColunas = strtoul (argv[1], &validacao, 10);

	
	
	
	if (*validacao != END_OF_STRING)
	{
	
		printf("%s \n ERRO: ARGUMENTO CONTEM CARACTERE INVALIDO! \'%c\' %s \n\n", RED, *validacao, RESET);
		exit (ARGUMENTO_CARACTER_INVALIDO);

	}
	
	
	
	if (numeroColunas < 1 || numeroColunas > 500)
	{
	
		printf ("%s \n ERRO: INTERVALO INVALIDO! DIGITE NUMERO DE ACORDO COM O INTERVALO 1 <= NUMERO <= 500! %s \n\n", RED, RESET);
		exit (INTERVALO_INVALIDO);

	}	

	
	numero = (us) numeroColunas;
	ExibirCabecalho (numero);

	return SUCESSO;
}
/* $RCSfile: aula0102.c,v $ */
