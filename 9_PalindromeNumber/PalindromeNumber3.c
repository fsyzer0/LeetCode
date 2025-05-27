
int check_num(int x){
    long long div=1;
    int num=0;

    while (x/div!=0){
        div*=10;
        num++;
    }

    return num;
}

bool palondrome_check(int x, int num){
    int *num_array;
    int i, temp=x;
    int s, e;

    num_array = (int*) malloc (num*sizeof(int));

    for (i=0; i<num ; i++){
        num_array[i] = x%10;
        x/=10;
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