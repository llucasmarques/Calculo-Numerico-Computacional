#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long double f(long double x) {

    return pow(x,3) + 4.0*pow(x,2) - 6.0*x;

}

int testa_erro(long double a, long double b, long double e ){
    if((abs(b-a)<e) && ((abs((f(a+b)/2))<e))){
        return 1;
    }else{
        return 0;
    }
}

int main () {
    long double a, b, e, x_k, fx_k;

    a = -5.0;
    b = -6.0;

    e = 0.000001;

    while(!testa_erro(a,b,e)){
        x_k = (a+b)/2.0;
        fx_k = f(x_k);
        if (fx_k == 0.0)
            break;
            
        if(f(a)*f(x_k) < 0) {
        	b = x_k;	
		}else {
			a = x_k;
		}
    }

    printf ("raiz = %Lf\n", x_k);
    return 0;
}
