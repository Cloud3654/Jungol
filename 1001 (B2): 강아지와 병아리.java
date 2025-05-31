import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int dog, chick;
		int sum, legs;
		boolean out = false;
		while (true) {
			sum = sc.nextInt();
			legs = sc.nextInt();
			sc.nextLine();
			dog = 1;
			chick = (legs - (dog * 4)) / 2;
			if (sum == 0 && legs == 0) break; //0 0 종료
			if (sum > 1000 || legs > 4000) { System.out.println("INPUT ERROR!"); continue; } //범위 초과
			if (sum * 2 > legs || legs % 2 == 1) { System.out.println(0); continue; } //계산 불가 처리 1
			while (true) {
				chick = (legs - (dog * 4)) / 2;
				if (dog + chick == sum) {
					if (dog < 0 || chick < 0) { //계산 불가 처리 2
						System.out.println(0);
						out = true;
					}
					break;
				}
				dog++;
			}
			if (!out) {
				System.out.println(dog + " " + chick);
			}
			out = false;
		}
	}
}
