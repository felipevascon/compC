/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: implementacao das funcoes do RG substituindo bytes por string
 *
 * $Author: felipe.farias $
 * $Date: 2024/07/24 03:33:59 $
 * $Log: aula0604.c,v $
 * Revision 1.2  2024/07/24 03:33:59  felipe.farias
 * implementacao funcao validarRg com string
 *
 * Revision 1.1  2024/07/24 00:28:22  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <string.h>

#include "aula0604.h"

#define END_OF_STRING	'\0'

tipoErros
GerarDigitosVerificadoresRg (char *entradaNumeroRg, char *saidaDigitoVerificador)

{
	us contadorRg, resto, digitoVerificador;
	us peso = 2;
	us soma = 0;

	if(!entradaNumeroRg || !saidaDigitoVerificador)
	{
		return argumentoRgInvalido;
	}

	for(contadorRg = 0; contadorRg < COMPRIMENTO_RG + 2; contadorRg++)
	{
		if(entradaNumeroRg[contadorRg] == '.')
		{
			contadorRg++;
		}

		if(entradaNumeroRg[contadorRg] < '0' || entradaNumeroRg[contadorRg] > '9')
		{
			return comprimentoRgInvalido;
		}

		soma += ((us) entradaNumeroRg[contadorRg] - '0') * peso;
		peso++;
	}
	
	resto = (soma % 11);
	digitoVerificador = (11 - resto);

	if(digitoVerificador == 10)
	{
	
		*saidaDigitoVerificador = 'X';

	}

	else if(digitoVerificador == 11)
	{

		*saidaDigitoVerificador = '0';

	}

	else
	{

		*saidaDigitoVerificador = (digitoVerificador + '0');

	}

	return sucesso;

}



tipoErros
ValidarRg (char *validarNumeroRg /* entrada*/)

{

	us contadorRg;
	tipoErros resultadoDigitoVerificadorRg;
	char validacao;
	char entradaNumeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR + 3];

	if(!validarNumeroRg)
	{
		return argumentoRgInvalido;
	}

	if(strlen(validarNumeroRg) != COMPRIMENTO_RG + DIGITO_VERIFICADOR + 3)
	{
		return comprimentoRgInvalido;
	}


	for(contadorRg = 0; contadorRg < COMPRIMENTO_RG + 2; contadorRg++)
	{
		entradaNumeroRg[contadorRg] = validarNumeroRg[contadorRg];
	}	

	entradaNumeroRg[COMPRIMENTO_RG + 2] = END_OF_STRING;

	resultadoDigitoVerificadorRg = GerarDigitosVerificadoresRg(entradaNumeroRg, &validacao);

	if(resultadoDigitoVerificadorRg != sucesso)
	{
		return resultadoDigitoVerificadorRg;
	}

	if(validacao != validarNumeroRg[COMPRIMENTO_RG + DIGITO_VERIFICADOR + 2])
	{
		return gerarDigitoVerificadorInvalido;
	}

	return sucesso;

}


/* $RCSfile: aula0604.c,v $ */
