/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes ValidarRg 1 unico argumento
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/23 16:44:05 $
 * $Log: aula0603b.c,v $
 * Revision 1.1  2024/07/23 16:44:05  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cores.h"
#include "aula0601.h"

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
	byte numeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR];
	us contadorRg = 0;
	char *terminalEntradaRg;
	us contadorEntradaRg;
	tipoErros resultadoValidarRg;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("\n%sERRO: Numero de argumentos invalidos! Considere 'd' = 'digito', uso: <d1d2.d3d4d5.d6d7d8-d9>%s\n\n", RED, RESET);
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	terminalEntradaRg = argv[1];

	if (strlen(terminalEntradaRg) != COMPRIMENTO_RG + DIGITO_VERIFICADOR + 3 || terminalEntradaRg[2] != '.' || terminalEntradaRg[6] != '.' || terminalEntradaRg[COMPRIMENTO_RG + 2] != '-')
	{
		printf("%s\nERRO: O comprimento do RG esta em formato invalido! Considere 'd' = 'digito', uso: <d1d2.d3d4d5.d6d7d8-d9> %s\n\n", RED, RESET);
		exit(FORMATO_ARGUMENTO_RG_INVALIDO);
	}

	for (contadorEntradaRg = 0; contadorEntradaRg < COMPRIMENTO_RG + DIGITO_VERIFICADOR + 3; contadorEntradaRg++)
	{	
		if(contadorEntradaRg == 2 || contadorEntradaRg == 6 || contadorEntradaRg == (COMPRIMENTO_RG + DIGITO_VERIFICADOR + 1))
		{
			contadorEntradaRg++;
		}

		if(terminalEntradaRg[contadorEntradaRg] < '0' || terminalEntradaRg[contadorEntradaRg] > '9')
		{
			printf("%s\nERRO: O RG digitado '%s' possui um ou mais caracteres invalidos! uso: <d1d2.d3d4d5.d6d7d8-d9>  %s\n\n", RED, terminalEntradaRg, RESET);
			return(CARACTER_INVALIDO);
		}
		
		numeroRg[contadorRg++] = terminalEntradaRg[contadorEntradaRg];

	}

	resultadoValidarRg = ValidarRg(numeroRg);

	printf("\n%sRG: %s%c%c.%c%c%c.%c%c%c-%c", GREEN, RESET, numeroRg[0], numeroRg[1], numeroRg[2], numeroRg[3], numeroRg[4], numeroRg[5], numeroRg[6], numeroRg[7], numeroRg[8]);

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

/* $RCSfile: aula0603b.c,v $ */
