
int check_num(int x){
    long long div=1;
    int num=0;

    while (x/div!=0){
        div*=10;
        num++;
    }

    return num;
}

int get_divl(int idx){
    int i = 0;
    long long temp = 1;
    while (i < idx-1){
        i++;
        temp*=10;
    }
    return temp;
}

bool palondrome_check(int x, int num){
    int *num_array;
    int i, temp=x;
    int s, e;

    num_array = (int*) malloc (num*sizeof(int));

    for (i=num; i>0 ; i--){
        num_array[i-1] = (temp/get_divl(i))%10;
    }

    for (s=num-1, e=0; s>e; s--, e++){
        if (num_array[s] != num_array[e]) return false;
    }

    return true;
}

bool isPalindrome(int x) {

    if (x<0) return false;

    return palondrome_check(x, check_num(x));
}