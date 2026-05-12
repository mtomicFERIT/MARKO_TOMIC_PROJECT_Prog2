//// SUBMENUS.C
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <corecrt_search.h>
//#include <corecrt.h>
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"

enum startMenu {EXIT, AREG, LOGIN, LOGOUT, DELETE, ADEACT, ACONFIG, MEM_ERASE, T_CLEAR, T_RUNTIME}OPTIONS;

void menuMain() {
	int selection = 0;
	printf(">Loading... \n");
	printf(">MAIN MENU ------------------------------------------------ \n");
	printf("\n");
	printf("\t %d - Exit \n", EXIT);
	printf("\t %d - Register new account \n", AREG);
	printf("\t %d - Log into an already existing account \n", LOGIN);
	printf("\t %d - Log out of your account \n", LOGOUT);
	printf("\t %d - Delete your account \n", DELETE);
	printf("\t %d - Deactivate account \n", ADEACT);
	printf("\t %d - Configure account settings \n", ACONFIG);
	printf("\t %d - Delete all acounts \n", MEM_ERASE);
	printf("\t %d - Refresh page \n", T_CLEAR);
	printf("\t %d - Total time spent on app \n", T_RUNTIME);
	printf("\n");
	printf(">MAIN MENU ------------------------------------------------ \n");
	printf("\n");
	printf(">Please input a number to select an action: \t");

	do {
		scanf("%d", &selection);
		if (selection < 0 || selection >= 10) {
			printf(">Selection cannot be decimal or negative.\n");
			printf(">Selection must be in the range from 0 to 9.\n");
			printf(">Please input a new number to select an action: \t");
		}
	} while (selection < 0 || selection >= 10);

	printf(">Selection memorised.\n");
	printf(">Option selected: %d\n", selection);

	checkSelection(selection);

}

void clearHistory() {

}

void backToMenu() {

}