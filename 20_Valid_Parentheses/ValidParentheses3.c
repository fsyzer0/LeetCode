//[knowhow]
// 1. using stack
// 2. simplize the condition
// 3. maybe we don't need to locate memory for stack...?
// 4. to reduce the memory usage, forloop use '\0' as the end confition

bool isValid(char* s) {
    int top = -1;
    char stack[strlen(s)];

    // '\0' will be the end of the string
    for (int i=0; s[i]!='\0' ; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            top++;
            stack[top] = s[i];
        }else{
            if ( (top == -1) ||
                ( ( s[i]==')') && (stack[top] != '(') ) ||
                ( ( s[i]=='}') && (stack[top] != '{') ) ||
                ( ( s[i]==']') && (stack[top] != '[') ) ){
                    return false;
            } else {
                top--;
            }
       }
   }
    if (top == -1) return true;
    return false;
}