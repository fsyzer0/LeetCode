
bool isPalindrome(int x) {
    int org = x, temp = 0;
    long long reversed = 0;

    if (x<0) return false;
    if (x!=0 && x%10==0) return false;

    // reverse the half of x
    while (x > reversed){
       reversed = reversed*10 + x%10;
       x/=10;
    }

    // if the length of x is even, compare with reversed
    // if the length of x is odd, compare with reversed/10
    return (x == reversed) || (x == reversed/10);
}