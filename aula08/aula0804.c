/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: programa de testes da funcao CodificarBase32
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/08 03:22:27 $
 * $Log: aula0804.c,v $
 * Revision 1.2  2024/08/08 03:22:27  felipe.farias
 * correcao de tipo de falha
 *
 * Revision 1.1  2024/08/02 04:46:18  felipe.farias
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

#define NUMERO_ARGUMENTOS_CODIFICAR_BYTES	3

#define OK					0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define VALOR_BYTE_EXCEDIDO			2
#define BYTE_NEGATIVO				3
#define BYTE_ZERADO				4	
#define ALFABETO_NEGATIVO			5
#define CARACTER_NUMERO_BYTES_INVALIDO		6
#define CARACTER_TIPO_BYTES_INVALIDO		7
#define CARACTER_ESPECIAL_ALFABETO_INVALIDO	8
#define DIGITO_ALFABETO_INVALIDO		9
#define ERRO_ALOCACAO_MEMORIA			10
#define ERRO_GERAR_CODIFICACAO			11

#define END_OF_STRING				'\0'

int
main (int argc, char **argv)
{

	ul auxiliarTipoByte;
	ull numeroBytes, numeroArgumentosBytesTerminal, contadorArgumentosTerminal;
	char *validacao, *saidaPacote;
	byte *bytesEntrada;
	tipoErros pacoteCodificado;
	tipoAlfabetoBase32 tipoAlfabetoEntrada;


	if (argc < NUMERO_ARGUMENTOS_CODIFICAR_BYTES)
	{
		printf ("\n%sERRO: Nenhum argumento para codificar Base 16 foi digitado! Uso: <alfabeto> <numeroBytes> <byte1> ... <byteN>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv[1][0] == '-')
	{
		printf ("\n%sERRO: O alfabeto esta negativo. Digite apenas o inteiro 0 (basico) ou 1 (estendido)!%s\n\n", RED, RESET);
		exit (ALFABETO_NEGATIVO);
	}


	tipoAlfabetoEntrada = (tipoAlfabetoBase32) strtoull(argv[1], &validacao, 10);

	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\' do argumento do tipo do alfabeto!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_ESPECIAL_ALFABETO_INVALIDO);
	}

	if(tipoAlfabetoEntrada != basico && tipoAlfabetoEntrada != estendido)
	{
		printf ("\n%sERRO: Argumento destinado ao tipo do alfabeto invalido. Digite apenas o inteiro 0 (basico) ou 1 (estendido)!%s\n\n", RED, RESET);
		exit (DIGITO_ALFABETO_INVALIDO);
	}


	if (argv[2][0] == '-')
	{
		printf ("\n%sERRO: O numero de bytes esta negativo. Deve-se digitar apenas inteiros positivos!%s\n\n", RED, RESET);
		exit (BYTE_NEGATIVO);
	}


	numeroBytes = strtoull(argv[2], &validacao, 10);

	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_NUMERO_BYTES_INVALIDO);
	}

	if(numeroBytes == 0)
	{
		printf ("\n%sERRO: O numero de bytes esta zerado. Deve-se digitar apenas inteiros positivos!%s\n\n", RED, RESET);
		exit (BYTE_ZERADO);
	}
	
	numeroArgumentosBytesTerminal = numeroBytes + 3;


	if (argc > numeroArgumentosBytesTerminal)
	{
		printf ("\n%sERRO: O programa espera <%llu> argumentos de bytes a codificar, porem houve excesso de argumentos digitados <%u> !>%s\n", RED, numeroBytes, argc - 3, RESET);
		printf ("%sUse: <tipoAlfabeto> <numeroBytes> <byte1> ... <byteN>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argc < numeroArgumentosBytesTerminal)
	{
		printf ("\n%sERRO: O programa espera <%llu> argumentos de bytes a codificar, porem foram digitados <%u> !>%s\n", RED, numeroBytes, argc - 3, RESET);
		printf ("%sUse: <tipoAlfabeto> <numeroBytes> <byte1> ... <byteN>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}


	
	bytesEntrada = (byte *) malloc(numeroBytes * sizeof(byte));

	if (!bytesEntrada)
	{
		printf ("\n%sERRO: Falha de alocacao de memoria!%s", RED, RESET);
		exit (ERRO_ALOCACAO_MEMORIA);
	}


	saidaPacote = (char *) malloc((numeroBytes * 8 / 5 + 1) * sizeof(char));	

	if (!saidaPacote)
	{

		free(bytesEntrada);

		printf ("\n%sERRO: Falha de alocacao de memoria!%s", RED, RESET);
		exit (ERRO_ALOCACAO_MEMORIA);

	}


	for (contadorArgumentosTerminal = 0; contadorArgumentosTerminal < numeroBytes; contadorArgumentosTerminal++)
	{
		auxiliarTipoByte = strtoul(argv[contadorArgumentosTerminal + 3], &validacao, 16);

		if(*validacao != END_OF_STRING)
		{
			free(bytesEntrada);
			free(saidaPacote);
			printf ("\n%sERRO: Caracter especial torna byte invalido no argumento '%s'. Programa aceita apenas valores de 0-255!%s\n\n", RED, argv[contadorArgumentosTerminal + 3], RESET);
			exit (CARACTER_TIPO_BYTES_INVALIDO);
		}


		if(auxiliarTipoByte > VALOR_BYTE)
		{
			free(bytesEntrada);
			free(saidaPacote);
			printf ("\n%sERRO: Byte invalido em '%s'. Programa aceita apenas inteiros positivos de 0-255!%s\n\n", RED, argv[contadorArgumentosTerminal + 3], RESET);
			exit (VALOR_BYTE_EXCEDIDO);
		}

		bytesEntrada[contadorArgumentosTerminal] = (byte) auxiliarTipoByte;

	}


	pacoteCodificado = CodificarBase32(bytesEntrada, numeroBytes, tipoAlfabetoEntrada, saidaPacote);

	if (pacoteCodificado != sucesso)
	{
		free(bytesEntrada);
		free(saidaPacote);
		printf ("\n%sERRO: Falha ao gerar a codificacao solicitada!%s", RED,RESET);
		exit (ERRO_GERAR_CODIFICACAO);
	}

	printf ("\n%s>>>>>%s%s ", WHITE_BACKGROUND, BOLD_BLACK, RESET);
	printf ("%s%s%s\n\n", GREEN, saidaPacote, RESET);

	free (bytesEntrada);
	free (saidaPacote);

	return OK;

}

/* $RCSfile: aula0804.c,v $ */
