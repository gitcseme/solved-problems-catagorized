import java.math.BigInteger;
import java.util.Scanner;

class uva_619_Numerically_Speaking {
	static int a[];
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		a = new int[26];
		for (int i = 0; i < 26; ++i) a[i] = i + 1;
		
		String s, first, last;
		
		while (true) {
			s = scan.nextLine();
			if (s.charAt(0) == '*') break;
			last = s;
			int len = s.length();
			BigInteger second = BigInteger.ONE, fix = BigInteger.valueOf(26), ZERO = BigInteger.ZERO;
			first = "";
			
			if(Character.isDigit(s.charAt(0))) {
				second = new BigInteger(s);
				while (second.compareTo(ZERO) != 0) {
					int v = Integer.parseInt((second.remainder(fix)).toString());
					if (v==0){ 
						first += 'z';
						v = 26;
					}
					else
						first = first + (char)('a' + v-1);
					
					second = second.subtract(BigInteger.valueOf(v));
					second = second.divide(fix);
				}
				first = new StringBuffer(first).reverse().toString();
			}
			else {
				second = BigInteger.valueOf(a[s.charAt(0)-'a']);
				for (int i = 1; i < len; ++i) {
					char c = s.charAt(i);
					second = second.multiply(fix);
					second = second.add(BigInteger.valueOf(a[c-'a']));
				}
				last = second.toString();
				first = s;
			}
			
			/* Output */
			len = first.length();
			System.out.print(first);
			for (int i = 1; i <= 22-len; ++i) System.out.print(" ");
			last = modify(last);
			System.out.println(last);
		}
		
	}

	static String modify(String last) {
		int len = last.length();
		if (last.length() <= 3) return last;
		String ret = "";
		int cnt = 0;
		for (int i = len-1; i >= 0; --i) {
			ret += last.charAt(i);
			++cnt;
			if (cnt % 3 == 0 && i != 0) ret += ',';
		}
		return new StringBuffer(ret).reverse().toString();
	}

}
