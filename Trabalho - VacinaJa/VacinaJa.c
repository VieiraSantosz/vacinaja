#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CSV_IDX_CRM     0
#define CSV_IDX_NOME    1
#define CSV_IDX_STATUS  2
#define CSV_IDX_DT_INI  3
#define CSV_IDX_DT_FIN  4
#define CSV_IDX_CIDADE  5
#define CSV_IDX_UF      6
#define CSV_IDX_ESPECI  7


struct Fila {
	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens; 
};

typedef struct {
    char crm[6];
    char nome[45];
    char status;
    char data_ini[10];
    char data_fin[10];
    char cidade[40];
    char UF[2];
    char especialidades[145];
} registro_cremesp;

struct dados_vacina {
    int id;
    char nome[20];
    char fabricante[20];
    char tipo[50];
    int dose;
    char eficacia[20];
    char arman[50];
} vacina;

struct dados_lotesvacinas {
    int id_vacina;
    int id_lote;
    int qtd_frascos;
    char data_fabric[20];
    char data_venci[20];
} lotes;

struct dados_medico {
    int crm;
    char nome[50];
} medicos;

struct dados_municipio {
    char nome[50];
    char data[30];
    char cpf[20];
    char pais[20];
    char estado[20];
    char municipio[30];
    char rua[60];
    int num;
    char complemento[30];
    char bairro[20];
    char cep[20];
    char email[30];
    char celular[20];
} municipio;

registro_cremesp reg;
struct Fila umaFila;
FILE *file;

char nome[50];
char delim[] = ";";
char linha[250] = "\0";
char resp;
char respM;

int senha;
int count = 0; 
int rem_count = 0;
int opc, i = 0;
int qtd_frasco = 0;
int opcao, capa;
int valor;
int id;
int v = 0;
int num[50];


