/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Prototipo das funcoes de codificar e decodificar bases
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/13 00:34:52 $
 * $Log: aula0801.h,v $
 * Revision 1.6  2024/08/13 00:34:52  felipe.farias
 * prototipo das funcoes codificar e decodificar bases
 *
 * Revision 1.5  2024/08/08 03:47:20  felipe.farias
 * prototipo das funcoes atualizado com a funcao CodificarBase64
 *
 * Revision 1.4  2024/08/06 22:13:07  felipe.farias
 * prototipo da funcao DecodificarBase32 add
 *
 * Revision 1.3  2024/08/02 04:46:18  felipe.farias
 * prototipo da funcao atualizado para a inclusao da funcao codificarBase32
 *
 * Revision 1.2  2024/07/30 22:24:33  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/07/28 18:43:43  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifndef _AULA08_
#define _AULA08_		"@(#)aula0801.h $Revision: 1.6 $"

#define VALOR_BYTE		255

typedef unsigned char byte;
typedef unsigned short us;
typedef unsigned long ul;
typedef unsigned long long ull;

typedef enum {sucesso, entradaByteInvalida, saidaPacoteInvalido, comprimentoInvalido, entradaNaoParInvalido, nibbleAltoInvalido, nibbleBaixoInvalido, baseInvalida, entradaInvalida, finalLinhaInvalido}

tipoErros;




tipoErros
CodificarBase16 (byte *,  	/* (E) */
		 ull,  		/* (E) */
		 char * );	/* (S) */

tipoErros
DecodificarBase16 (char *,	/* (E) */
		   byte *,	/* (S) */
		   ull * );	/* (S) */




typedef enum {basico, estendido}

tipoAlfabetoBase32;



typedef enum {desabilitado, habilitado}

tipoFinalLinha;


typedef enum {basico64, seguro} /*precisei usar basico64 em vez de basico conforme eh pedido no roteiro pois a repeticao do termo basico gera warning*/

tipoAlfabeto64;



tipoErros
CodificarBase32 (byte *,  		/* (E) */
		 ull,  			/* (E) */
		 tipoAlfabetoBase32,	/* (E) */
		 char * );		/* (S) */

tipoErros
DecodificarBase32 (char *,		/* (E) */
		   tipoAlfabetoBase32,	/* (E) */
		   byte *, 		/* (S) */
		   ull * );		/* (S) */

tipoErros
CodificarBase64 (byte *,  		/* (E) */
		 ull,  			/* (E) */
		 tipoFinalLinha,	/* (E) */
		 tipoAlfabeto64,	/* (E) */
		 char * );		/* (S) */

tipoErros
DecodificarBase64 (char *,		/* (E) */
		   tipoFinalLinha,	/* (E) */
		   tipoAlfabeto64,	/* (E) */
		   byte *, 		/* (S) */
		   ull * );		/* (S) */

#endif

/* $RCSfile: aula0801.h,v $ */
