#include "projeto_funcoes.h"


time_t t;

void client_projeto_2fase()
{
    srand((unsigned) time(&t));
    char pathfile []="./data/conversa1.txt";
    char pathfile1 []="./data/conversa2.txt";
    char pathfile2 []= "./data/conversa3.txt";
    char pathfile3 []= "./data/conversa4.txt";

    CORPUS inst_menss;

    inst_menss.pfirst = NULL;
    inst_menss.size_conversa = 0;

    int count = 0;
    count = contar_linhas(pathfile);
    //printf("count = %d\n",count);
    inserir_nova_conversa_cauda(&inst_menss);

    copiar_ficheiro_para_matriz(pathfile,count,inst_menss.pfirst);

    //printf("count = %d\n",count);
    //print_mensagens_de_uma_conversa(inst_menss.pfirst);
    //print_conversa(inst_menss.pfirst);
    //printf("conversa:\n");
    //print_conversa(inst_menss.pfirst);

    inserir_nova_conversa_cauda(&inst_menss);

    // printf("\n\n\n\nnova conversa\n\n\n\n");

    CONVERSA *aux = NULL;
    aux = inst_menss.pfirst;
    while(aux->pnext!=NULL)
    {
        aux = aux->pnext;
    }
    count = contar_linhas(pathfile1);
    // printf("count = %d\n",count);
    copiar_ficheiro_para_matriz(pathfile1,count,aux);
    //printf("conversa:\n");
    //print_conversa(aux);

    inserir_nova_conversa_cauda(&inst_menss);
    //printf("\n\n\n\nnova conversa\n\n\n\n");

    aux = NULL;
    aux = inst_menss.pfirst;
    while(aux->pnext!=NULL)
    {
        aux = aux->pnext;
    }
    count = contar_linhas(pathfile2);
    //printf("count = %d\n",count);
    copiar_ficheiro_para_matriz(pathfile2,count,aux);
    //printf("conversa:\n");
    //print_conversa(aux);
    //print_mensagens_de_uma_conversa(inst_menss.pfirst);

    //utilizador_remover_conversa (&inst_menss);

    //print_todas_conversas_usando_utilizadores_para_distincao(&inst_menss);
    //utilizador_remover_mensagem(&inst_menss);


    inserir_nova_conversa_cauda(&inst_menss);
    //printf("\n\n\n\nnova conversa\n\n\n\n");

    aux = NULL;
    aux = inst_menss.pfirst;
    while(aux->pnext!=NULL)
    {
        aux = aux->pnext;
    }
    count = contar_linhas(pathfile3);
    //printf("count = %d\n",count);
    copiar_ficheiro_para_matriz(pathfile3,count,aux);

    CONVERSA *aux1 = NULL;
    aux1 = inst_menss.pfirst;
    while(aux1!=NULL)
    {
        bag_of_words_conversa(aux1);
        aux1 = aux1->pnext;
    }


//     aux1 = inst_menss.pfirst;
//     while(aux1!=NULL){
//        print_matriz(aux1->bag_of_words , aux1->linhas_bag_of_words);
//        printf("\n\n\n");
//        aux1 = aux1->pnext;
//     }

    bag_of_words_corpus(&inst_menss);
    //print_matriz(inst_menss.bag_of_words , inst_menss.linhas_bag_of_words);


    printf("tfidf de cafe = %f\n",term_frequency_inverse_document_frequency("cafe", &inst_menss));

    //numero_paragrafos(inst_menss.pfirst);


    frequencia_reutilizacao_palavra (inst_menss.pfirst, "ola");

    distancia_textual_entre_duas_palavras( inst_menss.pfirst,"ola","contigo" );

    palavras_com_possiveis_raizes_comuns(inst_menss.pfirst->bag_of_words,inst_menss.pfirst->linhas_bag_of_words, "medico");

    aux1 = inst_menss.pfirst;
    while(aux1!=NULL)
    {
        printf("Tamanho = %d\n", aux1->tamanho);
        print_matriz(aux1->utilizadores, aux1->linhas_utilizadores);
        printf("\n\n\n");
        aux1 = aux1->pnext;
    }

    printf("Ordenacao por tamanho:\n");
    ordenacao_por_tamanho(&inst_menss);
    //printf("Ordenacao por timestamp:\n");
    //ordenacao_por_timestamp(&inst_menss);
    printf("Ordenacao por importancia:\n");
    ordenacao_por_importancia(&inst_menss);

    char buff[100];
    printf("escreva uma frase :\n");
    scanf("%[^\n]s",buff);
    setbuf(stdin, NULL);
    printf("AQUI = %s\n",buff);
    distancia_entre_strings (&inst_menss, buff);


    //print_matriz(inst_menss.bag_of_words , inst_menss.linhas_bag_of_words);

    tfidf_bag_of_words_corpus(&inst_menss);

    //print_tfidf(&inst_menss);

    gravar_para_ficheiro_binario(inst_menss.pfirst);
}


void gravar_para_ficheiro_binario(CONVERSA *cv)
{
    FILE *fp;
    char* quebra = "\n";
    char* pont = ":";
    char buffer[10];
    fp = fopen("FBinario.dat","wb");
    if(fp == NULL)
    {
        printf("Erro ao abrir ficheiro\n");
        return;
    }
    int i ;

    MENSAGEM * aux = NULL;

    aux = cv->pfirst;

    while(aux!=NULL)
    {
            //printf("size of %s = %d\n",aux->utilizador , sizeof(aux->utilizador));
            fwrite(aux->utilizador,sizeof(char),strlen(aux->utilizador),fp);
            fwrite(pont,sizeof(char),strlen(pont),fp);

            for(i=0; i<aux->linhas_mensagem; i++)
            {
                //printf("mensagem = %s\n", *(aux->mensagem+i));
                fwrite(*(aux->mensagem+i), sizeof(char), strlen(*(aux->mensagem+i)),fp);
                if(i+1==aux->linhas_mensagem){
                    break;
                }
                fwrite(quebra,sizeof(char),strlen(quebra),fp);
            }
          fwrite(pont,sizeof(char),strlen(pont),fp);

          itoa (aux->tempo->dia,buffer,10);
          fwrite(buffer,sizeof(char),strlen(buffer),fp);
          fwrite(pont,sizeof(char),strlen(pont),fp);
           itoa (aux->tempo->mes,buffer,10);
          fwrite(buffer,sizeof(char),strlen(buffer),fp);
          fwrite(pont,sizeof(char),strlen(pont),fp);
           itoa (aux->tempo->ano,buffer,10);
          fwrite(buffer,sizeof(char),strlen(buffer),fp);
          fwrite(pont,sizeof(char),strlen(pont),fp);
           itoa (aux->tempo->hora,buffer,10);
          fwrite(buffer,sizeof(char),strlen(buffer),fp);
          fwrite(pont,sizeof(char),strlen(pont),fp);
           itoa (aux->tempo->minuto,buffer,10);
          fwrite(buffer,sizeof(char),strlen(buffer),fp);
            fwrite(pont,sizeof(char),strlen(pont),fp);
           itoa (aux->tempo->segundo,buffer,10);
           fwrite(buffer,sizeof(char),strlen(buffer),fp);
          fwrite(quebra,sizeof(char),strlen(quebra),fp);
          aux = aux->pnext;
    }


    fclose(fp);
}





/** \brief Função que retorna o endereço da primeira posição de um vetor que contem o numero de ocorrencias de cada palavra na mensagem . Cada indice do vetor corresponde ao indice da matriz de palavras
 *
 * \param matriz_indices - Matriz de indices de palavras que estão na matriz de palavras
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param linhas_de_indices - Tamanho de cada linha da matriz de indices
 * \param linhas_matriz_indices - Numero de linhas da matriz de indices
 * \return Retorna o endereço do primeiro elemento de um vetor onde contem o numero de ocorrencias de cada palavra na mensagem
 *
 */
int * numero_de_ocorrencias(int** matriz_indices, char** matriz_palavras, int linhas_palavras, int *linhas_de_indices, int linhas_matriz_indices)
{
    int * array_ocurrencias = NULL;
    array_ocurrencias = (int*)calloc(linhas_palavras,sizeof(int));
    int i=0,j=0;
    for(i=0; i<linhas_matriz_indices; i++)
    {
        for(j=0; j<*(linhas_de_indices+i); j++)
        {
            array_ocurrencias[matriz_indices[i][j]]++;
        }
    }
//    for(i=0; i<linhas_palavras; i++)
//    {
//        printf("|%d",array_ocurrencias[i]);
//    }
    return array_ocurrencias;
}

