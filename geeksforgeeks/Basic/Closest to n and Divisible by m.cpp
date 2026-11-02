class Solution {
  public:
    int closestNumber(int n, int m) {
        m = abs(m);
        if(n>0){
            int x1 = n%m;
            if(x1 < m/2) return n-x1;
            else return n+(m-x1);
        }
        else{
            int x2 = abs(n)%m;
            if(x2<m/2) return -(abs(n)-x2) ;
            else return -(abs(n)+(m-x2));
        }
    }
};