/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes da funcao DecodificarBase16
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/30 22:31:46 $
 * $Log: aula0803.c,v $
 * Revision 1.1  2024/07/30 22:31:46  felipe.farias
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

#define NUMERO_ARGUMENTOS_DECODIFICAR_BYTES	2

#define OK					0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define ERRO_ALOCACAO_MEMORIA			2	

int
main (int argc, char **argv)
{

	ull tamanhoPacote;
	ul contador;
	byte *saidaBase16;
	tipoErros pacoteDecodificado;

	if (argc != NUMERO_ARGUMENTOS_DECODIFICAR_BYTES)
	{
		printf ("\n%sERRO: numero de argumentos invalido! Uso: <stringBase16>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	saidaBase16 = (byte *)malloc((strlen(argv[1]) / 2) * sizeof(byte));

	if (!saidaBase16)
	{
		printf ("\n%sERRO: falha de alocacao de memoria!\n\n%s", RED, RESET);
		exit (ERRO_ALOCACAO_MEMORIA);
	}

	pacoteDecodificado = DecodificarBase16(argv[1], saidaBase16, &tamanhoPacote);

	if(pacoteDecodificado != sucesso)
	{

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
			printf("\n%sERRO: Comprimento da string de entrada invalido!%s\n\n", RED, RESET);
			break;

			case nibbleAltoInvalido:
			printf("\n%sERRO: Nibble alto invalido!%s\n\n", RED, RESET);
			break;

			case nibbleBaixoInvalido:
			printf("\n%sERRO: Nibble baixo invalido!%s\n\n", RED, RESET);
			break;

			default:
			printf("\n%sERRO: Falha ao gerar funcao!%s\n", RED, RESET);
			break;
		}

		exit (pacoteDecodificado);

	}

	printf ("\n%s%s>>>>>%s %s", BOLD_HIGH_INTENSITY_BLACK, WHITE_BACKGROUND, RESET, GREEN);

	for (contador = 0; contador < tamanhoPacote; contador++)
	{

		printf ("%03u ", saidaBase16[contador]);

	}
	
	printf("%s\n\n", RESET);

	free (saidaBase16);

	return OK;

}

/* $RCSfile: aula0803.c,v $ */
