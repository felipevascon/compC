/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: tratamento de erros/implementacao main/chamada funcao CalcularMDC 
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/04 16:52:42 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2024/05/04 16:52:42  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "cores.h"
#include "aula0201.h"

#define NUMERO_ARGUMENTOS				3

#define SUCESSO						0
#define NUMERO_ARGUMENTOS_INVALIDO			2		
#define ARGUMENTO_CARACTER_INVALIDO			4
#define ARGUMENTO_CARACTER_HIFEN			5
#define CONDICAO_INVALIDA				6
#define TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO      7

#define END_OF_STRING					'\0'

int
main (int argc, char *argv[])
{
	ull primeiroNumero, segundoNumero, chamadaMaximoDivisorComum;
	char *validacao;
	int contador;

	/*tratamento numero de argumentos*/
	if (argc != NUMERO_ARGUMENTOS)
	{
	
		printf ("%s\n ERRO: NUMERO DE ARGUMENTOS INVALIDO! Uso: <inteiro positivo> <inteiro positivo>  \n\n %s", RED, RESET);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	for	(contador = 1; contador < NUMERO_ARGUMENTOS; contador++)
		{
			if (argv[contador][0] == '-')
			{
				printf ("%s\n ERRO: PRIMEIRO E/OU SEGUNDO ARGUMENTO CONTEM CARACTER HIFEN '-' ! \n\n %s", RED, RESET);
				exit (ARGUMENTO_CARACTER_HIFEN);
			}
		}	
		
		
		/*tratamento caractere invalido para o primeiro argumento*/
		primeiroNumero = strtoull (argv[1], &validacao, 10);
	
	
		if (*validacao != END_OF_STRING)
		{
	
			printf("%s \n ERRO: PRIMEIRO ARGUMENTO CONTEM CARACTERE INVALIDO! \'%c\' %s \n\n", RED, *validacao, RESET);
			exit (ARGUMENTO_CARACTER_INVALIDO);

		}
	
		if (errno == ERANGE)
		{
	
			printf("%s\n ERRO: VALOR MAXIMO DO TIPO UNSIGNED LONG LONG (%llu) FOI EXCEDIDO PELO PRIMEIRO ARGUMENTO! \n\n%s", RED, ULLONG_MAX, RESET);
			exit (TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);

		}	
		



		/*tratamento caractere invalido para o segundo argumento*/
		segundoNumero = strtoull(argv[2], &validacao, 10);
		
		if(*validacao != END_OF_STRING)
		{
		
			printf("%s \n ERRO: SEGUNDO ARGUMENTO CONTEM CARACTERE INVALIDO! \'%c\' %s \n\n", RED, *validacao, RESET);
			exit (ARGUMENTO_CARACTER_INVALIDO);
		}
		
		if (errno == ERANGE)
		{
	
			printf("%s\n ERRO: VALOR MAXIMO DO TIPO UNSIGNED LONG LONG (%llu) FOI EXCEDIDO PELO SEGUNDO ARGUMENTO! \n\n%s", RED, ULLONG_MAX, RESET);
			exit (TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);

		}	
	
	/* tratamento MDC(X,Y) igual a zero indicando condicao de erro */		
	if (primeiroNumero == 0 && segundoNumero == 0)
	{
		printf("%s\n ERRO: O MAXIMO DIVISOR COMUM ENTRE ZEROS 'MDC(0,0) = 0' EH UMA CONDICAO INVALIDA! \n\n%s", RED, RESET);
		exit (CONDICAO_INVALIDA);
	}

	
	chamadaMaximoDivisorComum = CalcularMaximoDivisorComum (primeiroNumero, segundoNumero);
	
	printf("%s\nMDC(%llu, %llu) = %llu%s\n\n",GREEN, primeiroNumero, segundoNumero, chamadaMaximoDivisorComum, RESET);	

	return SUCESSO;
}
/* $RCSfile: aula0202.c,v $ */
