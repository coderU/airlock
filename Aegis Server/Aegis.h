class Aegis{
  char* door;
  int auth;//1 for authorized
  int time_expire;
public:
  Aegis();
  void pre_open(char* login,char* token);
  void pre_close(char* login,char* token);
  void print_attr(char* login,char* token);
private:
  int verify(char* login,char* token);
  void open();
  void close();
};
