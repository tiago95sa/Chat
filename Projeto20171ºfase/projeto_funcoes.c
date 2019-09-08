#include "projeto_funcoes.h"

void client_main_funcoes()
{

    char *pathfile = "./data/mensagem.txt";
    char ** matriz_mensagem = NULL;
    char ** matriz_palavras = NULL;
    char ** matriz_frases = NULL;
    int ** matriz_de_indices=NULL;
    int * linhas_de_indices=NULL;
    int * array_de_ocorrencias=NULL;
    int ** matriz_indices_pontuacao = NULL;
    int * linhas_de_indices_pontuacao = NULL;
    int total_palavras = 0;


    char *pontuacao[5]= {"0","!",",",".","?"};
    int caracteres_pontuacao = 5;


    int linhas_matriz_mensagem = 0;
    int linhas_matriz_palavras = 0;
    int numero_frases = 0;


    linhas_matriz_mensagem = contar_linhas(pathfile);

    matriz_mensagem = criar_matriz(linhas_matriz_mensagem);

    ficheiro_para_matriz_mensagem(matriz_mensagem, linhas_matriz_mensagem, pathfile);

    print_matriz(matriz_mensagem, linhas_matriz_mensagem);


    linhas_matriz_palavras = contar_numero_de_palavras_mensagem(matriz_mensagem, linhas_matriz_mensagem);

    //printf("linhas_matriz_palavras = %d\n", linhas_matriz_palavras);

    matriz_palavras = criar_matriz(linhas_matriz_palavras);

    matriz_de_indices = criar_matriz_indices(linhas_matriz_mensagem);

    linhas_de_indices = criar_array_tamanho_indices(linhas_matriz_mensagem);

    preencher_matriz_palavras(matriz_mensagem,linhas_de_indices,matriz_de_indices, linhas_matriz_mensagem, linhas_matriz_palavras, matriz_palavras);

    //print_matriz(matriz_palavras , linhas_matriz_palavras);

    colocar_tudo_letras_pequenas(matriz_palavras,linhas_matriz_palavras);

    retirar_carateres_pontuacao_palavra(matriz_palavras,linhas_matriz_palavras);
    //print_matriz(matriz_palavras , linhas_matriz_palavras);
    //printf("linhas= %d\n",linhas_matriz_palavras);


    //printf("ORDENACAO\n\n\n");
    /* ORDENAÇÃO */

    int lo=0, hi=linhas_matriz_palavras-1, d=0;

    StringElementsArray a;
    StringElementsArray aux;
    createStringElementsArrayAndFill(&a,linhas_matriz_palavras,matriz_palavras);
    createStringElementsArray(&aux,linhas_matriz_palavras);
    //printStringElementsArray(&a);
    //printf("---------------------\n");
    //printStringElementsArray(&aux);
    msd_sort_whithout_cutoff(&a,&aux,lo,hi,d, CHAR_8BIT_RADIX);

    //printStringElementsArray(&a);
    //printf("Copiar\n\n\n");
    //printf("---------------------\n");
    matriz_palavras = criar_matriz_ordenada(matriz_palavras,&a, &linhas_matriz_palavras);

    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);

    //printf("linhas = %d\n", linhas_matriz_palavras);
    //print_matriz(aux123,linhas_matriz_palavras);

    //print_matriz(matriz_palavras,linhas_matriz_palavras);

    //printf("-------------------------\n");
    /* PESQUISA*/
    /*
    int existe = 0;

    existe = pesquisa_binaria("ja",matriz_palavras,0,linhas_matriz_palavras);

    if(existe ==0){
        printf("palavra nao existe\n");
    }else{
        printf("palavra existe na posicao = %d\n",existe+1);
    }
    */

    /*Indices*/


    preencher_matriz_indices(matriz_de_indices, matriz_mensagem, matriz_palavras, linhas_matriz_palavras,linhas_matriz_mensagem);

    print_matriz_indices(matriz_de_indices,linhas_matriz_mensagem,linhas_de_indices);
    //print_matriz(matriz_palavras , linhas_matriz_palavras);
    array_de_ocorrencias= numero_de_ocorrencias(matriz_de_indices,matriz_palavras,linhas_matriz_palavras,linhas_de_indices,linhas_matriz_mensagem);

    total_palavras = total_de_palavras(linhas_matriz_palavras, array_de_ocorrencias);

    //bag_of_words(matriz_palavras,matriz_de_indices,linhas_de_indices, linhas_matriz_palavras, array_de_ocorrencias,linhas_matriz_mensagem);

    term_frequency_inverse_document_frequency("cafe", matriz_de_indices, linhas_de_indices, linhas_matriz_mensagem, matriz_palavras,  linhas_matriz_palavras);
    numero_frases = numero_de_frases_mensagem (matriz_mensagem,linhas_matriz_mensagem);
    //printf("numero_frases = %d\n", numero_frases);
    matriz_frases = matriz_de_frases (matriz_mensagem,linhas_matriz_mensagem,numero_frases);
    //print_matriz(matriz_frases,numero_frases);
    //float x=0.0 ;
    //x = frequencia_de_reutilizacao("ola", matriz_de_indices , linhas_de_indices , linhas_matriz_mensagem, matriz_palavras , linhas_matriz_palavras,array_de_ocorrencias);
    //printf("x = %f\n",x);

    matriz_indices_pontuacao = criar_matriz_indices(linhas_matriz_mensagem);

    linhas_de_indices_pontuacao = matriz_de_pontuacao (matriz_mensagem,linhas_matriz_mensagem, matriz_indices_pontuacao, pontuacao, caracteres_pontuacao);

    print_matriz_indices(matriz_indices_pontuacao , linhas_matriz_mensagem , linhas_de_indices_pontuacao);

    printf("total de palavras = %d\n",total_palavras);
    print_matriz_indices(matriz_de_indices,linhas_matriz_mensagem,linhas_de_indices);

    reconstruir_mensagem(matriz_indices_pontuacao , matriz_de_indices ,linhas_matriz_mensagem ,linhas_de_indices_pontuacao , linhas_de_indices , pontuacao ,matriz_palavras , linhas_matriz_palavras);


    printf("\n\n\n\n\n");
    //procurar_padrao (matriz_mensagem ,linhas_matriz_mensagem ,"ola");

    int distancia=0;

    //distancia = contar_distancia_duas_palavras("bem", "cafe",matriz_de_indices,linhas_de_indices,linhas_matriz_mensagem, matriz_palavras, linhas_matriz_palavras);

    //distancia = KMPsearch_modificado_indice_ocorrencia_palavra(matriz_mensagem, "cafe" ,linhas_matriz_mensagem);
    //printf("distancia entre as duas palavras = %d\n",distancia);

    //distancia = contar_distancia_duas_palavras_KMP("ola", "cafe",matriz_mensagem, linhas_matriz_mensagem , matriz_palavras , linhas_matriz_palavras);
    //printf("distancia = %d\n",distancia);
    //frequencia_relativa_letras_alfabeto(matriz_palavras ,linhas_matriz_palavras , array_de_ocorrencias);
    //float media = 0.0;
    //media = calculo_media_palavras(matriz_palavras , linhas_matriz_palavras, array_de_ocorrencias,total_palavras);
    //printf("media = %f\n",media);

    //float frequencia = 0.0;
    //frequencia =  frequencia_relativa_palavras_menores_m(matriz_palavras ,linhas_matriz_palavras , array_de_ocorrencias , 3 , total_palavras);
    // printf("frequencia = %f\n",frequencia);

    palavras_com_possiveis_raizes_comuns(matriz_palavras ,linhas_matriz_palavras,"medico");

