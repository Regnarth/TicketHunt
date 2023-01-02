//#include <stdio.h>
#include <stdlib.h>
#include "Registracija.c"
#include "PregledNaloga.c"
#include "KreiranjeNaloga.c"
#include "SuspendovanjeNaloga.c"
#include "AktivacijaNaloga.c"

int main()
{
struct User user;
  register_user(&user);
  printf("Successfully registered user with username '%s' and password '%s'\n", user.username, user.password);
  kreirajNalog();
  suspendujNalog();
  aktivirajNalog();
  return 0;
}
