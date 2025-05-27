// thanks for the idea from M_Haris
bool isPalindrome(int x) {
    int org = x, temp = 0;
    long long reversed = 0;

    if (x<0) return false;
    if (x!=0 && x%10==0) return false;

    // reverse the x
    while (x > 0){
       reversed = reversed*10 + x%10;
       x/=10;
    }

    if (org != reversed) return false;
    return true;
}