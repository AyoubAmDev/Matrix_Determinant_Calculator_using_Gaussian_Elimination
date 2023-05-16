#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float ** alloc_Matrice(const int n);
int init_A(float **T);
int  init_manu(float **T, const int n);
int  init_aleat(float **T, const int n);
int  aff_Matrice(const float ** const T, const int n);
int Gauss_elimination(float ** T, const int n);
int Gauss_elimination_etap(float ** T, const int n);
int remplace_2_lignes(float ** T, const int n, const int x);
int aff_Matr_tri_sup(const float ** const T, const int n);
float calcul_det(const float ** const T, const int n, const int occ);

//LA FONCTION PRINCIPALE--------------------------------------------------------------------------------------------
int main()
{
    char option;
    int n,occ, **M, **A;
    srand(time(NULL));

    printf(" \n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Ce programme peut calculer le determinant d'une matrice caree d'ordre n en utilisant l'elimination de Gauss.");
    printf(" \n\n\n\t\t\t\t\t\t\t\t\t * Ayoub AMTDI S1 group 1 * \n\n\n\n\t\t\t\t\t\t\t\t\t      * 15/11/2022 * \n");
    printf(" \n\n\n\n\n\t\t\t\t\t\t Voulez vous continuer l'execution ou bien quitter le programme ? \n\n\n\n\n\n\t\t\t\t\t\t C: Contunier \t\t\t\t\t\t Q: Quitter \n\n\n\n");
    do
    {
        option = getch();
    }
    while (option != 'Q' && option != 'C' && option != 'q' && option != 'c' );
    if(option == 'Q' || option == 'q' )
        exit(99);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Voulez vous tester l'exemple typique (la matrice A(4x4)) ou bien une nouvelle matrice ?\n\n\n\n\n\n\n\n\n\n\t\t\t\t ");
    printf("# Pour la matrice typique A,\t\t\t\t\t\t # Pour une nouvelle matrice M,");
    printf(" \n\t\t\t\t   appuyez sur la touche : A .\t\t\t\t\t\t   appuyez sur la touche : M .");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t   (pas necessairement en majuscule)\n");
    do
    {
        option = getch();
    }
    while (option != 'A' && option != 'M' && option != 'a' && option != 'm' );
    if(option == 'A' || option == 'a' )
    {
        A=alloc_Matrice(4);
        init_A(A);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t   La matrice typique A (exemple d'une matrice carree) : \n\n");
        aff_Matrice(A,4);
        printf("\n\n");
        printf("\n\n\n\n\t\t\t Voulez vous voir les etapes d'elimination ? \t\t\t\t O: Oui \t\t N: Non(Passer) \n");
        do
        {
            option = getch();
        }
        while (option != 'O' && option != 'N' && option != 'o' && option != 'n' );
        if(option == 'O' || option == 'o' )
        {
            system("cls");
            printf("\n\n\n\n");
            Gauss_elimination_etap(A,4);
        }

        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t   La matrice typique A (exemple d'une matrice carree) : \n\n");
        aff_Matrice(A,4);
        printf("\n\n");
        occ=Gauss_elimination(A,4);

        printf("\n\t\t\t\t\t La matrice triangulaire superieure apres l'elimination : \n\n");
        aff_Matr_tri_sup(A, 4);
        printf("\n\n\n\t\t\t\t\t\t Le determinant de cette matrice est : \n");
        printf("\n\n\t\t\t\t\t\t\t   Det(A) = %.2f \n\n\n\n",calcul_det(A, 4, occ));

        printf("\n\n\t\t\t Voulez vous tester  une autre matrice ? \t\t\t\t O: Oui \t\t N: Non(Quitter) \n");
        do
        {
            option = getch();
        }
        while (option != 'O' && option != 'N' && option != 'o' && option != 'n' );
        if(option == 'N' || option == 'n' )
        {
            exit(44);
        }
    }

    do
    {
        do
        {
            system("cls");
            printf("\n\t Veuillez saisir l'ordre de la matrice : ");
            scanf("%d",&n);
        }
        while(n<0);
        M=alloc_Matrice(n);
        printf("\n\n\n\n\t Voulez vous remplir la matrice manuellement ? \n\n\n\t\t\t\t\t O: Oui \t\t\t N: Non \n");
        do
        {
            option = getch();
        }
        while (option != 'O' && option != 'N' && option != 'o' && option != 'n' );
        system("cls");
        if(option == 'O' || option == 'o' )
        {
            init_manu(M, n);
            system("cls");
        }
        else
        {
            init_aleat(M, n);
        }
        printf("\n Votre Matrice :");
        aff_Matrice(M, n);
        printf("\n\n\n\n\t\t\t Voulez vous voir les etapes d'elimination ? \t\t\t\t O: Oui \t\t N: Non(Passer) \n");
        do
        {
            option = getch();
        }
        while (option != 'O' && option != 'N' && option != 'o' && option != 'n' );
        if(option == 'O' || option == 'o' )
        {
            system("cls");
            printf("\n\n\n\n");
            Gauss_elimination_etap(M,n);
        }
        system("cls");
        printf("\n\n\n\n");
        printf("\n Votre Matrice :");
        aff_Matrice(M, n);
        occ=Gauss_elimination(M,n);

        printf("\n La matrice triangulaire superieure apres l'elimination : \n");
        aff_Matr_tri_sup(M, n);
        printf("\n Le determinant de cette matrice est : \n");
        printf("\n\n\t\t Det(M) = %.2f \n\n\n\n",calcul_det(M, n, occ));

        printf(" \n\n\t\t\t\t\t\t\t\t Voulez vous tester une autre matrice ?  \n\n\n\n\t\t\t\t\t\t\t O: Oui \t\t\t\t N: Non(Quitter) \n");
        do
        {
            option = getch();
        }
        while (option != 'O' && option != 'N' && option != 'o' && option != 'n' );
    }
    while (option == 'O' || option == 'o');

    return 0;
}
//------------------------------------------------------------------------------------------------
float ** alloc_Matrice(const int n)
{
    float **T;
    int i;
    T  = (void ** )malloc(n*sizeof(float *));
    if(T==NULL)
    {
        printf("\n ERREURE D'ALLOCATION.\n");
        exit(26);
    }
    for(i=0; i<n; i++)
    {
        T[i]=(void* )malloc(n*sizeof(float *));
        if(T==NULL)
        {
            printf("\n ERREURE D'ALLOCATION.\n");
            exit(35);
        }
    }

    return T;
}

int init_A(float **T)
{
    T[0][0] = 1 ;
    T[0][1] = 0 ;
    T[0][2] = 3 ;
    T[0][3] = 2 ;
    T[1][0] = 0 ;
    T[1][1] = 1 ;
    T[1][2] = -1 ;
    T[1][3] = 0 ;
    T[2][0] = 2 ;
    T[2][1] = 2 ;
    T[2][2] = 1 ;
    T[2][3] = 1 ;
    T[3][0] = -1 ;
    T[3][1] = 0 ;
    T[3][2] = 1 ;
    T[3][3] = 3 ;
    return 0;
}



int  init_manu(float **T, const int n)
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf(" \n Veuillez saisir M[%d][%d] : ",i,j);
            scanf("%f", &T[i][j]);
        }
    return 0;
}

