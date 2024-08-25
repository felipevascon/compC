/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao da funcao CalcularExponencial usando do..while
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/26 18:23:20 $
 * $Log: aula0401b.c,v $
 * Revision 1.1  2024/05/26 18:23:20  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <math.h>

#include "aula0401.h"

ld
CalcularExponencial (double basePotencia, int expoentePotencia)
{

	double termoAuxiliar;
	termoAuxiliar = 1;
	
	if (expoentePotencia == 0)
	{	
		return 1;
	}
	
	
	if (basePotencia == 0 && expoentePotencia < 0)
	{		
		return HUGE_VAL;
	}
	
	if (basePotencia == 0 && expoentePotencia > 0)
	{	
		return basePotencia;
	}
	
	
	if (basePotencia != 0 && expoentePotencia > 0)
	{
		do
		{
			termoAuxiliar = termoAuxiliar * basePotencia;
			expoentePotencia --;
		}
		while (expoentePotencia > 0);
		return termoAuxiliar;	
	}
	
	do
	{
		termoAuxiliar = termoAuxiliar * (1/basePotencia);
		expoentePotencia ++;
	}
		while (expoentePotencia < 0);
		return termoAuxiliar;	
}

/* $RCSfile: aula0401b.c,v $ */
