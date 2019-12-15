
package personal;

import java.util.*;

public class Personal {

    public static boolean Matches(String s)
    {
        return s.matches("[a-zA-Z_]+");
    }
    
    public static void main(String[] args) throws Exception
    {
        Scanner scanner = new Scanner(System.in);
        Osoba os1 = new Osoba();
        String temp;
        System.out.print("Podaj imie, nazwisko, wiek i pesel: ");
        temp = scanner.nextLine();
        String[] data = temp.split("\\s+");
        if (data.length != 4)
        {
            System.out.println("Nieprawidlowy format!");
            System.exit(0);
        }
        if (!Matches(data[0]) || !Matches(data[1]))
        {
            System.out.println("Imie i nazwisko musi sie skladac tylko z liter!");
            System.exit(0);
        }
        os1.imie = data[0];
        os1.nazwisko = data[1];
        try
        {
            os1.wiek = Integer.parseInt(data[2]);
            os1.pesel = Long.parseLong(data[3]);
        }
        catch (Exception e) {
            System.out.println("Wiek i pesel musi sie skladac tylko z cyfr!");
            System.exit(0);
        }
        System.out.println(os1.ToString());
    }
    
    public static class Osoba
    {
        String imie;
        String nazwisko;
        int wiek;
        long pesel;

        public String ToString()
        {
            return this.imie + " " + this.nazwisko + " " +
            String.valueOf(this.wiek) + " " + String.valueOf(this.pesel);
        }
    }
}
