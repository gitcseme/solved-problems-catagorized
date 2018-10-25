import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

class uva_324_Factorial_Frequencies {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		HashMap<Integer, String> hs = new HashMap<>();
		hs.put(0, "1");
		hs.put(1, "1");
		BigInteger b = BigInteger.ONE;
		
		for (int i = 2; i <= 367; ++i) {
			b = b.multiply(BigInteger.valueOf(i));
			hs.put(i, b.toString());
		}
		
		int n;
		int a[] = new int[10];
		char c;
		while(true) {
			n = scan.nextInt();
			if (n == 0) break;
			
			for (int i = 0; i < 10; ++i) a[i] = 0;
			String f = hs.get(n);
			for (int i = 0, len = f.length(); i < len; ++i) {
				++a[f.charAt(i) - '0'];
			}
			
			System.out.printf("%d! --\n", n);
			for (int i = 0; i <= 4; ++i) {
				if (i == 0) System.out.print("   ");
				if (i > 0) System.out.print("    ");
				System.out.printf("(%d)%5d", i, a[i]);
			}
			System.out.println();
			
			for (int i = 5; i <= 9; ++i) {
				if (i == 5) System.out.print("   ");
				if (i > 5) System.out.print("    ");
				System.out.printf("(%d)%5d", i, a[i]);
			}
			System.out.println();
		}
		
	}

}