void login();
void info_medico();
void menu();
void cad_cidadao();
void cad_vacina();
void cad_lotevacina();
void suporte1();
void suporte2();
void suporte3();
void suporte4();
void suporte5();
void opcao_errada();


 int main() {
     setlocale (LC_ALL, "Portuguese");

    Inicio:
        printf ("\n\tVACINA JÁ!");
        printf ("\n\n_____________________________________\n\n");

        printf (" 1. Realizar LOGIN.");
        printf ("\n 2. Listar INFORMAÇÕES dos médicos cadastrado.");

        printf ("\n\n  Opção desejada: ");
        scanf ("%i", &i);
        if (i == 1) 
            goto Login;
        else if (i == 2)
            goto Informacoes;
        else
            opcao_errada();
            goto Inicio;

    Login:
        login();
        goto Menu;

    Informacoes:
        info_medico();

    Menu:
        menu();
        scanf ("%i", &opc);
        
        switch (opc)
        {
            case 0:
            break;
        
            case 1:
                Municipio:
                    cad_cidadao();

                OpcaoMun:
                    system("cls");
                    printf ("\n\n\tCADASTRO REALIZADO COM SUCESSO!\n");
                    printf ("\n 1. Cadastrar um novo Cidadão.");
                    printf ("\n 2. Voltar ao menu.");
                    printf ("\n 0. ENCERRAR.");

                    printf ("\n\n    Opção desejada: ");
                    scanf ("%i", &i);
                    if (i == 1) 
                        goto Municipio;
                    else if (i == 2)
                        goto Menu;
                    else if (i == 0)
                        return 0;
                    else
                        opcao_errada();
                        goto OpcaoMun;
            break;
        
            case 2:
                Vacina:
                    system ("cls");
                    printf ("\n\tESCOLHA UMA OPÇÃO!");
                    printf ("\n\n_____________________________________\n");

                    printf ("\n 1. Cadastrar uma Vacina / Lote.");
                    printf ("\n 2. Analizar Frascos.");
                    printf ("\n 0. ENCERRAR.");

                    printf ("\n\n  Opção desejada: ");
                    scanf ("%i", &opc);
                    
                    switch (opc)
                    {
                        case 1:
                            cad_vacina();

                            OpcaoLotes:
                                system("cls");
                                printf ("\n\n\tCADASTRO DA VACINA REALIZADO COM SUCESSO!\n\n\n");
                                printf ("Deseja cadastrar o Lote dessa Vacina? S - SIM // N -NÃO\n\n");

                                printf ("Digite sua Resposta - ");
                                fflush (stdin);
                                scanf ("%c", &resp);
                                respM = toupper(resp);

                                switch (respM)
                                {
                                    case 'S':
                                        cad_lotevacina();
                                    break;

                                    case 'N':
                                    break;

                                    default:
                                        goto OpcaoLotes;
                                break;
                                }
                    break;

                    case 2:
                    IdVacina:
                        system("cls");
                        printf ("\n\n   Digite o ID da Vacina: ");
                        scanf ("%i", &id);

                        if (id == 1) {
                            suporte1();
                            if (qtd_frasco == 50) {
                                printf ("\n\n\n\t\t      SUPORTE CHEIO!");

                                printf ("\n\n\n 1. Voltar ao Menu Vacina.");
                                printf ("\n 2. Retirar um Frasco da Vacina Sputnik V.");
                                printf ("\n 0. ENCERRAR.");

                                printf ("\n\n  Opção desejada: ");
                                scanf ("%i", &i);
                                if (i == 1) 
                                    goto Vacina;
                                else if (i == 2) {
                                    remover_sup1();
                                } else if (i == 0) 
                                    return 0;
                                    
                            }
                        } else if (id == 2) {
                            suporte2();
                            if (qtd_frasco == 50) {
                                printf ("\n\n\n\t\t      SUPORTE CHEIO!");

                                printf ("\n\n\n 1. Voltar ao Menu Vacina.");
                                printf ("\n 0. ENCERRAR.");

                                printf ("\n\n  Opção desejada: ");
                                scanf ("%i", &i);
                                if (i == 1) 
                                    goto Vacina;
                                else if (i == 0)
                                    return 0;
                            }
                        } else if (id == 3) {
                            suporte3();
                            if (qtd_frasco == 50) {
                                printf ("\n\n\n\t\t      SUPORTE CHEIO!");

                                printf ("\n\n\n 1. Voltar ao Menu Vacina.");
                                printf ("\n 0. ENCERRAR.");

                                printf ("\n\n  Opção desejada: ");
                                scanf ("%i", &i);
                                if (i == 1) 
                                    goto Vacina;
                                else if (i == 0)
                                    return 0;
                            }
                        } else if (id == 4) {
                            suporte4();
                            if (qtd_frasco == 50) {
                                printf ("\n\n\n\t\t      SUPORTE CHEIO!");

                                printf ("\n\n\n 1. Voltar ao Menu Vacina.");
                                printf ("\n 0. ENCERRAR.");

                                printf ("\n\n  Opção desejada: ");
                                scanf ("%i", &i);
                                if (i == 1) 
                                    goto Vacina;
                                else if (i == 0)
                                    return 0;
                            }
                        } else if (id == 5) {
                            suporte5();
                            if (qtd_frasco == 50) {
                                printf ("\n\n\n\t\t      SUPORTE CHEIO!");

                                printf ("\n\n\n 1. Voltar ao Menu Vacina.");
                                printf ("\n 0. ENCERRAR.");

                                printf ("\n\n  Opção desejada: ");
                                scanf ("%i", &i);
                                if (i == 1) 
                                    goto Vacina;
                                else if (i == 0)
                                    return 0;
                            }
                        } else {
                            printf ("\n    ID NÃO CADASTRADO!");
                            printf ("\n    APERTE ENTER PARA CONTINUAR!\n\n");
                            system("pause");
                            goto IdVacina;
                        }                      
                    break;

                    case 0:
                        return 0;
                    break;

                    default:
                        opcao_errada();
                        goto Vacina;
                    break;
                }

                OpcaoVac:
                    system("cls");
                    printf ("\n\n\tCADASTRO REALIZADO COM SUCESSO!\n\n");
                    printf ("\n 1. Cadastrar uma nova Vacina.");
                    printf ("\n 2. Voltar ao Menu.");
                    printf ("\n 0. ENCERRAR.");

                    printf ("\n\n  Opção desejada: ");
                    scanf ("%i", &i);
                    if (i == 1) 
                        goto Vacina;
                    else if (i == 2)
                        goto Menu;
                    else if (i == 0)
                        return 0;
                    else
                        opcao_errada();
                        goto OpcaoVac;
            break;

            default:
                opcao_errada();
                goto Menu;
            break;
        }

 return 0;
 }


 void criarFila( struct Fila *f, int c ) { 
	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 
}

