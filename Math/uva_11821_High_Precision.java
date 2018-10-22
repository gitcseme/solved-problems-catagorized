import java.math.BigDecimal;
import java.util.Scanner;

class uva_11821_High_Precision {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		
		for (int i = 0; i < tc; ++i) {
			BigDecimal ans = BigDecimal.ZERO;
			while (true) {
				BigDecimal x = in.nextBigDecimal();
				if (x.compareTo(BigDecimal.ZERO) == 0) break;
				ans = ans.add(x);
			}
			ans = ans.stripTrailingZeros();
			System.out.println(ans.toPlainString());
		}
	}
}
