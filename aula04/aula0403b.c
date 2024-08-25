/*************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao CalcularSerieHarmonicaAlternada com exponencial do..while
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/27 03:35:53 $
 * $Log: aula0403b.c,v $
 * Revision 1.1  2024/05/27 03:35:53  felipe.farias
 * Initial revision
 *
 *
 *************************************************************************************/
#include "aula0401.h"


float
CalcularSerieHarmonicaAlternada(unsigned short int percentualSerieHarmonica)
{
	
	float termoAuxiliar = 0;
	
	if (percentualSerieHarmonica == 0)
	{
		return termoAuxiliar;
	}	

	do
	{	
		if ((percentualSerieHarmonica % 2) == 0)
		{
			termoAuxiliar = termoAuxiliar - 1/((float)CalcularExponencial (percentualSerieHarmonica, percentualSerieHarmonica));
		}
		
		if ((percentualSerieHarmonica %2) == 1)
		{
			termoAuxiliar = termoAuxiliar + 1/((float)CalcularExponencial (percentualSerieHarmonica, percentualSerieHarmonica));
		}
		
		percentualSerieHarmonica--;
	}
	
	while(percentualSerieHarmonica > 0);
	return termoAuxiliar;
}



/* $RCSfile: aula0403b.c,v $ */
