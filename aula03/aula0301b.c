
/**********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Codigo fonte da funcao CalcularTermoSerieFibonacci com do-while
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/11 20:33:39 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2024/05/11 20:33:39  felipe.farias
 * Initial revision
 *
 *
 **********************************************************************************/

#include "aula0301.h"

ull CalcularTermoSerieFibonacci (us numeroTermos)
{
	
	ull termoSeguinte;
	ull termoAuxiliarUm = 1;
	ull termoAuxiliarDois = 0;
	ull contador = 2;
	
	if(numeroTermos <= 1)
	{
		return numeroTermos;
	}
	
	do
	{
		
		termoSeguinte = termoAuxiliarUm + termoAuxiliarDois;
		termoAuxiliarDois = termoAuxiliarUm;
		termoAuxiliarUm = termoSeguinte;
		contador++; 

	}
	while (contador <= numeroTermos);
	return termoAuxiliarUm;
}
/* $RCSfile: aula0301b.c,v $ */
