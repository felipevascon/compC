/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes da funcao GerarDigitosVerificadoresRg
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/19 20:03:38 $
 * $Log: aula0602a.c,v $
 * Revision 1.3  2024/07/19 20:03:38  felipe.farias
 * correcao do programa de testes
 *
 * Revision 1.2  2024/06/24 04:01:35  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/06/24 03:19:14  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cores.h"
#include "aula0601.h"

#define NUMERO_ARGUMENTOS_GERAR_RG		COMPRIMENTO_RG + 1
#define NUMERO_ARGUMENTOS_INVALIDO		1

#define OK					0
#define CARACTER_INVALIDO			2
#define ARGUMENTO_SEM_UNICO_DIGITO		3
#define ERRO_GERAR_FUNCAO_RG			4

#define END_OF_STRING				'\0'

int main(int argc, char **argv)

{
	byte numeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR];
	us contadorArgumentoTerminal, digitoRg;
	char *validacao;
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

		digitoRg = strtoul(argv[contadorArgumentoTerminal], &validacao, 10);

		if(*validacao != END_OF_STRING)
		{
			printf("%s\nERRO: Caracter especial invalido \'%c\' identificado no %uo digito do RG. Retire-o! %s\n\n", RED, *validacao, contadorArgumentoTerminal, RESET);
			exit(CARACTER_INVALIDO);
		}
		
		numeroRg[contadorArgumentoTerminal - 1] = (byte) (digitoRg + '0');
	}

	resultadoRg = GerarDigitosVerificadoresRg(numeroRg);

	if(resultadoRg != sucesso)
	{
		printf("\n%sERRO: Falha ao executar a funcao geradora do RG (erro numero: %u)!%s\n\n", RED, resultadoRg, RESET);
		exit(ERRO_GERAR_FUNCAO_RG);
	}

	printf("\n%sRG: %s%c%c.%c%c%c.%c%c%c-%c\n\n", GREEN, RESET, numeroRg[0], numeroRg[1], numeroRg[2], numeroRg[3], numeroRg[4], numeroRg[5], numeroRg[6], numeroRg[7], numeroRg[8]);

	return OK;

}

/* $RCSfile: aula0602a.c,v $ */
