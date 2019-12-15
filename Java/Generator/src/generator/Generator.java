
package generator;

import java.util.ArrayList;
import java.util.List;

public class Generator {
    
    public static void main(String[] args) {
        GSquareData data = generateSquares(generatePoints(new Vector2(-8, 8), 16, 2), 16);
        int i = 0;
        for (List<Vector2> l : data.squares) {
            i++; System.out.println(i + ".");
            for (Vector2 v : l) {
                System.out.println(v);
            }
        }
        System.out.println("Min: " + data.min);
        System.out.println("Max: " + data.max);
    }
    
    public static GSquareData generateSquares(GPointData input, int step)
    {
        GSquareData data = new GSquareData();
        List<Vector2> points = input.points;
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
        data.squares = list;
        int d = (int)step / 2;
        data.min = new Vector2(input.min.x - d, input.min.y - d);
        data.max = new Vector2(input.max.x + d, input.max.y + d);
        return data;
    }
    
    public static GPointData generatePoints(Vector2 curr, int step, int size)
    {
        GPointData data = new GPointData();
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
                    Vector2 temp = curr.clone();
                    list.add(temp);
                    if (i == 0) data.max = temp;
                    else if (i == 2) data.min = temp;
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
        data.points = list;
        return data;
    }
    
    public static class GPointData
    {
        private Vector2 min;
        private Vector2 max;
        private List<Vector2> points;
    }
    
    public static class GSquareData
    {
        private Vector2 min;
        private Vector2 max;
        private List<List<Vector2>> squares;
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
        
        @Override
        public Vector2 clone() {
            return new Vector2(this.x, this.y);
        }
        
        @Override
        public String toString() {
            return "(" + this.x + ", " + this.y + ")";
        }
    }
}

