/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao da funcao GerarDigitosVerificadoresRg
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/23 15:50:56 $
 * $Log: aula0601.c,v $
 * Revision 1.3  2024/07/23 15:50:56  felipe.farias
 * implementacao da funcao ValidarRg
 *
 * Revision 1.2  2024/07/19 20:03:38  felipe.farias
 * correcao da implementacao da funcao
 *
 * Revision 1.1  2024/06/24 03:19:14  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include "aula0601.h"


tipoErros
GerarDigitosVerificadoresRg (byte numeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR])

{
	us contadorRg, resto, digitoVerificador;
	us peso = 2;
	us soma = 0;

	if(!numeroRg)
	{
		return argumentoRgInvalido;
	}

	for(contadorRg = 0; contadorRg < COMPRIMENTO_RG; contadorRg++)
	{
		if(numeroRg[contadorRg] < '0' || numeroRg[contadorRg] > '9')
		{
			return comprimentoRgInvalido;
		}

		soma += (numeroRg[contadorRg] - '0') * peso;
		peso++;
	}
	
	resto = (soma % 11);
	digitoVerificador = (11 - resto);

	if(digitoVerificador == 10)
	{
	
		numeroRg[COMPRIMENTO_RG] = 'X';

	}

	else if(digitoVerificador == 11)
	{

		numeroRg[COMPRIMENTO_RG] = '0';

	}

	else
	{
		numeroRg[COMPRIMENTO_RG] = (digitoVerificador + '0');
	}

	return sucesso;

}



tipoErros
ValidarRg (byte numeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR] /* entrada*/)

{

	us contadorRg;
	tipoErros resultadoDigitoVerificadorRg;

	if(!numeroRg)
	{
		return argumentoRgInvalido;
	}


	byte validarNumeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR];

	for(contadorRg = 0; contadorRg < COMPRIMENTO_RG; contadorRg++)
	{
		validarNumeroRg[contadorRg] = numeroRg[contadorRg];
	}	


	resultadoDigitoVerificadorRg = GerarDigitosVerificadoresRg(validarNumeroRg);

	if(resultadoDigitoVerificadorRg != sucesso)
	{
		return resultadoDigitoVerificadorRg;
	}


	if(validarNumeroRg[COMPRIMENTO_RG] != numeroRg[COMPRIMENTO_RG])
	{
		return gerarDigitoVerificadorInvalido;
	}

	return sucesso;

}
/* $RCSfile: aula0601.c,v $ */
