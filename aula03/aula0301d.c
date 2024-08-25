
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Codigo fonte da funcao CalcularTermoSerieFibonacci com while
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/13 00:22:27 $
 * $Log: aula0301d.c,v $
 * Revision 1.1  2024/05/13 00:22:27  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include "aula0301.h"

ull CalcularTermoSerieFibonacci (us numeroTermos)
{
	ull termoSeguinte;
	ull termoAuxiliarUm = 0;
	ull termoAuxiliarDois = 1;
	
	us contador = 1;

	if (numeroTermos <= 1)
	{
		return numeroTermos;
	}
	
	while (contador < numeroTermos)
	{
		termoSeguinte = termoAuxiliarUm + termoAuxiliarDois;
		termoAuxiliarUm = termoAuxiliarDois;
		termoAuxiliarDois = termoSeguinte;
		contador++;
	}
	return termoSeguinte;
}
/* $RCSfile: aula0301d.c,v $ */
