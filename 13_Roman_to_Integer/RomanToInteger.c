
// define a romans string and integer compare array
int romanToInt(char* s) {
    char romans[]  = "IVXLCDM";
    int integers[] = { 1,    5,  10,  50, 100, 500, 1000};
    int temp=0;

    for(int i=0; i < strlen(s); i++){
        for (int j=0; j < sizeof(integers)/sizeof(int); j++){
            if (s[i] == romans[j]){
                switch(j){
                    case 0:
                    case 2:
                    case 4:
                        if (s[i+1] == romans[j+1]){
                            temp += integers[j+1]-integers[j];
                            i++;
                            j++;
                        } else if (s[i+1] == romans[j+2]){
                            temp += integers[j+2]-integers[j];
                            i++;
                            j+=2;
                        } else {
                            temp += integers[j];
                        }
                        break;
                    default:
                        temp += integers[j];
                        break;
                }
                printf("i = %d, j = %d, temp = %d\n", i, j, temp);
            }
        }
    }
    return temp;
}