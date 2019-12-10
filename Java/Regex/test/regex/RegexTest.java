
package regex;

import java.util.Arrays;
import java.util.List;
import static org.junit.Assert.*;
import org.junit.Test;

public class RegexTest {
    
    public RegexTest() { TestFuncs(); }
    
    @Test
    public void TestFuncs() {
        System.out.println("Test walidacji email:");
        
        System.out.println("1.");
        List<String> res1 = Regex.FindEmails("bartosz@wp.pl[,darek23@gmail.com[");
        List<String> exp1 = Arrays.asList("bartosz@wp.pl", "darek23@gmail.com");
        assertEquals(res1, exp1);
        
        System.out.println("2.");
        res1 = Regex.FindEmails("bartosz@wp.pl[,darek23gmail.com[");
        exp1 = Arrays.asList("bartosz@wp.pl");
        assertEquals(res1, exp1);
        
        System.out.println("3.");
        res1 = Regex.FindEmails("bartosz@wp.pl[,darek23gmailcom[");
        exp1 = Arrays.asList("bartosz@wp.pl");
        assertEquals(res1, exp1);
        
        System.out.println("Test walidacji kodow pocztowych:");
        
        System.out.println("1.");
        boolean res2 = Regex.ValidateZipCode("26872");
        boolean exp2 = false;
        assertEquals(res2, exp2);
        
        System.out.println("2.");
        res2 = Regex.ValidateZipCode("26-872");
        exp2 = true;
        assertEquals(res2, exp2);
        
        System.out.println("3.");
        res2 = Regex.ValidateZipCode("26-8726");
        exp2 = false;
        assertEquals(res2, exp2);
    }
}

