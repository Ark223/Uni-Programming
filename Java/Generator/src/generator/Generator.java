
package generator;

import java.util.ArrayList;
import java.util.List;

public class Generator {
    
    public static void main(String[] args) {
        List<List<Vector2>> list = generateSquares(generatePoints(new Vector2(350, 350), 50, 2), 50);
        int i = 0;
        for (List<Vector2> l : list) {
            i++; System.out.println(i + ".");
            for (Vector2 v : l) {
                System.out.println(v);
            }
        }
    }
    
    public static List<List<Vector2>> generateSquares(List<Vector2> points, int step)
    {
        List<List<Vector2>> list = new ArrayList<>();
        for (Vector2 p : points) {
            List<Vector2> temp = new ArrayList<>();
            int d = (int)step / 2;
            for (int i = 0; i < 4; i++)
            {
                Vector2 offset = i == 0 ? new Vector2(-d, d) :
                                 i == 1 ? new Vector2(d, d) :
                                 i == 2 ? new Vector2(d, -d) :
                                 new Vector2(-d, -d);
                Vector2 n = p.add(offset);
                temp.add(n.clone());
            }
            list.add(temp);
        }
        return list;
    }
    
    public static List<Vector2> generatePoints(Vector2 curr, int step, int size)
    {
        List<Vector2> list = new ArrayList<>();
        int currSize = 1, helper = 1;
        list.add(curr);
        while (currSize <= size)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < helper; j++)
                {
                    Vector2 dv = i == 0 ? new Vector2(step, 0) :
                                 i == 1 ? new Vector2(0, -step) :
                                 new Vector2(-step, 0);
                    curr = curr.add(dv);
                    list.add(curr.clone());
                }
            }
            if (currSize != size)
            {
                curr = new Vector2(curr.x - step, curr.y);
                list.add(curr.clone());
                for (int i = 0; i < helper + 1; i++)
                {
                    curr = new Vector2(curr.x, curr.y + step);
                    list.add(curr.clone());
                }
            }
            helper += 2; currSize++;
        }
        return list;
    }
    
    public static class Vector2
    {
        private final int x;
        private final int y;

        public Vector2(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public Vector2 add(Vector2 v) {
            return new Vector2(this.x + v.x, this.y + v.y);
        }
        
        public Vector2 sub(Vector2 v) {
            return new Vector2(this.x - v.x, this.y - v.y);
        }
        
        public Vector2 clone() {
            return new Vector2(this.x, this.y);
        }
        
        @Override
        public String toString() {
            return "(" + this.x + ", " + this.y + ")";
        }
    }
}

