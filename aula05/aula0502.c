/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: tratamento de erros/ implementacao main/ chamada ExibirMatriz
 *
 * $Author: felipe.farias $
 * $Date: 2024/06/10 01:49:05 $
 * $Log: aula0502.c,v $
 * Revision 1.2  2024/06/10 01:49:05  felipe.farias
 * correcao de pular linhas
 *
 * Revision 1.1  2024/06/01 04:04:29  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined(__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <float.h>

#include "cores.h"
#include "aula0501.h"

#define NUMERO_MAXIMO_ARGUMENTOS			NUMERO_MAXIMO_LINHAS * NUMERO_MAXIMO_COLUNAS + 3
#define NUMERO_MINIMO_ARGUMENTOS			4

#define NUMERO_ARGUMENTOS_INVALIDO			1		
#define ARGUMENTO_CARACTER_INVALIDO			2
#define ARGUMENTO_CARACTER_HIFEN_INVALIDO		3

#define ARGUMENTO_ZERO_INVALIDO				5
#define TAMANHO_MAXIMO_LONG_EXCEDIDO			6
#define TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO		7
#define TAMANHO_MAXIMO_LONG_DOUBLE_EXCEDIDO		8
#define BASE_INVALIDA					9
#define BASE_DECIMAL					10
#define QUANTIDADES_INVALIDAS				11


#define END_OF_STRING					'\0'

int
main (int argc, char **argv)
{	
	
	us numeroLinhas, numeroColunas, auxiliarLinha, auxiliarColuna, validacaoAuxiliar;
	static ld matriz[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	unsigned long int primeiroTermoAuxiliar;
	ld segundoTermoAuxiliar;	
	char *validacao;
	unsigned char contador;
	unsigned char resultado;

	/*tratamento numero de argumentos*/
	if (argc > NUMERO_MAXIMO_ARGUMENTOS || argc < NUMERO_MINIMO_ARGUMENTOS)
	{
		printf("\n%sERRO: Numero de argumentos invalido! Uso:<Linhas(<=100)> <Colunas(<=100)> <a11> .. <a1n> <a21> .. <a2n> <aX1> .. <aXn>. %s\n\n", RED, RESET);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*tratamento para os argumentos linha e coluna */
	if(argv[1][0] == '-' || argv[2][0] <= '-')
	{
		printf("\n%sERRO: Nao existem matrizes com numero de linhas e/ou colunas negativas! Retire o '-'. %s\n\n", RED, RESET);	
		exit (ARGUMENTO_CARACTER_HIFEN_INVALIDO);
	}	

	for(contador = 1; contador <= 2; contador++)
	{
		primeiroTermoAuxiliar = strtoul(argv[contador], &validacao, BASE_DECIMAL);
		
		if(errno == EINVAL)
		{
			printf("\n%sERRO: Base invalida.%s\n\n", RED, RESET);
			exit (BASE_INVALIDA);
		}

		if (errno == ERANGE)
		{
			printf("\n%sERRO: Valor maximo de conversao do tipo unsigned long int (limite:%lu) foi ultrapassado. %s\n\n", RED, ULONG_MAX, RESET);
			exit (TAMANHO_MAXIMO_LONG_EXCEDIDO);
		}
	
		if(*validacao != END_OF_STRING)
		{
			printf("\n%sERRO: Caracteres especiais sao invalidos! Retire o (\'%c\')! %s\n\n", RED, *validacao, RESET);
			exit (ARGUMENTO_CARACTER_INVALIDO);
		}
	
		validacaoAuxiliar = (us) primeiroTermoAuxiliar;
		
		if(primeiroTermoAuxiliar > USHRT_MAX)
		{
			
			printf("\n%sERRO: Valor maximo do tipo unsigned short int(limite:%u) para linhas e/ou colunas foi ultrapassado. %s\n\n", RED, USHRT_MAX, RESET);
			exit (TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
		}
		
		if(primeiroTermoAuxiliar == 0)
		{
			printf("%s\nERRO: Numero de linhas e colunas devem ser numeros maiores do que zero! %s\n\n", RED, RESET);
			exit (ARGUMENTO_ZERO_INVALIDO);
		}
	
		if(contador == 1)
		numeroLinhas = (us)primeiroTermoAuxiliar;
		
		if(contador == 2)
		numeroColunas = (us)primeiroTermoAuxiliar;	
	
	}
	
	/*tratamento argumento dos indices*/
	if(numeroLinhas * numeroColunas == 1)
	{
	
		validacaoAuxiliar = numeroLinhas * numeroColunas + 1;
	
	}
	else
	{
		validacaoAuxiliar = numeroLinhas * numeroColunas;
	}

	if(argc != validacaoAuxiliar + 3)
	{
		
		printf("\n%sERRO: Numero de argumentos invalido! Uso:<Linhas(<=100)> <Colunas(<=100)> <a11> .. <a1n> <a21> .. <a2n> <aX1> .. <aXn>. %s\n\n", RED, RESET);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for(auxiliarLinha = 0; auxiliarLinha < numeroLinhas; auxiliarLinha++)
	{
		for(auxiliarColuna = 0; auxiliarColuna < numeroColunas; auxiliarColuna++)
		{
			segundoTermoAuxiliar = strtold (argv[3 + auxiliarColuna + auxiliarLinha * numeroColunas], &validacao);

			if(errno == EINVAL)
			{
				printf("\n%sERRO: Base invalida.%s", RED, RESET);
				exit (BASE_INVALIDA);
			}
			
			if(errno == ERANGE && segundoTermoAuxiliar > 0)
			{
				printf("%s\nERRO: Valor maximo long double (%Lg) para um ou mais indices da matriz esta excedido!%s\n\n", RED, LDBL_MAX, RESET);
				exit (TAMANHO_MAXIMO_LONG_DOUBLE_EXCEDIDO);
			}

			if(*validacao != END_OF_STRING)
			{
				printf("\n%sERRO: Caracteres especiais sao invalidos! Retire o (\'%c\'). %s\n\n", RED, *validacao, RESET);
				exit (ARGUMENTO_CARACTER_INVALIDO);
			}
			
			matriz[auxiliarLinha][auxiliarColuna] = segundoTermoAuxiliar;
				
		}
	}

	resultado = ExibirMatriz(numeroLinhas, numeroColunas, matriz);
	
	if(resultado != sucesso)
	{
		printf("\n%sERRO: Nao foi possivel gerar esta matriz.%s\n", RED, RESET);
		
		if(resultado == linhaColunaInvalida)
		{
			printf("\n%sERRO: O numero de linhas e colunas da matriz nao pode ser maior do que %d%s\n", RED, NUMERO_MAXIMO_LINHAS, RESET);
			exit (QUANTIDADES_INVALIDAS);
		}
	
	}

	return OK;
}

/* $RCSfile: aula0502.c,v $ */
