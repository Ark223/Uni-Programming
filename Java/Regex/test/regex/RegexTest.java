
package regex;

import java.util.Arrays;
import java.util.List;
import static org.junit.Assert.*;
import org.junit.Test;

public final class RegexTest {
    
    public RegexTest() { }
    
    @Test
    public void testFuncs() {
        System.out.println("Test walidacji email...");
        
        List<String> res1 = Regex.findEmails("bartosz@wp.pl[,darek23@gmail.com[");
        List<String> exp1 = Arrays.asList("bartosz@wp.pl", "darek23@gmail.com");
        assertEquals(res1, exp1);
        
        res1 = Regex.findEmails("bartosz@wp.pl[,darek23gmail.com[");
        exp1 = Arrays.asList("bartosz@wp.pl");
        assertEquals(res1, exp1);
        
        res1 = Regex.findEmails("bartosz@wp.pl[,darek23gmailcom[");
        exp1 = Arrays.asList("bartosz@wp.pl");
        assertEquals(res1, exp1);
        
        System.out.println("Test walidacji kodow pocztowych...");
        
        boolean res2 = Regex.validateZipCode("26872");
        boolean exp2 = false;
        assertEquals(res2, exp2);
        
        res2 = Regex.validateZipCode("26-872");
        exp2 = true;
        assertEquals(res2, exp2);
        
        res2 = Regex.validateZipCode("26-8726");
        exp2 = false;
        assertEquals(res2, exp2);
    }
}

