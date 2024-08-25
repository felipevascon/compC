/****************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa testes funcoes: ObterCodigoAnsiCor, MostrarMonitor e GerarDistribuicaoInicial
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/19 01:10:45 $
 * $Log: aula0702.c,v $
 * Revision 1.2  2024/08/19 01:10:45  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/08/17 18:36:51  felipe.farias
 * Initial revision
 *
 *
 ****************************************************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "aula0701.h"
#include "cores.h"

#define NUMERO_ARGUMENTOS 		10

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO 	1
#define ERRO_ARGUMENTO_INVALIDO 	2
#define ERRO_GERAR_DISTRIBUICAO 	3
#define ERRO_MOSTRAR_MONITOR 		4
#define ARGUMENTO_NEGATIVO		5

#define END_OF_STRING			'\0'

int main(int argc, char **argv)
{
	useconds_t tempoEspera;
  	unsigned numeroLinhas, numeroColunas;
  	float percentualDefeituosos, percentualApagados;
	char *corFundo;
	char *corPixelApagado;
	char *corPixelAceso;
	char *corPixelDefeituoso;
	unsigned contadorArgumento;
  	char *validacao;
  	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
  	tipoErros resultanteDistribuicao, resultanteMonitor;

  	if (argc != NUMERO_ARGUMENTOS)
  	{
    		printf("%s\nERRO: Numero argumentos invalido. Uso: <tempoEspera> <numeroLinhas> <numeroColunas> <percentualDefeituoso> <percentualApagado> <corFundo> <corApagado <corAceso> <corDefeituoso>\n\n%s", RED, RESET);

    		exit (NUMERO_ARGUMENTOS_INVALIDO);
  	}

	if (argv[1][0] == '-')
	{
		printf ("\n%sERRO: O primeiro argumento dos parametros destinado ao tempo de congelamento esta negativo. Digite apenas numeros inteiros positivos!%s\n\n", RED, RESET);
		exit (ARGUMENTO_NEGATIVO);
	}

	tempoEspera = strtoul(argv[1], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O primeiro argumento dos parametros destinado ao tempo de congelamento contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	if (argv[2][0] == '-')
	{
		printf ("\n%sERRO: O segundo argumento dos parametros destinado ao numero de linhas esta negativo. Digite apenas numeros inteiros positivos!%s\n\n", RED, RESET);
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroLinhas = strtoul(argv[2], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O segundo argumento dos parametros destinado ao numero de linhas contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	if (argv[3][0] == '-')
	{
		printf ("\n%sERRO: O terceiro argumento dos parametros destinado ao numero de colunas esta negativo. Digite apenas numeros inteiros positivos!%s\n\n", RED, RESET);
		exit (ARGUMENTO_NEGATIVO);
	}

	numeroColunas = strtoul(argv[3], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O terceiro argumento dos parametros destinado ao numero de colunas contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	if (argv[4][0] == '-')
	{
		printf ("\n%sERRO: O quarto argumento dos parametros destinado ao percentual de defeituosos esta negativo. Digite apenas numeros inteiros positivos!%s\n\n", RED, RESET);
		exit (ARGUMENTO_NEGATIVO);
	}

	percentualDefeituosos = strtof(argv[4], &validacao);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O quarto argumento dos parametros destinado ao percentual de defeituosos contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	if (argv[5][0] == '-')
	{
		printf ("\n%sERRO: O quinto argumento dos parametros destinado ao percentual de apagados esta negativo. Digite apenas numeros inteiros positivos!%s\n\n", RED, RESET);
		exit (ARGUMENTO_NEGATIVO);
	}

	percentualApagados = strtof(argv[5], &validacao);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O quinto argumento dos parametros destinado ao percentual de apagados contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}


	for (contadorArgumento = 6; contadorArgumento < 10; contadorArgumento++) 
	{
        	unsigned stringCorValida = 1;
		unsigned contadorAuxiliar;
        	for (contadorAuxiliar = 0; argv[contadorArgumento][contadorAuxiliar] != END_OF_STRING; contadorAuxiliar++) 
		{

            		if ((argv[contadorArgumento][contadorAuxiliar] < 'A' || argv[contadorArgumento][contadorAuxiliar] > 'Z') && (argv[contadorArgumento][contadorAuxiliar] < 'a' || argv[contadorArgumento][contadorAuxiliar] > 'z')) 
	    		{

				stringCorValida = 0;
				break;
            		}
        	}
	
		if (!stringCorValida)
		{
			printf("\n%sERRO: A cor %u contem um ou mais caracteres invalidos!%s\n\n", RED, contadorArgumento - 5, RESET);
			exit (ERRO_ARGUMENTO_INVALIDO);
		}

    		if (contadorArgumento == 6)
    		{
			corFundo = argv[contadorArgumento];
    		}

    		else if (contadorArgumento == 7)
    		{
			corPixelApagado = argv[contadorArgumento];
    		}

    		else if (contadorArgumento == 8)
    		{
			corPixelAceso = argv[contadorArgumento];
    		}

		else if (contadorArgumento == 9)
    		{
			corPixelDefeituoso = argv[contadorArgumento];
    		}


	}	


	resultanteDistribuicao = GerarDistribuicaoInicial(monitor, numeroLinhas, numeroColunas, percentualDefeituosos, percentualApagados); 
	if(resultanteDistribuicao != sucesso)
	{

		printf ("\n%sERRO: Falha ao gerar a distribuicao inicial! numero: %u%s\n\n", RED, resultanteDistribuicao, RESET);
		exit (ERRO_GERAR_DISTRIBUICAO);

	}

	resultanteMonitor = MostrarMonitor(tempoEspera, monitor, numeroLinhas, numeroColunas, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso); 
	if(resultanteMonitor != sucesso)
	{

		printf ("\n%sERRO: Falha ao gerar o monitor! numero: %u%s\n\n", RED, resultanteMonitor, RESET);
		exit (ERRO_MOSTRAR_MONITOR);

	}

	return OK;
}
/* $RCSfile: aula0702.c,v $ */ 
