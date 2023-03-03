class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh=haystack.length();
        int nn=needle.length();
        if(nn==0){
            return 0;
        }
        if(nn==1){
            for(int i=0;i<nh;i++){
                if(haystack[i]==needle[0]){
                    return i;
                }
            }
            return -1;
        }
        // we only need to go upto (len of haystack - len of needle)
        for(int i=0;i<nh-nn+1;i++){
            // may be possible
            // check if (curr i + len of needle) == end char of needle
            int check=i+nn-1;
            if(haystack[i]==needle[0]&&haystack[check]==needle[nn-1]){
                int x=1;
                for(int j=i+1;j<check&&j<nh;j++){
                    if(haystack[j]!=needle[x]){
                        break;
                    }else{
                        x++;
                    }
                }
                if(x==nn-1){
                    return i;
                }
            }
        }
        return -1;
    }
};