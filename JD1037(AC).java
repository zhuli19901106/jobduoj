import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		BigInteger a, b, c;
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNext()) {
			a = scanner.nextBigInteger();
			b = scanner.nextBigInteger();
			c = a.add(b);
			System.out.println(c);
			c = a.subtract(b);
			System.out.println(c);
			c = a.multiply(b);
			System.out.println(c);
		}
	}
}
