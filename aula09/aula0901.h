/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Prototipo das funcoes do nono roteiro
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/22 00:16:17 $
 * $Log: aula0901.h,v $
 * Revision 1.3  2024/08/22 00:16:17  felipe.farias
 * inclusao do prototipo da funcao ConverterArquivoFormatoDosParaFormatoUnix
 *
 * Revision 1.2  2024/08/21 05:09:58  felipe.farias
 * propotipo das atualizado com funcao ConverterArquivoFormatoUnixParaFormatoDos
 *
 * Revision 1.1  2024/08/20 23:39:39  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifndef _AULA0901_
#define _AULA0901_ 			"@(#)aula0901.h $Revision: 1.3 $"

#define TAMANHO_MAXIMO_NOME_ARQUIVO 	256

typedef unsigned long ul;
typedef unsigned long long ull;
typedef unsigned char byte;

typedef enum
{
  sucesso,
  nomeArquivoInvalido,
  tipoArquivoInvalido,
  arquivoInvalido,
  erroGerarArquivoTemporario,
  erroRenomearArquivoOriginal,
  erroRenomearArquivoSalvo,
  erroAlocacaoMemoria
} tipoErros;




tipoErros
ExibirConteudoArquivo(char * /* (E) */);


tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *, /* original */
             				   char *  /* convertido */);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix(char * /* original */,
                                          char * /*convertido */);


#endif
/* $RCSfile: aula0901.h,v $ */
