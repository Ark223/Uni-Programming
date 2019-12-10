
package regex;

import java.util.*;
import java.util.regex.*;

public class Regex
{
    public static void main(String[] args) { }
    
    public static boolean ValidateZipCode(String text) {
        return text.matches("^[0-9]{2}(?:-[0-9]{3})?$");
    }
    
    public static List<String> FindEmails(String text) {
        Pattern p = Pattern.compile("([a-z0-9_.-]+)@([a-z0-9_.-]+[a-z])");
        Matcher m = p.matcher(text);
        List<String> results = new ArrayList<>();
        while (m.find()) results.add(m.group());
        return results;
    }
}

