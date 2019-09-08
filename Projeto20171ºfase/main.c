#include "projeto_funcoes.h"

int main()
{


    //client_main_funcoes();


    char *** array_apont_matrizes_mensagens = NULL;
    char *** array_apont_matrizes_palavras = NULL;
    char *** array_apont_matrizes_frases = NULL;

    int *** array_apont_matrizes_indices = NULL;
    int ** linhas_de_indices = NULL;
    int ** array_de_ocorrencias = NULL;

    int *** array_apont_matrizes_indices_pontuacao = NULL;
    int ** linhas_de_indices_pontuacao = NULL;

    int * total_palavras = NULL;

    int count = -1; // para o primeiro caso . Caso o count seja -1 quer dizer que nao ha mensagens

    char pathfile[50]="./data/";

    //char *pathfile = "./data/mensagem.txt";
    //char ** matriz_mensagem = NULL;
    //char ** matriz_palavras = NULL;
    //char ** matriz_frases = NULL;
    //int ** matriz_de_indices=NULL;
    //int * linhas_de_indices=NULL;
    //int * array_de_ocorrencias=NULL;
    //int ** matriz_indices_pontuacao = NULL;
    //int * linhas_de_indices_pontuacao = NULL;
    //int total_palavras = 0;


    char *pontuacao[5]= {"0","!",",",".","?"};
    int caracteres_pontuacao = 5;


    int * linhas_matriz_mensagem = NULL;
    int * linhas_matriz_palavras = NULL;
    int * linhas_matriz_frases = NULL;

    int i=0, auxiliar =0;
    int menu;
    char buffer[50]; // buffer para os inputs
    char string[20];

//    client_main_funcoes();

    do
    {
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\tInstant messaging\n\n\n");
        printf("\t\t\t\t\t   ______________________________________________\n");
        printf("\t\t\t\t\t|1|- Copiar mensagem de ficheiro texto           |\n");
        printf("\t\t\t\t\t|2|- Mostrar mensagens                           |\n");
        printf("\t\t\t\t\t|3|- Matriz de palavras de uma mensagem          |\n");
        printf("\t\t\t\t\t|4|- Matriz de indices de uma mensagem           |\n");
        printf("\t\t\t\t\t|5|- Bag-of-words de uma mensagem                |\n");
        printf("\t\t\t\t\t|6|- Matriz de frases de uma mensagem            |\n");
        printf("\t\t\t\t\t|7|- Reconstruir uma determinada mensagem        |\n");
        printf("\t\t\t\t\t|8|- Pesquisa numa mensagem                      |\n");
        printf("\t\t\t\t\t|9|- Estatisticas de uma determinada mensagem    |\n");
        printf("\t\t\t\t\t|0|- Sair                                        |\n");
        printf("\t\t\t\t\t   ______________________________________________\n");
        scanf("%d",&menu);

        switch(menu)
        {
        case 1:
            system("CLS");
            if(count == -1)
            {
                count++;
                //printf("count = %d\n",count);
                printf("Insira o nome do fichero:\n");
                scanf("%s",string);
                strcat(string,".txt");
                strcat(pathfile,string);


                array_apont_matrizes_mensagens =(char***)realloc(array_apont_matrizes_mensagens,count+1);
                linhas_matriz_mensagem = (int*)realloc(linhas_matriz_mensagem,count+1);
                array_apont_matrizes_palavras =(char***)realloc(array_apont_matrizes_palavras,count+1);
                linhas_matriz_palavras = (int*)realloc(linhas_matriz_palavras,count+1);
                array_apont_matrizes_frases =(char***)realloc(array_apont_matrizes_frases,count+1);
                linhas_matriz_frases = (int*)realloc(linhas_matriz_frases,count+1);
                array_apont_matrizes_indices =(int***)realloc(array_apont_matrizes_indices,count+1);
                linhas_de_indices =(int**)realloc(linhas_de_indices,count+1);
                array_de_ocorrencias = (int**)realloc(array_de_ocorrencias, count+1);
                array_apont_matrizes_indices_pontuacao=(int***)realloc(array_apont_matrizes_indices_pontuacao,count+1);
                linhas_de_indices_pontuacao =(int**)realloc(linhas_de_indices_pontuacao,count+1);
                total_palavras = (int*)realloc(total_palavras,count+1);


            }
            else
            {
                count ++;
                strcpy(pathfile,"./data/");
                printf("count = %d\n",count);
                printf("Insira o nome do fichero:\n");
                scanf("%s",string);
                strcat(string,".txt");
                strcat(pathfile,string);

                array_apont_matrizes_mensagens =(char***)realloc(array_apont_matrizes_mensagens,count+1);
                linhas_matriz_mensagem = (int*)realloc(linhas_matriz_mensagem,count+1);
                array_apont_matrizes_palavras =(char***)realloc(array_apont_matrizes_palavras,count+1);
                linhas_matriz_palavras = (int*)realloc(linhas_matriz_palavras,count+1);
                array_apont_matrizes_frases =(char***)realloc(array_apont_matrizes_frases,count+1);
                linhas_matriz_frases = (int*)realloc(linhas_matriz_frases,count+1);
                array_apont_matrizes_indices =(int***)realloc(array_apont_matrizes_indices,count+1);
                linhas_de_indices =(int**)realloc(linhas_de_indices,count+1);
                array_de_ocorrencias = (int**)realloc(array_de_ocorrencias, count+1);
                array_apont_matrizes_indices_pontuacao=(int***)realloc(array_apont_matrizes_indices_pontuacao,count+1);
                linhas_de_indices_pontuacao =(int**)realloc(linhas_de_indices_pontuacao,count+1);
                total_palavras = (int*)realloc(total_palavras,count+1);

            }

            *(linhas_matriz_mensagem+count) = contar_linhas(pathfile);
            *(array_apont_matrizes_mensagens+count) = criar_matriz(*(linhas_matriz_mensagem+count));
            ficheiro_para_matriz_mensagem(*(array_apont_matrizes_mensagens+count), *(linhas_matriz_mensagem+count), pathfile);
            printf("Mensagem copiada com sucesso\n\n\n");
            print_matriz(*(array_apont_matrizes_mensagens+count),*(linhas_matriz_mensagem+count));

            /*




            // criação da matriz de palavras




            */

            *(linhas_matriz_palavras+count) = contar_numero_de_palavras_mensagem(*(array_apont_matrizes_mensagens+count), *(linhas_matriz_mensagem+count));
            *(array_apont_matrizes_palavras+count) = criar_matriz(*(linhas_matriz_palavras+count));
            *(array_apont_matrizes_indices+count) = criar_matriz_indices(*(linhas_matriz_mensagem+count));
            *(linhas_de_indices+count) = criar_array_tamanho_indices(*(linhas_matriz_mensagem+count));
            preencher_matriz_palavras(*(array_apont_matrizes_mensagens+count),*(linhas_de_indices+count),*(array_apont_matrizes_indices+count), *(linhas_matriz_mensagem+count), *(linhas_matriz_mensagem+count), *(array_apont_matrizes_palavras+count));
            colocar_tudo_letras_pequenas(*(array_apont_matrizes_palavras+count),*(linhas_matriz_palavras+count));
            retirar_carateres_pontuacao_palavra(*(array_apont_matrizes_palavras+count),*(linhas_matriz_palavras+count));



            //ORDENAÇÃO


            int lo=0, hi=*(linhas_matriz_palavras+count)-1, d=0;

            StringElementsArray a;
            StringElementsArray aux;
            createStringElementsArrayAndFill(&a,*(linhas_matriz_palavras+count),*(array_apont_matrizes_palavras+count));
            createStringElementsArray(&aux,*(linhas_matriz_palavras+count));
            msd_sort_whithout_cutoff(&a,&aux,lo,hi,d, CHAR_8BIT_RADIX);
            *(array_apont_matrizes_palavras+count) = criar_matriz_ordenada(*(array_apont_matrizes_palavras+count),&a, &*(linhas_matriz_palavras+count));

            freeStringElementsArray(&a);
            freeStringElementsArray(&aux);







            /*




            // criação da matriz de indices




            */


            preencher_matriz_indices(*(array_apont_matrizes_indices+count), *(array_apont_matrizes_mensagens+count), *(array_apont_matrizes_palavras+count), *(linhas_matriz_palavras+count),*(linhas_matriz_mensagem+count));
            *(array_de_ocorrencias+count)= numero_de_ocorrencias(*(array_apont_matrizes_indices+count),*(array_apont_matrizes_palavras+count),*(linhas_matriz_palavras+count),*(linhas_de_indices+count),*(linhas_matriz_mensagem+count));
            *(total_palavras+count) = total_de_palavras(*(linhas_matriz_palavras+count), *(array_de_ocorrencias+count));



            /*




            // criação da matriz de frases




            */


            *(linhas_matriz_frases+count) = numero_de_frases_mensagem (*(array_apont_matrizes_mensagens+count),*(linhas_matriz_mensagem+count));
            *(array_apont_matrizes_frases+count) = matriz_de_frases (*(array_apont_matrizes_mensagens+count),*(linhas_matriz_mensagem+count),*(linhas_matriz_frases+count));

            /*




            // criação da matriz de pontuação




            */

            *(array_apont_matrizes_indices_pontuacao+count) = criar_matriz_indices(*(linhas_matriz_mensagem+count));
            *(linhas_de_indices_pontuacao+count) = matriz_de_pontuacao (*(array_apont_matrizes_mensagens+count), *(linhas_matriz_mensagem+count), *(array_apont_matrizes_indices_pontuacao+count), pontuacao, caracteres_pontuacao);


            printf("\n\n\n\n\n\n");
            int opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 2:
            system("CLS");
            printf("Escolher uma mensagem que quer imprimir: \n\n");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                print_matriz(*(array_apont_matrizes_mensagens+auxiliar), *(linhas_matriz_mensagem+auxiliar));
            }
            printf("\n\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }
            }
            break;
        case 3:
            system("cls");
            printf("Escolher uma mensagem para imprimir a matriz de palavras: \n\n");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                printf("Matriz de palavras : \n\n\n\n\n");
                print_matriz(*(array_apont_matrizes_palavras+auxiliar), *(linhas_matriz_palavras+auxiliar));
            }
            printf("\n\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 4:
            system("cls");
            printf("Escolher uma mensagem para imprimir a matriz de indices: \n\n");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                printf("Matriz de indices : \n\n\n\n\n");
                print_matriz(*(array_apont_matrizes_palavras+auxiliar), *(linhas_matriz_palavras+auxiliar));
                printf("\n\n\n");
                print_matriz_indices(*(array_apont_matrizes_indices+auxiliar),*(linhas_matriz_mensagem+auxiliar),*(linhas_de_indices+auxiliar));
            }

            printf("\n\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 5:
            system("cls");
            printf("Escolher uma mensagem para imprimir a bag-of-words: \n\n");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                printf("Bag-of-words : \n\n\n\n\n");

                bag_of_words(*(array_apont_matrizes_palavras+auxiliar),*(array_apont_matrizes_indices+auxiliar),*(linhas_de_indices+auxiliar), *(linhas_matriz_palavras+auxiliar), *(array_de_ocorrencias+auxiliar), *(linhas_matriz_mensagem+auxiliar));


            }

            printf("\n\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 6:
            system("cls");
            printf("Escolher uma mensagem para imprimir a matriz de frases: \n\n");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                printf("Matriz de frases : \n\n\n\n\n");

                print_matriz(*(array_apont_matrizes_frases+auxiliar),*(linhas_matriz_frases+auxiliar));


            }


            printf("\n\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 7:
            system("cls");
            printf("Escolher uma mensagem para reconstruir: \n\n");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                printf("Mensagem reconstruida : \n\n\n\n\n");

                reconstruir_mensagem(*(array_apont_matrizes_indices_pontuacao+auxiliar), *(array_apont_matrizes_indices+auxiliar),*(linhas_matriz_mensagem+auxiliar),*(linhas_de_indices_pontuacao+auxiliar), *(linhas_de_indices+auxiliar), pontuacao, *(array_apont_matrizes_palavras+auxiliar), *(linhas_matriz_palavras+auxiliar));


            }
            printf("\n\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 8:
            system("cls");
            auxiliar = 0;
            for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
            {
                printf("[%d]- Mensagem %d \n", i+1,i+1);
            }
            scanf("%d", &auxiliar);
            auxiliar = auxiliar-1;
            system("cls");
            if(auxiliar>=0 && auxiliar<=count)
            {
                printf("Digite o padrao ou palavra que quer procurar:\n");
                scanf("%s",buffer);
                printf("\n\n\n\n\n");
                print_matriz(*(array_apont_matrizes_mensagens+auxiliar),*(linhas_matriz_mensagem+auxiliar));
                printf("\n\n\n\n\n");
                procurar_padrao (*(array_apont_matrizes_mensagens+auxiliar),*(linhas_matriz_mensagem+auxiliar),buffer);

            }
            printf("\n\n\n\n\n");
            opt=0;
            while(opt!=1)
            {
                printf("|1|- Voltar\n");
                printf("|0|- Sair\n");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    system("cls");
                    break;
                case 0:
                    exit(0);
                    break;
                }

            }
            break;
        case 9:
            system("cls");
            printf("\n\n");
            int pt=100; // a 100 para nao intreferir com o switch visto que o 0 é o menu de voltar . Portanto o valor inicial nao pode ser 0
            while(pt!=0)
            {
                printf("|1|- Term frequency inverse document frequency\n");
                printf("|2|- Numero de paragrafos\n");
                printf("|3|- Frequencia de reutilizaçao de uma determinada palavra\n");
                printf("|4|- Comprimento medio das palavras\n");
                printf("|5|- Frequencia relativa das palavras com tamanho <=M\n");
                printf("|6|- Palavras com possiveis raizes comuns\n");
                printf("|0|- Voltar\n");
                scanf("%d",&pt);
                switch(pt)
                {
                case 1:
                    system("cls");
                    auxiliar = 0;
                    for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
                    {
                        printf("[%d]- Mensagem %d \n", i+1,i+1);
                    }
                    scanf("%d", &auxiliar);
                    auxiliar = auxiliar-1;
                    system("cls");
                    if(auxiliar>=0 && auxiliar<=count)
                    {

                        printf("Digite a palavra para o calculo:\n");
                        scanf("%s",buffer);
                        term_frequency_inverse_document_frequency(buffer, *(array_apont_matrizes_indices+auxiliar), *(linhas_de_indices+auxiliar), *(linhas_matriz_mensagem+auxiliar), *(array_apont_matrizes_palavras+auxiliar),  *(linhas_matriz_palavras+auxiliar));
                    }
                    printf("\n\n\n\n");

                    opt=0;
                    while(opt!=1)
                    {
                        printf("|1|- Voltar\n");
                        printf("|0|- Sair\n");
                        scanf("%d",&opt);
                        switch(opt)
                        {
                        case 1:
                            system("cls");
                            break;
                        case 0:
                            exit(0);
                            break;
                        }

                    }
                    break;
                case 2:
                    system("cls");
                    auxiliar = 0;
                    for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
                    {
                        printf("[%d]- Mensagem %d \n", i+1,i+1);
                    }
                    scanf("%d", &auxiliar);
                    auxiliar = auxiliar-1;
                    system("cls");
                    if(auxiliar>=0 && auxiliar<=count)
                    {

                        printf("O numero de paragrafos e = %d\n\n\n",*(linhas_matriz_mensagem+auxiliar));
                    }

                    opt=0;
                    while(opt!=1)
                    {
                        printf("|1|- Voltar\n");
                        printf("|0|- Sair\n");
                        scanf("%d",&opt);
                        switch(opt)
                        {
                        case 1:
                            system("cls");
                            break;
                        case 0:
                            exit(0);
                            break;
                        }

                    }
                    break;
                case 3:
                    system("cls");

                    auxiliar = 0;
                    for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
                    {
                        printf("[%d]- Mensagem %d \n", i+1,i+1);
                    }
                    scanf("%d", &auxiliar);
                    auxiliar = auxiliar-1;
                    system("cls");
                    if(auxiliar>=0 && auxiliar<=count)
                    {
                        printf("Digite palavra para o calculo:\n");
                        scanf("%s",buffer);
                        float x=0.0 ;
                        x = frequencia_de_reutilizacao(buffer, *(total_palavras+auxiliar), *(linhas_matriz_mensagem+auxiliar), *(array_apont_matrizes_palavras+auxiliar), *(linhas_matriz_palavras+auxiliar),*(array_de_ocorrencias+auxiliar));
                        printf("A frequencia de reutilizacao da palavra %s e : %f\n",buffer,x);

                    }

                    printf("\n\n\n\n");
                    opt=0;


                    while(opt!=1)
                    {
                        printf("|1|- Voltar\n");
                        printf("|0|- Sair\n");
                        scanf("%d",&opt);
                        switch(opt)
                        {
                        case 1:
                            system("cls");
                            break;
                        case 0:
                            exit(0);
                            break;
                        }

                    }

                    break;
                case 4:
                    system("cls");
                    auxiliar = 0;
                    for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
                    {
                        printf("[%d]- Mensagem %d \n", i+1,i+1);
                    }
                    scanf("%d", &auxiliar);
                    auxiliar = auxiliar-1;
                    system("cls");
                    if(auxiliar>=0 && auxiliar<=count)
                    {
                        float media = 0.0;
                        media = calculo_media_palavras(*(array_apont_matrizes_palavras+auxiliar), *(linhas_matriz_palavras+auxiliar), *(array_de_ocorrencias+auxiliar),*(total_palavras+auxiliar));
                        printf("Media = %f\n\n\n\n\n",media);

                    }
                    opt=0;
                    while(opt!=1)
                    {
                        printf("|1|- Voltar\n");
                        printf("|0|- Sair\n");
                        scanf("%d",&opt);
                        switch(opt)
                        {
                        case 1:
                            system("cls");
                            break;
                        case 0:
                            exit(0);
                            break;
                        }

                    }

                    break;
                case 5:
                    system("cls");
                    auxiliar = 0;
                    for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
                    {
                        printf("[%d]- Mensagem %d \n", i+1,i+1);
                    }
                    scanf("%d", &auxiliar);
                    auxiliar = auxiliar-1;
                    system("cls");
                    if(auxiliar>=0 && auxiliar<=count)
                    {
                        int M;
                        printf("Digite o valor para o M :\n",M);
                        scanf("%d",&M);
                        float frequencia = 0.0;
                        frequencia =  frequencia_relativa_palavras_menores_m(*(array_apont_matrizes_palavras+auxiliar),*(linhas_matriz_palavras+auxiliar), *(array_de_ocorrencias+auxiliar), M, *(total_palavras+auxiliar));
                        printf("Frequencia = %f\n",frequencia);

                    }
                    opt=0;
                    while(opt!=1)
                    {
                        printf("|1|- Voltar\n");
                        printf("|0|- Sair\n");
                        scanf("%d",&opt);
                        switch(opt)
                        {
                        case 1:
                            system("cls");
                            break;
                        case 0:
                            exit(0);
                            break;
                        }

                    }
                    break;
                case 6:
                    system("cls");
                    auxiliar = 0;
                    for(i=0; i<=count; i++) // menor ou igual porque o count começa em 0
                    {
                        printf("[%d]- Mensagem %d \n", i+1,i+1);
                    }
                    scanf("%d", &auxiliar);
                    auxiliar = auxiliar-1;
                    system("cls");
                    if(auxiliar>=0 && auxiliar<=count)
                    {
                        char buffer[50];
                        printf("Insira uma palavra para verificar se existe palavras com possiveis raizes comuns:\n");
                        scanf("%s",buffer);
                        palavras_com_possiveis_raizes_comuns(*(array_apont_matrizes_palavras+auxiliar),*(linhas_matriz_palavras+auxiliar),buffer);

                    }
                    opt=0;
                    while(opt!=1)
                    {
                        printf("|1|- Voltar\n");
                        printf("|0|- Sair\n");
                        scanf("%d",&opt);
                        switch(opt)
                        {
                        case 1:
                            system("cls");
                            break;
                        case 0:
                            exit(0);
                            break;
                        }

                    }
                    break;
                case 0:
                    system("cls");
                    break;
                }
            }

            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Valor invalido, tente novamente\n");
            break;

        }
    }
    while(menu !=0);
}