int  init_aleat(float **T, const int n)
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            T[i][j]=(rand()%2?1:-1)*rand()%100;
    return 0;
}


int  aff_Matrice(const float ** const T, const int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("\n \t\t\t\t\t\t | ");

        for(j=0; j<n; j++)
            printf("%8.1f",T[i][j]);
        printf(" \t|");
    }
    printf(" \n");

    return 0;
}

int Gauss_elimination(float ** T, const int n)
{
    int k,i,j,x,occ=0;
    float pv,c;
    for(i=0; i<n-1; i++)
    {
        if (T[i][i]==0)
        {
            occ++;
            x=i;
            remplace_2_lignes(T,n,x);
        }
        pv=T[i][i];

        for(j=i+1; j<n; j++)
        {

            c=T[j][i]/pv;

            for(k=i; k<n; k++)
            {
                T[j][k]=T[j][k]-c*T[i][k];

            }
        }

    }
    return occ;
}

int Gauss_elimination_etap(float ** T, const int n)
{
    int k,i,j,x,occ=0;
    float pv,c;
    printf("\n\n\n");
    aff_Matrice(T, n);
    printf("\n\n\n");
    system("Pause");
    for(i=0; i<n-1; i++)
    {
        if (T[i][i]==0)
        {
            occ++;
            x=i;
            remplace_2_lignes(T,n,x);
            printf("\n\n\n");
            aff_Matrice(T,n);
            printf("\n\n\n");
            system("Pause");
        }
        pv=T[i][i];

        for(j=i+1; j<n; j++)
        {

            c=T[j][i]/pv;

            for(k=i; k<n; k++)
            {
                T[j][k]=T[j][k]-c*T[i][k];

            }

            printf("\n\n\n");
            aff_Matrice(T,n);
            printf("\n\n\n");
            system("Pause");

        }

    }

    return occ;
}

int remplace_2_lignes(float ** T, const int n, const int x)
{
    float *t;
    int i, j;
    t  = (void * )malloc(n*sizeof(float));
    if(T==NULL)
    {
        printf("\n ERREURE D'ALLOCATION.\n");
        exit(18);
    }

    for(j=1; j<n-x; j++)
        if(T[x+j][x]!= 0)
        {
            for(i=0; i<n; i++)
            {
                T[x][i]=t[i];
                T[x][i]=T[x+j][i];
                T[x+j][i]=t[i];
                break;
            }
        }
    return 0;
}


int aff_Matr_tri_sup(const float ** const T, const int n)
{
    int k, l;
    for(k=0; k<n; k++)
    {
        printf("\n \t\t\t\t\t\t | ");
        for(l=0; l<n; l++)
        {
            printf("%8.1f",T[k][l]);
        }
        printf(" \t|");
    }
    printf(" \n");
    return 0;
}

float calcul_det(const float ** const T, const int n, const int occ)
{
    int i;
    float det = 1;

    for(i=0; i<n; i++)
    {
        det=det*T[i][i];
    }
    if (occ%2==1)
    {
        det=det*(-1);
    }
    return det;
}
