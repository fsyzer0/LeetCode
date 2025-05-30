
int getnum(char a){
    switch(a){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

// define a romans string and integer compare array
int romanToInt(char* s) {
    int temp=0;
    int romanlen = strlen(s);
    for (int i = 0; i < romanlen; i++){
        if ( (i+1<romanlen) && (getnum(s[i]) < getnum(s[i+1])) ){
            // 1. According to the description
            // Th Roman numerals are usually written "largest" to "smallest" from left to right
            // if the current roman smaller than the next roman.
            // with means to minus current number

            // 2. And because we're using the int, which allow the signed/unsigned integer number
            // so we can minus the number first.
            temp-=getnum(s[i]); 
        } else {
            temp+=getnum(s[i]);
        }
    }
    return temp;
}

