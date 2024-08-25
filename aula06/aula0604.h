/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: prototipo das funcoes alterados de bytes para string
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/24 00:28:22 $
 * $Log: aula0604.h,v $
 * Revision 1.1  2024/07/24 00:28:22  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifndef _AULA0604_
#define _AULA0604_		"@(#)aula0604.h $Revision: 1.1 $"

#define COMPRIMENTO_RG		8
#define DIGITO_VERIFICADOR	1

typedef unsigned char byte;
typedef unsigned short us;
typedef enum {sucesso, argumentoRgInvalido, comprimentoRgInvalido, gerarDigitoVerificadorInvalido}

tipoErros;


tipoErros
GerarDigitosVerificadoresRg (char * /*entrada*/, char * /*saida*/);



tipoErros
ValidarRg (char *);

#endif

/* $RCSfile: aula0604.h,v $ */
