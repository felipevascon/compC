/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Codigos fonte do nono roteiro
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/23 00:45:33 $
 * $Log: aula0901.c,v $
 * Revision 1.5  2024/08/23 00:45:33  felipe.farias
 * correcao
 *
 * Revision 1.4  2024/08/22 01:04:00  felipe.farias
 * correcao
 *
 * Revision 1.3  2024/08/22 00:16:17  felipe.farias
 * inclusao do codigo fonte da funcao ConverterArquivoFormatoDosParaFormatoUnix
 *
 * Revision 1.2  2024/08/21 05:09:58  felipe.farias
 * codigo fonte com funcao ConverterArquivoFormatoUnixParaFormatoDos incluido
 *
 * Revision 1.1  2024/08/20 23:39:39  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE			600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "aula0901.h"
#include "cores.h"

#define TAMANHO_LINHA_HEXADECIMAL	16

#define END_OF_STRING			'\0'

tipoErros ExibirConteudoArquivo(char *nomeArquivo)
{
	FILE *arquivo;
	byte entrada[TAMANHO_LINHA_HEXADECIMAL];
	size_t quantidadeBytesLidos, contador;
	int comprimentoArquivo = 0;
	ull enderecoArquivo = 0;

	if (!nomeArquivo)
	{
		return nomeArquivoInvalido;	
	}

	while (nomeArquivo[comprimentoArquivo] != END_OF_STRING)
	{
		comprimentoArquivo++;
	}

	if (comprimentoArquivo < 2 || nomeArquivo[comprimentoArquivo - 2] != '.' || nomeArquivo[comprimentoArquivo - 1] != 'c')
	{
		return tipoArquivoInvalido;
	}

	arquivo = fopen(nomeArquivo, "r");
	if (arquivo == NULL)
	{
		return arquivoInvalido;
	}

	while ((quantidadeBytesLidos = fread(entrada, sizeof(byte), TAMANHO_LINHA_HEXADECIMAL, arquivo)) > 0)
	{
		printf("\n");
		printf("%s%016llX%s | ", CYAN, enderecoArquivo, RESET);

		for (contador = 0; contador < quantidadeBytesLidos; contador++)
		{
			printf("%s%02X%s ", GREEN, entrada[contador], RESET);
		}

		for (contador = quantidadeBytesLidos; contador < TAMANHO_LINHA_HEXADECIMAL; contador++)
		{
			printf("   ");
		}

		printf("| %s", YELLOW);

		for (contador = 0; contador < quantidadeBytesLidos; contador++)
		{
			if (entrada[contador] >= 0x20 && entrada[contador] < 0x7F)
			{
				printf("%c", entrada[contador]);
			}
			else
			{
				printf(".");
			}
		}

		printf("%s", RESET);

		enderecoArquivo += quantidadeBytesLidos;
		printf("\n\n");
	}
	
	fclose(arquivo);

  	return sucesso;
}




tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, /* original */
             				   char *convertido /* convertido */)

{

	FILE *arquivoOriginal, *arquivoConvertido;
	int descritorTemporario;
	char *conteudoArquivo, nomeArquivoTemporario[TAMANHO_MAXIMO_NOME_ARQUIVO], nomeArquivoSalvo[TAMANHO_MAXIMO_NOME_ARQUIVO];
	char caracterAnterior;
	char caracterSeguinte = 0;
	time_t tempo;
	size_t tamanhoArquivo, contador;
	struct tm *dataHoraAtual;

	if (!original)
	{
		return nomeArquivoInvalido;
	}

	arquivoOriginal = fopen(original, "r");
	if (!arquivoOriginal)
	{
		return arquivoInvalido;
	}

	while ((caracterAnterior = fgetc(arquivoOriginal)) != EOF)
	{
		if (caracterAnterior == '\r')
		{
			fclose(arquivoOriginal);
			return tipoArquivoInvalido;
		}

		caracterSeguinte = caracterAnterior;
	}

	if (caracterSeguinte != '\n')
	{
		fclose(arquivoOriginal);
		return tipoArquivoInvalido;
	}


	fseek(arquivoOriginal, 0, SEEK_SET);

	fseek(arquivoOriginal, 0, SEEK_END);
	tamanhoArquivo = ftell(arquivoOriginal);
	fseek(arquivoOriginal, 0, SEEK_SET);

	conteudoArquivo = (char *)malloc(tamanhoArquivo * sizeof(char));
	if (!conteudoArquivo)
	{
		fclose(arquivoOriginal);
		return erroAlocacaoMemoria;
	}

	fread(conteudoArquivo, sizeof(char), tamanhoArquivo, arquivoOriginal);
	fclose(arquivoOriginal);


	if (!convertido)
	{
		strncpy(nomeArquivoTemporario, "convXXXXXX", sizeof(nomeArquivoTemporario));
		descritorTemporario = mkstemp(nomeArquivoTemporario);

		if (descritorTemporario == -1)
		{
			free(conteudoArquivo);
			return erroGerarArquivoTemporario;
		}
		arquivoConvertido = fdopen(descritorTemporario, "w");
  	}

	else
	{
		arquivoConvertido = fopen(convertido, "w");
	}

	if (!arquivoConvertido)
	{
		free(conteudoArquivo);
		return arquivoInvalido;
	}

	for (contador = 0; contador < tamanhoArquivo; contador++)
	{
		if (conteudoArquivo[contador] == '\n')
		{
			fputc('\r', arquivoConvertido);
		}

		fputc(conteudoArquivo[contador], arquivoConvertido);
	}

	fclose(arquivoConvertido);
	free(conteudoArquivo);

	if (!convertido)
	{
		tempo = time(NULL);
		dataHoraAtual = localtime(&tempo);
		snprintf(nomeArquivoSalvo, sizeof(nomeArquivoSalvo), "%s-backup-%04d%02d%02d_%02d%02d%02d",
		original,
		dataHoraAtual->tm_year + 1900,
		dataHoraAtual->tm_mon + 1,
		dataHoraAtual->tm_mday,
		dataHoraAtual->tm_hour,
		dataHoraAtual->tm_min,
		dataHoraAtual->tm_sec);

		if (rename(original, nomeArquivoSalvo) != 0)
		{
			return erroRenomearArquivoSalvo;
		}

		if (rename(nomeArquivoTemporario, original) != 0)
		{
			return erroRenomearArquivoOriginal;
		}
	}

	return sucesso;

}


tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, /* original */
             				   char *convertido /* convertido */)

{

	FILE *arquivoOriginal, *arquivoConvertido;
	int descritorTemporario;
	int formatoArquivoDos = 0;
	char *conteudoArquivo, nomeArquivoTemporario[TAMANHO_MAXIMO_NOME_ARQUIVO], nomeArquivoSalvo[TAMANHO_MAXIMO_NOME_ARQUIVO];
	char caracterAnterior = 0;
	char caracterSeguinte;
	time_t tempo;
	size_t tamanhoArquivo, contador;
	struct tm *dataHoraAtual;

	if (!original)
	{
		return nomeArquivoInvalido;
	}

	arquivoOriginal = fopen(original, "r");
	if (!arquivoOriginal)
	{
		return arquivoInvalido;
	}

	while ((caracterSeguinte = fgetc(arquivoOriginal)) != EOF)
	{
		if (caracterSeguinte == '\n' && caracterAnterior == '\r')
		{
			formatoArquivoDos = 1;
			break;
		}

		caracterAnterior = caracterSeguinte;
	}


	if (!formatoArquivoDos)
	{
		fclose(arquivoOriginal);
		return tipoArquivoInvalido;
	}

	fseek(arquivoOriginal, 0, SEEK_SET);

	fseek(arquivoOriginal, 0, SEEK_END);
	tamanhoArquivo = ftell(arquivoOriginal);
	fseek(arquivoOriginal, 0, SEEK_SET);

	conteudoArquivo = (char *)malloc(tamanhoArquivo * sizeof(char));
	if (!conteudoArquivo)
	{
		fclose(arquivoOriginal);
		return erroAlocacaoMemoria;
	}

	fread(conteudoArquivo, sizeof(char), tamanhoArquivo, arquivoOriginal);
	fclose(arquivoOriginal);


	if (!convertido)
	{
		strncpy(nomeArquivoTemporario, "convXXXXXX", sizeof(nomeArquivoTemporario));
		descritorTemporario = mkstemp(nomeArquivoTemporario);

		if (descritorTemporario == -1)
		{
			free(conteudoArquivo);
			return erroGerarArquivoTemporario;
		}
		arquivoConvertido = fdopen(descritorTemporario, "w");
  	}

	else
	{
		arquivoConvertido = fopen(convertido, "w");
	}

	if (!arquivoConvertido)
	{
		free(conteudoArquivo);
		return arquivoInvalido;
	}

	for (contador = 0; contador < tamanhoArquivo; contador++)
	{

		if(conteudoArquivo[contador] == '\r')
		{
			if (contador + 1 < tamanhoArquivo && conteudoArquivo[contador + 1] == '\n')
			{
				continue;
			}
		}
			fputc(conteudoArquivo[contador], arquivoConvertido);
	}

	fclose(arquivoConvertido);
	free(conteudoArquivo);

	if (!convertido)
	{
		tempo = time(NULL);
		dataHoraAtual = localtime(&tempo);
		snprintf(nomeArquivoSalvo, sizeof(nomeArquivoSalvo), "%s-backup-%04d%02d%02d_%02d%02d%02d",
		original,
		dataHoraAtual->tm_year + 1900,
		dataHoraAtual->tm_mon + 1,
		dataHoraAtual->tm_mday,
		dataHoraAtual->tm_hour,
		dataHoraAtual->tm_min,
		dataHoraAtual->tm_sec);

		if (rename(original, nomeArquivoSalvo) != 0)
		{
			return erroRenomearArquivoSalvo;
		}

		if (rename(nomeArquivoTemporario, original) != 0)
		{
			return erroRenomearArquivoOriginal;
		}
	}

	return sucesso;

}

/* $RCSfile: aula0901.c,v $ */
