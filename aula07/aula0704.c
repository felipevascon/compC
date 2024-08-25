/*************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Programa de testes da funcao DesenharReta
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/19 23:56:01 $
 * $Log: aula0704.c,v $
 * Revision 1.1  2024/08/19 23:56:01  felipe.farias
 * Initial revision
 *
 *
 *************************************************************/
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

#include "aula0701.h"
#include "cores.h"

#define NUMERO_ARGUMENTOS 		14

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO 	1
#define ERRO_ARGUMENTO_INVALIDO 	2
#define ERRO_GERAR_DISTRIBUICAO 	3
#define ERRO_MOSTRAR_MONITOR 		4
#define ERRO_DESENHAR_RETA		5
#define ERRO_CONVERSAO_TIPOS_INVALIDO	6
#define ARGUMENTO_NEGATIVO		7

#define END_OF_STRING			'\0'

int main(int argc, char **argv)
{
	useconds_t tempoEspera;
  	unsigned numeroLinhas, numeroColunas, linhaPrimeiroPonto, colunaPrimeiroPonto, linhaSegundoPonto, colunaSegundoPonto;
  	float percentualDefeituosos, percentualApagados;
	char *corFundo;
	char *corPixelApagado;
	char *corPixelAceso;
	char *corPixelDefeituoso;
	unsigned contadorArgumento;
  	char *validacao;
  	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
  	tipoErros resultanteDistribuicao, resultanteMonitor, resultanteLimparMonitor, resultanteDesenharReta;

  	if (argc != NUMERO_ARGUMENTOS)
  	{
    		printf("%s\nERRO: Numero argumentos invalido!\n", RED);
    		printf("Uso: <tempoEspera> <numeroLinhas> <numeroColunas> <percentualDefeituosos> <percentualApagados> <linhaPrimeiroPonto> <colunaPrimeiroPonto> <linhaSegundoPonto> <colunaSegundoPonto> <corFundo> <corApagado <corAceso> <corDefeituoso>\n\n%s", RESET);
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


	linhaPrimeiroPonto = strtoul(argv[6], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O sexto argumento dos parametros destinado a linha do primeiro ponto contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}


	colunaPrimeiroPonto = strtoul(argv[7], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O setimo argumento dos parametros destinado a coluna do primeiro ponto contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	linhaSegundoPonto = strtoul(argv[8], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O oitavo argumento dos parametros destinado a linha do segundo ponto contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	colunaSegundoPonto = strtoul(argv[9], &validacao, 10);
	if(*validacao != END_OF_STRING)
	{

		printf ("\n%sERRO: O nono argumento dos parametros destinado a coluna do segundo ponto contem caracter invalido \'%c\'!%s\n\n", RED, *validacao, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}

	if(errno != 0)
	{

		printf ("\n%sERRO: Conversao dos tipos dos argumentos invalido!%s\n\n", RED, RESET);
		exit (ERRO_CONVERSAO_TIPOS_INVALIDO);

	}


	if(numeroLinhas > NUMERO_MAXIMO_LINHAS || numeroColunas > NUMERO_MAXIMO_COLUNAS || percentualDefeituosos < 0 || percentualDefeituosos > 100 || percentualApagados < 0 || percentualApagados > 100 || linhaPrimeiroPonto >= numeroLinhas || colunaPrimeiroPonto >= numeroColunas || linhaSegundoPonto >= numeroLinhas || colunaSegundoPonto >= numeroColunas)
	{

		printf ("\n%sERRO: Algum argumento dos parametros que envolvem linhas e colunas estao invalidos!%s\n\n", RED, RESET);
		exit (ERRO_ARGUMENTO_INVALIDO);

	}


	for (contadorArgumento = 10; contadorArgumento < 14; contadorArgumento++) 
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
			printf("\n%sERRO: A cor %u contem um ou mais caracteres invalidos!%s\n\n", RED, contadorArgumento - 9, RESET);
			exit (ERRO_ARGUMENTO_INVALIDO);

		}

    		if (contadorArgumento == 10)
    		{
			corFundo = argv[contadorArgumento];
    		}

    		else if (contadorArgumento == 11)
    		{
			corPixelApagado = argv[contadorArgumento];
    		}

    		else if (contadorArgumento == 12)
    		{
			corPixelAceso = argv[contadorArgumento];
    		}

		else if (contadorArgumento == 13)
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

	resultanteLimparMonitor = LimparMonitor(monitor, numeroLinhas, numeroColunas, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso);
	if(resultanteLimparMonitor != sucesso)
	{

		printf ("\n%sERRO: Falha ao gerar a limpeza do monitor! numero: %u%s\n\n", RED, resultanteLimparMonitor, RESET);
		exit (ERRO_MOSTRAR_MONITOR);

	}

	resultanteDesenharReta = DesenharReta(monitor, numeroLinhas, numeroColunas, linhaPrimeiroPonto, colunaPrimeiroPonto, linhaSegundoPonto, colunaSegundoPonto, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso); 
	if(resultanteDesenharReta != sucesso)
	{

		printf ("\n%sERRO: Falha ao gerar o desenho da reta! numero: %u%s\n\n", RED, resultanteDesenharReta, RESET);
		exit (ERRO_DESENHAR_RETA);

	}

	resultanteMonitor = MostrarMonitor(tempoEspera, monitor, numeroLinhas, numeroColunas, corFundo, corPixelApagado, corPixelAceso, corPixelDefeituoso); 
	if(resultanteMonitor != sucesso)
	{

		printf ("\n%sERRO: Falha ao gerar o monitor! numero: %u%s\n\n", RED, resultanteMonitor, RESET);
		exit (ERRO_MOSTRAR_MONITOR);

	}

	usleep(tempoEspera);

	return OK;
}
/* $RCSfile: aula0704.c,v $ */
