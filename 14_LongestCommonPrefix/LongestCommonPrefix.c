// [knowhow]
// 1. hanle the end if the string '\0' carefully
// 2. the strs[j] is a pointer for this string,
//    so if we need to check whether the string is the empty string, using "strlen(strs[j] == 0"
#define METHOD 2

#if (METHOD == 1)
// thanks for chocotoe's sample
// dirrect using/replacing the input strs & return it.

// But it will modify the input strs
char* longestCommonPrefix(char** strs, int strsSize) {
    int c, s;

    // check each characters
    for (c=0; ;c++){
        // if we find the current character is '\0'
        // which means the sting is handled by the forloop "for ( s=0; s<strsSize; s++ )"
        if( strs[0][c] == '\0') return strs[0];

        // check each string
        for ( s=0; s<strsSize; s++ ){
            // if we found the current character is not equal to the first string character
            // modify the first string and return it.
            if (strs[s][c] != strs[0][c]){
                strs[0][c] = '\0';
                return strs[0];
            }
        }
    }
}
#else

// use the malloc method to return a string, and it will not change the input strs
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0 ) {
        // if the input is NULL or a empty string
        char* empty = (char*)malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    // get the first string length
    int len = strlen(strs[0]);
    // locate memory spaces for prefix with extra '\0'
    char* prefix = (char*)malloc(sizeof(char) * (len + 1));
    prefix[0]='\0';

    // find the first string characters
    for (int i = 0; i < len; i++) {
        // fine each strings
        for (int j = 0; j < strsSize; j++) {
            // if i is bigger than current string length
            // which means the prefix is the common prefix
            if (i >= strlen(strs[j])) {
                prefix[i] = '\0';
                return prefix;
            }
            // if the first string character is not equal to current string character
            // cut off the prefix
            if (strs[0][i] != strs[j][i]) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        // set the prefix character equal to the first string character with '\0'
        prefix[i] = strs[0][i];
        prefix[i + 1] = '\0';
    }

    return prefix;
}

#endif