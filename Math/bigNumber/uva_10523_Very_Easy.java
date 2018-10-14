import java.math.BigInteger;
import java.util.Scanner;

class uva_10523_Very_Easy {

	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		int n, a;
		
		while (scan.hasNextInt()) {
			n = scan.nextInt();
			a = scan.nextInt();
			
			// Base case handling.
			if (a == 0) {
				System.out.println("0");
				continue;
			}
			if (a == 1) {
				System.out.println(((n * (n+1)) / 2));
				continue;
			}
			
			BigInteger big2, big1, biga, bign, dino;
			biga = BigInteger.valueOf(a);
			bign = BigInteger.valueOf(n);
			
			big2 = biga.pow(n+2).multiply(bign);
			big1 = biga.pow(n+1).multiply(bign.add(BigInteger.ONE));
			big2 = big2.subtract(big1).add(biga);
			
			dino = BigInteger.valueOf(1-a).multiply(BigInteger.valueOf(1-a));
			
			big2 = big2.divide(dino);
			System.out.println(big2.toString());
		}
	}

}
