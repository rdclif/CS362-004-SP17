
import junit.framework.TestCase;
import java.util.Random;


public class unitTestCase extends TestCase {
	
	public unitTestCase(String testName) {
		super(testName);
	}
	
	//creates a semi-random correct url 
	public String randomURLMaker() {
		Random rand = new Random();
		String[] startURL = {"ftp://www.", "http://www.", "http://", "ftp://"};
		String[] midURL = {"abc", "go", "espn", "oregonstate", "255"};
		String[] endURL = {".com", ".org", ".edu", ".gov", ".au"};
		String[] pathURL = {"", "/", ":8008", "/a/file/","/option?q=class"};
		int loc = rand.nextInt(startURL.length);
		String url = startURL[loc];
		loc = rand.nextInt(midURL.length);
		url += midURL[loc];
		loc = rand.nextInt(endURL.length);
		url += endURL[loc];
		loc = rand.nextInt(pathURL.length);
		url += pathURL[loc];
		return url;
	}
	
	//takes in a string and adds/removes semi-random characters to invalidate the url string
	public String makeBad(String validURL) {
		Random rand = new Random();
		StringBuilder url = new StringBuilder (validURL);
		String[] badChar = {":", "/", "w"};
		if (flipCoin()){
			int sLoc = rand.nextInt((10)-1);
			url.insert(sLoc, " ");
		} else {
			int sLoc = rand.nextInt(5);
			int cLoc = rand.nextInt(badChar.length);
			if (flipCoin()) {
				url.deleteCharAt(sLoc);
			} else {
				url.insert(sLoc, badChar[cLoc]);
			}
		}

		return url.toString(); 
	}
	
	//randomly returns true of false
	public boolean flipCoin () {
		Random rand = new Random();
		int x = rand.nextInt(100);
		if (x >= 50){
			return true;
		} else {
			return false; 
		}
	}

