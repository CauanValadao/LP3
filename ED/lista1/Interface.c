char menu(){
    char escolha;
  
    printf("\n----------------------------");
    printf("\n 1 - Cadastrar Aluno");
    printf("\n 2 - Exibir Alunos");
    printf("\n 3 - Consultar Aluno");
    printf("\n 4 - Remover Aluno");
    printf("\n 5 - Ordenar Crescentemente");
    printf("\n 6 - Sair do programa");
    printf("\n Escolha uma das opções acima: ");
    do{
      escolha = getch();
    }while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5') && (escolha !='6'));
    printf(" %c \n----------------------------", escolha);
    return  escolha;
}

void cadastrarLstE(tpNo **lstAl){
    tpItem aluno;
    char nome[30];
    unsigned int mat;

    printf("\n Digite o nome do aluno: ");
    fgets(nome,sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    getchar();
    aluno = setItem(nome,mat);
    tpNo *lstAux =insertLstE(*lstAl, aluno);
    if ( isEmptyLstE(lstAux) ){
        printf("\n ERRO - aluno não cadastrado");
    } else {
        printf("\n CADASTRO COM SUCESSO!!!");
        *lstAl = lstAux;
    }

}

void consultarLstE(tpNo *lstAl){
    unsigned int mat;

    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    getchar();
    tpItem *al = searchItemLstE(lstAl,mat);
    if ( al != NULL ){
        printf("\n aluno cadastrado");
        printf("\n Nome do aluno: %s", al->nome);
    } else {
        printf("\n ALUNO NÃO CADASTRADO!!!");
    }
}

void removerItemLstE(tpNo **lstAl){
    unsigned int mat;

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    /*tpNo* aux = removeItemLstE( mat, *lstAl);
    *lstAl = aux;*/
    booleano removido = removeItemLstE(mat, lstAl);
    if(removido == 1){
        printf("\n ALUNO REMOVIDO COM SUCESSO!!!");
    } else {
        printf("\n ALUNO NÃO CADASTRADO!!!");
    }
    
}


void lstEncadeada(){
    tpNo *lstAlunos = initLstE();
    printf("PROGRAMA ALUNOS!\n");
    char op;
    do{
            op = menu();
            switch (op){
                case '1': cadastrarLstE(&lstAlunos);
                          break;
                case '2': printLstE(lstAlunos);
                          break;
                case '3': consultarLstE(lstAlunos);
                          break;
                case '4': removerItemLstE(&lstAlunos);
                          break;	
                case '5': ordenarLstE(lstAlunos);
                          break;	
                case '6': printf("\n Hasta la vista baby!");
            }
    }while (op != '6');
}