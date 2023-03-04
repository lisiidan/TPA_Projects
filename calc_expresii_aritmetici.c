#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPRESSION_LENGTH 100

int prioritate(char c){
    switch(c){
        case '(': return 0;
        case ')': return 0;
        case '*': return 1;
        case '/': return 1;
        case '+': return 2;
        case '-': return 2;
        default: return -1;
    }
    
} 

void push(char stiva[], int *size, char c){
    stiva[*size] = c;
    *size = *size + 1;
    stiva[*size] = '\0';
}

char pop(char stiva[], int *size){
    char c = stiva[*size - 1];
    stiva[*size - 1] = '\0';
    *size = *size - 1;
    return c;
}

char* forma_poloneza(char *dest, char expression[]){
    char stiva_operatori[MAX_EXPRESSION_LENGTH], vec[MAX_EXPRESSION_LENGTH];
    int stiva_varf = 0,vec_varf = 0;
    int expression_length = strlen(expression);    
    for(int i = 0; i < expression_length; i++){
        if(prioritate(expression[i]) == -1) {       //daca este operand
            push(vec,&vec_varf,expression[i]);       //se adauga in vector
            if(prioritate(stiva_operatori[stiva_varf - 1]) == 1) // Daca ultimul operator a fost '*' sau '/'
            {
                push(vec,&vec_varf,pop(stiva_operatori,&stiva_varf)); // Transporta operatorul cu prioritate direct in vector
            }
        } else                                      //daca este operator
        {
            push(stiva_operatori,&stiva_varf,expression[i]); //se adauga la varful stivei
        }
        
        if(prioritate(stiva_operatori[stiva_varf - 1]) == 2){ // Daca este '+' sau '-'
            char c = pop(stiva_operatori,&stiva_varf); // operatorul se salveaza
            char temp;
            while(prioritate((temp = pop(stiva_operatori,&stiva_varf))) >= 1) //se introduc in vector toti operatorii
            {
                push(vec,&vec_varf,temp);
            }
            push(stiva_operatori,&stiva_varf,temp); // se intoarce ultimul element scos 
            push(stiva_operatori,&stiva_varf,c);    // se intoarce in stiva operatorul
        }
        if(stiva_operatori[stiva_varf - 1] == ')'){ // Daca este paranteza inchisa 
            while(stiva_operatori[stiva_varf - 1] != '('){ // Pana la intalnirea parantezei deschise se introduc toti operatorii
                char c = pop(stiva_operatori,&stiva_varf);
                if(c == ')')
                    continue;
                push(vec,&vec_varf,c);
            }
            pop(stiva_operatori,&stiva_varf); // scoate paranteza deschisa
        } 
    }
    strcpy(dest,vec);
    return dest;
}

int calc_fp(char fp[], int fp_size, int val[]){
    int st[MAX_EXPRESSION_LENGTH];
    int st_size = 0;
    for(int i = 0; i < fp_size; i++){
        if(fp[i] >= 'a' && fp[i] <= 'z' ){
            st[st_size] = val[fp[i] - 'a'];
            st_size++; 
        } else
        {
            switch(fp[i]){
                case '+': {
                    st[st_size - 2] += st[st_size - 1];
                    st_size--;
                    
                    break;
                }
                case '-': {
                    st[st_size - 2] -= st[st_size - 1];
                    st_size--;
                    break;
                }
                case '*': {
                    st[st_size - 2] *= st[st_size - 1];
                    st_size--;
                    break;
                }
                case '/': {
                    st[st_size - 2] /= st[st_size - 1];
                    st_size--;
                    break;
                }
            }
        }
    }
    return st[0];
}

int main(){
    
    FILE *f = NULL;
    f = fopen("expresii.in","r");
    if (f == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    char expression[MAX_EXPRESSION_LENGTH];
    fscanf(f,"%s",expression); //lucreaza doar daca nu sunt spatii intre operatori/operanzi
    int nr; int val_length = 0;
    int val[MAX_EXPRESSION_LENGTH];
    while(fscanf(f,"%d",&nr) != EOF){
        val[val_length] = nr;
        val_length++;
    }
    char fp[MAX_EXPRESSION_LENGTH];
    strcpy(fp, forma_poloneza(fp,expression));
    int result = calc_fp(fp,strlen(fp),val);   
    printf("%d\n",result);
    if(fclose(f) != 0){
        perror(NULL);
        exit(-1);
    }
    return 0;
}