/** \brief Função cria a bag_of_words de uma conversa, com a junção de todas as bag-of-words de todas as mensagens e com a posterior
            iliminação de repetidos. De seguida a bag-of-words é ordenada .
 *
 * \param cv - apontador para uma estrutura conversa
 *
 */
void bag_of_words_conversa (CONVERSA *cv)
{
    MENSAGEM *auxiliar = NULL;
    int total_linhas = 0, contador = 0, i=0, contador_palavras = 0;
    auxiliar = cv->pfirst;
    while(auxiliar!=NULL)
    {
        total_linhas = total_linhas + auxiliar->linhas_bag_of_words;
        contador_palavras = contador_palavras + auxiliar->total_palavras;
        auxiliar = auxiliar->pnext;
    }
    cv->bag_of_words = criar_matriz(total_linhas);
    auxiliar = cv->pfirst;
    int len = 0;
    cv->tamanho = contador_palavras;
    while(auxiliar!=NULL)
    {

        for(i=0; i<auxiliar->linhas_bag_of_words; i++)
        {
            len = strlen(*(auxiliar->bag_of_words+i));
            *(cv->bag_of_words+contador) = (char*)malloc((len+1)*sizeof(char));
            strcpy(*(cv->bag_of_words+contador),*(auxiliar->bag_of_words+i));
            *(*(cv->bag_of_words+contador)+len)= '\0';

            contador++;
        }
        auxiliar = auxiliar->pnext;
    }

    cv->linhas_bag_of_words = contador;
    //print_matriz(cv->bag_of_words , contador);

    /*ORDENAÇÃ*/

    int lo=0, hi=cv->linhas_bag_of_words-1, d=0;

    StringElementsArray a;
    StringElementsArray aux;
    createStringElementsArrayAndFill(&a,cv->linhas_bag_of_words,cv->bag_of_words);
    createStringElementsArray(&aux,cv->linhas_bag_of_words);

    msd_sort_whithout_cutoff(&a,&aux,lo,hi,d, CHAR_8BIT_RADIX);

    cv->bag_of_words = criar_matriz_ordenada(cv->bag_of_words,&a, &cv->linhas_bag_of_words);

    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);


    //print_matriz(cv->bag_of_words , cv->linhas_bag_of_words);
}




