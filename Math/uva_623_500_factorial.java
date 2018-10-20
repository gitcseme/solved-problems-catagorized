import java.math.BigInteger;
import java.util.Scanner;

public class uva_623_500_factorial {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int f;
		
		while (scan.hasNextInt()) {
			f = scan.nextInt();
			BigInteger big = BigInteger.ONE;
			
			for (int i = 2; i <= f; ++i) {
				big = big.multiply(BigInteger.valueOf(i));
			}
			
			System.out.println(f + "!");
			System.out.println(big);
		}
	}

}
