import java.math.BigDecimal;
import java.util.Scanner;

public class uva_748_Exponentiation {

	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		
		while (scan.hasNext()) {
			double d = scan.nextDouble();
			int e = scan.nextInt();
			
			BigDecimal bd = BigDecimal.valueOf(d);
			bd = bd.pow(e).stripTrailingZeros();
			String ans = bd.toPlainString();
			if (ans.charAt(0) == '0') 
				ans = ans.substring(1);
			
			System.out.println(ans);
		}
	}
}
