#if defined(__GNUC__) && __GNUC__ >= 3
#define NORET __attribute__((noreturn))
#else
#define NORET
#endif

void NORET Rf_error(const char *, ...);

