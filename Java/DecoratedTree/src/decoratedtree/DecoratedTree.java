
package decoratedtree;

import java.util.Scanner;

public class DecoratedTree
{
    public static char[] decs = "@Oo***".toCharArray();
    
    public static void FillText(String a, int n)
    {
        boolean b = "*".equals(a);
        for (int i = 1; i <= n; i++)
        {
            int r = (int)(Math.random() * 6);
            if (b) a = String.valueOf(decs[r]);
            System.out.print(a);
        }
    }
    
    public static void main(String[] args)
    {
        int n = 0, b = -1;
        System.out.print("Ilosc pieter: ");
        Scanner scan = new Scanner(System.in);
        try { n = scan.nextInt(); }
        catch (NumberFormatException e)
        {
            System.out.print("Nieprawidlowa liczba");
            System.exit(0);
        }
        for (int i = 0; i <= n; i++)
        {
            if (i == n) b = -1;
            int max = 2 * n - 1; b += 2;
            int step = (max - b) / 2;
            FillText(" ", step);
            FillText(i == 0 ? "^" : i == n ? "H" : "*", max - step * 2);
            FillText(" ", step);
            System.out.println("");
        }
    }
}
