
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

int get_target_num(int x, int num, int idx){
    if (num == 1) return x;
    // if (idx == num-1) return x/get_divl(idx);

    printf("---\n");
    printf("target = %d\n", idx);

    x /= get_divl(idx);
    printf("x / %d = %d\n",get_divl(idx), x);

    // x %= get_divl(idx+1);
    x %= 10;
    printf("x mod %d = %d\n", 10, x);

    return x;
}

bool palondrome_check(int x, int num){
    int idx_l = check_num(x);
    int idx_r = 1;

    while (idx_l >= idx_r){
        if ( get_target_num(x, num, idx_l) != get_target_num(x, num, idx_r) ) return false;
        idx_l--;
        idx_r++;
    }
    return true;
}

bool isPalindrome(int x) {

    if (x<0) return false;

    return palondrome_check(x, check_num(x));
}