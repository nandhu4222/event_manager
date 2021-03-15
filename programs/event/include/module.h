#define IS_DIGIT(n) (n>=48 && n<=57)?1:0
#define SET_BIT(val,pos) (val|=(1<<pos))
#define CHECK_BIT(val,pos) (val & (1<<pos))

typedef void (*fnptr)(int);

void module_init(int);

fnptr get_funcptr(int);

void printModule1(int);
void printModule2(int);
void printModule3(int);
void printModule4(int);
void printModule5(int);

void module_deinit(void);
