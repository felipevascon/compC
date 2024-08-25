/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao da funcao CalcularExponencial usando for
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/26 19:02:53 $
 * $Log: aula0401c.c,v $
 * Revision 1.1  2024/05/26 19:02:53  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <math.h>

#include "aula0401.h"

ld
CalcularExponencial (double basePotencia, int expoentePotencia)
{

	double primeiroContador, segundoContador, termoAuxiliar;

	termoAuxiliar = basePotencia;
	
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
		for (primeiroContador = 1; primeiroContador < expoentePotencia; primeiroContador++)
		{
			termoAuxiliar = termoAuxiliar * basePotencia;
		}
		return termoAuxiliar;
	}
	
	if (basePotencia != 0 && expoentePotencia < 0)
	{
		for (segundoContador = -1; segundoContador > expoentePotencia; segundoContador--)
		{
			termoAuxiliar = termoAuxiliar * basePotencia;
		}
		return 1/termoAuxiliar;
	}
	
	return termoAuxiliar;
		
}
/* $RCSfile: aula0401c.c,v $ */
