#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h" //include the contacts.h header file
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
//struct Contact contact;


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name * Contact) {
	// Contact Name Input:
	int i = 0;
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", Contact->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	i = yes();
	if (i == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", Contact->middleInitial);
		clearKeyboard();
	}
	else {
		*Contact->middleInitial = '\0';
	}
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", Contact->lastName);
	clearKeyboard();
}
// getAddress:
void getAddress(struct Address * address) {
	int flag = 0;
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	if (address->streetNumber < 0) {
		printf("Please enter the contact's street number: ");
		address->streetNumber = getInt();
	}
	printf("Please enter the contact's street name: ");
	scanf(" %41[^\n]s", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	flag = yes();
	if (flag == 1) {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		while (address->apartmentNumber < 0) {
			printf("Please enter the contact's apartment number: ");
			address->apartmentNumber = getInt();
		}
	}
	else {
		address->apartmentNumber = '\0';
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %41[^\n]s", address->city);
	clearKeyboard();
}
// getNumbers:
void getNumbers(struct Numbers * number) {
	int temp = 0;
	printf("Please enter the contact's cell phone number: ");
	//scanf(" %s", number->cell);
	getTenDigitPhone(number->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	temp = yes();
	if (temp == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(number->home);
	}
	else {
		number->home[0] = '\0';
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	temp = yes();
	if (temp == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(number->business);
	}
	else {
		number->business[0] = '\0';
	}
}

// getContact:
void getContact(struct  Contact * contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}