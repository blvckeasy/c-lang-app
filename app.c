#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct User {
  char fullname[32];
  char username[32];
  char password[16];
  long long int contact;
  unsigned int age;
  char gender;
};

struct User users[100] = {
  { "Doniyor Jo'rabekov", "ParadoxPDT", "12345678", 998990762259 , 19, 'E'},
  { "Og'abek Mashalov", "marshal", "69749604", 998906639599, 18, 'E' },
  { "Shamsiddin Najmiddinov", "shamsiddin77", "shamsiddin21", 998998226958, 21, 'E' },
  { "Ravshan Shodiyev", "rawshun", "__mechanicus2", 998977137279, 23, 'E' },
  { "Marjona Uzganboyeva", "uolker", "helloWORLD", 998901234567, 18, 'A' },
  { "Mirjalol To'raboyev", "mirjalol_toraboyev", "m2002003", 998941541695, 20, 'E' },
  { "Bekzod Ramazonov", "bekzod0703", "998997005272", 998997005272, 23, 'E' }
};
int length = 7;

int checkUserName(char username[]) {
  for (int i = 0; i < length; i++) {
    if (strcmp(users[i].username, username) == 0) {
     return 1;
    }
  }
  return 0;
}

int checkContact(long long int contact) {
  for (int i = 0; i < length; i++) {
    if (users[i].contact == contact) {
      return 1;
    }
  }
  return 0;
}

int checkGender(char gender) {
  if (gender == 'E' || gender == 'A') {
    return 1;
  }

  return 0;
}

int checkPassword(char password[]) {
  for (int i = 0; i < strlen(password); i++) {
    if (iscntrl(password[i])) return 1;
  }
  if (strlen(password) < 4) return 1;
  return 0;
}

int checkAge(unsigned int age) {
  if (!(age > 7 && age < 100)) return 1;
  return 0;
}

struct User createUser () {
  struct User new;
  printf("fullnameni kiriting: ");
  scanf(" %[^\n]s", new.fullname);

  while(true) {
    printf("usernameni kiriting: ");
    scanf(" %s", new.username);
    if (!checkUserName(new.username)) {
      break;
    }
    puts("\n!!! bu username band!!!\n");
  }  

  while(true) {
    printf("passwordni kiriting: ");
    scanf(" %s", new.password);

    if (!checkPassword(new.password)) {
      break;
    }

    puts("!!! invalid password !!!");
  }

  while(true) {
    printf("contactni kiriting: ");
    scanf("%lld", &new.contact);

    if (!checkContact(new.contact)) {
      break;
    }

    puts("\n!!! bu contact band!!!\n");
  }

  while (true) {
    printf("yoshingizni kiriting: ");
    scanf("%d", &new.age);
  
    if (!checkAge(new.age)) {
      break;
    }

    puts("!!! invalid age !!!");
  }

  while(true) {
    printf("jinsingizni kiriting (Agar Erkak bo'lsa 'E' aks xolda 'A'): ");
    scanf(" %c", &new.gender);

    if (checkGender(new.gender)) {
      break;
    }
  }

  users[length++] = new;

  return new;
}

struct User login (char username[], char password[]) {
  struct User new = { "", "", "", 0, 0, ' ' };
  for(int i = 0; i < length; i++) {
    if (!strcmp(users[i].username, username) && !strcmp(users[i].password, password)) {
      return users[i];
    }
  }
  return new;
}

void printUser(struct User *user) {
  puts("");
  printf("fullname = %s\n", user->fullname);
  printf("username = %s\n", user->username);
  printf("contact = %lld\n", user->contact);
  printf("age = %d\n", user->age);
  printf("gender = %s\n", user->gender == 'E' ? "Erkak" : user->gender == 'A' ? "Ayol" : "");
  puts("");
}

int main() {
  system("cls");
  
  char selection[32];

  printf("login yoki registationlardan birini tanlang: ");
  scanf(" %s", selection);

  if (!strcmp(selection, "login")) {
    char username[32];
    char password[16];
    
    printf("Usernameni kiriting: ");
    scanf(" %s", username);

    printf("Passwordni kiriting: ");
    scanf(" %s", password);
    
    struct User user = login(username, password);
    if (user.contact) {
      printUser(&user);
    } else {
      printf("ivalid user");
    }
  } else if (!strcmp(selection, "registration")) {
    struct User newuser = createUser();
    printUser(&newuser);
    puts("");

    newuser = createUser();
    printUser(&newuser);
  } else {
    printf("invalid request");
  }
  
  return 0;
}