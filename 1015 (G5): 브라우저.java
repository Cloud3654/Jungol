import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack<String> forward = new Stack<String>();
		Stack<String> backward = new Stack<String>();
		String command;
		String[] commandsplit = new String[2];
		String pagenow = "http://www.acm.org/";
		boolean quit = false;
		while (true) {
			command = sc.nextLine();
			commandsplit = command.split(" ");
			switch (commandsplit[0]) {
			case "VISIT":
				backward.push(pagenow);
				forward.clear();
				pagenow = commandsplit[1];
				System.out.println(pagenow);
				break;
			case "FORWARD":
				if (!forward.isEmpty()) {
					backward.push(pagenow);
					pagenow = forward.pop();
					System.out.println(pagenow);
				}
				else System.out.println("Ignored");
				break;
			case "BACK":
				if (!backward.isEmpty()) {
					forward.push(pagenow);
					pagenow = backward.pop();
					System.out.println(pagenow);
				}
				else System.out.println("Ignored");
				break;
			case "QUIT":
				quit = true;
			}
			if (quit) break;
		}
	}
}
