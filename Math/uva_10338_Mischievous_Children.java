import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

class uva_10338_Mischievous_Children {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        BigInteger f[] = new BigInteger[25];
        f[0] = f[1] = BigInteger.ONE;
        for (int i = 2; i <= 20; ++i) f[i] = f[i-1].multiply(BigInteger.valueOf(i));

        int t = scan.nextInt();
                scan.nextLine();
        for (int ds = 1; ds <= t; ++ds)
        {
            char c[] = scan.nextLine().toCharArray();
            int l = c.length;
            int cnt[] = new int [27];
            Arrays.fill(cnt, 0);
            for (int i = 0; i < l; ++i) ++cnt[c[i] - 'A'];

            BigInteger ans = f[l];
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 1)
                    ans = ans.divide(f[cnt[i]]);
            }

            System.out.println("Data set "+ds+": " + ans.toString());
        }
    }
}
