
import junit.framework.TestCase;


public class unitTestCase extends TestCase {
	
	public unitTestCase(String testName) {
		super(testName);
	}
	
	public void urlValidTest() {

		UrlValidator urlVal = new UrlValidator();
		System.out.print("--  TESTING isValid()  --\n");
		
		
		
		
		System.out.print("--  Test 1: Valid URLs  --\n");
		boolean result;
		String url;
		String[] validURL = {"http://www.google.com", "http://www.reddit.com/r/oregonstateuniv", "www.oregonlive.com", "espn.com", "255.255.255.255"};
		for (int i = 0; i < validURL.length; i++ ) {
			url = validURL[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-Test 1 fail at input: " + validURL[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-Test 1 pass: " + validURL[i]);
			}
		}
	 
	}
	 public static void main(String[] argv) {
		 unitTestCase unitTest = new unitTestCase("Unit Test");
		 unitTest.urlValidTest();
	 }

}
