//#include <stdio.h>
#include <stdlib.h>
#include "Registracija.c"
#include "KreiranjeNaloga.c"

int main()
{
struct User user;
  register_user(&user);
  printf("Successfully registered user with username '%s' and password '%s'\n", user.username, user.password);
  kreirajNalog();
  return 0;
}