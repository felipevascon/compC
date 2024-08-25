/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Arquivo de testes da funcao ExibirConteudoArquivo
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/20 23:39:39 $
 * $Log: aula0902.c,v $
 * Revision 1.1  2024/08/20 23:39:39  felipe.farias
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

#include "aula0901.h"
#include "cores.h"

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define END_OF_STRING			'\0'


int main(int argc, char **argv)
{
	tipoErros resultanteExibirConteudo;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf("%s\nERRO: numero de argumentos invalido! Uso: <nomeArquivo>%s\n\n", RED, RESET);
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	resultanteExibirConteudo = ExibirConteudoArquivo(argv[1]);


	if (resultanteExibirConteudo != sucesso)
	{
		switch (resultanteExibirConteudo)
		{
			case nomeArquivoInvalido:
			printf("%s\nERRO: Nome do arquivo invalido!%s\n\n", RED, RESET);
			break;

			case tipoArquivoInvalido:
			printf("%s\nERRO: Arquivo esta no formato invalido, o arquivo deve estar em .c!%s\n\n", RED, RESET);
			break;

			case arquivoInvalido:
			printf("%s\nERRO: Nao foi possivel abrir o arquivo!%s\n\n", RED, RESET);
			break;
			
			default:
			printf("%s\nERRO: Nao foi possivel gerar a funcao que exibe o conteudo do arquivo!%s\n\n", RED, RESET);
			break;
		}

		exit(resultanteExibirConteudo);

	}

	printf("\n%sConteudo do arquivo '%s' exibido com sucesso!%s\n", WHITE, argv[1], RESET);
	return OK;
}

/* $RCSfile: aula0902.c,v $ */

