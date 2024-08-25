/**********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Codigo fonte da funcao CalcularTermoSerieFibonacci com recursividade
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/11 16:38:32 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2024/05/11 16:38:32  felipe.farias
 * Initial revision
 *
 *
 **********************************************************************************/

#include "aula0301.h"

ull CalcularTermoSerieFibonacci (us numeroTermos)
{
	
	if (numeroTermos <= 1)
		return numeroTermos;
	else
		return CalcularTermoSerieFibonacci (numeroTermos - 1) + CalcularTermoSerieFibonacci (numeroTermos - 2);
}


/* $RCSfile: aula0301a.c,v $ */
