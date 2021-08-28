#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
long factor(int n);
void menu();
void voltaMenu(int *);

void quebra(int);
void tabula(int);

void DecParaBin();
void BinParaDec();
void DecParaHex();
void HexParaDec();
void DecParaOct();
void OctParaDec();
void BinParaHex();
void HexParaBin();


void PedeNumero();
void PedeBinario();
void PedeHexa();
void PedeOctal();

char valor[50];

int main (void)
{
    menu();
    quebra(2);

    system ("pause");
    return 0;
}

void quebra (int n)
{
     for (int i=0; i<n;i++)
     {
         printf ("\n");
     }
}

void tabula (int n)
{
     for (int i=0; i<n;i++)
     {
         printf ("\t");
     }
}

void menu()
{
     int opc;

     printf ("Programa para conversión entre sistemas numericos ");quebra(2);
     printf ("Escoja una conversion:");quebra(2);tabula(1);
     printf ("1 - Decimal a binario");quebra(1);tabula(1);
     printf ("2 - Binario a decimal");quebra(1);tabula(1);
     printf ("3 - Decimal a hexadecimal");quebra(1);tabula(1);
     printf ("4 - Hexadecimal a decimal");quebra(1);tabula(1);
     printf ("5 - Decimal a octal");quebra(1);tabula(1);
     printf ("6 - Octal a decimal");quebra(1);tabula(1);
     printf ("7 - Binario a hexadecimal");quebra(1);tabula(1);
     printf ("8 - Hexadecimal a binario");quebra(1);tabula(1);
     printf ("9 - permutaciones"); quebra(1);tabula(1);
     printf("10 - COMBINACIONES"); quebra(1);tabula(1);
     printf ("11 - Salir"); quebra(2);

     printf ("Opcion: ");
     scanf ("%d", &opc);

     switch (opc)
     {
            case 1:
                 DecParaBin();
                 voltaMenu(&opc);
                 break;
            case 2:
                 BinParaDec();
                 voltaMenu(&opc);
                 break;
            case 3:
                 DecParaHex();
                 voltaMenu(&opc);
                 break;
            case 4:
                 HexParaDec();
                 voltaMenu(&opc);
                 break;
            case 5:
                 DecParaOct();
                 voltaMenu(&opc);
                 break;
            case 6:
                 OctParaDec();
                 voltaMenu(&opc);
                 break;
            case 7:
                 BinParaHex();
                 voltaMenu(&opc);
                 break;
            case 8:
                 HexParaBin();
                 voltaMenu(&opc);
                 break;


            case 9:
                printf("permutaciones");
                int n, r, resultado;

            printf("La formula de la permutacion es nPr\n");
    printf("\nDe cuantos elementos conforma tu conjunto N\n"); scanf("%d", &n);
    printf("\nDe cuantos elementos conforma tu conjunto R\n"); scanf("%d", &r);

      r = n-r;
     resultado =factor(n) /factor (r);
     printf("El resultado de la permutacion es:%d", resultado);
     break;

            case 10: printf("Combinaciones");
printf("La formula de la combinacion es nCr\n");
int N1,R1,R2,ress;
printf("\nDe cuantos elementos conforma tu conjunto N\n"); scanf("%d", &N1);
printf("\nDe cuantos elementos conforma tu conjunto R\n"); scanf("%d", &R1);

R2 = N1 - R1;
ress =  factor (N1) / (factor(R2) * factor(R1));

printf("El resultado de la combinacion es:%li", ress);
break;

            case 11:
                exit(1);
            default:
                    system ("cls");

                    menu();
     }
}


void voltaMenu(int * op)
{
     quebra(2);
     printf ("Desea regresar al  menu? (1-si / 2-no) ");
     scanf ("%d", op);
     if (*op==1){
        system ("cls");
        menu();
     }
}

void DecParaBin()
{
     char binario[33];
     char buffer[33];

     int divisor = 2;

     int resto = 0;
     int quociente = 0;
     int temp = 0;

     quebra(2);
     printf ("Ingrese un numero entero para convertir: ");
     PedeNumero();

     quociente = atoi(valor);
     strcpy(binario, "");
     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;
           sprintf (buffer, "%d", resto);
           strcat (binario, buffer);
     }
     sprintf (buffer, "%d", quociente);
     strcat (binario, buffer);

     quebra(2);
     printf ("Convertido en binario: %s", strrev(binario));
     quebra(2);
}

void BinParaDec()
{
     int tamanio = 0;
     int result = 0;
     int temp = 0;
     int i = 0;

     quebra(2);
     printf ("Ingrese un valor binario para ser convertido: ");
     PedeBinario();

     tamanio = strlen(valor);
     tamanio--;
     while (tamanio >= 0)
     {
           temp = pow (2, tamanio);
           result += ((valor[i] - 48) * temp);
           tamanio--;
           i++;
     }

     quebra(2);
     printf ("Convertido en decimal: %d", result);
     quebra(2);
}

