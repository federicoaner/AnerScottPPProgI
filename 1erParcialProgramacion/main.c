#include <stdio.h>
#include <stdlib.h>
#define TAM 4



typedef struct
{
    int id;
     char procesador[20];
    char marca[20];
    int precio;

} eNotebook;


float aplicarDescuento(float precio);

void ordenarNotebook(eNotebook vec[],int tam);
void mostrarDatos(eNotebook vec[],int tam );
int contarCaracteres(char cadena[],char letra );


int main()
{

    eNotebook vec[TAM]={{1,"intel","mac",20000},{2,"intel","mac",50000},{5,"intel","samsung",30000},{7,"amd","asus",50000} };

    float precioInicial;
     float precioConDescuento;

     char cadena[20];
     char caracter;



    printf("Ingrese el precio: ");
    scanf("%f",&precioInicial);


 precioConDescuento=aplicarDescuento(precioInicial);
 printf("El precio con descuento del 5 porciento es: %2.f\n\n", precioConDescuento);


 ordenarNotebook(vec,TAM);
 mostrarDatos(vec,TAM);


 printf("\n\nIngrese  cadena: ");
    scanf("%s",&cadena);

    printf("Ingrese  letra: ");
    fflush(stdin);
    scanf("%c",&caracter);

   int cantidadCaracteres =contarCaracteres(cadena,caracter);
   printf("la cantidad de caracteres es: %d",cantidadCaracteres);



    return 0;
}




float aplicarDescuento(float precio){

int resultado;
float preciosinDescuento;


preciosinDescuento=precio*0.05;
resultado=(float)precio-preciosinDescuento;

return resultado;

}


int contarCaracteres(char a[],char b );

void ordenarNotebook(eNotebook vec[],int tam){

 eNotebook auxVec;
for (int i=0; i<TAM-1; i++)
    {
        for (int j=i+1; j<TAM; j++)
        {
            if(strcmp(vec[i].marca,vec[j].marca)>0)
            //if(vec[i].marca>vec[j].marca)

            {
                auxVec=vec[i];
                vec[i]=vec[j];
                vec[j]=auxVec;
            }
            else if(strcmp(vec[i].marca,vec[j].marca)>0 && vec[i].precio >vec[j].precio)
            {
                auxVec=vec[i];
                vec[i]=vec[j];
                vec[j]=auxVec;
            }
        }
    }


}



void mostrarDatos(eNotebook vec [],int tam ){

printf("***************************\n\n");
printf("id      procesador        marca        precio\n\n");

for (int i=0; i<tam; i++){


    printf("%d      %10s     %10s       %d\n",vec[i].id,vec[i].procesador,vec[i].marca,vec[i].precio );
    }

}

int contarCaracteres(char cadena[],char letra ){

 int retorno = 0;

  for(int i = 0;cadena[i]!='\0';i++)
    {
        if(cadena[i]==letra)
        {
            retorno++;
        }
    }

    return retorno;
}




