
/**********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Codigo fonte da funcao CalcularTermoSerieFibonacci com for
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/11 20:56:35 $
 * $Log: aula0301c.c,v $
 * Revision 1.1  2024/05/11 20:56:35  felipe.farias
 * Initial revision
 *
 *
 **********************************************************************************/

#include "aula0301.h"

ull CalcularTermoSerieFibonacci (us numeroTermos)
{
	ull termoSeguinte; 
	ull termoAuxiliarUm =0;
	ull termoAuxiliarDois = 1;
	us contador;

	for(contador = 2; contador <=numeroTermos; contador++)
	{	
		termoSeguinte = termoAuxiliarUm + termoAuxiliarDois;
		termoAuxiliarUm = termoAuxiliarDois;
		termoAuxiliarDois = termoSeguinte;
	
	}
	
	return termoAuxiliarDois;
}


/* $RCSfile: aula0301c.c,v $ */
