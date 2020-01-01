// SWERC 2015 - Sheldon Numbers
// Approach: Simply generate all sheldon numbers and count.
// Author: Miguel Oliveira
import java.io.IOException;
import java.util.*;

public class SheldonMO {

  public static void main( String[] args ) throws IOException {
    Scanner scanner = new Scanner(System.in);
    long A = scanner.nextLong();
    long B = scanner.nextLong();
    scanner.close();
 
    int answer = 0;
    for (long x : generate()) {
      if (A <= x && x <= B)
        answer++;
    }
    System.out.println(answer);       
  }

  static Set<Long> generate() {
    Set<Long> numbers = new HashSet<Long>();
    long[] bitMasks = new long[]{0, 0};
    for (int n = 1; n < 64; n++) {
      bitMasks[1] = bitMasks[1] * 2 + 1;
      for (int m = 1; m+n <= 64; m++) {
        final int[] sizes = new int[]{m, n};
        int nbits = sizes[1];
        long number = bitMasks[1];
        for (int turn = 0; nbits < 64; turn = 1 - turn) {
          numbers.add(number);
          number = (number << sizes[turn]) + bitMasks[turn];
          nbits += sizes[turn];
        }
      }
    }
    return numbers;
  }
}
