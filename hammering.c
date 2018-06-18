#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int hamming(int, int);
int count(int);
int main(void) {
    int n, m, p, i, j, k, cn, test, countn=0;
    unsigned long long int r;
    unsigned char c;
    int codes[24];
    scanf("%d %d %d",&n,&m,&p);
    for (i=0;i<m;i++)
    {
        scanf("%llu",&r);
        cn=0;
        test=0;
        while (cn<8)
        {
            int e=7;
            test=0;
            while (e>=0)
            {
                if (r&1==1)	// Numero mod 2	
                {
                    test+=1<<(7-e);   //Integer que voy a guardar
                }
                r=r>>1;		//Division dentro de 2
                e--;
            }
            codes[(7-cn)+countn]=test;   // Acá los meto como de el ultimo al primero, ya que en este metodo empieza a separarlo de izquierda a derecha el numero y lo quiero guardar de derecha a izquierda
            cn++;						//Ejemplo:   1111111100000000 para separarlo lo hago primero el 00000000 11111111, entonces el array lo guarda en la pos 2 el 00000000 y en la 1 el 11111111
        }
        countn+=8;   //Para adelantarse de 8 en 8 en el array
    }
    for (i=0;i<p;i++)
    {
        scanf("%hhu",&c);
        for (j=0;j<n;j++)
        {
            int x=hamming(codes[j],c);	//Si el hamming es exitoso devuelve el caracter que quiero imprimir, sino devuelve -1
            if (x>0)
            {
                printf("%hhu\n",x);
                break;
            }
        }
    }
    return 0;
}
int hamming(int a, int b)
{
    int p=a^b;  //XOR
    int x=count(p);   //Contar cuantos 1s
    if (x<=1)	
        return a;	//Si la diferencia es 1 devuelve el caracter que recibio, sino devuelve el negativo
    return -1;
}
int count(int p)	//La del count que te envie al principio para ver cuantos unos tiene
{
    int f,ans=0;
    for (f=0;f<8;f++)	//Recorre los 8 bits
    {
        if ((1<<f)&p)	//Compara el número con el bit corrido y suma cuantos encontró iguales
            ans++;    	//Ejemplo:  1<<5 es 100000, si lo compara con 101010 me sale 0 porque la posicion 5 del segundo es un 0
    }
    return ans;
}