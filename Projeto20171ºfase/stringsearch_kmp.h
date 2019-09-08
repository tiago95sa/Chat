

// tamanho do padrão a procurar
#define M_KMP 6
// tamanho do dicionário
#define R_KMP 256

void KMP (char * pattern , int** dfa , int len);
int KMPsearch(char * text, int** dfa , int colunas );
int printKMPsearch(char * text, char * pat, int **dfa, int len);
void printKMP_DFA(int** dfa , int len);

void preKmp_LP(char *pat, int m, int * kmpNext);
void KMP_LP(char *pat, int m, char *str, int n);
void clientKMP_LP();

void client_strstr_bf();
char * strstr_bf(char * txt, char * pat);

void clientKMP();
void clientKMP_6nov2013();
void clientKMP_19nov2015_aulatp();
void clientKMP_14jan2016();
void clientKMP_3fev2016();
void clientKMP_6jul2016();


