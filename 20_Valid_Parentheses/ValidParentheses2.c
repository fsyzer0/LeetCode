bool isValid(char* s) {
    int top = -1;
    int strl = strlen(s);
    char *stack = (char*) malloc ( sizeof(char)*strl );

    for (int i=0;i < strl ; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            if (top < strl){
                top++;
                stack[top] = s[i];
            }
        }else{
            if ( s[i]==')') {
                if ( (top == -1) || (stack[top] != '(') ){
                    free(stack);
                    return false;
                } else{
                    // stack[top] = '0';
                    top--;
                }
            }
            if ( s[i]=='}') {
                if ( (top == -1) || (stack[top] != '{') ){
                    free(stack);
                    return false;
                } else{
                    // stack[top] = '0';
                    top--;
                }
            }
            if ( s[i]==']') {
                if ( (top == -1) || (stack[top] != '[') ){
                    free(stack);
                    return false;
                } else{
                    // stack[top] = '0';
                    top--;
                }
            }
        }
   }
    free(stack);
    if (top == -1) return true;
    return false;
}