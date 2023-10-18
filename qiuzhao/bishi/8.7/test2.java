import java.util.*;

public class Main {
    public static String coupons(String s) {
        StringBuilder res = new StringBuilder();
        int[] chNums = new int[26];
        for (char ch : s.toCharArray()) {
            chNums[ch - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (chNums[i] > 0) {
                res.append((char) (i + 'a'));
                chNums[i]--;
            }
        }
        for (int i = 25; i >= 0; --i) {
            while (chNums[i] > 0) {
                res.append((char) (i + 'a'));
                chNums[i]--;
            }
        }
        return res.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        System.out.println(coupons(s));
    }
}