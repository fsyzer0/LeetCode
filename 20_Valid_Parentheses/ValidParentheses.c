bool isValid(char* s) {
    int top = -1;
    int strl = strlen(s);
    char *stack = (char*) malloc ( sizeof(char)*strl );

    for (int i=0;i < strl ; i++){
        switch(s[i]){
            case '(':
            case '{':
            case '[':
                if (top < strl){
                    top++;
                    stack[top] = s[i];
                }
                break;
            case ')':
                if ( (top >=0) && stack[top] == '('){
                    stack[top] = '0';
                    top--;
                }else{
                    free(stack);
                    return false;
                }
                break;
            case '}':
                if ( (top >=0) && stack[top] == '{'){
                    stack[top] = '0';
                    top--;
                }else{
                    free(stack);
                    return false;
                }
                break;
            case ']':
                if ( (top >=0) && stack[top] == '['){
                    stack[top] = '0';
                    top--;
                }else{
                    free(stack);
                    return false;
                }
                break;
        }
    }
    free(stack);
    if (top == -1) return true;
    return false;
}