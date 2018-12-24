//
class Solution {
public:
    /**
     * @param sx: x for starting point
     * @param sy: y for starting point
     * @param tx: x for target point
     * @param ty: y for target point
     * @return: if a sequence of moves exists to transform the point (sx, sy) to (tx, ty)
     */
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        //if (tx > ty) return tx == sx && ty == sy % sx;
        //return ty == sy && tx == sx % sy;
        if (tx == sx) return (ty - sy) % sx == 0;
        if (ty == sy) return (tx - sx) % sy == 0;
        return false;
    }
};

//
class Solution {
public:
    /**
     * @param sx: x for starting point
     * @param sy: y for starting point
     * @param tx: x for target point
     * @param ty: y for target point
     * @return: if a sequence of moves exists to transform the point (sx, sy) to (tx, ty)
     */
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        if(sx > tx || sy > ty) return false;
        if(sx == tx && (ty - sy) % sy == 0) return true;
        if(sy == ty && (tx - sx) % sx == 0) return true;

        return reachingPoints(sx, sy, tx % ty, ty % tx);
    }
};