//// SUBMENUS.C
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//// LIBRARIES
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"
//// DEFAULT
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_search.h>
#include <io.h>

//// GLOBAL VARIABLES // SUBMENUS.C
// MACROS
#define MAX_P 32
//
int accQuantity = 0;
extern PROFILE* activeSession;
extern FILE* textFilePointer;
extern PROFILE profileArray[32];
extern PROFILE* pArrayPTR;
extern PROFILE* targetAccount;
extern PROFILE** activeDelSession;

enum startMenu { EXIT, AREG, LOGIN, LOGOUT, DELETE, SORTSEARCH, FILE_MENU }OPTIONS;

void menuMain() {
	int selection = 0;
	isPointerValidProfile(pArrayPTR);

	printf(">Loading... \n");
	printf(">MAIN MENU ------------------------------------------------ \n");
	printf("\n");
	printf("\t %d - Exit \n", EXIT);
	printf("\t %d - Register new account \n", AREG);
	printf("\t %d - Log into an already existing account \n", LOGIN);
	printf("\t %d - Log out of your account \n", LOGOUT);
	printf("\t %d - Delete your account (this will also free its memory) \n", DELETE);
	printf("\t %d - Sort & search profiles \n", SORTSEARCH);
	printf("\t %d - Access storage text file menu \n", FILE_MENU);
	printf("\n");
	printf(">MAIN MENU ------------------------------------------------ \n");
	printf("\n");
	printf(">REMINDER: Register at least one account before choosing any option other than Exit.\n");
	printf(">REMINDER: Remember to sort accounts before searching!\n");
	printf("\n");
	printf(">Please input a number to select an action: \t");

	do {
		while (1) {
			if (scanf("%d", &selection) != 1) {
				printf(">Please enter a number!\n");
				while (getchar() != '\n');
				continue;
			}
			else if (selection < 0 || selection > 6) {
				printf(">Selection cannot be decimal or negative!\n");
				printf(">Selection must be in range from 0 to 6.\n");
				printf(">Please input a new number to select an action: \t");
			}
			break;
		}
	} while ((selection < 0 || selection > 6));

	printf("\n>Selection memorised.\n");
	printf(">Option selected: %d\n", selection);

	checkSelection(selection, activeSession, pArrayPTR, accQuantity);
}

int queryMainMenu() {
	char queryAnswer = '0';
	printf("Would you like to return to the main menu? Type 'Y' for yes.\n");
	scanf(" %c", &queryAnswer);
	if (queryAnswer == 'Y' || queryAnswer == 'y') {
		menuMain();
		return 0;
	}
	else {
		return 1;
	}
}

void displayAccountMenu(PROFILE* profileArray, int numAccounts) {
	int di;
	int flagLastProfile = 0;
	printf("\n");
	printf("ACCOUNT MENU -------------------------------------");
	printf("\n");
	printf(">CURRENTLY AVAILABLE ACCOUNTS: \n");
	if (numAccounts <= 0) {
		printf(">There are no accounts to choose from.\n");
		printf(">You must register some accounts first!\n");
	}
	else {
		for (di = 0; di < numAccounts; di++) {
			printAccount(&profileArray[di]);
		}
		printf("ACCOUNT MENU -------------------------------------");
	}
	printf("\n");
	printf("ACCOUNT MENU -------------------------------------");
}

enum txtMenu { RENAME, CLEAN_ALL };

void fileMenu(FILE* txt, const char* oldFilename) {
	int fSelect = 0;

	printf("\n");
	printf(">FILE MENU ---------------------------------------\n");
	printf("\n");
	printf("%d - Rename file \n", RENAME);
	printf("%d - Clean the contents of the file \n", CLEAN_ALL);
	printf("\n");
	printf(">FILE MENU ---------------------------------------\n");
	printf("\n");
	printf("Which action do you want to perform? Select one: ");

	while (1) {
		if (scanf("%d", &fSelect) != 1) {
			printf(">Please enter a number!\n");
			while (getchar() != '\n');
			continue;
		}
		break;
	}

	switch (fSelect) {

	case RENAME: {
		printf(">Renaming file '%s'...\n", oldFilename);
		txt = renameFileTxt(txt, oldFilename);
		break;
	}
	case CLEAN_ALL: {
		printf(">Cleaning file contents...\n");
		clearFileTxt(txt);
		break;
	}
	default: {
		printf(">No option was selected!\n");
		break;
	}
	}
}
