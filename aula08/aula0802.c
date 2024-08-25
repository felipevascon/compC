/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes da funcao CodificarBase16
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/30 22:24:33 $
 * $Log: aula0802.c,v $
 * Revision 1.2  2024/07/30 22:24:33  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/07/28 18:43:43  felipe.farias
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

#define NUMERO_ARGUMENTOS_CODIFICAR_BYTES	2

#define OK					0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define VALOR_BYTE_EXCEDIDO			2
#define BYTE_NEGATIVO				3
#define CARACTER_NUMERO_BYTES_INVALIDO		4
#define CARACTER_TIPO_BYTES_INVALIDO		5
#define ERRO_ALOCACAO_MEMORIA			6
#define ERRO_GERAR_CODIFICACAO			7

#define END_OF_STRING				'\0'

int
main (int argc, char **argv)
{

	ul auxiliarTipoByte;
	ull numeroBytes, numeroArgumentosBytesTerminal, contadorArgumentosTerminal;
	char *validacao, *saidaPacote;
	byte *bytesEntrada;
	tipoErros pacoteCodificado;


	if (argc < NUMERO_ARGUMENTOS_CODIFICAR_BYTES)
	{
		printf ("\n%sERRO: Nenhum argumento para codificar Base 16 foi digitado! Uso: <numeroBytes> <byte1> ... <byteN>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argv[1][0] == '-')
	{
		printf ("\n%sERRO: O numero de bytes esta negativo. Deve-se digitar apenas inteiros positivos!%s\n\n", RED, RESET);
		exit (BYTE_NEGATIVO);
	}


	numeroBytes = strtoull(argv[1], &validacao, 10);

	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_NUMERO_BYTES_INVALIDO);
	}



	numeroArgumentosBytesTerminal = numeroBytes + 2;

	if (argc > numeroArgumentosBytesTerminal)
	{
		printf ("\n%sERRO: O programa espera <%llu> argumentos de bytes a codificar, porem houve excesso de argumentos digitados <%u> !>%s\n", RED, numeroBytes, argc - 2, RESET);
		printf ("%sUse: <numeroBytes> <byte1> ... <byteN>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argc < numeroArgumentosBytesTerminal)
	{
		printf ("\n%sERRO: O programa espera <%llu> argumentos de bytes a codificar, porem foram digitados <%u> !>%s\n", RED, numeroBytes, argc - 2, RESET);
		printf ("%sUse: <numeroBytes> <byte1> ... <byteN>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}


	
	bytesEntrada = (byte *) malloc(numeroBytes * sizeof(byte));

	if (!bytesEntrada)
	{
		printf ("\n%sERRO: Falha de alocacao de memoria!%s", RED, RESET);
		exit (ERRO_ALOCACAO_MEMORIA);
	}


	saidaPacote = (char *) malloc((2 * numeroBytes + 2) * sizeof(char));	

	if (!saidaPacote)
	{

		free(bytesEntrada);

		printf ("\n%sERRO: Falha de alocacao de memoria!%s", RED, RESET);
		exit (ERRO_ALOCACAO_MEMORIA);

	}


	for (contadorArgumentosTerminal = 0; contadorArgumentosTerminal < numeroBytes; contadorArgumentosTerminal++)
	{
		auxiliarTipoByte = strtoul(argv[contadorArgumentosTerminal + 2], &validacao, 10);

		if(*validacao != END_OF_STRING)
		{
			free(bytesEntrada);
			free(saidaPacote);
			printf ("\n%sERRO: Caracter especial torna byte invalido no argumento '%s'. Programa aceita apenas valores de 0-255!%s\n\n", RED, argv[contadorArgumentosTerminal + 2], RESET);
			exit (CARACTER_TIPO_BYTES_INVALIDO);
		}


		if(auxiliarTipoByte > VALOR_BYTE)
		{
			free(bytesEntrada);
			free(saidaPacote);
			printf ("\n%sERRO: Byte invalido em '%s'. Programa aceita apenas inteiros positivos de 0-255!%s\n\n", RED, argv[contadorArgumentosTerminal + 2], RESET);
			exit (VALOR_BYTE_EXCEDIDO);
		}

		bytesEntrada[contadorArgumentosTerminal] = (byte) auxiliarTipoByte;

	}


	pacoteCodificado = CodificarBase16(bytesEntrada, numeroBytes, saidaPacote);

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

/* $RCSfile: aula0802.c,v $ */