	//unit tests 
	public void testURLValid() {
		
		UrlValidator urlVal = new UrlValidator();
		System.out.print("--  TESTING FUNCTION isValid()  --\n\n");
		
		
		
		//simple initial test of basic correct urls 
		System.out.print("\n--  Test 1: Simple Valid URLs  --\n");
		boolean result;
		String url;
		String[] validURL = {"http://www.google.com", "http://www.reddit.com/r/oregonstateuniv", "ftp://www.oregonlive.com", "http://espn.com", "ftp://255.255.255.255"};
		for (int i = 0; i < validURL.length; i++ ) {
			url = validURL[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + validURL[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + validURL[i]);
			}
		}
		
		//simple initial test of basic incorrect urls 
		System.out.print("\n\n--  Test 2: Simple Invalid URLs  --\n");
		String[] inValidURL = {"htp://www.google.com", "http:/www.reddit.com/r/oregonstateuniv", "http://www.reddit.com/r/oregon stateuniv", "ww.oregonlive.com", "www.oregonlive", ":espn.com", "1.2.3.4"};
		for (int i = 0; i < inValidURL.length; i++ ) {
			url = inValidURL[i].toString();
			result = urlVal.isValid(url);
			if (result == true) {
				System.out.print("\n-FAIL: " + inValidURL[i]);
				//assertEquals(inValidURL[i], false, result);
			} else {
				System.out.print("\n-PASS: " + inValidURL[i]);
			}
		}
		
		System.out.print("\n\n--  Test 3: Valid URLs  --\n");
		String[] vURL1 = {"http://www.google.com", "http://www.reddit.com/r/oregonstateuniv", "http://www.oregonlive.com", "http://www.espn.com", "http://www.255.com"};
		String[] vURL2 = {"http://www.google.org", "http://www.reddit.edu/r/oregonstateuniv", "http://www.oregonlive.gov/", "http://www.espn.au", "http://www.go.com"};
		String[] vURL3 = {"http://google.com", "http://reddit.com/r/oregonstateuniv", "http://oregonlive.com", "http://espn.com", "http://255.255.255.255"};
		String[] vURL4 = {"ftp://google.com", "ftp://reddit.com/r/oregonstateuniv", "ftp://oregonlive.com", "ftp://espn.com", "ftp://255.255.255.255"};
		String[] vURL5 = {"http://www.google.com/", "http://www.reddit.com/", "http://www.oregonlive.com/", "http://www.espn.com/", "http://www.go.com/"};
		String[] vURL6 = {"http://www.google.com/file", "http://www.reddit.com/u/$23", "http://www.oregonlive.com/user?one", "http://www.espn.com/true?x=1", "http://www.go.com/onelongthinghere/"};
		String[] vURL7 = {"http://www.google.com:4000", "http://www.reddit.com:4040", "http://www.oregonlive.com:0", "http://www.espn.com:10000", "http://www.go.com:8000"};
		for (int i = 0; i < vURL1.length; i++ ) {
			url = vURL1[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL1[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL1[i]);
			}
		}
		for (int i = 0; i < vURL2.length; i++ ) {
			url = vURL2[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL2[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL2[i]);
			}
		}
		for (int i = 0; i < vURL3.length; i++ ) {
			url = vURL3[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL3[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL3[i]);
			}
		}
		for (int i = 0; i < vURL4.length; i++ ) {
			url = vURL4[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL4[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL4[i]);
			}
		}
		for (int i = 0; i < vURL5.length; i++ ) {
			url = vURL5[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL5[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL5[i]);
			}
		}
		for (int i = 0; i < vURL6.length; i++ ) {
			url = vURL6[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL6[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL6[i]);
			}
		}
		for (int i = 0; i < vURL7.length; i++ ) {
			url = vURL7[i].toString();
			result = urlVal.isValid(url);
			if (result != true) {
				System.out.print("\n-FAIL: " + vURL7[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + vURL7[i]);
			}
		}
		
		
		System.out.print("\n\n--  Test 4: invalid URLs  --\n");
		String[] ivURL1 = {"ttp://www.google.com", "http//www.reddit.com/r/oregonstateuniv", "http:/www.oregonlive.com", "http:///espn.com", "htttp://255.255.255.255"};
		String[] ivURL2 = {"ww.google.com", "www..reddit.com/r/oregonstateuniv", "wwww.oregonlive.com/", "w ww.espn.com", "www go.com"};
		String[] ivURL3 = {"google.com.", "reddit.com r/oregonstateuniv", "oregonlivecom", "espn.c om", "1.2.3.4."};
		String[] ivURL4 = {"ftp:// google.com", "ftp://reddit.com//oregonstateuniv", "ftp//oregonlive.com", "ftp:/espn.com", "ftp:///255.255.255.255"};
		String[] ivURL5 = {"http://www.google.com-/", "http://www reddit.com/", "http:/www.oregonlive.com/", "ttp://www.espn.com/", "http:i//wwww.go.com/"};
		String[] ivURL6 = {"http://www.google.com/file///", "http://www.reddit.com/u/...", "http://www.oregonlive.com user?one", "http://www.espn.com/true//x=1", "http://www.go.com///onelongthinghere"};
		String[] ivURL7 = {"http://www.google.com:4000.", "http://www.reddit.com 4040", "http://www.oregonlive.com:0x", "http://www.espn.com:100p00", "http://www.go.com:80 00"};
		for (int i = 0; i < ivURL1.length; i++ ) {
			url = ivURL1[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL1[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL1[i]);
			}
		}
		for (int i = 0; i < ivURL2.length; i++ ) {
			url = ivURL2[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL2[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL2[i]);
			}
		}
		for (int i = 0; i < ivURL3.length; i++ ) {
			url = ivURL3[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL3[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL3[i]);
			}
		}
		for (int i = 0; i < ivURL4.length; i++ ) {
			url = ivURL4[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL4[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL4[i]);
			}
		}
		for (int i = 0; i < ivURL5.length; i++ ) {
			url = ivURL5[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL5[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL5[i]);
			}
		}
		for (int i = 0; i < ivURL6.length; i++ ) {
			url = ivURL6[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL6[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL6[i]);
			}
		}
		for (int i = 0; i < ivURL7.length; i++ ) {
			url = ivURL7[i].toString();
			result = urlVal.isValid(url);
			if (result != false) {
				System.out.print("\n-FAIL: " + ivURL7[i]);
				//assertEquals(validURL[i], true, result);
			} else {
				System.out.print("\n-PASS: " + ivURL7[i]);
			}
		}
		
	
		//
		System.out.print("\n\n--  Test 5: Random Mix  --\n");
		boolean testBool;   
		for (int i = 0; i < 200; i++ ) {
			testBool = true; 
			url = randomURLMaker();
			
			if (flipCoin()) {
				url = makeBad(url);
				testBool = false;
			}
		
			result = urlVal.isValid(url);
			
			if (result != testBool) {
				System.out.print("\n-FAIL: " + url);
				System.out.print("  -Expected: " + testBool + "  Returned: " + result);
				//assertEquals(inValidURL[i], false, result);
			} else {
				System.out.print("\n-PASS: " + url);
				//System.out.print("  -Expected: " + testBool + "  Returned: " + result);
			}
		}
	}
	
	//main function - calls testURLValid(); 
	 public static void main(String[] argv) {
		 unitTestCase unitTest = new unitTestCase("Unit Test");
		 unitTest.testURLValid();
	 }

}
