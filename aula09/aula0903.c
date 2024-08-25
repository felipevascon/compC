/***********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Arquivo de testes da funcao ConverterArquivoFormatoUnixParaFormatDos
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/22 01:04:00 $
 * $Log: aula0903.c,v $
 * Revision 1.3  2024/08/22 01:04:00  felipe.farias
 * correcao
 *
 * Revision 1.2  2024/08/21 21:06:51  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/08/21 05:09:58  felipe.farias
 * Initial revision
 *
 *
 ************************************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0901.h"
#include "cores.h"

#define NUMERO_ARGUMENTOS		3

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define END_OF_STRING			'\0'


int main(int argc, char **argv)
{
	char *nomeArquivoOriginal = argv[1];
	char *nomeArquivoConvertido;
	tipoErros resultadoConversao;

	if (argc > NUMERO_ARGUMENTOS || argc < NUMERO_ARGUMENTOS - 1)
	{
		printf("%s\nERRO: numero de argumentos invalido! Dois tipos de uso separados por pipe: <nomeArquivoOriginal> <nomeArquivoConvertido> | <nomeArquivoOriginal>%s\n", RED, RESET);
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	if (argc == NUMERO_ARGUMENTOS) 
	{
    		nomeArquivoConvertido = argv[2];
	}	 
	
	else 
	{
    		nomeArquivoConvertido = NULL;
	}

	resultadoConversao = ConverterArquivoFormatoUnixParaFormatoDos(nomeArquivoOriginal, nomeArquivoConvertido);
	if (resultadoConversao != sucesso)
	{
		switch (resultadoConversao)
		{
			case nomeArquivoInvalido:
			printf("%s\nERRO: Nome do arquivo invalido!%s\n\n", RED, RESET);
			break;

			case tipoArquivoInvalido:
			printf("%s\nERRO: O arquivo original nao esta no formato Unix!%s\n\n", RED, RESET);
			break;

			case arquivoInvalido:
			printf("%s\nERRO: Nao foi possivel abrir o arquivo!%s\n\n", RED, RESET);
			break;

			case erroAlocacaoMemoria:
			printf("%s\nERRO: Nao foi possivel realizar alocacao de memoria!%s\n\n", RED, RESET);
			break;

			case erroGerarArquivoTemporario:
			printf("%s\nERRO: Nao foi possivel gerar o arquivo temporario!%s\n\n", RED, RESET);
			break;

			case erroRenomearArquivoSalvo:
			printf("%s\nERRO: Nao foi possivel renomear o arquivo salvo!%s\n\n", RED, RESET);
			break;

			case erroRenomearArquivoOriginal:
			printf("%s\nERRO: Nao foi possivel renomear o arquivo original!%s\n\n", RED, RESET);
			break;

			default:
			printf("%s\nERRO: Nao foi possivel executar a funcao!%s\n\n", RED, RESET);
			break;
		}

		exit(resultadoConversao);
	}

	if (argc == NUMERO_ARGUMENTOS)
	{
		printf("\n%sConversao do arquivo '%s' formato Unix para o Dos '%s' realizada com sucesso!%s\n\n", GREEN, argv[1], argv[2], RESET);
	}

	if (argc == NUMERO_ARGUMENTOS - 1)
	{
		printf("\n%sComo o segundo argumento eh NULL, um arquivo temporario foi criado a partir do '%s' com sucesso!%s\n\n", GREEN, argv[1], RESET);
	}


	return OK;
}

/* $RCSfile: aula0903.c,v $ */