void DecParaHex()
{
     char hexa[33];
     char* hexadecimal = "0123456789ABCDEF";

     int divisor = 16;

     int resto = 0;
     int quociente = 0;
     int temp = 0;
     char tmp[5];

     strcpy(hexa, "");

     quebra(2);
     printf ("Ingrese un numero entero para ser  convertido: ");
     PedeNumero();

     quociente = atoi(valor);

     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;

           sprintf (tmp, "%c", hexadecimal[resto]);
           strcat (hexa, tmp);
     }
     sprintf (tmp, "%c", hexadecimal[quociente]);
     strcat (hexa, tmp);

     quebra(2);
     printf ("Convertido en Hexadecimal: %s", strrev(hexa));
     quebra(2);
}

void HexParaDec()
{
    int tamanio = 0;
    int result = 0;
    int temp = 0;
    int i = 0;

    quebra(2);
    printf ("Ingrese un  valor hexadecimal para ser convertido: ");
    PedeHexa();

    tamanio = strlen(valor);
    tamanio--;
    while (tamanio >= 0)
    {
          temp = pow (16, tamanio);
          if ((valor[i] - 48) >= 17 && (valor[i] - 48) <=22)
          {
             result += ((valor[i]-55) * temp);
          }else{
                result += ((valor[i] - 48) * temp);
          }
          tamanio--;
          i++;
    }

    quebra(2);
    printf ("Convertido en  decimal: %d", result);
    quebra(2);
}

void DecParaOct()
{
    char octal[33];
    char buffer[33];

    int divisor = 8;

    int resto = 0;
    int quociente = 0;
    int temp = 0;

    quebra(2);
    printf ("Ingrese un numero entero  para ser convertido: ");
    PedeNumero();

    quociente = atoi(valor);
    strcpy(octal, "");

    while (quociente >= divisor)
    {
          resto = quociente%divisor;
          temp = quociente/divisor;
          quociente = temp;
          sprintf (buffer, "%d", resto);
          strcat (octal, buffer);
    }
    sprintf (buffer, "%d", quociente);
    strcat (octal, buffer);

    quebra(2);
    printf ("Convertido en octal: %s", strrev(octal));
    quebra(2);
}

void OctParaDec()
{
    int tamanio = 0;
    int result = 0;
    int temp = 0;
    int i = 0;

    quebra(2);
    printf ("Ingrese  un valor octal para ser convertido: ");
    PedeOctal();

    tamanio = strlen(valor);
    tamanio--;
    while (tamanio >= 0)
    {
          temp = pow (8, tamanio);
          result += ((valor[i] - 48) * temp);
          tamanio--;
          i++;
    }

    quebra(2);
    printf ("Convertido a decimal: %d", result);
    quebra(2);
}

void BinParaHex()
{
    char hexa[33];
    char temp[33];
    char *p;
    char Hexas[16][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
    "B", "C", "D", "E", "F"};
    char Binarios[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101",
    "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110",
    "1111"};

    int tamanio = 0;
    int i;

    quebra(2);
    printf ("Ingrese un valor binario: ");
    PedeBinario();

    tamanio = strlen(valor);
    strcpy(hexa, "");
    strcpy(temp, "");

    if (tamanio%4==1){
        strcpy(temp, "000");
        tamanio+=3;
        strcat(temp, valor);
        strcpy(valor, temp);
    }else if (tamanio%4==2){
          strcpy(temp, "00");
          tamanio+=2;
          strcat(temp, valor);
          strcpy(valor, temp);
    }else if (tamanio%4==3){
          strcpy(temp, "0");
          tamanio+=1;
          strcat(temp, valor);
          strcpy(valor, temp);
    }

    p = valor;

    while (*p != '\0'){
          for (i=0;i<16;i++){
              if (strncmp(p, Binarios[i], 4) == 0){
                 strcat (hexa, Hexas[i]);
                 i = 16;
              }
          }
          p += 4;
    }

    quebra(2);
    printf ("Convertido en  hexadecimal: %s", hexa);
    quebra(2);
}

void HexParaBin()
{
    char binario[33];
    char Binarios[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101",
    "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110",
    "1111"};
    char Binarios2[16][5] = {"", "1", "10", "11", "100", "101", "110", "111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    int tamanio = 0;
    int i;
    int result;
    int cero=0;

    quebra(2);
    printf ("Ingrese un  valor hexadecimal: ");
    PedeHexa();

    tamanio = strlen(valor);
    strcpy(binario, "");

    for (i=0;i<tamanio;i++)
    {
          if ((valor[i] - 48) >= 17 && (valor[i] - 48) <= 22)
          {
             result = ((valor[i] - 55));
             strcat(binario, Binarios[result]);
          }else{
                result = ((valor[i] - 48));
                if (result==0 && i==0){
                   strcpy(binario, "");
                   cero++;
                }else if (result == 0){
                      cero++;
                }
                if (i==0 || cero != 0){
                   strcat(binario, Binarios2[result]);
                }else{
                      strcat(binario, Binarios[result]);
                }
          }
    }

    if (cero == tamanio){
       strcpy(binario, "0");
    }

    quebra(2);
    printf ("Convertido en binario: %s", binario);
    quebra(2);
}

void PedeNumero()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if (isdigit(c)!=0)
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeBinario()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if (c=='0' || c=='1')
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeHexa()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if ((c>=48 && c<=57) || (c>=65 && c<=70))
           {
          valor[i] = c;

          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeOctal()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if ((c>=48 && c<=55))
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';



}

long factor (int n){
 if (n<=1){
    return 1;
 }

 else {
    return (n*factor(n-1));
 }
 }
