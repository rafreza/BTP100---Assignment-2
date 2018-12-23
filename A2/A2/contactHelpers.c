#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}
// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}
// getInt:
int getInt(void)
{
	char x = '\0';
	int num;
	while (x != '\n')
	{
		scanf("%d%c", &num, &x);
		if (x != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	}
	return num;
}
// getIntInRange:
int getIntInRange(int min, int max)
{
	{
		int num;
		do {
			num = getInt();
			if (num < min || num > max)
			{
				printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
			}
		} while (num < min || num > max);
		return num;
	}
}
// yes:
int yes(void)
{
	char NL = 'x';
	char yorn = 'a';
	int check = 2;
	do {
		scanf("%c%c", &yorn, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else {
			if (yorn == 'y' || yorn == 'Y') {
				check = 1;
			}
			else if (yorn == 'n' || yorn == 'N') {
				check = 0;
			}
		}
	} while (check == 2);
	return check;
}

// menu:
int menu(void)
{
	int menu;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	do {
		menu = getInt();
		if (menu > 6 || menu < 0) {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	} while (menu > 6 || menu < 0);
	return menu;
}
// contactManagerSystem:
void contactManagerSystem(void)
{
	int num, g = 0;

	struct Contact contact[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" }
		},
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" }
		},
	{
		{ "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" }
		},
	{
		{ "Sasha",{ '\0' }, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" }
		}
	};

	while (g == 0)
	{
		num = menu();
		switch (num)
		{
		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			g = yes();
			printf("\n");
			break;
		default:
			break;
		}
		if (g == 1)
			printf("Contact Management System: terminated\n");
	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

void getTenDigitPhone(char telNum[11])
{
	int i = 0;
	int Done = 0;
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();
		Done = 0;
		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
		{
			for (i = 0; i < 10; i++)
				if (telNum[i] >= '0' && telNum[i] <= '9')
					Done = Done + 1;

			if (Done == 10)
				needInput = 0;
			else
				printf("Enter a 10-digit phone number: ");
		}
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNumber[])
{
	int i = 0;
	int index = -1;

	for (i = 0; i < size && index == -1; i++)
	{
		if (!strcmp(cellNumber, contacts[i].numbers.cell))
			index = i;
	}
	return index;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int fullContacts)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", fullContacts);
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *presentContact)
{
	if (strlen(presentContact->name.middleInitial) != 0) {
		printf(" %s %s %s\n", presentContact->name.firstName, presentContact->name.middleInitial, presentContact->name.lastName);
	}
	else {
		printf(" %s %s\n", presentContact->name.firstName, presentContact->name.lastName);
	}

	printf("    C: %10s   H: %10s   B: %10s\n", presentContact->numbers.cell, presentContact->numbers.home, presentContact->numbers.business); // Contact Phone Numbers

	printf("       %d %s, ", presentContact->address.streetNumber, presentContact->address.street); // Contact Full Address
	if (presentContact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", presentContact->address.apartmentNumber);
	}
	printf("%s, %s\n", presentContact->address.city, presentContact->address.postalCode);
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact completeContacts[], int size)
{
	int i = 0;
	int j = 0;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (*completeContacts[i].numbers.cell > 0) {
			displayContact(&completeContacts[i]);
			++j;
		}
	}
	displayContactFooter(j);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact completeContacts[], int size)
{
	char search[11] = { 0 };
	int index = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(search);
	index = findContactIndex(completeContacts, size, search);
	if (index != -1) {
		printf("\n");
		displayContact(&completeContacts[index]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n\n");
	}
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact completeContacts[], int size)
{
	int i = 0;
	int done = 0;
	for (i = 0; i < size; i++) {
		if (strlen(completeContacts[i].numbers.cell) == 0) {
			printf("\n");
			getContact(&completeContacts[i]);
			printf("--- New contact added! ---\n\n");
			done = 1;
		}
	}
	if (done == 0) {
		printf("\n*** ERROR: The contact list is full! ***\n\n");
	}

}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact completeContacts[], int size)
{
	char search[11] = { 0 };
	int index = 0;
	int choice = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(search);
	index = findContactIndex(completeContacts, size, search);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		printf("\nContact found:\n");

		displayContact(&completeContacts[index]);
		printf("\nDo you want to update the name? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getName(&completeContacts[index].name);
		}
		printf("Do you want to update the address? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getAddress(&completeContacts[index].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getNumbers(&completeContacts[index].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact completeContacts[], int size)
{
	char search[11] = { 0 };
	int index = 0;
	int choice = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(search);
	index = findContactIndex(completeContacts, size, search);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&completeContacts[index]);
	}
	printf("\nCONFIRM: Delete this contact? (y or n): ");
	choice = yes();
	if (choice == 1) {
		completeContacts[index].numbers.cell[0] = '\0';
		printf("--- Contact deleted! ---\n\n");
	}
	else {
		printf("\n");
	}
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact sort[], int size)
{
	printf("\n\n<<< Feature to sort is unavailable >>>\n\n");
}