/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes da funcao DecodificarBase64
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/13 00:34:52 $
 * $Log: aula0807.c,v $
 * Revision 1.1  2024/08/13 00:34:52  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"
#include "cores.h"

#define NUMERO_ARGUMENTOS_DECODIFICAR_BYTES	4

#define OK					0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define NUMERO_FINAL_LINHA_NEGATIVO		2
#define ALFABETO_NEGATIVO			3
#define CARACTER_ESPECIAL_FINAL_LINHA_INVALIDO	4
#define CARACTER_ESPECIAL_ALFABETO_INVALIDO	5
#define DIGITO_FINAL_LINHA_INVALIDO		6
#define DIGITO_ALFABETO_INVALIDO		7
#define COMPRIMENTO_STRING_INVALIDO		8
#define ERRO_ALOCACAO_MEMORIA			9		

#define END_OF_STRING				'\0'

int
main (int argc, char **argv)
{

	ull numeroBytes, comprimentoString;
	us contadorPacoteDecodificado;
	byte *saidaBase64;
	char *entradaByte, *validacao;
	tipoAlfabeto64 tipoAlfabetoEntrada;
	tipoFinalLinha finalLinha;
	tipoErros pacoteDecodificado;

	if (argc != NUMERO_ARGUMENTOS_DECODIFICAR_BYTES)
	{
		printf ("\n%sERRO: numero de argumentos invalido! Uso: <finalLinha> <tipoAlfabeto> <stringBase64>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv[1][0] == '-')
	{
		printf ("\n%sERRO: O argumento final de linha esta negativo. Digite apenas o inteiro 0 (desabilitado) ou 1 (habilitado)!%s\n\n", RED, RESET);
		exit (NUMERO_FINAL_LINHA_NEGATIVO);
	}

	finalLinha = (tipoFinalLinha)strtoul(argv[1], &validacao, 10);

	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\' do argumento final de linha!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_ESPECIAL_FINAL_LINHA_INVALIDO);
	}

	if(finalLinha != desabilitado && finalLinha != habilitado)
	{
		printf ("\n%sERRO: Primeiro argumento destinado ao final de linha invalido. Digite apenas o inteiro 0 (desabilitado) ou 1 (habilitado)!%s\n\n", RED, RESET);
		exit (DIGITO_FINAL_LINHA_INVALIDO);
	}

	if (argv[2][0] == '-')
	{
		printf ("\n%sERRO: O alfabeto esta negativo. Digite apenas o inteiro 0 (basico) ou 1 (seguro)!%s\n\n", RED, RESET);
		exit (ALFABETO_NEGATIVO);
	}

	tipoAlfabetoEntrada = (tipoAlfabeto64)strtoul(argv[2], &validacao, 10);
	
	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\' do argumento do tipo do alfabeto!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_ESPECIAL_ALFABETO_INVALIDO);
	}

	if(tipoAlfabetoEntrada != basico64 && tipoAlfabetoEntrada != seguro)
	{
		printf ("\n%sERRO: Primeiro argumento destinado ao tipo do alfabeto invalido. Digite apenas o inteiro 0 (basico) ou 1 (seguro)!%s\n\n", RED, RESET);
		exit (DIGITO_ALFABETO_INVALIDO);
	}

	entradaByte = argv[3];
	comprimentoString = strlen(entradaByte);

	if(comprimentoString % 4 != 0)
	{

		printf ("\n%sERRO: Terceiro argumento destinado a string base 64 invalido. O comprimento da string deve ser multiplo de 4!%s\n\n", RED, RESET);
		exit (COMPRIMENTO_STRING_INVALIDO);
	}

	saidaBase64 = (byte *)malloc((comprimentoString / 4 * 3) * sizeof(byte));


	if (!saidaBase64)
	{
		printf ("\n%sERRO: Falha de alocacao de memoria!\n\n%s", RED, RESET);
		exit (ERRO_ALOCACAO_MEMORIA);
	}

	pacoteDecodificado = DecodificarBase64(entradaByte, finalLinha, tipoAlfabetoEntrada, saidaBase64, &numeroBytes);

	if(pacoteDecodificado != sucesso)
	{

		free(saidaBase64);
		switch (pacoteDecodificado)
		{

			case entradaByteInvalida:
			printf("\n%sERRO: Entrada invalida!%s\n\n", RED, RESET);
			break;

			case saidaPacoteInvalido:
			printf("\n%sERRO: Saida invalida!%s\n\n", RED, RESET);
			break;

			case comprimentoInvalido:
			printf("\n%sERRO: Comprimento invalido!%s\n\n", RED, RESET);
			break;

			case entradaNaoParInvalido:
			printf("\n%sERRO: Comprimento da string invalido!%s\n\n", RED, RESET);
			break;

			case baseInvalida:
			printf("\n%sERRO: Falha ao gerar a codificacao!%s\n\n", RED, RESET);
			break;
	
			default:
			printf("\n%sERRO: Falha ao gerar a codificacao!%s", RED, RESET);
			break;

		}

		exit(pacoteDecodificado);
	}

	printf("\n%s%s>>>>>%s %s", BOLD_BLACK, WHITE_BACKGROUND, RESET, GREEN);

	for (contadorPacoteDecodificado = 0; contadorPacoteDecodificado < numeroBytes; contadorPacoteDecodificado++)
	{

		printf("%02X", saidaBase64[contadorPacoteDecodificado]);
		
		if (contadorPacoteDecodificado + 1 < numeroBytes)
		{
	
			printf(" ");

		}	
	

	}
	printf("%s\n\n", RESET);

	free(saidaBase64);

	return OK;
}
/* $RCSfile: aula0807.c,v $ */
