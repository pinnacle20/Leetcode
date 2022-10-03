class Solution {
public:
    int reverse(int x) {
        int y=0;
        int flag = 1;
        if(x<0){
            flag = -1;
            if(x==-2147483648){
                return 0;
            }
            x = flag*x;
        }
        int init = x%10;
        while(x>0){
            int a = x%10;
            if(y>214748364){
                return 0;
            }
            else if(y==214748364){
                if(a>7){
                    if(flag==-1 && a>8){
                        return 0;
                    }
                    if(flag==1){
                        return 0;
                    }
                }
            }
            y = y*10+a;
            x = x/10;
        }
        return flag*y;
        
    }
};