static int distancia (const char * word1, int len1, const char * word2, int len2)
{
    int matrix[len1 + 1][len2 + 1];
    int i;
    for (i = 0; i <= len1; i++)
    {
        matrix[i][0] = i;
    }
    for (i = 0; i <= len2; i++)
    {
        matrix[0][i] = i;
    }
    for (i = 1; i <= len1; i++)
    {
        int j;
        char c1;

        c1 = word1[i-1];
        for (j = 1; j <= len2; j++)
        {
            char c2;

            c2 = word2[j-1];
            if (c1 == c2)
            {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
            {
                int delete;
                int insert;
                int substitute;
                int minimum;

                delete = matrix[i-1][j] + 1;
                insert = matrix[i][j-1] + 1;
                substitute = matrix[i-1][j-1] + 1;
                minimum = delete;
                if (insert < minimum)
                {
                    minimum = insert;
                }
                if (substitute < minimum)
                {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return matrix[len1][len2];
}





void distancia_entre_strings (CORPUS * cp, char * string)
{
    const char s[2] = " ";
    char *token;

    int d,i=0;

    token = strtok(string, s);

    while( token != NULL )
    {

        for(i=0; i<cp->linhas_bag_of_words; i++)
        {
            d = distancia(token, strlen(token), *(cp->bag_of_words+i), strlen(*(cp->bag_of_words+i)));
            printf ("The edit distance between %s and %s is %d.\n",token,*(cp->bag_of_words+i), d);
        }
        token = strtok(NULL, s);
    }

}



/** \brief Função cria a bag_of_words de um corpus, com a junção de todas as bag-of-words de todas as conversas e com a posterior
            iliminação de repetidos. De seguida a bag-of-words é ordenada .
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void bag_of_words_corpus (CORPUS *cp)
{
    CONVERSA *auxiliar = NULL;
    int total_linhas = 0, contador = 0, i=0;
    auxiliar = cp->pfirst;
    while(auxiliar!=NULL)
    {
        total_linhas = total_linhas + auxiliar->linhas_bag_of_words;
        auxiliar = auxiliar->pnext;
    }
    cp->bag_of_words = criar_matriz(total_linhas);
    auxiliar = cp->pfirst;
    int len = 0;

    while(auxiliar!=NULL)
    {

        for(i=0; i<auxiliar->linhas_bag_of_words; i++)
        {
            len = strlen(*(auxiliar->bag_of_words+i));
            *(cp->bag_of_words+contador) = (char*)malloc((len+1)*sizeof(char));
            strcpy(*(cp->bag_of_words+contador),*(auxiliar->bag_of_words+i));
            *(*(cp->bag_of_words+contador)+len)= '\0';

            contador++;
        }
        auxiliar = auxiliar->pnext;
    }

    cp->linhas_bag_of_words = contador;
    //print_matriz(cv->bag_of_words , contador);

    /*ORDENAÇÃ*/

    int lo=0, hi=cp->linhas_bag_of_words-1, d=0;

    StringElementsArray a;
    StringElementsArray aux;
    createStringElementsArrayAndFill(&a,cp->linhas_bag_of_words,cp->bag_of_words);
    createStringElementsArray(&aux,cp->linhas_bag_of_words);

    msd_sort_whithout_cutoff(&a,&aux,lo,hi,d, CHAR_8BIT_RADIX);

    cp->bag_of_words = criar_matriz_ordenada(cp->bag_of_words,&a, &cp->linhas_bag_of_words);

    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);


    // print_matriz(cp->bag_of_words , cp->linhas_bag_of_words);



}


void print_tfidf(CORPUS *cp)
{
    int i=0;
    for(i=0; i<cp->linhas_bag_of_words; i++)
    {
        printf("O tfidf de %s e = %f\n", *(cp->bag_of_words+i), *(cp->tfidf+i));
    }
}



/** \brief Função que calcula a frequencia de reutilização de uma determinada palavra
 *
 * \param cv - Apontador para uma estrutura conversa
 * \param string - Palavra para calculo da frequencia de reutilização
 *
 */
void frequencia_reutilizacao_palavra (CONVERSA *cv, char * string)
{
    MENSAGEM * aux = NULL;
    aux = cv->pfirst;

    int total_string = 0, index = 0, total_palavras;
    float frequencia = 0.0;

    while(aux !=NULL)
    {
        if(index=pesquisa_binaria(string, aux->bag_of_words, 0, aux->linhas_bag_of_words-1)!= -1)
        {
            total_string = total_string + *(aux->numero_de_ocorrencias+index);
        }
        total_palavras = total_palavras + aux->total_palavras;
        aux = aux->pnext;
    }

    frequencia = (float)total_string / (float)total_palavras;
    printf("Frequencia de reutilizacao de \"%s\" = %f\n", string, frequencia);
}




/** \brief Função para imprimir uma matriz de caracteres
 *
 * \param matriz - apontador para apontador para strings
 * \param linhas - linhas da matriz
 *
 */
void print_matriz(char ** matriz, int linhas )
{
    int i ;
    for(i=0; i<linhas; i++)
    {
        printf("%s\n",*(matriz+i));
    }
}


/** \brief Função que permite imprimir todas as mensagens de uma conversa
 *
 * \param pc - apontador para uma estrutura conversa
 *
 */
void print_mensagens_de_uma_conversa(CONVERSA *pc)
{
    printf("Utilizadores da conversa:\n");
    print_matriz(pc->utilizadores, pc->linhas_utilizadores);
    printf("-----------------------\n\n\n");
    MENSAGEM * paux = NULL;
    paux = pc->pfirst;
    while(paux!=NULL)
    {
        printf("%s:",paux->utilizador);
        print_matriz(paux->mensagem, paux->linhas_mensagem);
        print_timestamp(paux);
        printf("\n\n");
        paux = paux->pnext;
    }
}


/** \brief Função que permite inserir uma nova estrutura conversa numa lista ligada de estruturas conversas que está dentro de um corpus. A função insere à cauda.
 *
 * \param pc - apontador para uma estrutura corpus
 *
 */
void inserir_nova_conversa_cauda(CORPUS *pc)
{
    CONVERSA *pnew = criar_struct_conversa();
    if(pc->pfirst==NULL)
    {
        pc->pfirst = pnew;
        pnew->pante = NULL;
        pc->size_conversa++;
        return;
    }
    CONVERSA *paux = NULL;
    paux = pc->pfirst;
    while(paux->pnext != NULL)
    {
        paux = paux->pnext;
    }
    paux->pnext = pnew;
    pnew->pnext = NULL;
    pnew->pante = paux;
    pc->size_conversa ++;
    return;
}


/** \brief Função permite contar as linhas ( \n) de um ficheiro
 *
 * \param path - diretorio para sitio onde se encontra o ficheiro
 *
 */
int contar_linhas(char * path)
{
    FILE *fp = NULL;
    char buff[400];
    int i=0, size = 0;
    fp = fopen(path, "r");

    while(fgets(buff, 400, fp)!= NULL)
    {
        size =  strlen(buff);
        if(buff[size-2]!='!' && buff[size-2]!='.' && buff[size-2]!='?')  // como todas as frases tem que acabar com caracteres de pontuação. Se nao houver caracter de pontuacao quer dizer que é fim de mensagem
        {
            i++;
        }
    }

    fclose(fp);

    return i;
}


/** \brief Função que permite copiar varias mensagens de um ficheiro txt para uma estrutura , varios tipos de elementos. Os elementos que são
            copiados do ficheiro para a estrutura são: a sua mensagem , o timestamp da mensagem e o utilizador que a enviou . Chama outras funções para
            criar matrizes adicionais.
 *
 * \param pc - estrutura conversa onde vai ser guardada numa lista ligadas de mensagens , as mensagens e todas as informações presentes.
 * \param count - vai ser o numero de mensagens que vai ter;
 * \param path - diretorio para o sitio do ficheiro presente no computador
 *
 */
void copiar_ficheiro_para_matriz(char * path, int count, CONVERSA *pc)
{

    FILE *fp = NULL;

    int i;

    char utilizador[400];
    char data[400];
    char mensagem[400];

    if((fp=fopen(path,"r"))==NULL)
    {
        printf("...Erro abrir ficheiro %s\n",path);
        return ;
    }

    //pc->utilizadores = criar_matriz(count);
    //pc->linhas_utilizadores = count;
    int len = 0, j=0;
    const char s[2] = "\n";
    char *token;

    for(i=0; i<count; i++) // itera até ao numero de mensagens que estão presentes no ficheiro
    {

        j=0;
        //matriz = NULL;
        //printf("i=%d\n",i);
        MENSAGEM *paux = NULL;
        paux = (MENSAGEM*)malloc(sizeof(MENSAGEM));
        fscanf(fp, "%[^:] %*[:]", utilizador);
        len = strlen(utilizador);
        /* para a struct conversa */

        if(verificar_se_existe_na_matriz(pc->utilizadores, utilizador, pc->linhas_utilizadores) == 0) // verifica se o utilizador ja existe
        {
            // se nao existir
            pc->utilizadores = (char**)realloc(pc->utilizadores, (pc->linhas_utilizadores +1)*sizeof(char*));
            pc->linhas_utilizadores ++;
            pc->utilizadores[pc->linhas_utilizadores-1] = (char*)(malloc((len+1)*sizeof(char)));
            strcpy(pc->utilizadores[pc->linhas_utilizadores-1], utilizador);
            pc->utilizadores[pc->linhas_utilizadores-1][len]='\0';

        }

        /* para a struct mensagem */

        paux->utilizador = (char*)malloc((len+1)*sizeof(utilizador));

        strcpy(paux->utilizador,utilizador);
        paux->utilizador[len] = '\0';
        //printf("utilizador = %s\n", paux->utilizador);

        fscanf(fp, "%[^:] %*[:]", mensagem);
//        size =strlen(mensagem);
//        paux->tamanho = size;
        //printf("mensagem = %s\n",mensagem);

        paux->linhas_mensagem = contar_paragrafos_mensagem(mensagem);
        //printf("size = %d\n",size);

        paux->mensagem = criar_matriz(paux->linhas_mensagem);
        //matriz = criar_matriz(size);
        //paux->importancia = 50;

        token = strtok(mensagem, s);
        while( token != NULL )
        {
            //printf("token = %s\n",token);
            len = strlen(token);
            paux->mensagem[j]= (char*)malloc((len+1)*sizeof(char));
            strcpy(paux->mensagem[j], token);
            paux->mensagem[j][len] = '\0';
            token = strtok(NULL, s);
            //printf("i=%d - j = %d\n",i,j);
            j++;
        }
        //printf("j = %d\n",j);
        //print_matriz(paux->mensagem, paux->linhas_mensagem);
        //printf("paux->linhas_mensagem = %d\n", paux->linhas_mensagem);

        criar_matrizes_adicionais_de_mensagem(paux);

        fscanf(fp, "%[^\n] %*[\n]", data);
        paux->tempo = string_para_inteiro_timestamp(data);
        inserir_mensagem_conversa_cauda(pc,paux);

    }
    // atualizar a bag of words
    //printf("UTILIZADORES = %d\n",pc->linhas_utilizadores);
}

/** \brief Função para encontrar uma dada palavra com raizes comuns numa matriz de palavras
 *
 * \param matriz_palavras - Matriz onde tem todas as palavras da mensagem sem repetições e ordenada.
 * \param linhas_matriz_palavras - Numero de palavras que tem a matriz de palavras
 * \param palavra - Palavra inserida para procura
 *
 */
void palavras_com_possiveis_raizes_comuns(char ** matriz_palavras, int linhas_matriz_palavras, char * palavra)
{

    int N = strlen(palavra);
    int i=0,j=0;
    char** suffix_array = (char**)malloc((N-1)*sizeof(char*));
    char** prefix = create_prefix_array(palavra);

    int** dfa=NULL;
    // Alocação de memoria para o DFA
    dfa = (int**)malloc(R_KMP*sizeof(int*));

    for(i=0; i<R_KMP; i++)
    {
        dfa[i] = (int*)calloc(N,sizeof(int));
    }

    // preenchimento do DFA
    KMP(palavra,dfa,N);
    int controlo1 =0, controlo2 =0,len1 =0,len2=0, controlo=0;
    for(i=0; i<linhas_matriz_palavras; i++)
    {
        for(j=0; j<N-2; j++)
        {
            suffix_array[j]=&palavra[j];
            //printf("prefix[%d]=%s\n",j,prefix[j]);
            len1= strlen(suffix_array[j]);
            len2 = strlen(prefix[j]);
            controlo1 = printKMPsearch(matriz_palavras[i], suffix_array[j], dfa, len1);
            controlo2 = printKMPsearch(matriz_palavras[i], prefix[j], dfa, len2);

            if(controlo1 == 1 || controlo2 == 1)
            {
                printf("palavra com raiz comum = %s\n", matriz_palavras[i]);
                controlo = 1;
                break;
            }
        }
    }
    if(controlo==0)
    {
        printf("Nao existe palavras com raizes comuns\n");
    }

    for(i=0; i<R_KMP; i++)
    {
        free(dfa[i]);
    }
    free(dfa);
}

/** \brief Funcao para criar uma matriz de prefixos de uma dada palavra
 *
 * \param str - Palavra usada
 * \return Retorna um apontador para um apontador. Neste caso vai retorna o endereço da primeira posição da matriz de prefixos
 *
 */
char ** create_prefix_array(char *str)
{
    int N = strlen(str);
    int i ;
    char * aux = NULL;
    aux = (char*)malloc(N*sizeof(char));
    char ** prefix_array = (char**)malloc((N-1)*sizeof(char*));

    strcpy(aux, str);

    int    len = strlen(aux);

    for(i=0; i<N-1; i++)
    {
        prefix_array[i] = (char*)malloc(len*sizeof(char));
        strcpy(prefix_array[i],aux);
        aux[len-1]='\0';
        len--;
    }

    free(aux);

    return prefix_array;
}

/** \brief Função que permite veirificar se existe uma string numa matriz
 *
 * \param matriz - matriz para a procura
 * \param string - palavra que pertendemos procurar na matriz
 * \param size - numero de linhas da matriz
 * \return Retorna 1 se existir , retorna 0 se não existir
 *
 */
int verificar_se_existe_na_matriz(char** matriz, char *string, int size)
{

    if(matriz==NULL)
    {
        return 0;
    }
    int i=0, controlo = 0;
    for(i=0; i<size; i++)
    {

        controlo = strcmp(matriz[i], string);
        if(controlo == 0)
        {
            return 1;
        }
    }
    return 0;
}


/** \brief Função que preenche uma matriz com palavras
 *
 * \param matriz_mensagem - Matriz com a mensagem completa
 * \param array_tamanho_matriz_indices - Vetor para preencher com o tamanho de cada linha da matriz de indices
 * \param matriz_indices - Endereço de memória de um array de apontadores para inteiros para a posterior alocação de memoria
 * \param linhas_palavras - Numero de linhas da matriz de palavras
 * \param linhas_mensagem - Numero de linhas da matriz que contem a mensagem
 * \param matriz_palavras - Endereço de memória de um array de apontadores para strings para a posterior alocação
 *
 */
void preencher_matriz_palavras(char** matriz_mensagem,int* array_tamanho_matriz_indices, int** matriz_indices, int linhas_mensagem, int linhas_palavras, char ** matriz_palavras)
{
    char str[100];
    int i=0,index=0, len,controlo1=0, count_indices=0;
    //char s[7][7] = {' ','\n'};
    char s[] = " \n";
    char *token;

    for(i=0; i<linhas_mensagem; i++)
    {
        strcpy(str,*(matriz_mensagem+i));
        token = strtok(str,s);
        while( token != NULL )
        {
            controlo1=verificar_se_palavra_e_pontuacao(token); // verifica se o token retornado é um caracter de pontuação , se for passa à frente porque queremos palavras

            if(controlo1 == 0)
            {
                len = strlen(token);
                *(matriz_palavras+index) = (char*)malloc((len+1)*sizeof(char));
                strcpy(*(matriz_palavras+index), token);
                *(*(matriz_palavras+index)+len)='\0';
                index++; // indice da matriz de palavras
                count_indices++; // contador para a matriz de indices
            }
            //size = strlen(matriz_palavras[index]);
            //printf("matriz_palavras[%d] - %s ------- size = %d\n",index,matriz_palavras[index],size);
            token = strtok(NULL, s);
        }
        //printf("preencher: count_indices = %d\n",count_indices);
        *(matriz_indices+i)=(int*)malloc(count_indices*sizeof(int)); // alocação de memoria para uma linha da matriz de indices
        *(array_tamanho_matriz_indices+i) = count_indices; //contador para contar o numero de colunas que a matriz de indices vai ter. O valor vai ser guardado num array
        //printf("array : %d\n",array_tamanho_matriz_indices[i]);
        count_indices=0;
    }
}


/** \brief Função com o objetivo de preencher nas posições correstas da mensagem os indices de uma matriz de palavras
 *
 * \param matriz_indices - Matriz que é alocada por outras funções que vai conter os indices de palavras de uma matriz de palaras
 * \param matriz_mensagem - Matriz que contem a mensagem completa
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param linhas - Numero de linhas da matriz de mensagem
 *
 */
void preencher_matriz_indices(int** matriz_indices, char** matriz_mensagem, char** matriz_palavras, int linhas_palavras, int linhas)
{
    // alocação de memoria para a matriz de indices é feita pela função "criar_matriz_indices" e "preencher_matriz_palavras"
    int i=0,indice_palavra_na_matriz=0, index_matriz_indices=0;
    char str[400];
    char *token;

    char s[] = ",! ?.:\n";
    for(i=0; i<linhas; i++)
    {
        strcpy(str,*(matriz_mensagem+i));
        token = strtok(str,s);
        while( token != NULL )
        {
            //printf("token: %s\n",token);
            indice_palavra_na_matriz = pesquisa_binaria(token,matriz_palavras,0,linhas_palavras-1);
            //printf("indice_palavra_na_matriz=%d\n", indice_palavra_na_matriz);
            matriz_indices[i][index_matriz_indices] = indice_palavra_na_matriz;
            index_matriz_indices++;
            token = strtok(NULL, s);
        }
        index_matriz_indices=0;
    }
}

/** \brief Função que permite criar uma matriz ordenada , retornando uma matriz ordenada, sem repetições
 *
 * \param matriz - Matriz antiga para libertar memoria
 * \param a - Estrutura do tipo StringElementsArray que contem uma matriz ordenada com repetições
 * \param linhas - Aponta para um lugar de memoria que está guardado uma variavel de "size" para que possa atualizar esse valor
 * \return Retorna um endereço da primeira posição de uma matriz ordenada sem repetições
 *
 */
char ** criar_matriz_ordenada(char** matriz,StringElementsArray *a, int *linhas)
{
    int i,size=0,index=0, len=0;
    size = verifica_quantiade_linhas_stringelementarray(a);
    char** matriz_ordenada = NULL;
    matriz_ordenada = (char**)malloc(size*sizeof(char*));
    for(i=0; i<a->N-1; i++)
    {
        if(strcmp(a->str[i],a->str[i+1]) !=0)//  copia palavras de forma a não copiar palavras repetidas
        {
            len = a->len[i]+1; // -1 para o '\0'
            *(matriz_ordenada+index)= (char*)malloc(len*sizeof(char)); // alocar memoria para len para ter espaço para o \0
            strcpy(*(matriz_ordenada+index),a->str[i]);
            *(*(matriz_ordenada+index)+(len-1)) = '\0'; // colocar '\0' no fim da string . (len-1) para que a para o ultimo carater
            index++;
        }
    }
    // copiar a ultima palavra que nao foi comparada :
    len = a->len[i]+1;
    *(matriz_ordenada+index)= (char*)malloc(len*sizeof(char));
    strcpy(*(matriz_ordenada+index),a->str[i]);
    *(*(matriz_ordenada+index)+(len-1)) = '\0';
    //print_matriz(matriz_ordenada,size);
    // acabou a copia para a matriz
    free_matriz(matriz,*linhas);
    *linhas = size; // atualiza a variavel para um size novo
    return matriz_ordenada;
}

/** \brief Função para contar o numero de linhas de uma matriz de caracteres de uma estrutura. Faz a contagem de elementos unicos , ou seja, só conta uma vez para elementos repetidos
 *
 * \param a - Estrutura do tipo StringElementsArray que contem uma matriz ordenada com repetições
 * \return Retorna a numero de linhas sem repetições
 *
 */
int verifica_quantiade_linhas_stringelementarray(StringElementsArray* a)
{
    int i=0, count=0;
    //printf("verifica_quantiade_linhas_stringelementarray: a->N = %d\n",a->N);
    for(i=0; i<a->N-1; i++)
    {
        //printf("verifica_quantiade_linhas_stringelementarray: a->str[%d] = %s , a->str[%d] = %s\n",i,a->str[i],i+1,a->str[i+1]);
        if(strcmp(a->str[i],a->str[i+1])!=0)
        {
            count++;
            //printf("count = %d\n",count);
            //printf("----------------\n");
        }
    }
    count++; // para contar a ultima palavra , para não usar o strcmp com uma palavra que nao existe na memoria
    return count;
}

/** \brief Função que permite calcular a distancia entre duas palavras numa conversa
 *
 * \param cv - apontador para uma estrutura conversa
 * \param string1 - palavra a ser procurada
 * \param string2 - palavra a ser procurada
 *
 */
void distancia_textual_entre_duas_palavras(CONVERSA *cv, char* string1, char* string2)
{
    int auxiliar1 = 0, auxiliar2 = 0;

    //verifica se as palavras existem na bag-of-words
    auxiliar1 = pesquisa_binaria(string1,cv->bag_of_words, 0, cv->linhas_bag_of_words);
    auxiliar2 = pesquisa_binaria(string2,cv->bag_of_words, 0, cv->linhas_bag_of_words);

    if(auxiliar1 != -1 && auxiliar2 != -1) // se existirem
    {

        MENSAGEM * aux = NULL;
        aux = cv->pfirst;

        int distancia_textual = 0, distancia1 =0, distancia2 =0, controlo = 0, total_inicio_string1 = 0, total_inicio_string2 = 0;;

        while(aux!=NULL)
        {
            controlo = pesquisa_binaria(string1, aux->bag_of_words, 0, aux->linhas_bag_of_words-1); // pesquisa na bag-of-words de cada estrutura mensagem
            if(controlo != -1)
            {
                distancia1 = contar_distancia_desde_inicio_de_uma_palavra_KMP(string1,aux->mensagem, aux->linhas_mensagem); // distancia entre a primeira palavra da mensagem ate a palavra dada
                total_inicio_string1 = total_inicio_string1 + distancia1; // distancia do inicio da conversa até à palavra
                break;
            }
            total_inicio_string1 = total_inicio_string1 + aux->total_palavras;
            aux = aux->pnext;
        }
        aux = cv->pfirst;

        // repete para a outra palavra
        while(aux!=NULL)
        {
            controlo = pesquisa_binaria(string2, aux->bag_of_words, 0, aux->linhas_bag_of_words-1);
            if(controlo != -1)
            {
                distancia2 = contar_distancia_desde_inicio_de_uma_palavra_KMP(string2,aux->mensagem, aux->linhas_mensagem);
                total_inicio_string2 = total_inicio_string2 + distancia2;
                break;
            }
            total_inicio_string2 = total_inicio_string2 + aux->total_palavras;
            aux = aux->pnext;
        }
        // printf("total_inicio_string1 = %d\n",total_inicio_string1);
        // printf("total_inicio_string1 = %d\n",total_inicio_string2);

        if(total_inicio_string1 >= total_inicio_string2)
        {
            distancia_textual = total_inicio_string1 - total_inicio_string2;
        }
        else
        {
            distancia_textual = total_inicio_string2 - total_inicio_string1;
        }

        printf("A distancia textual entre \"%s\" e \"%s\" e = %d\n",string1, string2, distancia_textual-1); // -1 porque o resultado da mais 1

    }
    else
    {

        printf("A palavra nao existe na conversa\n");
    }
}




/** \brief Função para verificar se um caracter c é um numero ou uma letra.
 *
 * \param c - Caracter que é passado pela função que chama
 * \return Se for letra ou número retorna 1 se não for retorna 0
 *
 */
int verificacao_caracter_ou_numero(char c)
{

    if (c >='a' && c<='z' || c>='0' && c<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


/** \brief Função que conta a distancia de palavras entre a palavra do inicio da mensagem até à ocorrencia de uma dada palavra
 *
 * \param string - Palavra a procurar
 * \param text - Matriz da mensagem. Contém a mensagem completa
 * \param linhas_matriz_mensagem - Numero de linhas/paragrafos que tem a matriz mensagem
 * \return Retorna a distancia entre a primeira palavra e a palavra que procura
 *
 */
int contar_distancia_desde_inicio_de_uma_palavra_KMP(char * string,char ** text, int linhas_matriz_mensagem)
{

    int** dfa=NULL; // matriz para o dfa
    char *buff =NULL; // Apontador para utilizar para cada linha da matriz de mensagem

    int i=0,len=0, p=0,j=0, N=0, count=0, controlo =0,controlo1 = 0, controlo2=0;;

    len = strlen(string);

    // alocação de memoria para o dfa
    dfa = (int**)malloc(R_KMP*sizeof(int*));

    for(i=0; i<R_KMP; i++)
    {
        dfa[i] = (int*)calloc(len,sizeof(int));
    }
    // preenchimento do dfa
    KMP(string,dfa,len);

    // pesquisa da palavra
    for(p=0; p<linhas_matriz_mensagem; p++)
    {
        buff = text[p]; // apontador buff começa a apontar para o primeiro elemento da linhas p da matriz text
        N = (int) strlen(buff);
        for (i = 0, j = 0; i < N; i++)
        {
            j = dfa[buff[i]][j];
            controlo1 = verificacao_caracter_ou_numero(buff[i]); // funcoes para verificar se é o fim da palavra . para ser o fim da palavra o buff[i] tem que ser uma letra ou numero
            controlo2 = verificacao_caracter_ou_numero(buff[i+1]); // e o buff[i+1] tem que ser diferente de letra ou numero . Passamos entao um caracter à função verificação_caracter_ou_numero
            // que retorna 1 se for caracter ou numero e 0 se nao for.
            if(controlo1 == 1 && controlo2 == 0)
            {
                count++; // contador para posteriormente retornar com o valor da distancia do inicio da mensagem ate a ocorrencia
            }
            if (j == len) // se for igual encontrou a mensagem
            {
                controlo = 1; // variavel de controlo para parar a pesquisa
                break; // pára o for de dentro
            }
        }
        if(controlo != 0)
        {
            break; // pára o primeiro for
        }

    }
    for(i=0; i<R_KMP; i++)
    {
        free(dfa[i]);
    }
    free(dfa);
    return count;
}


/** \brief Função que permite calcular o tfidf de todos os termos de uma bag-of-words
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void tfidf_bag_of_words_corpus(CORPUS *cp)
{

    int i=0;
    cp->tfidf = (float*)malloc(cp->linhas_bag_of_words*sizeof(float));
    for(i=0; i<cp->linhas_bag_of_words; i++)
    {
        //printf("%f\n", term_frequency_inverse_document_frequency(*(cp->bag_of_words+i),cp));
        *(cp->tfidf+i) = term_frequency_inverse_document_frequency(*(cp->bag_of_words+i),cp);
    }
}


/** \brief Função que permite o calculo do tfidf de um termo de uma bag-of-words de um corpus
 *
 * \param string - termo para efetuar o calculo
 * \param cp - apontador para uma estrutura corpus
 *
 */
float term_frequency_inverse_document_frequency(char *string, CORPUS *cp)
{
    int controlo = 0;
    //printf("cp->size_conversa = %d\n", cp->size_conversa);
    if((controlo = pesquisa_binaria(string,cp->bag_of_words,0, cp->linhas_bag_of_words))== -1)
    {
        printf("A palavra nao existe\n");
    }
    else
    {
        //printf("tamanho_conversa = %d\n", cp->size_conversa);
        int numero_ocorrencias_conversa = 0,index = 0, i=0, total_palavras =0, controlo1 = 0, count=0;
        float * term_frequency = NULL;
        term_frequency = (float*)calloc(cp->size_conversa,sizeof(float));
        float  auxiliar = 0.0, inverse_document = 0.0, media_termfrequency=0.0, tfidf = 0.0 ;
        CONVERSA *aux = NULL;
        MENSAGEM *aux1=NULL;
        aux = cp->pfirst;
        //printf("aqui1");
        while(aux!=NULL)
        {
            aux1 = aux->pfirst;
            while(aux1!=NULL)
            {

                //print_matriz(aux1->bag_of_words, aux1->linhas_bag_of_words);

                index = pesquisa_binaria(string, aux1->bag_of_words, 0, aux1->linhas_bag_of_words-1);
                if(index == -1)
                {

                    total_palavras = total_palavras + aux1->total_palavras;

                }
                else
                {
                    total_palavras = total_palavras + aux1->total_palavras;
                    numero_ocorrencias_conversa = numero_ocorrencias_conversa + *(aux1->numero_de_ocorrencias+index);
                    controlo1 = 1;

                }
                aux1 = aux1->pnext;
            }

            if(controlo1==1)
            {
                count ++;
            }
            *(term_frequency+i) = (float)numero_ocorrencias_conversa / (float)total_palavras ;

            i++;
            aux = aux->pnext;
            controlo1 = 0;
        }
        numero_ocorrencias_conversa = 0;
        total_palavras = 0;
        auxiliar = (float)cp->size_conversa / (float)count;
        inverse_document = log10(auxiliar);
        // problema com a media
        auxiliar =0;
        for(i=0; i<cp->size_conversa; i++)
        {
            auxiliar = auxiliar + *(term_frequency+i);
        }

        media_termfrequency = auxiliar / (float)cp->size_conversa;

        tfidf = media_termfrequency * inverse_document;
        //printf("TFIDF = %0.5f\n", tfidf);
        return tfidf;
    }
    return 0;
}

/** \brief Função que permite calcular o numero de paragrafos numa conversa
 *
 * \param cv - apontador para uma estrutura conversa
 *
 */
void numero_paragrafos(CONVERSA *cv)
{
    MENSAGEM *aux = NULL;
    aux = cv->pfirst;
    int numero_paragrafos = 0;
    while(aux!=NULL)
    {
        numero_paragrafos = numero_paragrafos + aux->linhas_mensagem;
        aux = aux->pnext;
    }
    printf("Numero de paragrados = %d\n", numero_paragrafos);
}



/** \brief Função que dada uma matriz retira os caracteres de pontuação aí presentes
 *
 * \param matriz - Matriz que contem strings
 * \param linhas - Numero de linhas da matriz
 *
 */
void retirar_carateres_pontuacao_palavra(char** matriz, int linhas)
{
    int i=0, controlo=0, len=0, size = linhas;
    for(i=0; i<size; i++)
    {
        controlo = verificar_pontuacao_palavra(matriz[i]);
        if(controlo ==1)
        {
            len = strlen(*(matriz+i));
            //printf("C len-1 = %c - C len = %c\n",*(*(matriz+i)+(len-1)),*(*(matriz+i)+(len)));
            *(*(matriz+i)+(len-1)) = *(*(matriz+i)+(len));
            //printf("caracteres = %d\n", *caracteres_pontuacao);
        }
    }
}



/** \brief Função para alocar memoria para um vetor com tamanho de "linhas"
 *
 * \param linhas - Tamanho de memoria que queremos alocar
 * \return Retorna o endereço da primeira posição da memória que foi alocada
 *
 */
int * criar_array_tamanho_indices(int linhas)
{
    int * array = NULL;
    array = (int*)malloc(linhas*sizeof(int));
    return array;
}



/** \brief Função que permite contar o numero de palavras de uma matriz de char's
 *
 * \param matriz - Matriz que contem o conteudo para contagem
 * \param linhas - Numero de linhas da matriz para a contagem
 * \return Numero de linhas da matriz
 *
 */
int contar_numero_de_palavras_mensagem(char** matriz,int linhas)
{
    char str[100];
    int i=0, count=0,controlo=0;
    char s[] = " \n";
    //char s[7][7] = {' ','\n'};

    char *token;
    // calcular o numero de linhas para alocar a matriz de palavras
    for(i=0; i<linhas; i++)
    {
        strcpy(str,*(matriz+i));
        token = strtok(str,s);
        while( token != NULL )
        {
            controlo = verificar_se_palavra_e_pontuacao(token); // para evitar situações como "ola , mundo"
            if(controlo == 0)
            {
                count++;
            }
            token = strtok(NULL, s);
        }
    }
    //printf("count=%d\n",count);
    return count;
}



/** \brief Função para alocar memoria para um vetor de apontadores
 *
 * \param linhas - numero de linhas de uma matriz de inteiros
 * \return Endereço da primeira posição de um vetor de apontadores
 *
 */
int ** criar_matriz_indices(int linhas)
{
    int ** matriz = NULL;
    matriz = (int**)malloc(linhas*sizeof(int*));
    return matriz;
}

void criar_matrizes_adicionais_de_mensagem(MENSAGEM *ms)
{
    //time_t t;

    //755printf(" numero linhas mensagem = %d\n", ms->linhas_mensagem);
    ms->linhas_bag_of_words = contar_numero_de_palavras_mensagem(ms->mensagem, ms->linhas_mensagem);
    ms->bag_of_words = criar_matriz(ms->linhas_bag_of_words);
    ms->matriz_de_indices = criar_matriz_indices(ms->linhas_mensagem);
    ms->linhas_matriz_indices = criar_array_tamanho_indices(ms->linhas_mensagem);
    preencher_matriz_palavras(ms->mensagem,ms->linhas_matriz_indices,ms->matriz_de_indices, ms->linhas_mensagem, ms->linhas_bag_of_words, ms->bag_of_words);
    retirar_carateres_pontuacao_palavra(ms->bag_of_words,ms->linhas_bag_of_words);


    /*ORDENAÇÃ*/

    int lo=0, hi=ms->linhas_bag_of_words-1, d=0;

    StringElementsArray a;
    StringElementsArray aux;
    createStringElementsArrayAndFill(&a,ms->linhas_bag_of_words,ms->bag_of_words);
    createStringElementsArray(&aux,ms->linhas_bag_of_words);

    msd_sort_whithout_cutoff(&a,&aux,lo,hi,d, CHAR_8BIT_RADIX);

    ms->bag_of_words = criar_matriz_ordenada(ms->bag_of_words,&a, &ms->linhas_bag_of_words);

    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);

    preencher_matriz_indices(ms->matriz_de_indices, ms->mensagem, ms->bag_of_words, ms->linhas_bag_of_words,ms->linhas_mensagem);

//    srand((unsigned) time(&t));
//
//    ms->importancia = rand()%100;

    ms->numero_de_ocorrencias = numero_de_ocorrencias(ms->matriz_de_indices, ms->bag_of_words, ms->linhas_bag_of_words, ms->linhas_matriz_indices, ms->linhas_mensagem);

    ms->total_palavras = total_de_palavras(ms->linhas_bag_of_words, ms->numero_de_ocorrencias);
}



/** \brief Função que retorna o numero total de palavras que estão na mensagem.
 *
 * \param linhas_matriz_palavras - Numero de linhas a matriz de palavras tem. Sem repetições.
 * \param array_ocorrencias - Vetor de inteiros que guarda o numero de vezes em que cada palavra aparece. O seu tamanho é igual ao da matriz de palavras porque
                            cada indice representa uma palavra na matriz de palavras.
 * \return Retorna o numero de palavras da mensagem
 */
int total_de_palavras(int linhas_matriz_palavras, int * array_ocorrencias)
{
    int i=0, soma=0;
    for(i=0; i<linhas_matriz_palavras; i++)
    {
        soma = soma + array_ocorrencias[i];
    }
    return soma;
}


/** \brief Função que permite o utilizador remover uma conversa de uma lista ligada de conversas de um corpus
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void utilizador_remover_conversa (CORPUS *cp)
{

    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    int num_conversa=0, count =1;
    while(aux!=NULL)
    {
        printf("\n\nConversa %d :\n\n", count);
        printf("Utilizadores:\n");
        print_matriz(aux->utilizadores, aux->linhas_utilizadores);
        printf("\n\n\n");
        aux = aux->pnext;
        count++;
    }
    printf("Qual a conversa que pretende remover ?\n");
    scanf("%d",&num_conversa);
    remover_conversa(cp, num_conversa);

}


/** \brief Função que permite identificar todas as conversas presentes numa lista ligada de conversa de um corpus , utilizando os utiliadores intervenientes para as distinguir
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void print_todas_conversas_usando_utilizadores_para_distincao(CORPUS *cp)
{

    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    int count =1;
    while(aux!=NULL)
    {
        printf("\n\nConversa %d :\n\n", count);
        printf("Utilizadores:\n");
        print_matriz(aux->utilizadores, aux->linhas_utilizadores);
        printf("\n\n\n");
        aux = aux->pnext;
        count++;
    }

}

/** \brief Função que permite imprimir um timestamp de uma mensagem
 *
 * \param ms - apontador para uma estrutura mensagem
 *
 */
void print_timestamp(MENSAGEM *ms)
{
    MENSAGEM *aux = NULL;
    aux = ms;
    printf("(%d/%d/%d - %d:%d:%d)", aux->tempo->dia, aux->tempo->mes, aux->tempo->ano, aux->tempo->hora, aux->tempo->minuto
           , aux->tempo->segundo);

}


/** \brief Função que permite ao utilizador remover uma mensagem de uma conversa
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void utilizador_remover_mensagem(CORPUS *cp)
{
    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    int num_conversa=0, num_mensagem=0, count =1;
    while(aux!=NULL)
    {
        printf("\n\nConversa %d :\n\n", count);
        printf("Utilizadores:\n");
        print_matriz(aux->utilizadores, aux->linhas_utilizadores);
        printf("\n\n\n");
        aux = aux->pnext;
        count++;
    }
    printf("Qual a conversa que pretende remover a mensagem?\n");
    scanf("%d",&num_conversa);

    int index=1;
    aux = cp->pfirst;
    while(aux!=NULL)
    {
        if(index == num_conversa)
        {
            break;
        }
        aux = aux->pnext;
        index++;
    }

    MENSAGEM *aux1 = NULL;
    aux1 = aux->pfirst;
    count=1;
    while(aux1!= NULL)
    {
        printf("|%d| - ",count);
        printf("%s - ",aux1->utilizador);
        print_matriz(aux1->mensagem, aux1->linhas_mensagem);
        print_timestamp(aux1);
        printf("\n\n");
        aux1 = aux1->pnext;
        count++;
    }
    printf("Qual a mensagem que pertende remover?\n");
    scanf("%d",&num_mensagem);
    remover_mensagem(aux,num_mensagem);

    print_mensagens_de_uma_conversa(aux);
}

// estou aqui . Acho que é problema com o pante!
/** \brief Função que permite remover uma mensagem de uma lista ligada de mensagens de uma estrutura conversa
 *
 * \param cv - apontador para uma estrutura conversa
 * \param index - posição da estrutura na lista ligada
 *
 */
void remover_mensagem(CONVERSA *cv, int index)
{
    printf("Dentro do remover mensagem\n\n utilizadores : \n");
    print_matriz(cv->utilizadores, cv->linhas_utilizadores);
    MENSAGEM *aux =NULL;
    aux = cv->pfirst;
    int i=1;
    printf("index =%d\n",index);
    if(aux->pante == NULL && i==index)// primeiro elemento da lista
    {
        printf("primeiro if\n");
        cv->pfirst = aux->pnext;
        cv->size_mensagem--;
        free(aux);
        return;
    }

    while(aux->pnext!=NULL)
    {
        if(i == index)
        {
            printf("segundo if");
            aux->pante->pnext = aux->pnext;
            aux->pnext->pante = aux->pante;
            cv->size_mensagem--;
            free(aux);
            return;
        }
        aux = aux->pnext;
        i++;
    }

    if(aux->pnext == NULL && i==index)  // para o ultimo elemento
    {
        aux->pante->pnext = NULL;
        cv->size_mensagem--;
        free(aux);
        return;
    }
    printf("Mensagem nao foi encontrada\n");


}


/** \brief Função que permite remover uma estrutura conversa de uma lista ligada de conversas que está dentro de um corpus
 *
 * \param cp - apontador para uma estrutura corpus
 * \param index - posição onde a conversa que queremos remover está
 *
 */
void remover_conversa(CORPUS *cp, int index)
{


    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    int i=1;

    if(aux->pante == NULL && i==index)// primeiro elemento da lista
    {

        cp->pfirst = aux->pnext;
        free(aux);
        return;
    }

    while(aux->pnext!=NULL)
    {
        if(i == index)
        {
            aux->pante->pnext = aux->pnext;
            aux->pnext->pante = aux->pante;
            free(aux);
            return;
        }
        i++;
        aux = aux->pnext;
    }
    if(aux->pnext == NULL && i==index)  // para o ultimo elemento
    {
        aux->pante->pnext = NULL;
        free(aux);
        return;
    }
    printf("Conversa nao foi encontrada\n");

}


/** \brief Função que permite imprimir todas as mensagens de uma conversa
 *
 * \param pc - apontador para uma estrutura conversa
 *
 */
void print_conversa(CONVERSA *pc)
{
    MENSAGEM *paux = NULL;
    paux = pc->pfirst;
    while(paux!=NULL)
    {
        printf("Mensagem:\n\n");
        printf("Utilizador: %s\n",paux->utilizador);
        print_matriz(paux->mensagem, paux->linhas_mensagem);
        printf("Enviada as: %d/%d/%d , %d:%d:%d\n",paux->tempo->dia, paux->tempo->mes, paux->tempo->ano,
               paux->tempo->hora, paux->tempo->minuto, paux->tempo->segundo);

        //printf("Bag-of-words:\n\n");
        //print_matriz(paux->bag_of_words, paux->linhas_bag_of_words);
        //printf("\n\nMatriz de indices:\n\n");
        //print_matriz_indices(paux->matriz_de_indices , paux->linhas_mensagem , paux->linhas_matriz_indices);
        paux = paux->pnext;
    }
}


/** \brief Função que permite contar os paragrafos de uma mensagem dentro de uma string
 *
 * \param string - apontador para a posição de memoria onde a mensagem se encontra
 *
 */
int contar_paragrafos_mensagem (char *string)
{
    const char s[2] = "\n";
    char *token;
    char buff[100];
    strcpy(buff,string);
    int count = 0;

    /* get the first token */
    token = strtok(buff, s);

    /* walk through other tokens */
    while( token != NULL )
    {

        count ++;
        token = strtok(NULL, s);
    }
    return count ;
}


/** \brief Função que permite inserir uma estrutura mensagem na cauda de uma lista ligada de mensagens de uma conversa
 *
 * \param pc - apontador para a estrutura conversa onde queremos inserir a mensagem
 * \param pnew - apontador para estrutura mensagem que queremos adicionar
 *
 */
void inserir_mensagem_conversa_cauda(CONVERSA *pc, MENSAGEM *pnew)
{
    MENSAGEM * paux = NULL;
    paux = pc->pfirst;

    if(paux == NULL)
    {
        pc->pfirst = pnew;
        pnew->pante = NULL;
        pnew->pnext = NULL;
        pc->size_mensagem ++;
        return;
    }
    paux = pc->pfirst;
    while(paux->pnext != NULL)
    {
        paux = paux->pnext;
    }
    paux->pnext =pnew;
    pnew->pante = paux;
    pnew->pnext = NULL;
    pc->size_mensagem ++;
    // copia o timestamp da mensagem que é inserida de modo a atualziar o timestamp da conversa sempre com a ultima mensagem
    pc->tempo->ano = pnew->tempo->ano;
    pc->tempo->mes = pnew->tempo->mes;
    pc->tempo->dia = pnew->tempo->dia;
    pc->tempo->hora = pnew->tempo->hora;
    pc->tempo->minuto = pnew->tempo->minuto;
    pc->tempo->segundo = pnew->tempo->segundo;
    return;
}


/** \brief Função para alocar memoria para um vetor de apontadores para alocação de memoria de uma matriz
 *
 * \param linhas - Tamanho da memoria que queremos alocar
 * \return Retorna o endereço da primeira posição da memória que foi alocada
 *
 */
char** criar_matriz(int linhas)
{
    char ** matriz = NULL;
    matriz = (char**)malloc(linhas*sizeof(char*));
    return matriz;
}


/** \brief Função que permite transformar uma string em varios inteiros de modo a termos dia , mes , ano , hora , minuto , segundo
 *
 * \param string - Apontador para uma string onde tem a informação que vai ser convertida
 * \return Retorna uma estrutura com os campos relativos a uma data , hora , minuto e segundo.
 *
 */
TIMESTAMP *string_para_inteiro_timestamp(char * string)
{

    TIMESTAMP *pnew = (TIMESTAMP*)malloc(sizeof(TIMESTAMP));


    int array[14]; // para guardar os numeros inteiros
    int len = 0, i=0, j=0;
    len = strlen(string);

    for(i=0; i<len; i++)
    {
        if(string[i]!='/' && string[i]!=' ' && string[i]!='.')
        {
            array[j] = string[i] - '0';
            j++;
        }
    }

    int aux1 = 0, aux2 = 0, aux3 =0, aux4=0;

    aux1 = array[0] * 10 ;
    aux2 = aux1 + array[1];

    pnew->dia = aux2;

    aux1 = 0;
    aux2 = 0;
    aux1 = array[2] * 10;
    aux2 = aux1 + array[3];
    pnew->mes = aux2;

    aux1 = 0;
    aux2 = 0;
    aux1 = array[4] * 1000;
    aux2 = array[5] * 100;
    aux3 = array[6] * 10;
    aux4 = aux1 + aux2 + aux3 + array[7];
    pnew->ano = aux4;

    aux1 = array[8] * 10 ;
    aux2 = aux1 + array[9];
    pnew->hora = aux2;

    aux1 = array[10] * 10 ;
    aux2 = aux1 + array[11];
    pnew->minuto = aux2;

    aux1 = array[12] * 10 ;
    aux2 = aux1 + array[13];
    pnew->segundo = aux2;

    return pnew;
}



// por testar // problema com contar_linhas.
/** \brief Função que permite inserir uma estrutura mensagem numa lista ligada de mensagens de uma determinada conversa
 *
 * \param cv - apontador para uma estrutura conversa onde vai ser adicionada a mensagem
 * \param mensagem - matriz onde contem a mensagem
 *
 */
void inserir_nova_mensagem_na_conversa(CONVERSA *cv,  char ** mensagem)
{

    MENSAGEM *pnew = NULL;
    pnew = criar_struct_mensagem();
    pnew->linhas_mensagem = contar_linhas(mensagem);
    pnew->mensagem = (char**)malloc(pnew->linhas_mensagem*sizeof(char*));
    int i=0, len=0 ;
    for(i=0; i<pnew->linhas_mensagem; i++)
    {
        len = *(mensagem+i);
        *(pnew->mensagem+i) = (char*)malloc((len+1)*sizeof(char));
        strcpy(*(pnew->mensagem+i),*(mensagem+i));
    }
    criar_matrizes_adicionais_de_mensagem(pnew);
    inserir_mensagem_conversa_cauda(cv,pnew);

}


/** \brief Função que permite alocar memoria para uma estrutura mensagem
 *
 * \return Retorna um endereço onde está a estrutura que foi alocada
 *
 */
MENSAGEM *criar_struct_mensagem()
{

    MENSAGEM * pnew = NULL;
    pnew = (MENSAGEM*)malloc(sizeof(MENSAGEM));
    printf("aqui\n");
    pnew->utilizador = NULL;
    pnew->mensagem = NULL;
    pnew->linhas_mensagem = 0;
    pnew->bag_of_words = NULL;
    pnew->linhas_bag_of_words = 0;
    pnew->matriz_de_indices = NULL;
    pnew->tempo = NULL;
    pnew->linhas_matriz_indices = NULL;
    pnew->tempo = NULL;
    pnew->pnext = NULL;
    pnew->pante = NULL;
    pnew->importancia = 50;

    return pnew;
}


/** \brief Função que permite alocar memoria para uma estrutura conversa
 *
 * \return Retorna um endereço onde está a estrutura que foi alocada
 *
 */
CONVERSA *criar_struct_conversa()
{
    CONVERSA *pnew = NULL;
    pnew = (CONVERSA*)malloc(sizeof(CONVERSA));
    pnew->utilizadores = NULL;
    pnew->linhas_utilizadores = 0;
    pnew->bag_of_words = NULL;
    pnew->linhas_bag_of_words = 0;
    pnew->pfirst = NULL;
    pnew->importancia = rand()%100;
    pnew->pnext = NULL;
    pnew->pante = NULL;
    pnew->tempo =(TIMESTAMP*)malloc(sizeof(TIMESTAMP));
    pnew->size_mensagem = 0;
    return pnew;
}

/** \brief Função para libertar memória que foi alocada para uma matriz
 *
 * \param matriz - Matriz a libertar
 * \param linhas - Numero de linhas da matriz
 *
 */
void free_matriz(char** matriz, int linhas)
{
    int i;
    for(i=0; i<linhas; i++)
    {
        free(*(matriz+i));
    }
    free(matriz);
}



/** \brief Função que serve para verificar se uma string contem um caracter de pontuação
 *
 * \param string - String para verificar se contem um caracter de pontuação
 * \return Retorna 1 se encontrar algum caracter de pontuação e retorna 0 se não encontrar
 *
 */
int verificar_pontuacao_palavra(char *string)
{
    int size=0;
    char c;
    size = strlen(string);
    // printf("string = %s\n" , string);
    c=*(string+(size-1));
    // printf("%c\n",c);
    if(c ==',' || c== '.' || c== '?' || c== '!' || c==';' || c==':')
    {
        return 1;
    }
    return 0;
}



/** \brief Função que verifica se a string recebida é pontuação
 *
 * \param string - String para verificar se é pontuação
 * \return Retorna 1 se for pontuação e retorna 0 se não for
 *
 */
int verificar_se_palavra_e_pontuacao(char *string)
{
    char c;
    c=string[0];
    if(c ==',' || c== '.' || c== '?' || c== '!' || c==';' || c==':')
    {
        return 1;
    }
    return 0;
}


/** \brief Algoritmo de pesquisa binária
 *
 * \param procura - Palavra a procurar numa matriz
 * \param tudo - Texto/matriz para procura de uma palavra
 * \param low - Valor do indice a partir do qual queremos procurar (minimo)
 * \param high - Valos maximo do indice a partir do qual queremos procurar
 * \return Retorna o indice da posição da palavra no texto/matriz
 *
 */
int pesquisa_binaria( char* procura, char** tudo, int low, int high)
{

    //print_matriz(tudo, high);
    int mid, cmp;
    if (low > high) // sera que é > = ?
    {

        return -1;
    }

    mid = (low + high) / 2;

    cmp = strcmp( procura, tudo[mid]);

    if (cmp == 0 )
    {
        return mid;
    }
    if (cmp < 0)
    {
        return pesquisa_binaria( procura, tudo, low, mid - 1);
    }
    else
    {
        return pesquisa_binaria( procura, tudo, mid + 1, high);
    }
}


/** \brief Função que permite ordenar uma lista ligadas de conversas pelo seu timstamp. Esta função usa o recurso a mergesort
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void ordenacao_por_timestamp(CORPUS *cp)
{

    MergeSort(&cp->pfirst, 0);
    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    while(aux!=NULL)
    {
        print_timestamp(aux);
        printf("\n");
        print_matriz(aux->utilizadores, aux->linhas_utilizadores);
        printf("\n\n\n");
        aux = aux->pnext;
    }

}


/** \brief Função que imprime o timestamp de uma determinada conversa
 *
 * \param cv - apontador para uma estrutura conversa
 *
 */
void print_timestamp_conversa(CONVERSA * cv)
{

    CONVERSA *aux = NULL;
    aux = cv;
    printf("(%d/%d/%d - %d:%d:%d)", aux->tempo->dia, aux->tempo->mes, aux->tempo->ano, aux->tempo->hora, aux->tempo->minuto
           , aux->tempo->segundo);


}


/** \brief Função que permite ordenar uma lista ligadas de conversas pela sua importancia. Esta função usa o recurso a mergesort
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void ordenacao_por_importancia(CORPUS *cp)
{

    MergeSort(&cp->pfirst, 2);
    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    while(aux!=NULL)
    {
        printf("importancia = %d\n", aux->importancia);
        print_matriz(aux->utilizadores, aux->linhas_utilizadores);
        printf("\n\n\n");
        aux = aux->pnext;
    }

}


/** \brief Função que permite ordenar uma lista ligadas de conversas pelo seu tamanho. Esta função usa o recurso a mergesort
 *
 * \param cp - apontador para uma estrutura corpus
 *
 */
void ordenacao_por_tamanho(CORPUS *cp)
{

    MergeSort(&cp->pfirst, 1);
    CONVERSA *aux = NULL;
    aux = cp->pfirst;
    while(aux!=NULL)
    {
        printf("tamanho = %d\n", aux->tamanho);
        printf("aqui\n");
        print_matriz(aux->utilizadores, aux->linhas_utilizadores);
        printf("\n\n\n");
        aux = aux->pnext;
    }
}




/** \brief Função que imprime uma matriz de inteiros
 *
 * \param matriz - Matriz a imprimir
 * \param linhas_matriz - tamanho de linhas da matriz a imprimir
 * \param tamanho_linhas - Apontador para um vetor que contem o numero de colunas de cada linha
 *
 */
void print_matriz_indices(int ** matriz,int linhas_matriz, int *tamanho_linhas)
{
    int i,j;
    for(i=0; i<linhas_matriz; i++)
    {
        printf("%d paragrafo ->",i+1);
        for(j=0; j<tamanho_linhas[i]; j++)
        {
            printf("|%d",matriz[i][j]);
        }
        printf("|\n");
    }
}

