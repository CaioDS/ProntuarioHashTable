#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

typedef struct {
    int CPF;
    char Nome[50];
    char Data_nasc[8];
    char Sexo;
    char Texto[300];
} Pessoa;

void GeraArquivo(int n) {
    FILE * arq_mestre = fopen("Dados/Arquivo_Mestre.txt", "a");
    FILE * arq_nomes = fopen("Dados/GeradorArquivo/Nomes.txt", "r");

    int x, d, m, y;
    char nome[50], dia[3], mes[3], ano[5], data_nasc[15];

    for (int i = 0; i < n; i++)
    {
        x = rand()%50;
        d = rand()%31;
        m = rand()%12;
        y = 1950 + rand()%2020;
        sprintf(dia,"%d",d);
        sprintf(mes,"%d",m);
        sprintf(ano,"%d",y);
        strcat(data_nasc, dia);
        strcat(data_nasc, mes);
        strcat(data_nasc, ano);
        fseek(arq_nomes, x, SEEK_SET);
        fscanf(arq_nomes, "%s\n", &nome);
        fprintf(arq_mestre, "%d %s %s\n", rand()%999999999, nome, data_nasc);
        srand(time(NULL));
    }
    fclose(arq_mestre);
    fclose(arq_nomes);
}

void CriarEstrutura(){
	FILE * diretorio = fopen("Dados/Diretorio.txt", "a");
	FILE * buckets = fopen("Dados/Buckets.txt", "a");
	FILE * arq_mestre = fopen("Dados/Arquivo_Mestre.txt", "a");
	FILE * arq_nomes = fopen("Dados/GeradorArquivo/Nomes2.txt", "rb");

	if(diretorio == NULL || buckets == NULL || arq_mestre == NULL ){
		printf("Erro ao criar a estrutura de arquivos");
	}

	fclose(diretorio);
	fclose(buckets);
	fclose(arq_mestre);
}

int main()
{
    int x = 0;
    CriarEstrutura();
    printf("\nquantidade: ");
    scanf("%d", &x);
    GeraArquivo(x);
}
