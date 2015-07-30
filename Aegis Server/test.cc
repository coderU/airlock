#include "Aegis.h"
#include <string.h>
#include <unistd.h>
int main(int argc,char** argv){
  char* t = strdup("I'm so awesome!\n");
  Aegis *test = new Aegis();
  test->print_attr(t,t);
  test->pre_open(t,t);
  sleep(5);
  test->pre_close(t,t);
}
