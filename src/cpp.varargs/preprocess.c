// check this source code using gcc -E ${src-filename}

#define VARIABLE 3
#define PASTER(x,y) x ## _ ## y
#define EVALUATOR(x,y) PASTER(x,y)
#define NAME(func) EVALUATOR(func, VARIABLE)

#define x 100
#define FUNC01(x) x ## _ ## VARIABLE

#define FUNC_VAR00(a, b, ...) func( x_ ## __VA_ARGS__)
#define FUNC_VAR01(a, b, ...) func( ## __VA_ARGS__)
#define FUNC_VAR02(a, b, ...) func( # __VA_ARGS__)
#define FUNC_VAR03(a, b, ...) func(__VA_ARGS__)

//extern void func( 100, y, z);
//extern void func( "x, y, z");
//extern void func(100, y, z);
//extern void mine_3(char *100);

extern void FUNC01(10);
extern void FUNC_VAR00(10, 20, x, y, z);
extern void FUNC_VAR01(10, 20, x, y, z);
extern void FUNC_VAR02(10, 20, x, y, z);
extern void FUNC_VAR03(10, 20, x, y, z);
extern void NAME(mine)(char *x);
// VARIABLE is variable
