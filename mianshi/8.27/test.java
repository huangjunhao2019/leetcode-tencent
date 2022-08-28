import java.util.*;
import java.util.stream.Collectors;

public class Main {
   
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int n1 = scanner.nextInt();  // 主语的单词数量
        final int n2 = scanner.nextInt();  // 谓语的单词数量
        final int n3 = scanner.nextInt();  // 宾语的单词数量
        Set<String> set1 = new HashSet<>();  // 存放主语
        Set<String> set2 = new HashSet<>();  // 存放谓语
        Set<String> set3 = new HashSet<>();  // 存放宾语
        for (int i = 0; i < n1; i++) {
            set1.add(scanner.next());
        }
        for (int i = 0; i < n2; i++) {
            set2.add(scanner.next());
        }
        for (int i = 0; i < n3; i++) {
            set3.add(scanner.next());
        }
        int m = scanner.nextInt();  // 读取的是下面要输入的句子的数量
        scanner.nextLine();  // 跳转到下一行去
        List<List<String>> data = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<String> data0 = Arrays.stream(scanner.nextLine().split(" ")).collect(Collectors.toList());
            data.add(data0);
        }
        data.forEach(e -> process(set1, set2, set3, e));
    }

    // 要求，谓语只能有一个，主语数量>=1，宾语数量>=0，句子结构严格按照`主谓宾`的结构进行
    public static void process(Set<String> set1, Set<String> set2, Set<String> set3, List<String> data0) {
        int weiYuCount = 0, weiYuIndex = 0;
        for (int i = 0; i < data0.size(); i++) {
            final String e = data0.get(i);
            if (set2.contains(e)) {
                weiYuCount++;  // 如果这个词是谓语的话，那么把谓语的数量++
                weiYuIndex = i;  // 修改谓语所在的索引
            }
        }

        // 如果谓语的数量不是1个，return 并输出NO
        if (weiYuCount != 1) {
            System.out.println("NO");
            return;
        }
        // 如果谓语的数量是1个的话...

        // 如果谓语是句子中的第一个单词，那么输出NO
        if (weiYuIndex == 0) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}