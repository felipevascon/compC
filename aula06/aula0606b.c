/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes ValidarRg com string 1 unico argumento
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/24 15:21:37 $
 * $Log: aula0606b.c,v $
 * Revision 1.1  2024/07/24 15:21:37  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cores.h"
#include "aula0604.h"

#define NUMERO_ARGUMENTOS			2
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define OK					0
#define CARACTER_INVALIDO			2
#define FORMATO_ARGUMENTO_RG_INVALIDO		3
#define ERRO_VALIDAR_RG				4
#define SUCESSO_VALIDAR_RG			5

#define END_OF_STRING				'\0'

int main(int argc, char **argv)
{

	char *entradaNumeroRg;
	tipoErros resultadoValidarRg;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("\n%sERRO: Numero de argumentos invalidos! Considere 'd' = 'digito', uso: <d1d2.d3d4d5.d6d7d8-d9>%s\n\n", RED, RESET);
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	entradaNumeroRg = argv[1];

	if (strlen(entradaNumeroRg) != COMPRIMENTO_RG + DIGITO_VERIFICADOR + 3 || entradaNumeroRg[2] != '.' || entradaNumeroRg[6] != '.' || entradaNumeroRg[COMPRIMENTO_RG + 2] != '-')
	{
		printf("%s\nERRO: O comprimento do RG esta em formato invalido! Considere 'd' = 'digito', uso: <d1d2.d3d4d5.d6d7d8-d9> %s\n\n", RED, RESET);
		exit(FORMATO_ARGUMENTO_RG_INVALIDO);
	}

	resultadoValidarRg = ValidarRg(entradaNumeroRg);

	printf("\n%sRG:%s %s", GREEN, RESET, entradaNumeroRg);

	if(resultadoValidarRg != sucesso)
	{
		printf(" - %sinvalido%s\n\n", RED, RESET);
		exit(ERRO_VALIDAR_RG);
	}

	if(resultadoValidarRg == sucesso)
	{
		printf(" - %svalido%s\n\n", GREEN, RESET);
		exit(SUCESSO_VALIDAR_RG);
	}

	return OK;
}
/* $RCSfile: aula0606b.c,v $ */
