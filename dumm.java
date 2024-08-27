import java.util.Scanner;

public class dumm {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        scanner.close();

        // Step 1: Compute prefixXor array
        int[] prefixXor = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ a[i - 1];
        }

        int count = 0;
        
        // Step 2: Iterate over all possible triplets (x, y, z)
        for (int x = 1; x <= n; x++) {
            for (int y = x; y <= n; y++) {
                for (int z = y; z <= n; z++) {
                    int f_xz = prefixXor[z] ^ prefixXor[x - 1];
                    int f_xy = prefixXor[y] ^ prefixXor[x - 1];
                    int f_yz = prefixXor[z] ^ prefixXor[y - 1];
                    
                    if (f_xz < (f_xy ^ f_yz)) {
                        count++;
                    }
                }
            }
        }

        // Step 3: Output the result
        System.out.println(count);
    }
}