void inserir_sup1 (struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++; 

    file = fopen ("suporte_1.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }
            fprintf (file, "%i \n", v);
        
    fclose(file);
}

void inserir_sup2 (struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++; 

    file = fopen ("suporte_2.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }
            fprintf (file, "%i \n", v);
        
    fclose(file);
}

void inserir_sup3 (struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++; 

    file = fopen ("suporte_3.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }
            fprintf (file, "%i \n", v);
        
    fclose(file);
}

void inserir_sup4 (struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++; 

    file = fopen ("suporte_4.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }
            fprintf (file, "%i \n", v);
        
    fclose(file);
}

void inserir_sup5 (struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++; 

    file = fopen ("suporte_5.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }
            fprintf (file, "%i \n", v);
        
    fclose(file);
}

void remover_sup1 () {
    FILE *file;
    int v;
    int i = 0;
    int rem_count = 0;
    int num[50];

    file = fopen ("suporte_1.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while (fscanf (file, "%i \n", &v) != EOF) {
            num[i] = v;
            i++;
            rem_count++;
        }

        file = fopen ("suporte_1.csv", "w");
            if (file == NULL) {
                printf ("Não foi possível abrir o arquivo!");
                exit (0);
            }

            for (i = 0; i < rem_count-1; i++)
            {
                fprintf (file, "%i \n", num[i+1]);
            }

            printf ("\n Lote com o Id %i retirado com sucesso!\n\n", num[0]);

        fclose(file); 
        
    fclose(file);
    system("pause");
}

void remover_sup2 () {
    FILE *file;
    int v;
    int i = 0;
    int rem_count = 0;
    int num[50];

    file = fopen ("suporte_2.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while (fscanf (file, "%i \n", &v) != EOF) {
            num[i] = v;
            i++;
            rem_count++;
        }

        file = fopen ("suporte_2.csv", "w");
            if (file == NULL) {
                printf ("Não foi possível abrir o arquivo!");
                exit (0);
            }

            for (i = 0; i < rem_count-1; i++)
            {
                fprintf (file, "%i \n", num[i+1]);
            }

            printf ("\n Lote com o Id %i retirado com sucesso!\n\n", num[0]);

        fclose(file); 
        
    fclose(file);
    system("pause");
}

void remover_sup3 () {
    FILE *file;
    int v;
    int i = 0;
    int rem_count = 0;
    int num[50];

    file = fopen ("suporte_3.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while (fscanf (file, "%i \n", &v) != EOF) {
            num[i] = v;
            i++;
            rem_count++;
        }

        file = fopen ("suporte_3.csv", "w");
            if (file == NULL) {
                printf ("Não foi possível abrir o arquivo!");
                exit (0);
            }

            for (i = 0; i < rem_count-1; i++)
            {
                fprintf (file, "%i \n", num[i+1]);
            }

            printf ("\n Lote com o Id %i retirado com sucesso!\n\n", num[0]);

        fclose(file); 
        
    fclose(file);
    system("pause");
}

void remover_sup4 () {
    FILE *file;
    int v;
    int i = 0;
    int rem_count = 0;
    int num[50];

    file = fopen ("suporte_4.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while (fscanf (file, "%i \n", &v) != EOF) {
            num[i] = v;
            i++;
            rem_count++;
        }

        file = fopen ("suporte_4.csv", "w");
            if (file == NULL) {
                printf ("Não foi possível abrir o arquivo!");
                exit (0);
            }

            for (i = 0; i < rem_count-1; i++)
            {
                fprintf (file, "%i \n", num[i+1]);
            }

            printf ("\n Lote com o Id %i retirado com sucesso!\n\n", num[0]);

        fclose(file); 
        
    fclose(file);
    system("pause");
}

void remover_sup5 () {
    FILE *file;
    int v;
    int i = 0;
    int rem_count = 0;
    int num[50];

    file = fopen ("suporte_5.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while (fscanf (file, "%i \n", &v) != EOF) {
            num[i] = v;
            i++;
            rem_count++;
        }

        file = fopen ("suporte_5.csv", "w");
            if (file == NULL) {
                printf ("Não foi possível abrir o arquivo!");
                exit (0);
            }

            for (i = 0; i < rem_count-1; i++)
            {
                fprintf (file, "%i \n", num[i+1]);
            }

            printf ("\n Lote com o Id %i retirado com sucesso!\n\n", num[0]);

        fclose(file); 
        
    fclose(file);
    system("pause");
}

int estaVazia( struct Fila *f ) { 

	return (f->nItens==0);
}

int estaCheia( struct Fila *f ) {

	return (f->nItens == f->capacidade);
}

void mostrarFila1() {

    file = fopen ("suporte_1.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            printf (" %i ", i);
        }
        printf ("\n");
	fclose (file);
}

void mostrarFila2() {

    file = fopen ("suporte_2.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            printf (" %i ", i);
        }
        printf ("\n");
	fclose (file);
}

void mostrarFila3() {

    file = fopen ("suporte_3.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            printf (" %i ", i);
        }
        printf ("\n");
	fclose (file);
}

void mostrarFila4() {

    file = fopen ("suporte_4.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            printf (" %i ", i);
        }
        printf ("\n");
	fclose (file);
}

void mostrarFila5() {

    file = fopen ("suporte_5.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            printf (" %i ", i);
        }
        printf ("\n");
	fclose (file);
}

 void login()
 {
    FILE *file;
    char nome[50];
    int senha;

    system ("cls");
    file = fopen ("medicos.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

            fscanf (file, "%i; %[^;]s;", &senha, nome);
                strcpy (medicos.nome, nome);
                medicos.crm = senha;
        
        printf ("\n NOME - %s\n", medicos.nome);
        printf (" CRM  - %i\n\n", medicos.crm);
        
      ErroLogin:
        printf ("\tUSUÁRIO: ");
        fflush (stdin);
        scanf ("%[^\n]s", &nome);

        printf ("\tCRM    : ");
        fflush (stdin);
        scanf ("%i", &senha);

        if (strcmp (nome, medicos.nome) != 0 || senha != medicos.crm) {
            printf ("\n\tMÉDICO E/OU CRM INVÁLIDO!\n\n");
            goto ErroLogin;
        }
    
    fclose (file);
 }

 void info_medico()
 {
    FILE *file;
    registro_cremesp reg;

    char delim[] = ";";
    char linha[250] = "\0";
    int count = 0; 

    file = fopen ("medicos.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        registro_cremesp readdata (FILE *f); {
        fscanf(file, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]",
                 &reg.crm,&reg.nome
                 ,&reg.status,&reg.data_ini,&reg.data_fin
                 ,&reg.cidade,&reg.UF
                 ,&reg.especialidades);
        }

        while( 1 ) {
            fgets(linha, 250, file);
            if ( feof(file) ) break;
            count++;
            //printf("%s\n",linha);
            char *token = strtok(linha,delim);
            int idx = 0;
            while(token != NULL) {
                switch ( idx ) {
                    case CSV_IDX_CRM    : strcpy( reg.crm            , token ); printf("\n CRM.....: %s\n", reg.crm); break;
                    case CSV_IDX_NOME   : strcpy( reg.nome           , token ); printf(" NOME....: %s\n", reg.nome); break;
                    case CSV_IDX_STATUS : reg.status = token[0];                break;
                    case CSV_IDX_DT_INI : strcpy( reg.data_ini       , token ); break;
                    case CSV_IDX_CIDADE : strcpy( reg.cidade         , token ); printf(" CIDADE..: %s\n", reg.cidade); break;
                    case CSV_IDX_UF     : strcpy( reg.UF             , token ); printf(" UF......: %s\n", reg.UF); break;
                    case CSV_IDX_ESPECI : strcpy( reg.especialidades , token ); break;
                } 
        
                token = strtok(NULL, delim);
                idx++;
            }
        }
        
    fclose (file);
 }

 void menu()
 {
    system ("cls");
    printf ("\n\tADM VACINA");
    printf ("\n\n_____________________________________\n");

    printf ("\n 1. Pré-Cadastro de cidadãos.");
    printf ("\n 2. Cadastro de Vacinas.");
    printf ("\n 0. ENCERRAR.");

    printf ("\n\n    Opção desejada: ");
 }

 void cad_cidadao()
 {
    FILE* file;

    system ("cls");
    printf ("\n\tPRÉ-CADASTRO DE CIDADÃO!");
    printf ("\n\n_____________________________________\n\n");
            
    file = fopen ("municipio.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        printf (" Digite o Nome Completo do Cidadão: ");
        fflush (stdin);
        gets (municipio.nome);
        fprintf (file, "\n%s;", municipio.nome);

        printf ("\n Digite a Data de Nascimento do Cidadão: ");
        fflush (stdin);
        gets (municipio.data);
        fprintf (file, "%s;", municipio.data);

        printf ("\n Digite o CPF do Cidadão: ");
        fflush (stdin);
        gets (municipio.cpf);
        fprintf (file, "%s;", municipio.cpf);

        printf ("\n Digite o País do Cidadão: ");
        fflush (stdin);
        gets (municipio.pais);
        fprintf (file, "%s;", municipio.pais);

        printf ("\n Digite o Estado do Cidadão: ");
        fflush (stdin);
        gets (municipio.estado);
        fprintf (file, "%s;", municipio.estado);

        printf ("\n Digite o Município do Cidadão: ");
        fflush (stdin);
        gets (municipio.municipio);
        fprintf (file, "%s;", municipio.municipio);

        printf ("\n Digite a Rua do Cidadão: ");
        fflush (stdin);
        gets (municipio.rua);
        fprintf (file, "%s;", municipio.rua);

        printf ("\n Digite o Número da Rua do Cidadão: ");
        scanf ("%i", &municipio.num);
        fprintf (file, "%i;", municipio.num);

        printf ("\n Digite o Complemento do Cidadão: ");
        fflush (stdin);
        gets (municipio.complemento);
        fprintf (file, "%s;", municipio.complemento);

        printf ("\n Digite o Bairro do Cidadão: ");
        fflush (stdin);
        gets (municipio.bairro);
        fprintf (file, "%s;", municipio.bairro);

        printf ("\n Digite o CEP do Cidadão: ");
        fflush (stdin);
        gets (municipio.cep);
        fprintf (file, "%s;", municipio.cep);

        printf ("\n Digite o E-mail do Cidadão: ");
        fflush (stdin);
        gets (municipio.email);
        fprintf (file, "%s;", municipio.email);

        printf ("\n Digite o Telefone do Cidadão: ");
        fflush (stdin);
        gets (municipio.celular);
        fprintf (file, "%s;", municipio.celular);
        
    fclose (file);
 }

 void cad_vacina()
 {
    FILE* file;

    file = fopen ("vacina.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        system ("cls");
        printf ("\n\tCADASTRO DE VACINAS!");
        printf ("\n\n_____________________________________\n\n");

        printf ("Digite o Id da Vacina: ");
        scanf ("%i", &vacina.id);
        fprintf (file, "\n%i;", vacina.id);

        printf ("\nDigite o Nome da Vacina: ");
        fflush (stdin);
        gets (vacina.nome);
        fprintf (file, "%s;", vacina.nome);

        printf ("\nDigite o Fabricante da Vacina: ");
        fflush (stdin);
        gets (vacina.fabricante);
        fprintf (file, "%s;", vacina.fabricante);

        printf ("\nDigite o Tipo da Vacina: ");
        fflush (stdin);
        gets (vacina.tipo);
        fprintf (file, "%s;", vacina.tipo);

        printf ("\nDigite a quantidade de Dose(s) da Vacina: ");
        scanf ("%i", &vacina.dose);
        fprintf (file, "%i;", vacina.dose);

        printf ("\nDigite a %% da Eficácia da Vacina: ");
        fflush (stdin);
        gets (vacina.eficacia);
        fprintf (file, "%s;", vacina.eficacia);

        printf ("\nDigite as instruções para o Armazenamento da Vacina: ");
        fflush (stdin);
        gets (vacina.arman);
        fprintf (file, "%s;", vacina.arman);
    
    fclose (file);
}

void cad_lotevacina()
{
    FILE *file;

    file = fopen ("lotesvacinas.csv", "a");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        system ("cls");
        printf ("\n\tCADASTRO DO LOTE DE VACINAS!");
        printf ("\n\n_____________________________________\n");

        fprintf (file, "\n%i;", vacina.id);

        printf ("\nDigite o Id do Lote da Vacina: ");
        scanf ("%i", &lotes.id_lote);
        fprintf (file, "%i;", lotes.id_lote);

        printf ("\n Digite a Data de Fabricação da Vacina: ");
        fflush (stdin);
        gets (lotes.data_fabric);
        fprintf (file, "%s;", lotes.data_fabric);

        printf ("\n Digite a Data de Vencimento da Vacina: ");
        fflush (stdin);
        gets (lotes.data_venci);
        fprintf (file, "%s;", lotes.data_venci);

    fclose (file);
}

 void suporte1()
 {
    qtd_frasco = 0;
    file = fopen ("suporte_1.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            qtd_frasco++;
        }
        
        system ("cls");
        printf ("\n\tId Vacina \t Id Lote \t Frascos Disponíveis\n");
        printf ("\t  1 \t\t 20210001 \t\t%i", qtd_frasco);

        if (qtd_frasco == 0) {
            printf ("\n\n\n\t\tATENÇÃO! NÃO HÁ VACINAS DISPONIVÉIS!");
            printf ("\n\n\n Deseja adicionar Vacina no Suporte? S - SIM // N -NÃO\n\n");

            printf ("   Digite sua Resposta - ");
            fflush (stdin);
            scanf ("%c", &resp);
            respM = toupper(resp);

            switch (respM)
            {
                case 'S':
                    printf("\nDigite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao)
                        {
                            case 0: 
                                return 0;
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                printf("\n Fila Cheia!!!\n\n");
                                } else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup1(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                } else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila1(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                    break;

                    case 'N':
                    break;

                    default:                                
                    break;
                }

        } else if (qtd_frasco < 50) {
            printf ("\n\n\n\t\tEslotes Livres - %i", 50-qtd_frasco);

            printf ("\n\n\n 1. Adicionar Frasco da Vacina CoronaVac.");
            printf ("\n 2. Retirar um Frasco da Vacina CoronaVac.");
            printf ("\n 0. ENCERRAR.");

            printf ("\n\n  Opção desejada: ");
            scanf ("%i", &i);

            switch (i)
            {
                case 1:
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao) 
                        {
                            case 0:
                                return 0; 
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                    printf("\n Fila Cheia!!!\n\n");
                                }
                                else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup1(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                }
                                else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila1(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                break;

                case 2:
                    remover_sup1();
                break;

                default:
                        
                break;
            }
        }
    fclose (file);
 }

 void suporte2()
 {
    qtd_frasco = 0;
    file = fopen ("suporte_2.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            qtd_frasco++;
        }
        
        system ("cls");
        printf ("\n\tId Vacina \t Id Lote \t Frascos Disponíveis\n");
        printf ("\t  2 \t\t 20220002 \t\t%i", qtd_frasco);

        if (qtd_frasco == 0) {
            printf ("\n\n\n\t\tATENÇÃO! NÃO HÁ VACINAS DISPONIVÉIS!");
            printf ("\n\n\n Deseja adicionar Vacina no Suporte? S - SIM // N -NÃO\n\n");

            printf ("   Digite sua Resposta - ");
            fflush (stdin);
            scanf ("%c", &resp);
            respM = toupper(resp);

            switch (respM)
            {
                case 'S':
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao)
                        {
                            case 0: 
                                return 0;
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                printf("\n Fila Cheia!!!\n\n");
                                } else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup2(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                } else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila2(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                    break;

                    case 'N':
                    break;

                    default:                                
                    break;
                }

        } else if (qtd_frasco < 50) {
            printf ("\n\n\n\t\tEslotes Livres - %i", 50-qtd_frasco);

            printf ("\n\n\n 1. Adicionar Frasco da Vacina Covishield.");
            printf ("\n 2. Retirar um Frasco da Vacina Covishield.");
            printf ("\n 0. ENCERRAR.");

            printf ("\n\n  Opção desejada: ");
            scanf ("%i", &i);

            switch (i)
            {
                case 1:
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao) 
                        {
                            case 0: 
                                return 2;
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                    printf("\n Fila Cheia!!!\n\n");
                                }
                                else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup2(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                }
                                else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila2(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                break;

                case 2:
                    remover_sup2();
                break;

                default:
                        
                break;
            }
        }
    fclose (file);
 }

 void suporte3()
 {
    qtd_frasco = 0;
    file = fopen ("suporte_3.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            qtd_frasco++;
        }
        
        system ("cls");
        printf ("\n\tId Vacina \t Id Lote \t Frascos Disponíveis\n");
        printf ("\t  3 \t\t 20230003 \t\t%i", qtd_frasco);

        if (qtd_frasco == 0) {
            printf ("\n\n\n\t\tATENÇÃO! NÃO HÁ VACINAS DISPONIVÉIS!");
            printf ("\n\n\n Deseja adicionar Vacina no Suporte? S - SIM // N -NÃO\n\n");

            printf ("   Digite sua Resposta - ");
            fflush (stdin);
            scanf ("%c", &resp);
            respM = toupper(resp);

            switch (respM)
            {
                case 'S':
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao)
                        {
                            case 0: 
                                return 0;
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                printf("\n Fila Cheia!!!\n\n");
                                } else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup3(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                } else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila3(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                    break;

                    case 'N':
                    break;

                    default:                                
                    break;
                }

        } else if (qtd_frasco < 50) {
            printf ("\n\n\n\t\tEslotes Livres - %i", 50-qtd_frasco);

            printf ("\n\n\n 1. Adicionar Frasco da Vacina mRNA-1273.");
            printf ("\n 2. Retirar um Frasco da Vacina mRNA-1273.");
            printf ("\n 0. ENCERRAR.");

            printf ("\n\n  Opção desejada: ");
            scanf ("%i", &i);

            switch (i)
            {
                case 1:
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao) 
                        {
                            case 0: 
                                return 0;
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                    printf("\n Fila Cheia!!!\n\n");
                                }
                                else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup3(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                }
                                else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila3(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                break;

                case 2:
                    remover_sup3();
                break;

                default:
                        
                break;
            }
        }
    fclose (file);
 }

 void suporte4()
 {
    qtd_frasco = 0;
    file = fopen ("suporte_4.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            qtd_frasco++;
        }
        
        system ("cls");
        printf ("\n\tId Vacina \t Id Lote \t Frascos Disponíveis\n");
        printf ("\t  4 \t\t 20240004 \t\t%i", qtd_frasco);

        if (qtd_frasco == 0) {
            printf ("\n\n\n\t\tATENÇÃO! NÃO HÁ VACINAS DISPONIVÉIS!");
            printf ("\n\n\n Deseja adicionar Vacina no Suporte? S - SIM // N -NÃO\n\n");

            printf ("   Digite sua Resposta - ");
            fflush (stdin);
            scanf ("%c", &resp);
            respM = toupper(resp);

            switch (respM)
            {
                case 'S':
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao)
                        {
                            case 0: 
                                return 0;
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                printf("\n Fila Cheia!!!\n\n");
                                } else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup4(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                } else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila4(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                    break;

                    case 'N':
                    break;

                    default:                                
                    break;
                }

        } else if (qtd_frasco < 50) {
            printf ("\n\n\n\t\tEslotes Livres - %i", 50-qtd_frasco);

            printf ("\n\n\n 1. Adicionar Frasco da Vacina mRNA BNT162b2.");
            printf ("\n 2. Retirar um Frasco da Vacina mRNA BNT162b2.");
            printf ("\n 0. ENCERRAR.");

            printf ("\n\n  Opção desejada: ");
            scanf ("%i", &i);

            switch (i)
            {
                case 1:
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao) 
                        {
                            case 0:
                                return 0; 
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                    printf("\n Fila Cheia!!!\n\n");
                                }
                                else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup4(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                }
                                else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila4(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                break;

                case 2:
                    remover_sup4();
                break;

                default:
                        
                break;
            }
        }
    fclose (file);
 }

 void suporte5()
 {
    qtd_frasco = 0;
    file = fopen ("suporte_5.csv", "r");
        if (file == NULL) {
            printf ("Não foi possível abrir o arquivo!");
            exit (0);
        }

        while(fscanf(file, "%i", &i) != EOF)
        {
            qtd_frasco++;
        }
        
        system ("cls");
        printf ("\n\tId Vacina \t Id Lote \t Frascos Disponíveis\n");
        printf ("\t  5 \t\t 20250005 \t\t%i", qtd_frasco);

        if (qtd_frasco == 0) {
            printf ("\n\n\n\t\tATENÇÃO! NÃO HÁ VACINAS DISPONIVÉIS!");
            printf ("\n\n\n Deseja adicionar Vacina no Suporte? S - SIM // N -NÃO\n\n");

            printf ("   Digite sua Resposta - ");
            fflush (stdin);
            scanf ("%c", &resp);
            respM = toupper(resp);

            switch (respM)
            {
                case 'S':
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao)
                        {
                            case 0: 
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                printf("\n Fila Cheia!!!\n\n");
                                } else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup5(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                } else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila5(&umaFila);
                                }
                            break;

                            default:
                                printf("\nOpcao Invalida\n\n");
                        }
                    }
                    break;

                    case 'N':
                    break;

                    default:                                
                    break;
                }

        } else if (qtd_frasco < 50) {
            printf ("\n\n\n\t\tEslotes Livres - %i", 50-qtd_frasco);

            printf ("\n\n\n 1. Adicionar Frasco da Vacina Sputnik V.");
            printf ("\n 2. Retirar um Frasco da Vacina Sputnik V.");
            printf ("\n 0. ENCERRAR.");

            printf ("\n\n  Opção desejada: ");
            scanf ("%i", &i);

            switch (i)
            {
                case 1:
                    printf("\n Digite quantos Frascos serão adicionados - ");
                    scanf("%d" ,&capa);
                    criarFila(&umaFila, capa);

                    while( 1 ) {
                        printf("\n 1 - Adicionar Frascos.");
                        printf("\n 2 - Mostrar a Fila dos Frascos do Suporte.");
                        printf("\n 0 - ENCERRAR.");

                        printf("\n\n  Escolha uma Opção: ");
                        scanf("%d", &opcao);

                        switch(opcao) 
                        {
                            case 0: 
                            break;

                            case 1:
                                if (estaCheia(&umaFila)) {
                                    printf("\n Fila Cheia!!!\n\n");
                                }
                                else {
                                    for (i = 0; i < capa; i++)
                                    {
                                        printf("\n Digite o %i° Id do Frasco - ", i+1);
                                        scanf("%i", &valor);
                                        inserir_sup5(&umaFila, valor);
                                    }
                                }
                            break;

                            case 2:
                                if (estaVazia(&umaFila)) {
                                    printf("\n Fila vazia!!!\n\n");
                                }
                                else {
                                    printf("\n Fila dos Frascos => ");
                                    mostrarFila5(&umaFila);
                                }
                            break;

                            default:
                                printf("\n Opcao Invalida\n\n");
                        }
                    }
                break;

                case 2:
                    remover_sup5();
                break;

                default:
                        
                break;
            }
        }
    fclose (file);
 }

 void opcao_errada()
 {
    printf ("\n    OPÇÃO INVALIDA!");
    printf ("\n    APERTE ENTER PARA CONTINUAR!\n\n");
    system("pause");
    system ("cls");
 }