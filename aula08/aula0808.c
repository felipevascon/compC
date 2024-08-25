/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Arquivo de testes da funcao CodificarBase64
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/14 22:08:51 $
 * $Log: aula0808.c,v $
 * Revision 1.3  2024/08/14 22:08:51  felipe.farias
 * correcao
 *
 * Revision 1.2  2024/08/14 04:57:13  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/08/14 03:12:41  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"
#include "cores.h"

typedef size_t comprimentoObjeto;

#define NUMERO_ARGUMENTOS_TERMINAL			4

#define OK						0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define CARACTER_ESPECIAL_ALFABETO_INVALIDO		2
#define DIGITO_ALFABETO_INVALIDO			3
#define ALFABETO_NEGATIVO				4
#define ERRO_ALOCACAO_MEMORIA				5

#define END_OF_STRING					'\0'

int
main (int argc, char **argv)
{

	FILE *arquivoCodificado, *arquivoGerado;
  	byte *memoriaTemporariaByte;
  	char *memoriaTemporariaChar, *validacao;
  	ull tamanhoEntrada, tamanhoSaida;
  	tipoAlfabeto64 tipoAlfabetoEntrada;
  	tipoErros pacoteCodificado;
  	comprimentoObjeto tamanhoArquivo;

	if (argc != NUMERO_ARGUMENTOS_TERMINAL)
	{
		printf ("\n%sERRO: O numero de argumentos passados no terminal invalido! Uso: <tipoAlfabeto> <arquivoCodificado> <arquivoAgerar>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}


	if (argv[1][0] == '-')
	{
		printf ("\n%sERRO: O alfabeto esta negativo. Digite apenas o inteiro 0 (basico) ou 1 (seguro)!%s\n\n", RED, RESET);
		exit (ALFABETO_NEGATIVO);
	}

	tipoAlfabetoEntrada = (tipoAlfabeto64) strtoul(argv[1], &validacao, 10);

	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\' do argumento do tipo do alfabeto!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_ESPECIAL_ALFABETO_INVALIDO);
	}

	if(tipoAlfabetoEntrada != basico64 && tipoAlfabetoEntrada != seguro)
	{
		printf ("\n%sERRO: Argumento destinado ao tipo do alfabeto invalido. Digite apenas o inteiro 0 (basico) ou 1 (seguro)!%s\n\n", RED, RESET);
		exit (DIGITO_ALFABETO_INVALIDO);
	}

	
	arquivoCodificado = fopen(argv[2], "r");
	if (arquivoCodificado == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo codificado para que seja possivel gerar o novo arquivo!%s\n\n", RED, RESET);
		exit (entradaInvalida);
	
	}

	fseek(arquivoCodificado, 0, SEEK_END);
	tamanhoArquivo = ftell(arquivoCodificado);
	fseek(arquivoCodificado, 0, SEEK_SET);

	memoriaTemporariaByte = (byte *)malloc(tamanhoArquivo * sizeof(byte));
	if (memoriaTemporariaByte == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo codificado para que seja possivel gerar o novo arquivo!%s\n\n", RED, RESET);
		fclose (arquivoCodificado);
		exit (ERRO_ALOCACAO_MEMORIA);
	
	}

	fread(memoriaTemporariaByte, 1, tamanhoArquivo, arquivoCodificado);
	fclose(arquivoCodificado);

	tamanhoEntrada = tamanhoArquivo;
	tamanhoSaida = 4 * ((tamanhoEntrada + 2) / 3);

	memoriaTemporariaChar = (char *)malloc((tamanhoSaida + 1) * sizeof(char));
	if (memoriaTemporariaChar == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo codificado para que seja possivel gerar o novo arquivo!%s\n\n", RED, RESET);
		free (memoriaTemporariaByte);
		exit (ERRO_ALOCACAO_MEMORIA);
	
	}

	pacoteCodificado = CodificarBase64(memoriaTemporariaByte, tamanhoEntrada, desabilitado, tipoAlfabetoEntrada, memoriaTemporariaChar);

	if (pacoteCodificado != sucesso)
	{
		free(memoriaTemporariaByte);
		free(memoriaTemporariaChar);

		switch (pacoteCodificado)
		{

			case entradaByteInvalida:
			printf("\n%sERRO: Entrada invalida!%s\n\n", RED, RESET);
			break;

			case saidaPacoteInvalido:
			printf("\n%sERRO: Saida invalida!%s\n\n", RED, RESET);
			break;

			default:
			printf("\n%sERRO: Falha ao gerar arquivo!%s\n\n", RED, RESET);
			break;

		}

		exit (pacoteCodificado);
	}

	arquivoGerado = fopen(argv[3], "w");
	if (arquivoGerado == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo a ser gerado!%s\n\n", RED, RESET);
		free (memoriaTemporariaByte);
		free (memoriaTemporariaChar);
		exit (saidaPacoteInvalido);

	}

	fwrite(memoriaTemporariaChar, 1, tamanhoSaida, arquivoGerado);
	fclose(arquivoGerado);
	free(memoriaTemporariaByte);
	free(memoriaTemporariaChar);

	return OK;
}

/* $RCSfile: aula0808.c,v $ */
