#include<stdio.h>
int somat(int b){
    if(b==1) return 1;
    return somat(b-1)+b;
}
int main(){
    int a;
    printf("Digite o valor: ");
    scanf("%d",&a);
    printf("%d",somat(a));
    return 0;
}