//    char k1[] = "agora";
//    char k2[] = "ate";
//    char k3[] = "ja";
//    char **mtr = NULL;
//    int i;
//    mtr = (char**)malloc(3*sizeof(char*));
//    mtr[0] = k1;
//    mtr[1] = k2;
//    mtr[2] = k3;
//
//    int index =0;
//    print_matriz(mtr, 3);
//    index = pesquisa_binaria("ja" , mtr , 0 , 2);
//    printf("index = %d\n",index);
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

/** \brief Função para encontrar uma dada palavra com raizes comuns numa matriz de palavras
 *
 * \param matriz_palavras - Matriz onde tem todas as palavras da mensagem sem repetições e ordenada.
 * \param linhas_matriz_palavras - Numero de palavras que tem a matriz de palavras
 * \param palavra - Palavra inserida para procura
 *
 */
void palavras_com_possiveis_raizes_comuns(char ** matriz_palavras , int linhas_matriz_palavras, char * palavra){

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
    int controlo1 =0 , controlo2 =0 ,len1 =0  ,len2=0 , controlo=0;
    for(i=0;i<linhas_matriz_palavras;i++){
        for(j=0;j<N-2;j++){
        suffix_array[j]=&palavra[j];
        //printf("palavra = %s\n",palavra);
        //printf("suffix_array[%d]=%s\n",j,suffix_array[j]);
        len1= strlen(suffix_array[j]);
        //printf("len1 = %d\n" , len1);
        len2 = strlen(prefix[j]);
        //printf("matriz_palavras[i] = %s\n", matriz_palavras[i]);
        controlo1 = printKMPsearch(matriz_palavras[i], suffix_array[j], dfa, len1);
        //printf("controlo1 = %d\n", controlo1);
        controlo2 = printKMPsearch(matriz_palavras[i], prefix[j], dfa, len2);
        //printf("controlo2 = %d\n", controlo2);
        if(controlo1 == 1 || controlo2 == 1){
            printf("palavra com raiz comum = %s\n", matriz_palavras[i]);
            controlo = 1;
            break;
        }
        }
    }
    if(controlo==0){
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
char ** create_prefix_array(char *str){
    int N = strlen(str);
    int i ;
    char * aux = NULL;
    aux = (char*)malloc(N*sizeof(char));
    char ** prefix_array = (char**)malloc((N-2)*sizeof(char*));

    strcpy(aux , str);

    int    len =0 ;
    for(i=0;i<N-2;i++){
       len = strlen(aux);
       prefix_array[i] = (char*)malloc(len*sizeof(char));
       strcpy(prefix_array[i],aux);
       aux[len-1]='\0';
       len--;
    }

    free(aux);

    //print_matriz(prefix_array , N-1);

    return prefix_array;
}




/** \brief Função para contar distância entre duas palavras numa mensagem usando o algoritmo KMP. Conta a distância da primeira ocorrencia de cada palavra
 *
 * \param string1 - Primeira palavra a procurar. Contudo pode não sei a primera palavra a aparecer na mensagem
 * \param string2 - Segunda palavra a procurar. Contudo pode não sei a segunda palavra a aparecer na mensagem
 * \param matriz_mensagem - Matriz onde tem a mensagem completa
 * \param linhas_matriz_mensagem - Numero de linhas da mensagem, que vai ser o numero de paragrafos.
 * \param matriz_palavras - Matriz onde tem todas as palavras da mensagem sem repetições e ordenada.
 * \param linhas_matriz_palavras - Numero de palavras que tem a matriz de palavras
 * \return Retorna a distancia entre as duas palavras
 *
 */
int contar_distancia_duas_palavras_KMP(char * string1, char* string2, char** matriz_mensagem, int linhas_matriz_mensagem, char ** matriz_palavras, int linhas_matriz_palavras)
{
    int controlo1=0, controlo2=0;

    controlo1 = pesquisa_binaria(string1,matriz_palavras,0,linhas_matriz_palavras-1); // procura o indice da palavra na matriz de palavras
    controlo2 = pesquisa_binaria(string2,matriz_palavras,0,linhas_matriz_palavras-1);

    if(controlo1 != -1 && controlo2 !=-1)  // se ambas existirem na mensagem
    {

        int distancia_string1=0, distancia_string2=0, distancia = 0;
        distancia_string1 = contar_distancia_desde_inicio_de_uma_palavra_KMP(string1, matriz_mensagem,linhas_matriz_mensagem); // retorna a distancia de palavras desde o inicio da mensagem até a ocorrencia da palavra
        distancia_string2 = contar_distancia_desde_inicio_de_uma_palavra_KMP(string2, matriz_mensagem,linhas_matriz_mensagem);
        if(distancia_string1 > distancia_string2)  // verifica quem aparece primeiro
        {
            distancia = distancia_string1 - distancia_string2;
        }
        else
        {
            distancia = distancia_string2 - distancia_string1;
        }
        distancia--; // porque o valor dá mais um do que o realmente é , devido à subtração
        return distancia;
    }
    else
    {
        printf("Uma das palavras nao existe\n");

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


/** \brief Função para procurar um padrão numa mensagem. Utilizando o KMP
 *
 * \param matriz_mensagem - Matriz que tem a mensagem
 * \param linhas_matriz_mensagem - Linhas/paragrafos da matriz que contem a mensagem
 * \param padrao - Padrao a procurar na matriz_mensagem
 */
void procurar_padrao (char ** matriz_mensagem, int linhas_matriz_mensagem, char * padrao )
{
    int** dfa=NULL;

    int i=0,len=0 ;

    len = strlen(padrao);

    // Alocação de memoria para o DFA
    dfa = (int**)malloc(R_KMP*sizeof(int*));

    for(i=0; i<R_KMP; i++)
    {
        dfa[i] = (int*)calloc(len,sizeof(int));
    }

    // preenchimento do DFA
    KMP(padrao,dfa,len);

    for(i=0; i<linhas_matriz_mensagem; i++) // procura em cada paragrafo/linha da mensagem
    {
        KMPsearch_modificado(matriz_mensagem[i],padrao,dfa,len,i+1); // pesquisa do padrao utilizando KMP. Passa i+1 para imprimir o numero do paragrafo de 1 até linhas_matriz_mensagem
    }


    for(i=0; i<R_KMP; i++)
    {
        free(dfa[i]);
    }
    free(dfa);
}


/** \brief Função de pesquisa de um padrão numa string. Não é o KMP original mas sim um modificado por mim
 *
 * \param text - String onde vai ser procurado o padrão
 * \param pat - Padrão a procurar na string
 * \param dfa - Matriz que representa indices de 0 até len-1
 * \param len - tamanho do padrao
 * \param paragrafo - numero do paragrafo de uma mensagem. Para imprimir
 *
 */
void KMPsearch_modificado(char * text, char * pat, int** dfa, int len, int paragrafo)
{

    int N = (int) strlen(text);
    char c;
    int * occor = (int *)calloc(N,sizeof(int));
    int i, j, controlo = 0;  // variavel controlo para verificar se tem alguma ocorrencia no paragrafo

    for (i = 0, j = 0; i < N; i++)
    {
        j = dfa[text[i]][j];
        occor[i] = -1;
        if (j == len)
        {
            controlo = 1;
            occor[i]= i -(len-1);// len-1 para dar o indice certo , visto que para um len de 4 , i-4 = vai dar o indice anterior ao que a palavra começa
            j = dfa[text[i]][0];
        }
    }

    if(controlo != 0)
    {

        for (i = 0; i < N; i++)
        {
            //printf("occor[%d] = %d\n",i,occor[i]);
            if(occor[i]!=-1)
            {
                printf("Ocorrencia do padrao no indice %d do paragrafo %d\n",occor[i],paragrafo);
            }
        }
    }
    else
    {
        printf("Nao houve ocorrencias do padrao no paragrafo %d\n",paragrafo);
    }
    free(occor);
}



/** \brief Função que reconstroi uma mensagem atravez de uma matriz de palavras , pontuação e numero de ocorrencias de cada palavra
 *
 * \param matriz_pontuacao - Matriz que contem o lugar onde os caracteres estão na mensagem. Em cada linha da matriz tem inteiros a 0 que representam a mensagem e indices
                            de uma matriz que tem caracteres de pontuação
 * \param matriz_indice_pavras - Matriz que contem os indices das palavras que estão representadas na matriz de palavras
 * \param linhas_matriz - linhas/paragrafos da mensagem
 * \param linhas_matriz_pontuacao - Vetor onde contem o tamanho de cada linha da matriz de pontuacao
 * \param linhas_matriz_indices - Vetor onde contem o tamanho de cada linha da matriz de indices
 * \param pontuacao - Matriz onde contem os caracteres de pontuação
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param size_matriz_palavras - Numero de linhas da matriz de palavras
 *
 */
void reconstruir_mensagem(int ** matriz_pontuacao, int ** matriz_indice_palavras, int linhas_matriz, int * linhas_matriz_pontuacao, int * linhas_matriz_indices, char ** pontuacao, char ** matriz_palavras, int size_matriz_palavras  )
{
    int i=0,j=0,index=0,len=0;
    char ** mensagem_reconstruida = NULL;
    char buff[200]="\0";
    mensagem_reconstruida = criar_matriz(linhas_matriz); // Cria um vetor de apontadores para strings que vão ser postriormente criadas

    // precorre a matriz de pontuação
    for(i=0; i<linhas_matriz; i++)
    {
        for(j=0; j<linhas_matriz_pontuacao[i]; j++)
        {
            // se for igual a 0 representa que naquele indice está uma palavra
            if(matriz_pontuacao[i][j] == 0)
            {
                strcat(buff, matriz_palavras[matriz_indice_palavras[i][index]]); // Adiciona ao buffer a palavra
                // matriz_indice_palavras[i][index] dá o valor ( que esta presente na matriz de indices) do indice da palavra na matriz_palavras

                if(j != linhas_matriz_pontuacao[i]) // se não for o fim da frase
                {
                    //printf("entrou palavra\n");
                    strcat(buff, " "); // adiciona o espaço
                }
                index++; // variavel index para utilizar como indice na matriz de indices de palavras
            }
            else // se nao for igual a 0 quer dizer que é um caracter de pontuação
            {
                //printf("j+1= %d   ->  linhas_matriz_pontuacao[i] = %d\n",j+1,linhas_matriz_pontuacao[i]);
                //printf("matriz_pontuacao[%d][%d] = %s\n",i,j,pontuacao[matriz_pontuacao[i][j]]);
                strcat(buff, pontuacao[matriz_pontuacao[i][j]]); // adiciona um caracter de pontuação
                if(j+1 != linhas_matriz_pontuacao[i])
                {
                    //printf("entrou pontuacao\n");
                    strcat(buff, " ");
                }
            }
        }
        len = strlen(buff);
        index = 0;
        mensagem_reconstruida[i] = (char*)malloc((len+1)*sizeof(char));
        strcpy(mensagem_reconstruida[i], buff);
        mensagem_reconstruida[i][len]='\0';
        memset(buff,0,strlen(buff));
    }

    printf("\n\n\t\t\t\tMENSAGEM RECONSTRUIDA:\n\n");
    for(i=0; i<linhas_matriz; i++)
    {
        printf("%s\n", mensagem_reconstruida[i]);
    }
    //return mensagem_reconstruida;
}


/** \brief Função que calcula a frequencia de reutilização de uma palavra
 *
 * \param string - Palavra para calculo da frequencia de reutilização
 * \param total_palavras - Total de palavras da mensagem
 * \param linhas_matriz_mensagem - Tamanho da matriz de mensagens/ Numero de linhas/paragrafos
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param array_ocorrencias - Array de tamanho igual ao da matriz de palavras e o conteudo representa o numero de ocorrencias de cada palavra
 * \return Retorna a frequencia de reutilização de uma palavra
 *
 */
float frequencia_de_reutilizacao(char* string, int total_palavras, int linhas_matriz_mensagem, char ** matriz_palavras, int linhas_matriz_palavras, int *array_ocorrencias)
{
    int count=0, i, soma=0, controlo=0;
    float frequencia= 0.0;
    controlo = pesquisa_binaria(string, matriz_palavras, 0, linhas_matriz_palavras-1);
    if(controlo != -1)
    {
        count = array_ocorrencias[controlo];
        //printf("count = %d\n",count);
        //printf("coma = %d\n",soma);
        frequencia = (float)count / (float)total_palavras;
        //printf("frequencia = %f\n",frequencia);
        return frequencia;

    }
    else
    {
        printf("A palavra nao existe\n");
        return 0;
    }
}

/** \brief Função que permite contar a distância entre duas palavras na mensagem com recurso à matriz de indices
 *
 * \param string1 - Primeira palavra a procurar na matriz de indices. Contudo pode não ser a primeira
 * \param string2 - Segunda palavra a procurar na matriz de indices. Contudo pode não ser a segunda
 * \param matriz_indices - Matriz onde tem os indices das palavras da matriz de palavras
 * \param linhas_indices - Vetor usado para guardar o comprimento das linhas da matriz de indices
 * \param linhas_matriz_mensagem - Numero de linhas/paragrafos da mensagem
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \return Retorna a distancia entre as duas palavras
 *
 */
int contar_distancia_duas_palavras(char* string1, char* string2, int ** matriz_indices, int * linhas_indices, int linhas_matriz_mensagem, char ** matriz_palavras, int linhas_matriz_palavras)
{
    int i, j, pos_string1=0,pos_string2=0, string1_ocorr=0, string2_ocorr=0, count=1, resultado=0;

    string1_ocorr = pesquisa_binaria(string1, matriz_palavras, 0, linhas_matriz_palavras-1);
    //printf("indice 1 = %d\n", string1_ocorr);
    string2_ocorr = pesquisa_binaria(string2, matriz_palavras, 0, linhas_matriz_palavras-1);
    //printf("indice 2 = %d\n", string2_ocorr);

    if(string1_ocorr !=-1 && string1_ocorr != -1)
    {
        count = 1;

        for(i=0; i<linhas_matriz_mensagem; i++)
        {
            for(j=0; j<linhas_indices[i]; j++)
            {
                if(string1_ocorr == matriz_indices[i][j])
                {
                    pos_string1 = count;
                    break;
                }
                count++;
            }
            if(j!=linhas_indices[i])
            {
                break;
            }
        }

        count = 1;

        for(i=0; i<linhas_matriz_mensagem; i++)
        {
            for(j=0; j<linhas_indices[i]; j++)
            {
                if(string2_ocorr == matriz_indices[i][j])
                {
                    pos_string2 = count;
                    break;
                }
                count++;
            }
            if(j!=linhas_indices[i])
            {
                break;
            }
        }

        if(pos_string1>pos_string2) // verifica qual das palavras aparece primeiro
        {
            resultado = pos_string1 - pos_string2 ;
            return resultado;
        }
        else
        {
            resultado = pos_string2 - pos_string1 ;
            return resultado;
        }
    }
    else
    {
        printf("Uma das palavras nao existe\n");
    }
}


/** \brief Função que faz a contagem do numero de frases que existe numa mensagem
 *
 * \param matriz_mensagem - Matriz que contém a mensagem
 * \param linhas_matriz_mensagem - Numero de linhas da matriz_mensagem
 * \return Retorna o numero de frases que existe na matriz mensagem
 *
 */
int numero_de_frases_mensagem (char** matriz_mensagem, int linhas_matriz_mensagem)
{
    int i=0,count=0;
    char str[400];
    //char s[4][2]= {'.','!','?','\n'};
    char s[] = ".!?\n";
    char *token;
    for(i=0; i<linhas_matriz_mensagem; i++)
    {
        strcpy(str,matriz_mensagem[i]);
        //printf("%s\n",str);

        token = strtok(str, s);
        //printf("Token = %s\n",token);
        while( token != NULL )
        {

            count++;
            //printf("COUNT :Token =%s\n",token);
            token = strtok(NULL, s);
        }
    }
    return count;
}


/** \brief Função que aloca memória para uma matriz de frases e copia as frases da matriz_mensagem para uma matriz de frases
 *
 * \param matriz_mensagem - Matriz que contém a mensagem
 * \param linhas_matriz_mensagem - Numero de linhas da matriz_mensagem
 * \param numero_frases - Numero de linhas que vai ter a matriz de frases. Neste caso é o numero de frases
 * \return Retorna um apontador para um apontador. Neste caso vai retorna o endereço da primeira posição da matriz de frases
 *
 */
char ** matriz_de_frases (char ** matriz_mensagem, int linhas_matriz_mensagem, int numero_frases)
{
    int i=0,len=0,index=0;
    // printf("numero frases = %d\n",numero_frases);
    char ** matriz_frases = (char**)malloc(numero_frases*sizeof(char*));
    char str[100], buff[100];
    //char s[4][2]= {'.','!','?','\n'};
    char s[] = ".!?\n";
    char *token;
    for(i=0; i<linhas_matriz_mensagem; i++)
    {
        strcpy(str,matriz_mensagem[i]);
        //printf("STR = %s\n",str);
        token = strtok(str, s);
        //printf("Token = %s\n",token);
        while( token != NULL )
        {
            //printf("index = %d\n",index);
            //printf("token = %s\n",token);
            if(token[0]==' ')
            {
                token = &token[1]; // o apontador token que estava a apontar para a posicao 0 passa a apontar para a posicao 1.
                // serve para corrigir os espaços que tem antes das frases
                // printf("string = %s\n", token);
            }
            len = strlen(token);
            if(token[len-1]==' ') // serve para corrigir eventuais espaços no fim da frases.
            {
                token[len-1]=token[len];
//        printf("token = %s\n",token);
            }
            len = strlen(token);
            //printf("LEN = %d - STRING =%s\n",len,token);
            matriz_frases[index]=(char*)malloc((len+1)*sizeof(char));
            strcpy(matriz_frases[index],token);
            matriz_frases[index][len] = '\0';
            index++;
            token = strtok(NULL, s);
            //printf("TOKEN 2 : %s\n", token);
        }
    }
    return matriz_frases;
}


/** \brief Função que faz o calculo do TF-IDF de uma dada palavra (!REVISÃO!)
 *
 * \param string - Palavra para calcular o TF-IDF
 * \param matriz_indices - Matriz de indices de palavras que estão na matriz de palavras
 * \param linhas_indices - Tamanho de cada linha da matriz de indices
 * \param linhas_matriz_mensagem - Numero de linhas da matriz que contem a mensagem
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 *
 */
void term_frequency_inverse_document_frequency(char * string, int ** matriz_indices, int * linhas_indices, int linhas_matriz_mensagem, char ** matriz_palavras, int linhas_matriz_palavras)
{
    int controlo = 0;
    controlo = pesquisa_binaria(string,matriz_palavras,0,linhas_matriz_palavras-1);
    if(controlo==-1)
    {
        printf("A palavra nao existe\n");
    }
    else
    {
        int i,j, numero_paragrafos, numero_palavras_paragrafo, count=0, numero_paragrafos_com_a_string=0;
        int *numero_de_ocorrencias_paragrafo = (int*)calloc(linhas_matriz_mensagem, sizeof(int));
        //contar numero de ocorrencias da palavra em cada paragrafo e guardar num vetor
        for(i=0; i<linhas_matriz_mensagem; i++)
        {
            for(j=0; j<linhas_indices[i]; j++)
            {
                if(controlo==matriz_indices[i][j])
                {
                    count++;
                }
            }
            if(count!=0)
            {
                numero_paragrafos_com_a_string++;
            }
            numero_de_ocorrencias_paragrafo[i] = count;
            count=0;
        }
        // calculo do term frequency
        double * tfidf = (double*)calloc(linhas_matriz_mensagem,sizeof(double));
        double aux1=0.0, aux2=0.0, aux3 = 0.0;
        for(i=0; i<linhas_matriz_mensagem; i++)
        {
            if(numero_de_ocorrencias_paragrafo!=0)
            {
                aux1 = (double)numero_de_ocorrencias_paragrafo[i] / (double)linhas_indices[i]; // Tf = nº ocorrencias / nº total de elementos
                aux2 = (double)linhas_matriz_mensagem / (double)numero_paragrafos_com_a_string; // idf = log10(nº total de linhas / nº de linhas em que a palavra aparece)
                aux3 = log10(aux2);
                aux2 = aux1*aux3; // td-idf = tf * idf
                tfidf[i]=aux2;
            }
        }
        for(i=0; i<linhas_matriz_mensagem; i++)
        {
            printf("term frequency–inverse document frequency %d - > %f\n",i, tfidf[i]);
        }
        free(numero_de_ocorrencias_paragrafo);
    }
}

/** \brief Função para criar a bag-of-words. Entendi como bag-of-words todas as palavras sem repetições ordenadas pelo numero de ocorrencias
 *
 * \param matriz_indices - Matriz de indices de palavras que estão na matriz de palavras
 * \param linhas_indices - Tamanho de cada linha da matriz de indices
 * \param linhas_matriz_mensagem - Numero de linhas da matriz que contem a mensagem
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param array_ocorrencias - Vetor onde contem o numero de ocorrencias de cada palavra na mensagem
 *
 */
void bag_of_words(char** matriz_palavras,int** matriz_indices, int* linhas_indices, int linhas_matriz_palavras, int * array_ocorrencias, int linhas_matriz_mensagem)
{
    struct index *indice;
    indice = (struct index *)malloc(linhas_matriz_palavras*sizeof(struct index));
    int i,len ;
    for(i=0; i<linhas_matriz_palavras; i++)
    {
        //copiar da matriz para a estrutura
        len = strlen(matriz_palavras[i]);
        indice[i].str = (char*)malloc((len+1)*sizeof(char));
        strcpy(indice[i].str, matriz_palavras[i]);
        indice[i].str[len]='\0';
        indice[i].len = len;
        indice[i].numero_ocorrencias = array_ocorrencias[i];
        //printf("array_ocorrencias = %d\n", array_ocorrencias[i]);
        //printf("i = %d\n",i);
        //printf("String[%d]=%s\n",i,indice[i].str);
        //printf("Len = %d\n",indice[i].len);
        //printf("Numero de ocorrencias = %d\n", indice[i].numero_ocorrencias);
        //printf("-----------------------------\n");
    }
    qsort(indice, linhas_matriz_palavras,sizeof(struct index),(const void*)comparar );

    for(i=0;i<linhas_matriz_palavras;i++){
      printf("%s\n", indice[i].str);
    }

}

int comparar(struct index *elem1, struct index *elem2)
{
    if ( elem1->numero_ocorrencias < elem2->numero_ocorrencias)
        return 1;

    else if (elem1->numero_ocorrencias > elem2->numero_ocorrencias)
        return -1;

    else
        return 0;
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



/** \brief Função que permite colocar as letras de uma matriz todas em letras pequenas
 *
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem
 * \param linhas_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 *
 */
void colocar_tudo_letras_pequenas(char ** matriz_palavras, int linhas_palavras)
{
    int i ;
    char c;
    for(i=0; i<linhas_palavras; i++)
    {
        c = tolower(*(*(matriz_palavras+i)));
        *(*(matriz_palavras+i)) = c;
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
//    printf("entrou\n");
//    print_matriz(tudo,3);
//    printf("procura = %s\n",procura);
//    printf("low = %d\n",low);
//    printf("high = %d\n", high);
    int mid, cmp;
    if (low > high)
    {
        return -1;
    }
    mid = (low + high) / 2;
    cmp = strcmp( procura, tudo[mid]);
//    printf("aqui\n");
//    printf("procura1 = %s\n", procura);
//    printf("tudo[mid] = %s\n", tudo[mid]);
//    printf("mid = %d\n",mid);

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



/** \brief Conta as linhas de um ficheiro texto. O fgets guarda o conteudo no buff ate encontrar o \n e vai
            fazendo isso até não ter mais nada para ler
 *
 * \param path - Diretorio para o ficheiro que se pertende ler
 * \return Retorna o numero de linhas (\n) do ficheiro
 *
 */
int contar_linhas(char * path)
{
    FILE *fp = NULL;
    char buff[400];
    int i=0;
    fp = fopen(path, "r");

    while(fgets(buff, 400, fp)!= NULL)
    {
        //printf("%s",buff);
        i++;
    }

    fclose(fp);

    return i;
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

/** \brief Função para passar o conteudo de um ficheiro e alocar memoria para o tamanho desse conteudo para uma matriz
 *
 * \param matriz - Matriz de strings que vai ser preenchida com o conteudo do ficheiro
 * \param linhas - Numero de linnhas do ficheiro
 * \param path - Diretorio para o ficheiro que se pertende ler
 *
 */
void ficheiro_para_matriz_mensagem(char ** matriz, int linhas, char* path)
{
    FILE * fp = NULL;
    char  buff[400];
    int i=0,size=0;
    fp = fopen(path,"r");
    i=0;
    while(fgets(buff,400,fp)!=NULL)
    {
        size=strlen(buff);
        if(buff[size-1] == '\n') // retura o caracter \n do buff para não ser copiado para a matriz
        {
            buff[size-1] = '\0';
            size = strlen(buff);
        }
        *(matriz+i) = (char*)malloc((size+1)*sizeof(char)); // alocar memoria para a matriz
        strcpy(*(matriz+i),buff);
        *(*(matriz+i)+size) = '\0';
        i++;
    }
    fclose(fp);
}

/** \brief Função para imprimir uma matriz de char's
 *
 * \param matriz - Matriz para imprimir
 * \param linhas - Numero de linhas da matriz que se quer imprimir
 *
 */
void print_matriz(char ** matriz, int linhas )
{
    int i ;
    for(i=0; i<linhas; i++)
    {
        printf("|%d| - %s\n",i,*(matriz+i));
    }
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
    int i=0, count=0, size=0, pontuacao=0,controlo=0;
    char s[] = " \n";
    //char s[7][7] = {' ','\n'};
    char c;
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


/** \brief Função que faz o preenchimento da matriz de pontuação . A matriz de pontuação vai ter valores de 0 até 5 em que o 0 representa palavras e os restantes representam
        indices de caracteres de pontuação da uma matriz predefenida .
 *
 * \param matriz_mensagem - Matriz com a mensagem completa
 * \param linhas_mensagem - Numero de linhas da matriz de mensagem
 * \param matriz_de_pontuacao - endereço da primeira posição de um vetor de apontadores para inteiros, para posterior alocação de memoria e preenchimento
 * \param pontuacao - matriz predefenida com os caracteres de pontuação
 * \param size_pontuacao - Numero de linhas da matriz de pontuação
 * \return Retorna endereço da primeira posição de um vetor que contem o tamanho das linhas da matriz de pontuação
 *
 */
int * matriz_de_pontuacao (char ** matriz_mensagem, int linhas_mensagem,int ** matriz_de_pontuacao, char ** pontuacao, int size_pontuacao)
{
    int i=0 ;
    int * count = NULL;
    count = count_matriz_de_pontuacao(matriz_mensagem,linhas_mensagem); // contagem de palavras e pontuação em cada linha da mensagem
    for(i=0; i<linhas_mensagem; i++)
    {
        //printf("count = %d\n",count[i]);
        *(matriz_de_pontuacao+i) = (int*)calloc(count[i],sizeof(int));
    }

    char str[100];
    int j=0,index=0, controlo1=0, controlo2=0, aux=0, len;
    //char s[2][5] = {' ','\n'};
    char s[] = " \n";
    char *token;

    for(i=0; i<linhas_mensagem; i++)
    {
        strcpy(str,*(matriz_mensagem+i));
        //printf("str = %s\n",str);
        token = strtok(str,s);
        while( token != NULL )
        {
            //printf("index = %d\n",index);
            //printf("token= %s\n",token);
            controlo1=verificar_se_palavra_e_pontuacao(token);
            controlo2=verificar_pontuacao_palavra(token);
            if(controlo1 != 0) // Se for um caracter de pontuaçao isolado . ex: " ? "
            {
                len = strlen(token);
                for(j=1; j<size_pontuacao; j++)
                {
                    if(token[len-1]==pontuacao[j][0])
                    {
                        //printf("j= %d token[len-1]=%c , pontuacao = %c\n",j, token[len-1], pontuacao[j][0]);
                        break;
                    }
                }
                matriz_de_pontuacao[i][index] = j;
                //printf("Matriz_de_pontuacao[%d]=%d\n", index , matriz_de_pontuacao[index]);
                //printf("controlo1 - >index = %d , i = %d\n", index, i );
                index++;
            }
            else if (controlo2 != 0) // se for um caracter de pontuação junto com uma palavra . Ex: "ola."
            {

                index ++; // incrementa index primeiro porque é a posição da palavra
                len = strlen(token);
                for(j=1; j<size_pontuacao; j++)
                {
                    if(token[len-1]==pontuacao[j][0])
                    {
                        break;
                    }
                }
                matriz_de_pontuacao[i][index] = j;
                //printf("Matriz_de_pontuacao[%d]=%d\n", index , matriz_de_pontuacao[index]);
                //printf("controlo2 - >index = %d , i = %d\n", index, i );
                index++;

            }
            else // se for uma palavra sem nenhum caracter de pontuação
            {
                matriz_de_pontuacao[i][index] = 0;
                //printf("Matriz_de_pontuacao[%d]=%d\n", index , matriz_de_pontuacao[index]);
                //printf("controlo3 - >index = %d , i = %d\n", index, i );
                index++;
            }
            token = strtok(NULL, s);
        }
        index = 0;
    }
    return count;
}



/** \brief Função que faz a contagem de palavras e caracteres de pontução de cada linha de uma matriz que contenha uma mensagem
 *
 * \param matriz_mensagem - Matriz que contem uma mensagem
 * \param linhas_mensagem - Numero de linhas da matriz que contem a mensagem
 * \return Retorna o endereço da primeira posição de um vetor com a contagem de palavras e caracteres de cada linha.
 *
 */
int * count_matriz_de_pontuacao (char ** matriz_mensagem, int linhas_mensagem)
{
    char str[100];
    int i=0, controlo1=0, controlo2=0;
    //char s[2][5] = {' ','\n'};
    char s[] = " \n";
    char *token;

    int * size_matriz_pontuacao = (int*)malloc(linhas_mensagem*sizeof(int));

    int size=1;

    for(i=0; i<linhas_mensagem; i++)
    {
        strcpy(str,*(matriz_mensagem+i));
        token = strtok(str,s);
        while( token != NULL )
        {
            controlo1=verificar_se_palavra_e_pontuacao(token);
            controlo2=verificar_pontuacao_palavra(token);
            if(controlo1 != 0)
            {
                size++;
            }
            else if (controlo2 != 0)
            {
                size = size+2;
            }
            else
            {
                size++;
            }
            token = strtok(NULL, s);
        }
        size_matriz_pontuacao[i] = size-1;
        size = 1;
    }
    return size_matriz_pontuacao;
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



/** \brief Função que calcula a frequencia relativa de cada letro do alfabeto
 *
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param array_ocorrencias - Vetor que contem todas as ocorrencias de cada palavra numa mensagem.
 *
 */
void frequencia_relativa_letras_alfabeto(char ** matriz_palavras, int linhas_matriz_palavras, int * array_ocorrencias)
{

    int tamanho_alfabeto = 26, i=0, j=0, len=0,count=0,aux=0;
    int contagem_letras_alfabeto[26];
    float frequencia_de_utilizacao_letras[26];

    // Inicializar a 0 cada vetor
    for(i=0; i<26; i++)
    {
        contagem_letras_alfabeto[i] =0;
        frequencia_de_utilizacao_letras[i]=0.0;
    }

    for(i=0; i<linhas_matriz_palavras; i++)
    {
        len = strlen(matriz_palavras[i]);
        for(j=0; j<len; j++)
        {
            aux = matriz_palavras[i][j] - 'a'; // aux vai ficar com o valor do indice do vetor de contagem_letras_alfabeto

            contagem_letras_alfabeto[aux] = contagem_letras_alfabeto[aux] + array_ocorrencias[i];
            count ++; // contador para contar o numero de letras de uma mensagem
        }
    }
    for(i=0; i<tamanho_alfabeto; i++)
    {
        frequencia_de_utilizacao_letras[i] = (float)contagem_letras_alfabeto[i] / (float)count;
        frequencia_de_utilizacao_letras[i] = frequencia_de_utilizacao_letras[i] *100;
    }
    for(i=0; i<tamanho_alfabeto; i++)
    {
        printf("Frequencia relativa de %c = %0.2f %% \n",i+'a', frequencia_de_utilizacao_letras[i]);
    }
}



/** \brief Função que calcula a média do tamanho das palavras de uma matriz
 *
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param array_ocorrencias - Vetor que contem todas as ocorrencias de cada palavra numa mensagem
 * \param total_palavras - Valor do total de todas as palavras que existem numa mensagem
 * \return Retorna uma variáver do tipo float que é o valor do calculo da media
 *
 */
float calculo_media_palavras(char ** matriz_palavras, int linhas_matriz_palavras, int * array_ocorrencias, int total_palavras)
{
    int i=0, len=0, total_len=0, aux=0, soma=0;

    float media=0.0;
    for(i=0; i<linhas_matriz_palavras; i++)
    {
        len = strlen(matriz_palavras[i]);
        aux = len * array_ocorrencias[i];
        total_len = total_len + aux;
    }
    media = (float)total_len/(float)total_palavras;

    return media;
}




/** \brief Função que calcula a frequencia relativa das palavras que são menores que M
 *
 * \param matriz_palavras - Matriz onde contem todas as palavras que estao na mensagem de forma ordenada e sem repetições
 * \param linhas_matriz_palavras - Tamanho da matriz de palavras/ Numero de linhas da matriz de palavras
 * \param array_ocorrencias - Vetor que contem todas as ocorrencias de cada palavra numa mensagem
 * \param M - Tamanho
 * \param total_palavras - Valor do total de todas as palavras que existem numa mensagem
 * \return Retorna uma variavel do tipo float que contem o valor da frequencia relativa das palavras menores que M
 *
 */

float frequencia_relativa_palavras_menores_m(char ** matriz_palavras, int linhas_matriz_palavras, int *array_ocorrencias, int M, int total_palavras)
{

    int i=0, count=0, aux =0, len=0;
    float frequencia= 0.0;

    for(i=0; i<linhas_matriz_palavras; i++)
    {
        len = strlen (matriz_palavras[i]);
        if(len <= M)
        {
            count ++;
        }
    }
    //printf("count = %d\n",count);
    //printf("total_palavras = %d\n",total_palavras);
    frequencia = (float)count / (float)total_palavras;
    return frequencia;
}





