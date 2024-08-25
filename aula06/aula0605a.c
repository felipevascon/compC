/*********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes da funcao GerarDigitosVerificadoresRg com string
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/24 00:28:22 $
 * $Log: aula0605a.c,v $
 * Revision 1.1  2024/07/24 00:28:22  felipe.farias
 * Initial revision
 *
 *
 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cores.h"
#include "aula0604.h"

#define NUMERO_ARGUMENTOS_GERAR_RG		COMPRIMENTO_RG + 1
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define OK					0
#define CARACTER_INVALIDO			2
#define ARGUMENTO_SEM_UNICO_DIGITO		3
#define ERRO_GERAR_FUNCAO_RG			4

#define END_OF_STRING				'\0'

int main(int argc, char **argv)
{
	char entradaNumeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR + 4];
	us contadorArgumentoTerminal;
	char validacao;
	tipoErros resultadoRg;

	if (argc != NUMERO_ARGUMENTOS_GERAR_RG)
	{
		printf("\n%sERRO: Numero de digitos do RG invalido! Considerando 'd' = 'digito', uso: <d1> <d2> ... <d7> <d8>%s\n\n", RED, RESET);
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (contadorArgumentoTerminal = 1; contadorArgumentoTerminal <= COMPRIMENTO_RG; contadorArgumentoTerminal++)
	{
		if (strlen(argv[contadorArgumentoTerminal]) != 1)
		{
			printf("%s\nERRO: Argumento '%s' do %uo digito do RG tem mais de um termo! Uso: <0 a 9>! %s\n\n", RED, argv[contadorArgumentoTerminal], contadorArgumentoTerminal, RESET);
			exit(ARGUMENTO_SEM_UNICO_DIGITO);
		}

		switch (contadorArgumentoTerminal)
		{
			case 1:
				entradaNumeroRg[0] = argv[contadorArgumentoTerminal][0];
			break;


			case 2:
				entradaNumeroRg[1] = argv[contadorArgumentoTerminal][0];
			break;


			case 3:
				entradaNumeroRg[3] = argv[contadorArgumentoTerminal][0];
			break;


			case 4:
				entradaNumeroRg[4] = argv[contadorArgumentoTerminal][0];
			break;


			case 5:
				entradaNumeroRg[5] = argv[contadorArgumentoTerminal][0];
			break;


			case 6:
				entradaNumeroRg[7] = argv[contadorArgumentoTerminal][0];
			break;


			case 7:
				entradaNumeroRg[8] = argv[contadorArgumentoTerminal][0];
			break;


			case 8:
				entradaNumeroRg[9] = argv[contadorArgumentoTerminal][0];
			break;

		}

	}

	entradaNumeroRg[2] = '.';
	entradaNumeroRg[6] = '.';
	entradaNumeroRg[COMPRIMENTO_RG + 2] = END_OF_STRING;
	
	resultadoRg = GerarDigitosVerificadoresRg(entradaNumeroRg, &validacao);

	if(resultadoRg != sucesso)
	{
		printf("\n%sERRO: Falha ao executar a funcao geradora do RG (erro numero: %u)!%s\n\n", RED, resultadoRg, RESET);
		exit(ERRO_GERAR_FUNCAO_RG);
	}

	entradaNumeroRg[10] = '-';
	entradaNumeroRg[11]= validacao;
	entradaNumeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR + 3] = END_OF_STRING;

	printf("\n%sRG:%s %s\n\n", GREEN, RESET, entradaNumeroRg);

	return OK;

}
/* $RCSfile: aula0605a.c,v $ */
