/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Prototipo das funcoes de gerar e validar numero do RG
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/23 15:50:56 $
 * $Log: aula0601.h,v $
 * Revision 1.3  2024/07/23 15:50:56  felipe.farias
 * inclusao do prototipo da funcao ValidarRg
 *
 * Revision 1.2  2024/07/19 20:03:38  felipe.farias
 * correcao do prototipo da funcao
 *
 * Revision 1.1  2024/06/24 03:19:14  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifndef _AULA0601_
#define _AULA0601_		"@(#)aula0601.h $Revision: 1.3 $"

#define COMPRIMENTO_RG		8
#define DIGITO_VERIFICADOR	1

typedef unsigned char byte;
typedef unsigned short us;
typedef enum {sucesso, argumentoRgInvalido, comprimentoRgInvalido, gerarDigitoVerificadorInvalido}

tipoErros;


tipoErros
GerarDigitosVerificadoresRg (byte[COMPRIMENTO_RG + DIGITO_VERIFICADOR] /* entrada/saida*/);



tipoErros
ValidarRg (byte[COMPRIMENTO_RG + DIGITO_VERIFICADOR] /* entrada*/);

#endif

/* $RCSfile: aula0601.h,v $ */
