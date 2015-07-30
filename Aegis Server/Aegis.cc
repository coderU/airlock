#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


class Aegis{
  char* door;
  int auth;//1 for authorized
  int time_expire;
public:
  Aegis();
  ~Aegis();
  void pre_open(char* login,char* token);
  void pre_close(char* login,char* token);
  void print_attr(char* login,char* token);
private:
  int verify(char* login,char* token);
  void open();
  void close();
};

/*****************************Public***************************/

Aegis::~Aegis(){
  free(door);
}

Aegis::Aegis(){
  door = strdup("Default");
  auth = 0;
  time_expire = 1;
}

void Aegis::pre_open(char* login,char* token){
  if( auth == 0){
    auth = verify(login,token);
  }
  //open the door
  if( auth == 1){
    open();
  }
}

void Aegis::pre_close(char* login,char* token){
  if( auth == 0 ){
    auth = verify(login,token);
  }

  if( auth == 1){
    close();
  }
}

void Aegis::print_attr(char* login,char* token){
  if( auth == 0 ){
    auth = verify(login,token);
  }

  if( auth == 1 ){
    std::cout<<door<<std::endl;
  }
}

int Aegis::verify(char* login,char* token){
  return 1;
}

void Aegis::open(){
  pid_t child_pid;
  char* open_command[5];
  open_command[0] = "sudo";
  open_command[1] = "python";
  open_command[2] = "stepper.py";
  open_command[3] = "open";
  open_command[4] = 0;
  
  child_pid = fork();
  if(child_pid == 0){
    execvp(open_command[0],open_command);
  }
    //wait(60);

  std::cout<<"Open\n";
  
  
  
  
  for( int i = 0; i < 5 ; i++){
    std::cout<<open_command[i]<<std::endl;
  }  
  
}

void Aegis::close(){
  pid_t child_pid;
  char* open_command[5];
  open_command[0] = "sudo";
  open_command[1] = "python";
  open_command[2] = "stepper.py";
  open_command[3] = "close";
  open_command[4] = 0;
  
  
  child_pid = fork();
  if(child_pid == 0){
    execvp(open_command[0],open_command);
  }
    //wait(60);

  std::cout<<"close\n";
  
  
  
  
  for( int i = 0; i < 5 ; i++){
    std::cout<<open_command[i]<<std::endl;
  }  
 
}
